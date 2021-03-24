#include <GL/glut.h>///使用GLUT外掛
#include <stdio.h>

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景
    glutSwapBuffers();///更新畫面
}

void mouse(int button,int state,int x,int y)///(左中右鍵,上下,x座標)
{
    printf("button:%d state%d x:%d y:%d\n",button,state,x,y );///觀察印出來的值
}

int main(int argc, char *argv[])///main()函式
{
    glutInit(&argc, argv);///Init初始化GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///Init初始化Display功能
    glutCreateWindow("07160325 小乖的滑鼠座標");///建立自訂名稱的GLUT視窗
    glutDisplayFunc(display);///準備display()函式
    glutMouseFunc(mouse);///新增的mouse函式
    glutMainLoop();///主要函式
}
