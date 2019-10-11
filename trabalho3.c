/*  
Tarefa 3
Grupo 1
Alunos:
Alan
Jônatas
Vinícius
*/

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int x;
	int y;
}Ponto;

int window;

double color[3] = {1.0, 0.0, 0.0};

/*********** Protótipos ***********/

void drawCircle(Ponto pC, int r);
void setup();
void display();

/********************************/

int main(int argc, char *argv[]){

   	glutInit(&argc, argv);
   	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800,600);
   	window = glutCreateWindow("Círculo");
	glutDisplayFunc(display);
	setup();
   	glutMainLoop();

   	return 0;
}

/*********** Funções ***********/

void drawCircle(Ponto pC, int r){
	
	int x = r, y = 0, k = 0;
	
	while(x >= y)
	{
	
		glPointSize(3);
		glColor3d(color[0], color[1], color[2]);
		glBegin(GL_POINTS);
			glVertex2i(pC.x + x, pC.y + y);	
			glVertex2i(pC.x + y, pC.y + x);
			glVertex2i(pC.x - y, pC.y + x);
			glVertex2i(pC.x - x, pC.y + y);
			glVertex2i(pC.x - x, pC.y - y);
			glVertex2i(pC.x - y, pC.y - x);
			glVertex2i(pC.x + y, pC.y - x);
			glVertex2i(pC.x + x, pC.y - y);
		glEnd();
		
		if(k <= 0)
		{
			y++;	
			k += (2 * y) + 1;
		}
		
		if(k > 0)
		{	
			x--;
			k -= (2 * x) + 1;
		}	

	}
}

void setup() 
{
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
   gluOrtho2D(0, 800, 0, 600);
}

void display()
{
   		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Ponto p;
		p.x = 400;
		p.y = 300;

		drawCircle(p, 60);

   glutSwapBuffers();
}



