//
// Book:      OpenGL(R) ES 2.0 Programming Guide
// Authors:   Aaftab Munshi, Dan Ginsburg, Dave Shreiner
// ISBN-10:   0321502795
// ISBN-13:   9780321502797
// Publisher: Addison-Wesley Professional
// URLs:      http://safari.informit.com/9780321563835
//            http://www.opengles-book.com
//

// Hello_Triangle.c
//
//    This is a simple example that draws a single triangle with
//    a minimal vertex/fragment shader.  The purpose of this 
//    example is to demonstrate the basic concepts of 
//    OpenGL ES 2.0 rendering.
package net.pflager.openglesbooksamples;

import com.pflager.glut;
import net.pflager.gles2;

public class Hello_Triangle extends glut implements gles2 {

	class UserData {
		// Handle to a program object
		int programObject;
	};

	UserData userData;

	int height = 240;
	int width = 320;

	///
	// Create a shader object, load the shader source, and
	// compile the shader.
	//
	int LoadShader ( int type, String shaderSrc )
	{
	   int shader;
	   boolean compiled;
	   
	   // Create the shader object
	   shader = glCreateShader( type );
	
	   if ( shader == 0 )
	   	return 0;
	
	   // Load the shader source
	   glShaderSource ( shader, 1, &shaderSrc, NULL );
	   
	   // Compile the shader
	   glCompileShader ( shader );
	
	   // Check the compile status
	   glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );
	
	   if ( !compiled ) 
	   {
	      int infoLen = 0;
	
	      glGetShaderiv ( shader, GL_INFO_LOG_LENGTH, &infoLen );
	      
	      if ( infoLen > 1 )
	      {
	         String infoLog;
	
	         glGetShaderInfoLog ( shader, infoLen, null, infoLog );
	         System.err.printf("Error compiling shader:\n%s\n", infoLog );
	      }
	
	      glDeleteShader ( shader );
	      return 0;
	   }
	
	   return shader;
	
	}

	///
	// Initialize the shader and program object
	//
	boolean Init ( )
	{
	   String vShaderStr =
	      "attribute vec4 vPosition;    \n" +
	      "void main()                  \n" +
	      "{                            \n" +
	      "   gl_Position = vPosition;  \n" +
	      "}                            \n";
	   
	   String fShaderStr =
	      "precision mediump float;                     \n" +
	      "void main()                                  \n" +
	      "{                                            \n" +
	      "  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n" +
	      "}                                            \n";
	
	   // Load the vertex/fragment shaders
	   int vertexShader = LoadShader ( GL_VERTEX_SHADER, vShaderStr );
	   int fragmentShader = LoadShader ( GL_FRAGMENT_SHADER, fShaderStr );
	
	   // Create the program object
	   int programObject = glCreateProgram ( );
	   
	   if ( programObject == 0 )
	      return false;
	
	   glAttachShader ( programObject, vertexShader );
	   glAttachShader ( programObject, fragmentShader );
	
	   // Bind vPosition to attribute 0   
	   glBindAttribLocation ( programObject, 0, "vPosition" );
	
	   // Link the program
	   glLinkProgram ( programObject );
	
	   // Check the link status
	   Boolean linked;
	
	   glGetProgramiv ( programObject, GL_LINK_STATUS, linked );
	
	   if ( !linked ) 
	   {
	      int infoLen = 0;
	
	      glGetProgramiv ( programObject, GL_INFO_LOG_LENGTH, &infoLen );
	      
	      if ( infoLen > 1 )
	      {
	         String infoLog;
	
	         glGetProgramInfoLog ( programObject, infoLen, NULL, infoLog );
	         System.err.printf("Error linking program:\n%s\n", infoLog );
	      }
	
	      glDeleteProgram ( programObject );
	      return false;
	   }
	
	   // Store the program object
	   userData.programObject = programObject;
	
	   glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );
	   return true;
	}

	///
	// Draw a triangle using the shader pair created in Init()
	//
	void Draw() {
		float vVertices[] = { 0.0f, 0.5f, 0.0f, -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f };

		// Set the viewport
		glViewport(0, 0, width, height);

		// Clear the color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		// Use the program object
		glUseProgram(userData.programObject);

		// Load the vertex data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
		glEnableVertexAttribArray(0);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glutSwapBuffers();
	}

	public static void main(String[] args) {
		glutInit();
		glutInitContextVersion(2, 0);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowSize(width, height);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Hello Triangle");

		if (!Init())
			return 0;

		glutDisplayFunc(Draw);
		glutMainLoop();
	}
}