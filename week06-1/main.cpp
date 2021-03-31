#include <GL/glut.h>
float angle=0;

void hand()
{
    glPushMatrix();
        glScalef(0.5,0.2,0.2);///�ܧ�
        glColor3f(0,0,1);///�C��
        glutSolidCube(1);///�e�x��
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(0.25,0.25,0);///�N���b���઺�Ŧ�������
        glRotatef(angle,0,0,1);///����(����,x,y,z)
        glTranslatef(0.2,0,0);///������b
        hand();
        glPushMatrix();
            glTranslatef(0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.2,0,0);
        hand();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.25,0.25,0);///�N���b���઺�Ŧ�������
        glRotatef(-angle,0,0,1);///����(����,x,y,z)
        glTranslatef(-0.2,0,0);///������b
        hand();
        glPushMatrix();
            glTranslatef(-0.25,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.2,0,0);
        hand();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///Init��l��GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("07160325 �p�Ī��e");
    glutDisplayFunc(display);
    glutIdleFunc(display);///�@�����s��s�ù�
    glutMainLoop();
}
