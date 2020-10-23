// Template1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "include\GL\GL.H"
#include "include\GL\GLU.H"
#include "include\GL\glut.h"

//clors//
//glColor4f(1.0f, 0.0f, 0.0f, 1.0f);//Red;
//glColor4f(0.0f, 1.0f, 0.0f, 1.0f);//Green
//glColor4f(0.0f, 0.0f, 1.0f, 1.0f);//Blue;
//glColor4f(1.0f, 0.5f, 0.0f, 1.0f);//Orange
//glColor4f(1.0f, 0.0f, 1.0f, 1.0f);//Magenta
//glColor4f(1.0f, 1.0f, 0.0f, 1.0f);//Yellow
double angle = 0;
double transition = 0;
void DrawTriangle(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	glBegin(GL_POLYGON);// OpenGLa state
	glColor4f(red, green, blue, alpha);//blue
	glVertex2f(0.0f, 100.0f);
	glColor4f(red, green, blue, alpha);//blue
	glVertex2f(0.0f, 0.0f);
	glColor4f(red, green, blue, alpha);//blue
	glVertex2f(100.0f, 0.0f);
	glEnd();

}
void innerRing(void) {
	glPushMatrix();
	glRotated(angle, 0, 0, 1);
	DrawTriangle(0.0f, 0.0f, 1.0f, 1.0f);
	glPopMatrix();

}

void middleRing(void) {
	glPushMatrix();
	glRotated(-angle, 0, 0, 1);
	glTranslated(100, 0, 0);
	DrawTriangle(0.0f, 1.0f, 0.0f, 1.0f);
	glTranslated(-100, 100, 0);
	DrawTriangle(1.0f, 0.0f, 0.0f, 1.0f);
	glPopMatrix();
}

void outerRing(void) {
	glPushMatrix();
	glRotated(angle, 0, 0, 1);
	glTranslated(200, 0, 0);
	DrawTriangle(1.0f, 0.5f, 0.0f, 1.0f);
	glTranslated(-100, 100, 0);
	DrawTriangle(1.0f, 0.0f, 1.0f, 1.0f);
	glTranslated(-100, 100, 0);
	DrawTriangle(1.0f, 1.0f, 0.0f, 1.0f);
	glPopMatrix();
}



void DrawQuarter(void) {
	/*glTranslated(0, 0, 0);
	DrawTriangle(0.0f, 0.0f, 1.0f, 1.0f);
	glTranslated(0, 100, 0);
	DrawTriangle(0.0f, 1.0f, 0.0f, 1.0f);
	glTranslated(0, 100, 0);
	DrawTriangle(1.0f, 0.0f, 0.0f, 1.0f);
	glTranslated(100, -100, 0);
	DrawTriangle(1.0f, 1.0f, 0.0f, 1.0f);
	glTranslated(0, -100, 0);
	DrawTriangle(1.0f, 0.5f, 0.0f, 1.0f);
	glTranslated(100, 0, 0);
	DrawTriangle(1.0f, 0.0f, 1.0f, 1.0f);
	*/

	innerRing();
	middleRing();
	outerRing();

}

void Timer(int) {
	angle += 10;
	transition += 10;
	glutPostRedisplay();
	//glutTimerFunc(1000, timer, 0);
}

void QuarterMovment(void) {
	glRotated(angle, 0, 0, 1);
	DrawQuarter();
}





void MyDisplay(void) {
	// The new scene
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glTranslated(0, 0, 0);

	
	
	for (int i = 0; i < 4; i++) {
		glRotated(90, 0, 0, 1);
		glPushMatrix();
		//glRotated(i * 90, 0, 0, 100);
		
		//glPopMatrix();
		DrawQuarter();
		//glLoadIdentity();
		//glPushMatrix();
	}




		// The end of scene
	glFlush();//start processing buffered OpenGL routines
	glutTimerFunc(500, Timer, 0);
}


void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);//select clearing (background) color
									 /* initialize viewing values */
	glViewport(0, 0, 400, 400);//window origin and size
	glMatrixMode(GL_PROJECTION);//
	glLoadIdentity();//=1
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//=1
}




int main(int argc, char** argv) { //<- for normal API
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//single buffer and RGBA
	glutInitWindowSize(600, 600);//initial window size
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Triangles");//create widnow, hello title bar
	MyInit();
	glutDisplayFunc(MyDisplay);

	glutMainLoop();//enter main loop and process events
	return 0;
}