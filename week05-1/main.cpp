#include <GL/glut.h>///�ϥ�GLUT�~��
#include <stdio.h>
int n=0,vx[3000],vy[3000];
float angle=0;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��

    glPushMatrix();///�Ƥ��x�}
        glRotatef(angle,0,0,1);
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<n;i++)///��for�e�X��
        {
            glVertex2f((vx[i]-150)/150.0,-(vy[i]-150)/150.0);///�y�д���
        }
        glEnd();
    glPopMatrix();///�٭�x�}

    glutSwapBuffers();///��s�e��
}

void keyboard(unsigned char key,int x,int y)
{
    angle++;
    display();
}

void motion(int x,int y)
{
    vx[n]=x;///�N�ƹ�x�Ȧs�_��
    vy[n]=y;///�N�ƹ��Ȧs�_��
    n++;
    display();///�C�����ʷƹ����|�I�sdisplay
}

int main(int argc, char *argv[])///main()�禡
{
    glutInit(&argc, argv);///Init��l��GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///Init��l��Display�\��
    glutCreateWindow("07160325 �p�Ī��e");///�إߦۭq�W�٪�GLUT����
    glutDisplayFunc(display);///�ǳ�display()�禡
    glutKeyboardFunc(keyboard);///����L�I�skeyboard�禡
    glutMotionFunc(motion);///���ƹ��I�smotion�禡
    glutMainLoop();///�D�n�禡
}
