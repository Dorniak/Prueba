#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>

void init();
void display(void);
void keyboard(unsigned char, int , int );
void centerOnScreen();
void drawObject();
void trabajo();

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = 480;
int window_height = 480;

//  variable representing the window title
char *window_title = "Sample OpenGL FreeGlut App";

//-------------------------------------------------------------------------
//  Program Main method.
//-------------------------------------------------------------------------
void main(int argc, char **argv)
{
	//  Connect to the windowing system + create a window
	//  with the specified dimensions and position
	//  + set the display mode + specify the window title.
	glutInit(&argc, argv);
	trabajo();
	//  Start GLUT event processing loop
	glutMainLoop();
}
void trabajo()
{
	centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(window_title);

	//  Set OpenGL program initial state.
	init();

	// Set the callback functions
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
}
//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init()
{
	//  Set the frame buffer clear color to black. 
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//  OpenGL contents on the window.
//-------------------------------------------------------------------------
void display(void)
{
	//  Clear the window or more specifically the frame buffer...
	//  This happens by replacing all the contents of the frame
	//  buffer by the clear color (black in our case)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//  Draw object
	drawObject();

	//  Swap contents of backward and forward frame buffers
	glutSwapBuffers();
}

//-------------------------------------------------------------------------
//  Draws our object.
//-------------------------------------------------------------------------
void drawObject()
{
	//  Draw Icosahedron
	//glutWireIcosahedron();
	//glutWireRhombicDodecahedron();
	//glutWireOctahedron();
	glPointSize(2);
	glBegin(GL_POINTS);
	GLfloat x = 0.1;
	GLfloat y = 1;
	for (double i=-1.0; i < y; i=(i + x)) {
		for (double j = -1.0; j < y; j = (j + x)) {
			for (double k = -1.0; k < y; k = (k + x)) {
				glVertex3d(i, j, k);
			}
			}

	}
	glEnd();
}

//-------------------------------------------------------------------------
//  This function sets the window x and y coordinates
//  such that the window becomes centered
//-------------------------------------------------------------------------
void centerOnScreen()
{
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'h':
		printf("help\n\n");
		printf("c - Toggle culling\n");
		printf("q/escape - Quit\n\n");
		break;
	case 'c':
		if (glIsEnabled(GL_CULL_FACE))
			glDisable(GL_CULL_FACE);
		else
			glEnable(GL_CULL_FACE);
		break;
	case '1':
		glRotatef(1.0, 1., 0., 0.);
		break;
	case '3':
		glRotatef(1.0, 0., 1., 0.);
		break;
	case '5':
		glRotatef(1.0, 0., 0., 1.);
		break;
	case '2':
		glRotatef(1.0, -1., 0., 0.);
		break;
	case '4':
		glRotatef(1.0, 0., -1., 0.);
		break;
	case '6':
		glRotatef(1.0, 0., 0., -1.);
		break;
	case '7':
		glScalef(0.5,0.5,0.5);
		break;
	case '8':
		glScalef(2, 2, 2);
		break;
	case '9':
		exit(0);
		break;
	}
	glutPostRedisplay();
}