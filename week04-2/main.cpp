#include <GL/glut.h>///使用GLUT外掛
#include <stdio.h>
int n=0,vx[3000],vy[3000];

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景

    glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++)///用for畫出來
    {
        glVertex2f((vx[i]-150)/150.0,-(vy[i]-150)/150.0);///座標換算
    }
    glEnd();

    glutSwapBuffers();///更新畫面
}

void motion(int x,int y)
{
    vx[n]=x;///將滑鼠x值存起來
    vy[n]=y;///將滑鼠值存起來
    n++;
    display();///每次移動滑鼠都會呼叫display
}

int main(int argc, char *argv[])///main()函式
{
    glutInit(&argc, argv);///Init初始化GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///Init初始化Display功能
    glutCreateWindow("07160325 小乖的畫");///建立自訂名稱的GLUT視窗
    glutDisplayFunc(display);///準備display()函式
    glutMotionFunc(motion);///新增的motion函式
    glutMainLoop();///主要函式
}
