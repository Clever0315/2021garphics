#include <opencv/highgui.h> ///for cvLoadImage()
#include <opencv/cv.h> ///for cvCvtColor()
#include <GL/glut.h> ///3D glut
#include <stdio.h>
float angle=0; ///�۰���ܫ�
GLUquadric * quad;
void display()
{   glEnable(GL_DEPTH_TEST); ///�n�Ұ� Detph Test �`�׭Ȫ�����,3D��ܤ~���T
    glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�۰���ܫ�
        glRotatef(90, 1,0,0);
        glRotatef(angle, 0,0,1);///�۰���ܫ�
        gluQuadricTexture(quad, 1);
        gluSphere(quad, 0.5, 30, 30);///glutSolidTeapot(0.3);
    glPopMatrix();///�۰���ܫ�
    glFlush();
    angle+=1;///�۰���ܫ�
}
void myInit()
{
    quad = gluNewQuadric();
    IplImage * img = cvLoadImage("earth.jpg"); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
}   ///�̫�@�����/�̭��n, �ҶK�ϼv������Ƴ��]�w�n
void timer(int t)
{/// 1000 msec   50fps:20msec
    glutTimerFunc(20, timer, 0);
    //printf("timer now\n");
    glutPostRedisplay();
}
int main(int argc, char**argv)
{   glutInit(&argc, argv);
    glutCreateWindow("3D");
    glutDisplayFunc(display); ///���
    //glutIdleFunc(display);///�۰���ܫ� (�����S�ƷF, �N���e)
    glutTimerFunc(0, timer, 0);

    myInit(); ///�ڪ� init ��l�� ��K�ϷǳƦn �e��OpenCV 2��, �᭱ OpenGL 9��
    glutMainLoop();
}
