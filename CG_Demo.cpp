/*
 * Sergio Ruiz.
 *
 * TC3022. Computer Graphics Course.
 * Basic template OpenGL project.
 * Editado por Emiliano y Alison
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

int shape;

void init() // FOR GLUT LOOP
{
	glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
	glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
	glLoadIdentity();					// Reset 3D view matrix.
	shape = 7;
}

void display()							// Called for each frame (about 60 times per second).
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.

	glColor3f(1.0f, 1.0f, 0.0f);									// Yellow
	//glutWireTeapot(1);
	//glutWireSphere(1, 20, 20);
	glLineWidth(5);

	//glBegin(GL_POINTS);//Nunca dejarla vacía
	/*glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1);
	glEnd();*/

	/*if (shape == 0) {
		glBegin(GL_TRIANGLES);
		//Línea roja, línea verde
		glColor3f(1, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glEnd();
	}
	else if(shape == 1) {
		glBegin(GL_TRIANGLES);
		//Línea verde, línea azul
		glColor3f(0, 1, 1);
		//glVertex3f(x,y,z);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(0, 0, 1);
		glEnd();
	}
	else {
		//Línea azul, línea roja
		glBegin(GL_TRIANGLES);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);
		glVertex3f(1, 0, 0);
		glEnd();
	}*/

	//JAPON
	if (shape == 1)
	{
		//Rectangulo
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glVertex3f(7.5, 5, 0);
		glVertex3f(-7.5, 5, 0);
		glVertex3f(-7.5, -5, 0);
		glVertex3f(7.5, -5, 0);
		glEnd();

		//Circulo
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		for (int i = 0; i < 360; i++) {
			float radian = i * (3.1415f / 180.0f);

			float xcos = cos(radian) * 3;
			float ysin = sin(radian) * 3;

			//glTexCoord2f(tx, ty);
			glVertex3f(xcos, ysin, 1);
		}
		glEnd();
	}
	else if (shape == 2)
	{
		//Alemania
		//Rectangulo 1 - negro
		glBegin(GL_POLYGON);
		glColor3f(0.05, 0.05, 0.05);
		glVertex3f(7.5, 4.5, 0);
		glVertex3f(-7.5, 4.5, 0);
		glVertex3f(-7.5, 1.5, 0);
		glVertex3f(7.5, 1.5, 0);
		//glEnd();

		//Rectangulo 2 - rojo
		//glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex3f(7.5, 1.5, 0);
		glVertex3f(-7.5, 1.5, 0);
		glVertex3f(-7.5, -1.5, 0);
		glVertex3f(7.5, -1.5, 0);
		//glEnd();

		//Rectangulo 3 - amarillo
		//glBegin(GL_POLYGON);
		glColor3f(1, 1, 0);
		glVertex3f(7.5, -1.5, 0);
		glVertex3f(-7.5, -1.5, 0);
		glVertex3f(-7.5, -4.5, 0);
		glVertex3f(7.5, -4.5, 0);
		glEnd();
	}
	else if (true)
	{
		//Jamaica
		//Fondo amarillo
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 0);
		glVertex3f(8, 5, 0);
		glVertex3f(-8, 5, 0);
		glVertex3f(-8, -5, 0);
		glVertex3f(8, -5, 0);
		glEnd();

		//Tríangulos verdes
		glBegin(GL_TRIANGLES);
		glColor3f(0, 0.6, 0.3);
		glVertex3f(7, 5, 0.001);
		glVertex3f(-7, 5, 0.001);
		glVertex3f(0, 0.5, 0.001);
		//glEnd();

		glColor3f(0, 0.6, 0.3);
		glVertex3f(7, -5, 0.001);
		glVertex3f(-7, -5, 0.001);
		glVertex3f(0, -0.5, 0.001);
		//glEnd();

		//Tríangulos negros
		glBegin(GL_TRIANGLES);
		glColor3f(0.05, 0.05, 0.05);
		glVertex3f(8, 4, 0.001);
		glVertex3f(8, -4, 0.001);
		glVertex3f(1.5, 0, 0.001);
		//glEnd();

		glColor3f(0.05, 0.05, 0.05);
		glVertex3f(-8, 4, 0.001);
		glVertex3f(-8, -4, 0.001);
		glVertex3f(-1.5, 0, 0.001);
		glEnd();
	}


	//This is the last line you should have.
	glutSwapBuffers();												// Swap the hidden and visible buffers.
}

void idle()															// Called when drawing is finished.
{
	glutPostRedisplay();											// Display again.
}

void reshape(int x, int y)											// Called when the window geometry changes.
{
	glMatrixMode(GL_PROJECTION);									// Go to 2D mode.
	glLoadIdentity();												// Reset the 2D matrix.
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);		// Configure the camera lens aperture.
	glMatrixMode(GL_MODELVIEW);										// Go to 3D mode.
	glLoadIdentity();												// Reset the 3D matrix.
	glViewport(0, 0, x, y);											// Configure the camera frame dimensions.
	gluLookAt(0, 0, 40.0,										// Where the camera is.
		0.0, 0.0, 0.0,												// To where the camera points at.
		0.0, 1.0, 0.0);												// "UP" vector.
	display();
}

void keys(unsigned char k, int x, int y)
{
	switch (k)
	{
	case '1':
		shape = 1;
		break;
	case '2':
		shape = 2;
		break;
	case '3':
		shape = 3;
		break;
	case '4':
		shape = 4;
		break;
	case '5':
		shape = 5;
		break;
	case '6':
		shape = 6;
		break;
	case '7':
		shape = 7;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);											// Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 800);
	glutCreateWindow("CG DEMO");
	
	init();
	glutReshapeFunc(reshape);										// Reshape CALLBACK function.
	glutDisplayFunc(display);										// Display CALLBACK function.
	glutKeyboardFunc(keys); //Register keyboard callback funtion "keys"
	glutIdleFunc(idle);												// Idle CALLBACK function.
	glutMainLoop();													// Begin graphics program.
	return 0;														// ANSI C requires a return value.
}
