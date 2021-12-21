package com.pflager;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URISyntaxException;

public class glut extends glu {

	@SuppressWarnings("serial")
	static public class NotImplementedException extends Exception {
		public NotImplementedException() {
		}

		public NotImplementedException(String msg) {
			super(msg);
		}
	}

	static public String getVersion() {
		return "0.1.6";
	}
	
	static {
		if (System.getProperty("os.name").contains("Windows")) {
			load("/libglut-0.dll");
			load("/libjglut.dll");
		} else { // Assumes Linux
			load("/libjglut.so");
		}
	}

	final static boolean debug = false;  // This debug flag is strictly for debugging in glut.java.  Change it explicitly.

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

	static boolean isInAJar(String resourcePath) {
		return glut.class.getResource("glut.class").toString().startsWith("jar:");
	}

	static void extractFromJarAndLoad(String resourcePath) {
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
	
	/*
	 * GLUT API macro definitions -- the special key codes:
	 */
	public final int GLUT_KEY_F1 = 0x00000001;
	public final int GLUT_KEY_F2 = 0x00000002;
	public final int GLUT_KEY_F3 = 0x00000003;
	public final int GLUT_KEY_F4 = 0x00000004;
	public final int GLUT_KEY_F5 = 0x00000005;
	public final int GLUT_KEY_F6 = 0x00000006;
	public final int GLUT_KEY_F7 = 0x00000007;
	public final int GLUT_KEY_F8 = 0x00000008;
	public final int GLUT_KEY_F9 = 0x00000009;
	public final int GLUT_KEY_F10 = 0x0000000A;
	public final int GLUT_KEY_F11 = 0x0000000B;
	public final int GLUT_KEY_F12 = 0x0000000C;
	public final int GLUT_KEY_LEFT = 0x00000064;
	public final int GLUT_KEY_UP = 0x00000065;
	public final int GLUT_KEY_RIGHT = 0x00000066;
	public final int GLUT_KEY_DOWN = 0x00000067;
	public final int GLUT_KEY_PAGE_UP = 0x00000068;
	public final int GLUT_KEY_PAGE_DOWN = 0x00000069;
	public final int GLUT_KEY_HOME = 0x0000006A;
	public final int GLUT_KEY_END = 0x0000006B;
	public final int GLUT_KEY_INSERT = 0x0000006C;

	/*
	 * GLUT API macro definitions -- mouse state definitions
	 */
	public final int GLUT_LEFT_BUTTON = 0x00000000;
	public final int GLUT_MIDDLE_BUTTON = 0x00000001;
	public final int GLUT_RIGHT_BUTTON = 0x00000002;
	public final int GLUT_SCROLLWHEEL_UP = 0x00000003;
	public final int GLUT_SCROLLWHEEL_DOWN = 0x00000003;
	public final int GLUT_DOWN = 0x00000000;
	public final int GLUT_UP = 0x00000001;
	public final int GLUT_LEFT = 0x00000000;
	public final int GLUT_ENTERED = 0x00000001;

	/*
	 * GLUT API macro definitions -- the display mode definitions
	 */
	public final int GLUT_RGB = 0x00000000;
	public final int GLUT_RGBA = 0x00000000;
	public final int GLUT_INDEX = 0x00000001;
	public final int GLUT_SINGLE = 0x00000000;
	public final int GLUT_DOUBLE = 0x00000002;
	public final int GLUT_ACCUM = 0x00000004;
	public final int GLUT_ALPHA = 0x00000008;
	public final int GLUT_DEPTH = 0x00000010;
	public final int GLUT_STENCIL = 0x00000020;
	public final int GLUT_MULTISAMPLE = 0x00000080;
	public final int GLUT_STEREO = 0x00000100;
	public final int GLUT_LUMINANCE = 0x00000200;

	/*
	 * GLUT API macro definitions -- windows and menu related definitions
	 */
	public final int GLUT_MENU_NOT_IN_USE = 0x00000000;
	public final int GLUT_MENU_IN_USE = 0x00000001;
	public final int GLUT_NOT_VISIBLE = 0x00000000;
	public final int GLUT_VISIBLE = 0x00000001;
	public final int GLUT_HIDDEN = 0x00000000;
	public final int GLUT_FULLY_RETAINED = 0x00000001;
	public final int GLUT_PARTIALLY_RETAINED = 0x00000002;
	public final int GLUT_FULLY_COVERED = 0x00000003;

	public final int GLUT_STROKE_ROMAN = 0x00000000;
	public final int GLUT_STROKE_MONO_ROMAN = 0x00000001;
	public final int GLUT_BITMAP_9_BY_15 = 0x00000002;
	public final int GLUT_BITMAP_8_BY_13 = 0x00000003;
	public final int GLUT_BITMAP_TIMES_ROMAN_10 = 0x00000004;
	public final int GLUT_BITMAP_TIMES_ROMAN_24 = 0x00000005;
	public final int GLUT_BITMAP_HELVETICA_10 = 0x00000006;
	public final int GLUT_BITMAP_HELVETICA_12 = 0x00000007;
	public final int GLUT_BITMAP_HELVETICA_18 = 0x00000008;

	/*
	 * GLUT API macro definitions -- the glutGet parameters
	 */
	public final int GLUT_WINDOW_X = 0x00000064;
	public final int GLUT_WINDOW_Y = 0x00000065;
	public final int GLUT_WINDOW_WIDTH = 0x00000066;
	public final int GLUT_WINDOW_HEIGHT = 0x00000067;
	public final int GLUT_WINDOW_BUFFER_SIZE = 0x00000068;
	public final int GLUT_WINDOW_STENCIL_SIZE = 0x00000069;
	public final int GLUT_WINDOW_DEPTH_SIZE = 0x0000006A;
	public final int GLUT_WINDOW_RED_SIZE = 0x0000006B;
	public final int GLUT_WINDOW_GREEN_SIZE = 0x0000006C;
	public final int GLUT_WINDOW_BLUE_SIZE = 0x0000006D;
	public final int GLUT_WINDOW_ALPHA_SIZE = 0x0000006E;
	public final int GLUT_WINDOW_ACCUM_RED_SIZE = 0x0000006F;
	public final int GLUT_WINDOW_ACCUM_GREEN_SIZE = 0x00000070;
	public final int GLUT_WINDOW_ACCUM_BLUE_SIZE = 0x00000071;
	public final int GLUT_WINDOW_ACCUM_ALPHA_SIZE = 0x00000072;
	public final int GLUT_WINDOW_DOUBLEBUFFER = 0x00000073;
	public final int GLUT_WINDOW_RGBA = 0x00000074;
	public final int GLUT_WINDOW_PARENT = 0x00000075;
	public final int GLUT_WINDOW_NUM_CHILDREN = 0x00000076;
	public final int GLUT_WINDOW_COLORMAP_SIZE = 0x00000077;
	public final int GLUT_WINDOW_NUM_SAMPLES = 0x00000078;
	public final int GLUT_WINDOW_STEREO = 0x00000079;
	public final int GLUT_WINDOW_CURSOR = 0x0000007A;

	public final int GLUT_SCREEN_WIDTH = 0x000000C8;
	public final int GLUT_SCREEN_HEIGHT = 0x000000C9;
	public final int GLUT_SCREEN_WIDTH_MM = 0x000000CA;
	public final int GLUT_SCREEN_HEIGHT_MM = 0x000000CB;
	public final int GLUT_MENU_NUM_ITEMS = 0x0000012C;
	public final int GLUT_DISPLAY_MODE_POSSIBLE = 0x00000190;
	public final int GLUT_INIT_WINDOW_X = 0x000001F4;
	public final int GLUT_INIT_WINDOW_Y = 0x000001F5;
	public final int GLUT_INIT_WINDOW_WIDTH = 0x000001F6;
	public final int GLUT_INIT_WINDOW_HEIGHT = 0x000001F7;
	public final int GLUT_INIT_DISPLAY_MODE = 0x000001F8;
	public final int GLUT_ELAPSED_TIME = 0x000002BC;
	public final int GLUT_WINDOW_FORMAT_ID = 0x0000007B;

	/*
	 * GLUT API macro definitions -- the glutDeviceGet parameters
	 */
	public final int GLUT_HAS_KEYBOARD = 0x00000258;
	public final int GLUT_HAS_MOUSE = 0x00000259;
	public final int GLUT_HAS_SPACEBALL = 0x0000025A;
	public final int GLUT_HAS_DIAL_AND_BUTTON_BOX = 0x0000025B;
	public final int GLUT_HAS_TABLET = 0x0000025C;
	public final int GLUT_NUM_MOUSE_BUTTONS = 0x0000025D;
	public final int GLUT_NUM_SPACEBALL_BUTTONS = 0x0000025E;
	public final int GLUT_NUM_BUTTON_BOX_BUTTONS = 0x0000025F;
	public final int GLUT_NUM_DIALS = 0x00000260;
	public final int GLUT_NUM_TABLET_BUTTONS = 0x00000261;
	public final int GLUT_DEVICE_IGNORE_KEY_REPEAT = 0x00000262;
	public final int GLUT_DEVICE_KEY_REPEAT = 0x00000263;
	public final int GLUT_HAS_JOYSTICK = 0x00000264;
	public final int GLUT_OWNS_JOYSTICK = 0x00000265;
	public final int GLUT_JOYSTICK_BUTTONS = 0x00000266;
	public final int GLUT_JOYSTICK_AXES = 0x00000267;
	public final int GLUT_JOYSTICK_POLL_RATE = 0x00000268;

	/*
	 * GLUT API macro definitions -- the glutLayerGet parameters
	 */
	public final int GLUT_OVERLAY_POSSIBLE = 0x00000320;
	public final int GLUT_LAYER_IN_USE = 0x00000321;
	public final int GLUT_HAS_OVERLAY = 0x00000322;
	public final int GLUT_TRANSPARENT_INDEX = 0x00000323;
	public final int GLUT_NORMAL_DAMAGED = 0x00000324;
	public final int GLUT_OVERLAY_DAMAGED = 0x00000325;

	/*
	 * GLUT API macro definitions -- the glutVideoResizeGet parameters
	 */
	public final int GLUT_VIDEO_RESIZE_POSSIBLE = 0x00000384;
	public final int GLUT_VIDEO_RESIZE_IN_USE = 0x00000385;
	public final int GLUT_VIDEO_RESIZE_X_DELTA = 0x00000386;
	public final int GLUT_VIDEO_RESIZE_Y_DELTA = 0x00000387;
	public final int GLUT_VIDEO_RESIZE_WIDTH_DELTA = 0x00000388;
	public final int GLUT_VIDEO_RESIZE_HEIGHT_DELTA = 0x00000389;
	public final int GLUT_VIDEO_RESIZE_X = 0x0000038A;
	public final int GLUT_VIDEO_RESIZE_Y = 0x0000038B;
	public final int GLUT_VIDEO_RESIZE_WIDTH = 0x0000038C;
	public final int GLUT_VIDEO_RESIZE_HEIGHT = 0x0000038D;

	/*
	 * GLUT API macro definitions -- the glutUseLayer parameters
	 */
	public final int GLUT_NORMAL = 0x00000000;
	public final int GLUT_OVERLAY = 0x00000001;

	/*
	 * GLUT API macro definitions -- the glutGetModifiers parameters
	 */
	public final int GLUT_ACTIVE_SHIFT = 0x00000001;
	public final int GLUT_ACTIVE_CTRL = 0x00000002;
	public final int GLUT_ACTIVE_ALT = 0x00000004;

	/*
	 * GLUT API macro definitions -- the glutSetCursor parameters
	 */
	public final int GLUT_CURSOR_RIGHT_ARROW = 0x00000000;
	public final int GLUT_CURSOR_LEFT_ARROW = 0x00000001;
	public final int GLUT_CURSOR_INFO = 0x00000002;
	public final int GLUT_CURSOR_DESTROY = 0x00000003;
	public final int GLUT_CURSOR_HELP = 0x00000004;
	public final int GLUT_CURSOR_CYCLE = 0x00000005;
	public final int GLUT_CURSOR_SPRAY = 0x00000006;
	public final int GLUT_CURSOR_WAIT = 0x00000007;
	public final int GLUT_CURSOR_TEXT = 0x00000008;
	public final int GLUT_CURSOR_CROSSHAIR = 0x00000009;
	public final int GLUT_CURSOR_UP_DOWN = 0x0000000A;
	public final int GLUT_CURSOR_LEFT_RIGHT = 0x0000000B;
	public final int GLUT_CURSOR_TOP_SIDE = 0x0000000C;
	public final int GLUT_CURSOR_BOTTOM_SIDE = 0x0000000D;
	public final int GLUT_CURSOR_LEFT_SIDE = 0x0000000E;
	public final int GLUT_CURSOR_RIGHT_SIDE = 0x0000000F;
	public final int GLUT_CURSOR_TOP_LEFT_CORNER = 0x00000010;
	public final int GLUT_CURSOR_TOP_RIGHT_CORNER = 0x00000011;
	public final int GLUT_CURSOR_BOTTOM_RIGHT_CORNER = 0x00000012;
	public final int GLUT_CURSOR_BOTTOM_LEFT_CORNER = 0x00000013;
	public final int GLUT_CURSOR_INHERIT = 0x00000064;
	public final int GLUT_CURSOR_NONE = 0x00000065;
	public final int GLUT_CURSOR_FULL_CROSSHAIR = 0x00000066;

	/*
	 * GLUT API macro definitions -- RGB color component specification definitions
	 */
	public final int GLUT_RED = 0x00000000;
	public final int GLUT_GREEN = 0x00000001;
	public final int GLUT_BLUE = 0x00000002;

	/*
	 * GLUT API macro definitions -- additional keyboard and joystick definitions
	 */
	public final int GLUT_KEY_REPEAT_OFF = 0x00000000;
	public final int GLUT_KEY_REPEAT_ON = 0x00000001;
	public final int GLUT_KEY_REPEAT_DEFAULT = 0x00000002;

	public final int GLUT_JOYSTICK_BUTTON_A = 0x00000001;
	public final int GLUT_JOYSTICK_BUTTON_B = 0x00000002;
	public final int GLUT_JOYSTICK_BUTTON_C = 0x00000004;
	public final int GLUT_JOYSTICK_BUTTON_D = 0x00000008;

	/*
	 * GLUT API macro definitions -- game mode definitions
	 */
	public final int GLUT_GAME_MODE_ACTIVE = 0x00000000;
	public final int GLUT_GAME_MODE_POSSIBLE = 0x00000001;
	public final int GLUT_GAME_MODE_WIDTH = 0x00000002;
	public final int GLUT_GAME_MODE_HEIGHT = 0x00000003;
	public final int GLUT_GAME_MODE_PIXEL_DEPTH = 0x00000004;
	public final int GLUT_GAME_MODE_REFRESH_RATE = 0x00000005;
	public final int GLUT_GAME_MODE_DISPLAY_CHANGED = 0x00000006;

	/*
	 * GLUT API Extension macro definitions -- behaviour when the user clicks on an "x" to close a window
	 */
	public final int GLUT_ACTION_EXIT                	= 0;
	public final int GLUT_ACTION_GLUTMAINLOOP_RETURNS 	= 1;
	public final int GLUT_ACTION_CONTINUE_EXECUTION     = 2;

	/*
	 * GLUT API Extension macro definitions -- the glutGet parameters
	 */
	public final int  GLUT_INIT_STATE                    = 0x007C;
	public final int  GLUT_ACTION_ON_WINDOW_CLOSE        = 0x01F9;
	public final int  GLUT_WINDOW_BORDER_WIDTH           = 0x01FA;
	public final int  GLUT_WINDOW_BORDER_HEIGHT          = 0x01FB;
	public final int  GLUT_WINDOW_HEADER_HEIGHT          = 0x01FB;  /* Docs say it should always have been GLUT_WINDOW_BORDER_HEIGHT, keep this for backward compatibility */
	public final int  GLUT_VERSION                       = 0x01FC;
	public final int  GLUT_RENDERING_CONTEXT             = 0x01FD;
	public final int  GLUT_DIRECT_RENDERING              = 0x01FE;
	public final int  GLUT_FULL_SCREEN                   = 0x01FF;
	public final int  GLUT_SKIP_STALE_MOTION_EVENTS      = 0x0204;
	public final int  GLUT_GEOMETRY_VISUALIZE_NORMALS    = 0x0205;
	public final int  GLUT_STROKE_FONT_DRAW_JOIN_DOTS    = 0x0206;  /* Draw dots between line segments of stroke fonts? */

	/*
	 * Initialization functions, see fglut_init.c
	 */
	public native void glutInit(int argc, String[] argv);
	public native void glutInit(String[] argv);
	public native void glutInit(String arg);
	public native void glutInit();

	public native void glutInitWindowPosition(int x, int y);

	public native void glutInitWindowSize(int width, int height);

	public native void glutInitDisplayMode(int displayMode);

	public native void glutInitDisplayString(String displayMode);

	/*
	 * Process loop function, see fg_main.c
	 */
	public native void glutMainLoop();
	public native void glutLeaveMainLoop(); // freeGlut extension.

	/*
	 * Window management functions, see fg_window.c
	 */
	public native int glutCreateWindow(String title);

//	public native int glutCreateSubWindow(int window, int x, int y, int width, int height);

//	public native void glutDestroyWindow(int window);

//	public native void glutSetWindow(int window);

//	public native int glutGetWindow();

	public native void glutSetWindowTitle(String title);

//	public native void glutSetIconTitle(String title);

//	public native void glutReshapeWindow(int width, int height);

	public native void glutPositionWindow(int x, int y);

//	public native void glutShowWindow();

//	public native void glutHideWindow();

//	public native void glutIconifyWindow();

//	public native void glutPushWindow();

//	public native void glutPopWindow();

//	public native void glutFullScreen();

	/*
	 * Display-related functions, see fg_display.c
	 */
//	public native void glutPostWindowRedisplay(int window);

	public native void glutPostRedisplay();

	public native void glutSwapBuffers();

	/*
	 * Mouse cursor functions, see fg_cursor.c
	 */
//	public native void glutWarpPointer(int x, int y);

//	public native void glutSetCursor(int cursor);

	/*
	 * Overlay stuff, see fg_overlay.c
	 */
//	public native void glutEstablishOverlay();

//	public native void glutRemoveOverlay();

//	public native void glutUseLayer(int layer);

//	public native void glutPostOverlayRedisplay();

//	public native void glutPostWindowOverlayRedisplay(int window);

//	public native void glutShowOverlay();

//	public native void glutHideOverlay();

	/*
	 * Menu stuff, see fg_menu.c
	 */
//	public interface Menu {
//		void menu(int menu);
//	}
//
//	public native int glutCreateMenu(Menu menu);

//	public native void glutDestroyMenu(int menu);

//	public native int glutGetMenu();

//	public native void glutSetMenu(int menu);

//	public native void glutAddMenuEntry(String label, int value);
//
//	public native void glutAddSubMenu(String label, int subMenu);
//
//	public native void glutChangeToMenuEntry(int item, String label, int value);
//
//	public native void glutChangeToSubMenu(int item, String label, int value);
//
//	public native void glutRemoveMenuItem(int item);
//
//	public native void glutAttachMenu(int button);
//
//	public native void glutDetachMenu(int button);

	/*
	 * Global callback functions, see fg_callbacks.c
	 */
	public interface TimerFunc {
		public void timer(int value);
	}

	public native void glutTimerFunc(int time, TimerFunc timerFunc, int value);

	public interface IdleFunc {
		void idle();
	}

	public native void glutIdleFunc(IdleFunc idleFunc);

	/*
	 * Window-specific callback functions, see fg_callbacks.c
	 */
	public interface KeyboardFunc {
		public void keyboard(char c, int x, int y);
	}

	public native void glutKeyboardFunc(KeyboardFunc keyboardFunc);

//	public interface SpecialFunc {
//		public void special(int key, int x, int y);
//	}
//
//	public native void glutSpecialFunc(SpecialFunc specialFunc);

	public interface ReshapeFunc {
		public void reshape(int width, int height);
	}

	public native void glutReshapeFunc(ReshapeFunc reshapeFunc);

//	public interface VisibilityFunc {
//		public void visibility(int state);
//	}
//
//	public native void glutVisibilityFunc(VisibilityFunc visibilityFunc);

	public interface DisplayFunc {
		public void display();
	}

	public native void glutDisplayFunc(DisplayFunc displayFunc);

	public interface MouseFunc {
		public void mouse(int button, int state, int x, int y);
	}

	public native void glutMouseFunc(MouseFunc mouseFunc);

	public interface MotionFunc {
		public void motion(int x, int y);
	}

	public native void glutMotionFunc(MotionFunc motionFunc);

//	public interface PassiveMotionFunc {
//		public void motion(int x, int y);
//	}
//
//	public native void glutPassiveMotionFunc(PassiveMotionFunc passiveMotionFunc);

//	public interface EntryFunc {
//		public void entry(int state);
//	}
//
//	public native void glutEntryFunc(EntryFunc entryFunc);

//	public interface KeyboardUpFunc {
//		public void keyboardUp(char c, int x, int y); // TODO: DPP: 180103T222200: Confirm the parameter names somehow. They weren't
//														// in the 1.3 Glut reference.
//	}
//
//	public native void glutKeyboardUpFunc(KeyboardUpFunc keyboardUpFunc);

//	public interface SpecialUpFunc {
//		public void specialUp(int key, int x, int y); // TODO: DPP: 180103T222200: Confirm the parameter names somehow. They weren't
//														// in the 1.3 Glut reference.
//	}
//
//	public native void glutSpecialUpFunc(SpecialUpFunc specialUpFunc);

//	public interface JoystickFunc {
//		public void joystick(int a, int b, int x, int y); // TODO: DPP: 180103T222200: Confirm the parameter names somehow. They weren't
//															// in the 1.3 Glut reference.
//	}
//
//	public native void glutJoystickFunc(JoystickFunc joystickFunc, int pollInterval);

//	public interface MenuStateFunc {
//		public void menuState(int status); // DPP: 180103T222200: <code>int status</code> (sic), not <code>int
//											// state</code>.
//	}
//
//	public native void glutMenuStateFunc(MenuStateFunc menuStateFunc);

//	public interface MenuStatusFunc {
//		public void menuStatus(int status, int x, int y);
//	}
//
//	public native void glutMenuStatusFunc(MenuStatusFunc menuStatusFunc);

//	public interface OverlayDisplayFunc {
//		public void overlayDisplay();
//	}
//
//	public native void glutOverlayDisplayFunc(OverlayDisplayFunc overlayDisplayFunc);

//	public interface WindowStatusFunc {
//		public void windowStatus(int status);
//	}
//
//	public native void glutWindowStatusFunc(WindowStatusFunc windowStatusFunc);

//	public interface SpaceballMotionFunc {
//		public void spaceballMotion(int x, int y, int z);
//	}
//
//	public native void glutSpaceballMotionFunc(SpaceballMotionFunc spaceballMotionFunc);

//	public interface SpaceballRotateFunc {
//		public void spaceballRotate(int x, int y, int z);
//	}
//
//	public native void glutSpaceballRotateFunc(SpaceballRotateFunc spaceballRotateFunc);

//	public interface SpaceballButtonFunc {
//		public void spaceballButton(int button, int state);
//	}
//
//	public native void glutSpaceballButtonFunc(SpaceballButtonFunc spaceballButtonFunc);

//	public interface ButtonBoxFunc {
//		public void buttonBox(int button, int state);
//	}
//
//	public native void glutButtonBoxFunc(ButtonBoxFunc buttonBoxFunc);

//	public interface DialsFunc {
//		public void dials(int dial, int value);
//	}
//
//	public native void glutDialsFunc(DialsFunc dialsFunc);

//	public interface TabletMotionFunc {
//		public void tabletMotion(int x, int y);
//	}
//
//	public native void glutTabletMotionFunc(TabletMotionFunc tabletMotionFunc);

//	public interface TabletButtonFunc {
//		public void tabletButton(int button, int state, int x, int y);
//	}
//
//	public native void glutTabletButtonFunc(TabletButtonFunc tabletButtonFunc);

	/*
	 * State setting and retrieval functions, see fg_state.c
	 */
	public native int glutGet(int query); 		// These two are identical
	public native int glutGetOption(int query);	//           "

//	public native int glutDeviceGet(int query);

//	public native int glutGetModifiers();
//
//	public native int glutLayerGet(int query);

	public native void glutSet( int eWhat, int value ); 		// These two are identical
	public native void glutSetOption( int eWhat, int value ); 	//           "

	/*
	 * Font stuff, see fg_font.c
	 */
	public native void glutBitmapCharacter(int font, char character);

//	public native int glutBitmapWidth(int font, int character);
//
//	public native void glutStrokeCharacter(int font, int character);
//
//	public native int glutStrokeWidth(int font, int character);
//
//	public native float glutStrokeWidthf(int font, int character); /* GLUT 3.8 */
//
//	public native int glutBitmapLength(int font, String string);
//
//	public native int glutStrokeLength(int font, String string);
//
//	public native float glutStrokeLengthf(int font, String string); /* GLUT 3.8 */

	/*
	 * Geometry functions, see fg_geometry.c
	 */

	public native void glutWireCube(double size);

	public native void glutSolidCube(double size);

	public native void glutWireSphere(double radius, int slices, int stacks);

	public native void glutSolidSphere(double radius, int slices, int stacks);

	public native void glutWireCone(double base, double height, int slices, int stacks);

	public native void glutSolidCone(double base, double height, int slices, int stacks);

	public native void glutWireTorus(double innerRadius, double outerRadius, int sides, int rings);

	public native void glutSolidTorus(double innerRadius, double outerRadius, int sides, int rings);

	public native void glutWireDodecahedron();

	public native void glutSolidDodecahedron();

	public native void glutWireOctahedron();

	public native void glutSolidOctahedron();

	public native void glutWireTetrahedron();

	public native void glutSolidTetrahedron();

	public native void glutWireIcosahedron();

	public native void glutSolidIcosahedron();

	/*
	 * Teapot rendering functions, found in fg_teapot.c NB: front facing polygons
	 * have clockwise winding, not counter clockwise
	 */
	public native void glutWireTeapot(double size);

	public native void glutSolidTeapot(double size);

	/*
	 * Geometry extension functions
	 */
	public native void glutWireRhombicDodecahedron();
	public native void glutSolidRhombicDodecahedron();
	public native void glutWireSierpinskiSponge ( int num_levels, double[] offset, double scale );
	public native void glutSolidSierpinskiSponge ( int num_levels, double[] offset, double scale );
	public native void glutWireCylinder( double radius, double height, int slices, int stacks);
	public native void glutSolidCylinder( double radius, double height, int slices, int stacks);

	/*
	 * Rest of functions for rendering Newell's teaset,
	 * NB: front facing polygons have clockwise winding, not counter clockwise
	 */
	public native void glutWireTeacup( double size );
	public native void glutSolidTeacup( double size );
	public native void glutWireTeaspoon( double size );
	public native void glutSolidTeaspoon( double size );

	/*
	 * Game mode functions, see fg_gamemode.c
	 */
//	public native void glutGameModeString(String string);
//
//	public native int glutEnterGameMode();
//
//	public native void glutLeaveGameMode();
//
//	public native int glutGameModeGet(int query);

	/*
	 * Video resize functions, see fg_videoresize.c
	 */
//	public native int glutVideoResizeGet(int query);
//
//	public native void glutSetupVideoResizing();
//
//	public native void glutStopVideoResizing();
//
//	public native void glutVideoResize(int x, int y, int width, int height);
//
//	public native void glutVideoPan(int x, int y, int width, int height);

	/*
	 * Colormap functions, see fg_misc.c
	 */
	public native void glutSetColor(int color, double red, double green, double blue);
	public native void glutSetColor(int color, float red, float green, float blue);

	public native float glutGetColor(int color, int component);

	public native void glutCopyColormap(int window);

	/*
	 * Misc keyboard and joystick functions, see fg_misc.c
	 */
//	public native void glutIgnoreKeyRepeat(int ignore);
//
//	public native void glutSetKeyRepeat(int repeatMode);

//	public native void glutForceJoystickFunc();

	/*
	 * Misc functions, see fg_misc.c
	 */
//	public native int glutExtensionSupported(String extension);
//
//	public native void glutReportErrors();

	/*
	 * More freeglut extensions
	 */
	public static native void glutSetDebug(boolean debug);
}
