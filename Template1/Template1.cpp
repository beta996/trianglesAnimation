// Template1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "include\GL\GL.H"
#include "include\GL\GLU.H"
#include "include\GL\glut.h"
#define LENGTH_OF_TRIANGLE 90.0f
#define STEP 2


double spread = 10;
double spreadStep = 2;
const double limit = 30.00;
double angle = 0;

void CenterOfMassRotation() {
	glTranslated(LENGTH_OF_TRIANGLE / 3, LENGTH_OF_TRIANGLE / 3, 0);
	glRotated(angle, 0, 0, 1);
	glTranslated(-LENGTH_OF_TRIANGLE / 3, -LENGTH_OF_TRIANGLE / 3, 0);
}


void DrawTriangle(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	glBegin(GL_POLYGON);
	glColor4f(red, green, blue, alpha);
	glVertex2f(0.0f, 100.0f);
	glColor4f(red, green, blue, alpha);
	glVertex2f(0.0f, 0.0f);
	glColor4f(red, green, blue, alpha);
	glVertex2f(100.0f, 0.0f);
	glEnd();

}

void spreadingOut(float x, float y) {
	//glTranslated(spread * x, spread * y, 0);
}

void drawPatternQuarter(void) {

	//blue
	glPushMatrix();
	glTranslated(0, 0, 0);
	CenterOfMassRotation();
	spreadingOut(1.0, 1.0);
	DrawTriangle(0.0f, 0.0f, 1.0f, 1.0f);
	glPopMatrix();
	glTranslated(0, 100, 0);

	//green
	glPushMatrix();
	CenterOfMassRotation();
	spreadingOut(1.0, 4.0);
	DrawTriangle(0.0f, 1.0f, 0.0f, 1.0f);
	glPopMatrix();
	glTranslated(0, 100, 0);

	//red
	glPushMatrix();
	CenterOfMassRotation();
	spreadingOut(1.0, 7.0);
	DrawTriangle(1.0f, 0.0f, 0.0f, 1.0f);
	glPopMatrix();
	glTranslated(100, -100, 0);

	//yellow
	glPushMatrix();
	CenterOfMassRotation();
	spreadingOut(4.0, 4.0);
	DrawTriangle(1.0f, 1.0f, 0.0f, 1.0f);
	glPopMatrix();
	glTranslated(0, -100, 0);
	//orange
	glPushMatrix();
	CenterOfMassRotation();
	spreadingOut(4.0, 1.0);
	DrawTriangle(1.0f, 0.5f, 0.0f, 1.0f);
	glPopMatrix();

	glTranslated(100, 0, 0);
	glPushMatrix();
	CenterOfMassRotation();
	spreadingOut(7.0, 1.0);
	DrawTriangle(1.0f, 0.0f, 1.0f, 1.0f);
	glPopMatrix();
	
}


void Timer(int) {
	angle += 6;
	if (spread >= limit || spread <= 0)
	{
		spreadStep *= -1;
	}
	spread += spreadStep;
	glutPostRedisplay();
}


void patternRotation(void) {
	//hglRotated(angle, 0, 0, 1);
	drawPatternQuarter();
}


void MyDisplay(void) {
	
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glTranslated(0, 0, 0);

	for (int i = 0; i < 4; i++) {

		glRotated(i * 90, 0, 0, 100);
		patternRotation();
		glLoadIdentity();

	}

	glFlush();
	glutTimerFunc(80, Timer, 0);
}


void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
									 
	glViewport(0, 0, 400, 400);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Triangle");
	MyInit();
	glutDisplayFunc(MyDisplay);

	glutMainLoop();
	return 0;
}