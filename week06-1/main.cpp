#include <GL/glut.h>
float angle=0;

void hand()
{
    glPushMatrix();
        glScalef(0.5,0.2,0.2);///變形
        glColor3f(0,0,1);///顏色
        glutSolidCube(1);///畫矩形
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(0.25,0.25,0);///將正在旋轉的藍色方塊移動
        glRotatef(angle,0,0,1);///旋轉(角度,x,y,z)
        glTranslatef(0.2,0,0);///移動轉軸
        hand();
        glPushMatrix();
            glTranslatef(0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.2,0,0);
        hand();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.25,0.25,0);///將正在旋轉的藍色方塊移動
        glRotatef(-angle,0,0,1);///旋轉(角度,x,y,z)
        glTranslatef(-0.2,0,0);///移動轉軸
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
    glutInit(&argc, argv);///Init初始化GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("07160325 小乖的畫");
    glutDisplayFunc(display);
    glutIdleFunc(display);///一直重新刷新螢幕
    glutMainLoop();
}
