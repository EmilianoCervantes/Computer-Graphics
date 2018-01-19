/*
*
* TC3022. Computer Graphics Course.
* Brick Breaker template OpenGL project.
*
* Edited by Emiliano Cervantes
*/

#ifdef __APPLE__
// See: http://lnx.cx/docs/opengl-in-xcode/
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif
#include <stdio.h>
#include <math.h>

#define HEIGHT 5
#define WIDTH 6

float cellWidth = 0.3f;
float cellHeight = 0.1f;

int wall[HEIGHT][WIDTH];

void init() { // FOR GLUT LOOP
	glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
	glClearColor(0.15, 0.15, 0.15, 0.0);    // Clear the color state.
	glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
	glLoadIdentity();                    // Reset 3D view matrix.
	
	//Generate bricks
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			wall[row][col] = 1;
		}
	}
}

void drawSquare(float x, float y, float w, float h, float r, float g, float b) {
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	{
		glVertex3f(x, y, 0);
		glVertex3f(x+w, y, 0);
		glVertex3f(x+w, y+h, 0);
		glVertex3f(x, y+h, 0);
	}
	glEnd();
}

void display() {                            // Called for each frame (about 60 times per second).
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers.

	//bricks
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			if (wall[row][col] == 1)
			{
				drawSquare(col*cellWidth);
			}
		}
	}

	glutSwapBuffers();                                                // Swap the hidden and visible buffers.
}

void idle() {                                                            // Called when drawing is finished.
	glutPostRedisplay();                                            // Display again.
}

void reshape(int x, int y) {                                            // Called when the window geometry changes.
	glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
	glLoadIdentity();                                                // Reset the 2D matrix.
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);        // Configure the camera lens aperture.
	glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
	glLoadIdentity();                                                // Reset the 3D matrix.
	glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
	gluLookAt(0.0, 0.0, 35.0,                                        // Where the camera is.
		0.0, 0.0, 0.0,                                                // To where the camera points at.
		0.0, 1.0, 0.0);                                                // "UP" vector.
	display();
}

void keys(unsigned char k, int x, int y) {
	switch (k) {
	case '1':
		
		break;
	case '2':
		
		break;
	case '3':
		
		break;
	case '4':
		
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 800);
	glutCreateWindow("CG Brick Breaker");

	init();
	glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
	glutDisplayFunc(display);                                        // Display CALLBACK function.
	glutKeyboardFunc(keys);
	glutIdleFunc(idle);                                                // Idle CALLBACK function.
	glutMainLoop();                                                    // Begin graphics program.
	return 0;                                                        // ANSI C requires a return value.
}
