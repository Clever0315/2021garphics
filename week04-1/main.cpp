#include <GL/glut.h>///�ϥ�GLUT�~��
#include <stdio.h>

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��
    glutSwapBuffers();///��s�e��
}

void mouse(int button,int state,int x,int y)///(�����k��,�W�U,x�y��)
{
    printf("button:%d state%d x:%d y:%d\n",button,state,x,y );///�[��L�X�Ӫ���
}

int main(int argc, char *argv[])///main()�禡
{
    glutInit(&argc, argv);///Init��l��GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///Init��l��Display�\��
    glutCreateWindow("07160325 �p�Ī��ƹ��y��");///�إߦۭq�W�٪�GLUT����
    glutDisplayFunc(display);///�ǳ�display()�禡
    glutMouseFunc(mouse);///�s�W��mouse�禡
    glutMainLoop();///�D�n�禡
}
