#include <opencv/highgui.h> ///for cvLoadImage()
#include <opencv/cv.h> ///for cvCvtColor()
#include <GL/glut.h> ///3D glut
#include <stdio.h>
float angle=0; ///自動轉很帥
GLUquadric * quad;
void display()
{   glEnable(GL_DEPTH_TEST); ///要啟動 Detph Test 深度值的測試,3D顯示才正確
    glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///自動轉很帥
        glRotatef(90, 1,0,0);
        glRotatef(angle, 0,0,1);///自動轉很帥
        gluQuadricTexture(quad, 1);
        gluSphere(quad, 0.5, 30, 30);///glutSolidTeapot(0.3);
    glPopMatrix();///自動轉很帥
    glFlush();
    angle+=1;///自動轉很帥
}
void myInit()
{
    quad = gluNewQuadric();
    IplImage * img = cvLoadImage("earth.jpg"); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
}   ///最後一行最難/最重要, 所貼圖影像的資料都設定好
void timer(int t)
{/// 1000 msec   50fps:20msec
    glutTimerFunc(20, timer, 0);
    //printf("timer now\n");
    glutPostRedisplay();
}
int main(int argc, char**argv)
{   glutInit(&argc, argv);
    glutCreateWindow("3D");
    glutDisplayFunc(display); ///顯示
    //glutIdleFunc(display);///自動轉很帥 (閒閒沒事幹, 就重畫)
    glutTimerFunc(0, timer, 0);

    myInit(); ///我的 init 初始化 把貼圖準備好 前面OpenCV 2行, 後面 OpenGL 9行
    glutMainLoop();
}
