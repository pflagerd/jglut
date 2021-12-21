package org.pflager.gl;

import java.io.IOException;

import org.junit.jupiter.api.Test;

public class Test_com_pflager_gl_glRectd extends glutTest {

	@Test
	void testFullyFilledCanvas_DD_DD() throws IOException, InterruptedException {
		singleShotDisplayTest(() -> {
			glClear(GL_COLOR_BUFFER_BIT);

			glRectd(-0.001, -0.001, 0.001, 0.001);

			glFinish(); // waits for display to settle down.

			try {
				captureCanvasAsImageFile("test/referenceImages/tmp.png");
			} catch (IOException ioException) {
				System.err.println("Couldn't save file test/referenceImages/tmp.png");
				ioException.printStackTrace(System.err);
			}
			glutLeaveMainLoop();
		});
	}

	@Test
	void testSquareInTheMiddleOfTheCanvas_DD_DD() throws IOException, InterruptedException {
		singleShotDisplayTest(() -> {
			glClear(GL_COLOR_BUFFER_BIT);
			glRectd(-0.07, -0.07, 0.007, 0.007);
			glFinish(); // waits for display to settle down.

			try {
				captureCanvasAsImageFile("test/referenceImages/tmp.png");
			} catch (IOException ioException) {
				System.err.println("Couldn't save file test/referenceImages/tmp.png");
				ioException.printStackTrace(System.err);
			}
			glutLeaveMainLoop();
		});
	}

	@Test
	void testPartiallyFilledCanvas_DD_DD() throws IOException, InterruptedException {
		singleShotDisplayTest(() -> {
			glClear(GL_COLOR_BUFFER_BIT);
			// glRectd(-3, -3, -0.01, 0.01);
			glRectd(-0.01, -0.1, -3, -3);
			glFinish(); // waits for display to settle down.

			try {
				captureCanvasAsImageFile("test/referenceImages/tmp.png");
			} catch (IOException ioException) {
				System.err.println("Couldn't save file test/referenceImages/tmp.png");
				ioException.printStackTrace(System.err);
			}
			glutLeaveMainLoop();
		});
	}
}
