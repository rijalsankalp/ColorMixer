#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>
void display();
void reshape(int, int);
void motion(int, int);
void timer(int);
void keyboard(unsigned char, int, int);

float red = -175, green = -175, blue = -175;
float theta, val;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Color Function");

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMotionFunc(motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutMainLoop();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(4.0);

    glTranslated(0, 100, 0);

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);



    glVertex2f(0, 0);
    for(float i = 0; i <= 360; i += 0.05)
    {
        theta = i*3.142/180;
        glVertex2f(105*cos(theta), 105*sin(theta));
    }
    glEnd();



    glBegin(GL_POLYGON);
    glColor3f((red + 75)/100 + 1, (green + 75)/100 + 1, (blue + 75)/100 + 1);

    for(float i = 0; i <= 360; i++)
    {
        theta = i*3.142/180;
        glVertex2f(100*cos(theta), 100*sin(theta));
    }
    glEnd();
    glLoadIdentity();


    //RED
    glColor3f(1, 1, 1);
    glPointSize(4.0);
    glBegin(GL_LINES);
    glVertex2f(-100, -175);
    glVertex2f(-100, -75);
    glEnd();

    glLoadIdentity();
    glColor3f(1, 0, 0);
    glPointSize(20);
    glBegin(GL_POINTS);
    glVertex2f(-100,red);
    glEnd();
    glLoadIdentity();

    //GREEN
    glColor3f(1, 1, 1);
    glPointSize(4.0);
    glBegin(GL_LINES);
    glVertex2f(0, -175);
    glVertex2f(0, -75);
    glEnd();

    glLoadIdentity();
    glColor3f(0, 1, 0);
    glPointSize(20);
    glBegin(GL_POINTS);
    glVertex2f(0, green);
    glEnd();
    glLoadIdentity();

    //BLUE
    glColor3f(1, 1, 1);
    glPointSize(4.0);
    glBegin(GL_LINES);
    glVertex2f(100, -175);
    glVertex2f(100, -75);
    glEnd();

    glLoadIdentity();
    glColor3f(0, 0, 1);
    glPointSize(20);
    glBegin(GL_POINTS);
    glVertex2f(100, blue);
    glEnd();
    glLoadIdentity();


    glutSwapBuffers();
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-250, 250, -250, 250);
    glMatrixMode(GL_MODELVIEW);
}

void motion(int x, int y)
{
    //std::cout<<x<<" "<<y<<std::endl;
    if(y>425)
        y = 425;
    else if(y<325)
        y =325;

    val = 250 -y;
    //val = (-7 * (250 - y)) / (250 -425);
    if(140 <= x && x<= 160)
    {
        //std::cout<<"Red"<<std::endl;

        red = val;
    }

    else if(240 <= x && x <= 260)
    {
        //std::cout<<"Green"<<std::endl;
        green = val;

    }
    else if(340 <= x && x <= 360)
    {
        blue = val;
    }
}


void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'Q' || key == 'q')
        exit(0);
}
