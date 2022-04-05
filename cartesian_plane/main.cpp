#include "GL/freeglut.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

constexpr int FLOAT_MIN = 0;
constexpr int FLOAT_MAX = 1;

//Initialize OpenGL 
void init(void)
{
	// color de la ventana, negro
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//  proyección de la imagen en la ventana devisualización
}

void drawSquare() {
	//borramos la pantalla
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// forzar el dibujo
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();

	glFlush();
}

void drawLines(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.4, 0.2);
	glPointSize(3.0);

	glBegin(GL_LINE_STRIP);
	// vertical axis
	glVertex2d(0, 500);
	glVertex2d(0, -500);
	// horizontal axis
	glVertex2d(-500, 0);
	glVertex2d(500, 0);
	glEnd();
	glFlush();
}

void drawCartesianPlane(void)
{
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);
	float x = -1.0, y = 1.0, z = 0.0;
	
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	
	glPointSize(1.0);

	glBegin(GL_POINTS);
	for (float i = -1.0; i < 1.0; i += 0.01) {
		glBegin(GL_POINTS);
		glColor3f(x, y, z);
		glVertex2d(x, 0);
		glVertex2d(0, y);
		x += 0.02f;
		y -= 0.02f;
		z += 0.02f;
	}
	glEnd();
	
	glFlush();
}

int main(int argc, char** argv)
{
	srand(GetTickCount());
	glutInit(&argc, argv); //inicializa la libreria de glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);//selecciona el RGB y single buffering
	glutInitWindowSize(512, 512);//fija el tamanho de la ventana
	glutInitWindowPosition(400, 150);//fija la posicion de la ventana
	glutCreateWindow("cartesian plane");//crea la ventana con el nombre							
	//Llamar a la funcion init
	init();
	//declara los callbacks
	glutDisplayFunc(drawCartesianPlane);
	//entra en el loop de reconocimientos de eventos
	glutMainLoop();
	return 0;
}
