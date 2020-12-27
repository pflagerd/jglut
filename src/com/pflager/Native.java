package com.pflager;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URISyntaxException;

public class Native {
	
	static boolean debug = Boolean.parseBoolean(System.getProperty("jglut.debug", "true"));

	/**
	 * 
	 * Searches glut class for a named native resource, and if found, loads it using
	 * System.load().
	 * 
	 * If not in a .jar, loads directly from disk. If in a jar, extracts to the same
	 * directory as contains the .jar and then loads it from disk.
	 * 
	 * NOTE: Dependent natives must be loaded in order.
	 * 
	 * @param resourcePath Pass the resource path, usually as a class-relative
	 *                     absolute path. e.g. /libjglut.dll or /libjglut.so
	 */
	static void load(String resourcePath) {
		if (debug)
			System.out.println("resourcePath == \"" + resourcePath + "\"");

		if (isInAJar(resourcePath)) {
			extractFromJarAndLoad(resourcePath);
		} else {
			try {
				System.load(new File(glut.class.getProtectionDomain().getCodeSource().getLocation().toURI()).getAbsolutePath() + resourcePath);
			} catch (URISyntaxException e) {
				System.err.println("Should never reach here!");
				e.printStackTrace(System.err);
			}
		}
	}

	private static boolean isInAJar(String resourcePath) {
		return glut.class.getResource("glut.class").toString().startsWith("jar:");
	}

	private static void extractFromJarAndLoad(String resourcePath) {
		try (InputStream in = glut.class.getResourceAsStream(resourcePath)) {
			if (debug)
				System.out.println("resourcePath == " + in.toString());
			
			File jarFile = new File(glut.class.getProtectionDomain().getCodeSource().getLocation().toURI());
			if (debug)
				System.out.println("jarFile.lastModified() == " + jarFile.lastModified());
			
			File jarDir = new File(glut.class.getProtectionDomain().getCodeSource().getLocation().toURI()).getParentFile();
			if (debug)
				System.out.println(jarDir.getAbsolutePath());

			String destinationSharedObjectFileString = jarDir.getAbsolutePath() + "/" + resourcePath.substring(1);
			if (debug)
				System.out.println("destinationSharedObjectFileString == \"" + destinationSharedObjectFileString + "\"");
			
			// If the timestamp on the jar file is the same or older than that of the existing destinationSharedObjectFileString
			// then do not extract it.
			File destinationSharedObjectFile = new File(destinationSharedObjectFileString);
			if (debug)
				System.out.println("destinationSharedObjectFile.lastModified() == " + destinationSharedObjectFile.lastModified());

			if (jarFile.lastModified() > destinationSharedObjectFile.lastModified()) {
				if (debug)
					System.out.println(jarFile.getAbsolutePath() + " is younger than " + destinationSharedObjectFile.getAbsolutePath() + ", extracting and overwriting it!");
				try (FileOutputStream fos = new FileOutputStream(destinationSharedObjectFileString)) {
					byte[] buffer = new byte[8 * 1024 * 1024];
					int read = -1;
					while ((read = in.read(buffer)) != -1) {
						fos.write(buffer, 0, read);
					}
				} catch (FileNotFoundException fnfe) {
					System.err.println("File not found: " + destinationSharedObjectFileString);
					fnfe.printStackTrace(System.err);
					System.exit(1);
				} catch (IOException ieo) {
					System.out.println("IOException writing to " + destinationSharedObjectFileString);
					ieo.printStackTrace(System.err);
					System.exit(1);
				}
			} else {
				if (debug)
					System.out.println(jarFile.getAbsolutePath() + " is older than or the same age as " + destinationSharedObjectFile.getAbsolutePath() + ", therefore NOT extracting NOR overwriting it!");
			}
			
			System.load(destinationSharedObjectFileString);
		} catch (IOException ioe) {
			System.out.println("IOException getting resource as stream: " + resourcePath);
			ioe.printStackTrace(System.err);
			System.exit(1);
		} catch (URISyntaxException use) {
			System.out.println("URISyntaxException getting resource as stream: " + resourcePath);
			use.printStackTrace(System.err);
			System.exit(1);
		}
	}
}
