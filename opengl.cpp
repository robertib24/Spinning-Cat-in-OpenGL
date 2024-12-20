﻿#include <GL/glut.h>

int prevX = 0;
int spinAngle = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotatef(spinAngle, 0.0f, 1.0f, 0.0f);

    // calculeaza culoarea in functie de unghiul de rotatie
    float red = (spinAngle % 360) / 360.0f;
    float green = ((spinAngle + 120) % 360) / 360.0f;
    float blue = ((spinAngle + 240) % 360) / 360.0f;

    // Corp
    glColor3f(red, green, blue);
    glutSolidSphere(0.5, 50, 50);

    // Cap
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f);
    glColor3f(blue, red, green);
    glutSolidSphere(0.3, 50, 50);
    glPopMatrix();

    // Urechi
    glPushMatrix();
    glTranslatef(0.15f, 0.85f, 0.25f);
    glRotatef(-45.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(green, blue, red);
    glutSolidCone(0.1, 0.3, 50, 50);
    glTranslatef(-0.3f, 0.0f, 0.0f);
    glutSolidCone(0.1, 0.3, 50, 50);
    glPopMatrix();

    // Ochi
    glPushMatrix();
    glColor3f(red, green, blue);
    glTranslatef(0.1f, 0.55f, 0.3f);
    glutSolidSphere(0.05, 50, 50);
    glTranslatef(-0.2f, 0.0f, 0.0f);
    glutSolidSphere(0.05, 50, 50);
    glPopMatrix();

    // Nas
    glColor3f(green, blue, red);
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.3f);
    glutSolidCone(0.05, 0.2, 50, 50);
    glPopMatrix();

    glPopMatrix();

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        prevX = x;
    }
}

void motion(int x, int y)
{
    int deltaX = x - prevX;
    spinAngle += deltaX;
    prevX = x;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("pisik");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5f, 0.8f, 0.9f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // centreaza pisica
    glTranslatef(0.0f, -0.3f, 0.0f);

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

    return 0;
}
