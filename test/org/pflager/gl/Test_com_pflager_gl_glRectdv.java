package org.pflager.gl;

import java.io.IOException;

import org.junit.jupiter.api.Test;

class Test_com_pflager_gl_glRectdv extends glutTest {

	@Test
	void testFullyFilledCanvas_II_II() throws IOException, InterruptedException {
		singleShotDisplayTest(() -> {
			glClear(GL_COLOR_BUFFER_BIT);

			glRectdv(new double[] { -1, -1 }, new double[] { 1, 1 });

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

			glRectdv(new double[] { -0.5, -0.5 }, new double[] { 0.5, 0.5 });

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
	void testPartiallyFilledCanvas_II_FF() throws IOException, InterruptedException {
		singleShotDisplayTest(() -> {
			glClear(GL_COLOR_BUFFER_BIT);

			glRectdv(new double[] { 0, 0 }, new double[] { 1f, 1.0f });

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
