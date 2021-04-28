/*#include <windows.h>
#include <stdio.h>
int main()
{
    PlaySound("2020-12-1-14-59-3-165-nf1.wav",NULL,SND_SYNC);
}*/

/*#include <windows.h>
#include <stdio.h>
int main()
{
    PlaySound("do.wav",NULL,SND_ASYNC);
    PlaySound("re.wav",NULL,SND_ASYNC);
    PlaySound("mi.wav",NULL,SND_ASYNC);
    PlaySound("fa.wav",NULL,SND_ASYNC);
    PlaySound("so.wav",NULL,SND_ASYNC);
}*/

/*#include <windows.h>
#include <stdio.h>
int main()
{
    while(1){
        char c=getchar();
        if(c=='z')PlaySound("do.wav",NULL,SND_ASYNC);
        if(c=='x')PlaySound("re.wav",NULL,SND_ASYNC);
        if(c=='c')PlaySound("mi.wav",NULL,SND_ASYNC);
        if(c=='v')PlaySound("fa.wav",NULL,SND_ASYNC);
        if(c=='b')PlaySound("so.wav",NULL,SND_ASYNC);
    }
}*/

/*#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

void keyboard(unsigned char c,int x,int y)
{
    if(c=='z') PlaySound("do.wav",NULL,SND_ASYNC);
    if(c=='x') PlaySound("re.wav",NULL,SND_ASYNC);
    if(c=='c') PlaySound("mi.wav",NULL,SND_ASYNC);
    if(c=='v') PlaySound("fa.wav",NULL,SND_ASYNC);
    if(c=='b') PlaySound("so.wav",NULL,SND_ASYNC);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("小乖的鋼琴");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}*/

/*#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

void keyboard(unsigned char c,int x,int y)
{
    if(c=='z') PlaySound("do.wav",NULL,SND_ASYNC);
    if(c=='x') PlaySound("re.wav",NULL,SND_ASYNC);
    if(c=='c') PlaySound("mi.wav",NULL,SND_ASYNC);
    if(c=='v') PlaySound("fa.wav",NULL,SND_ASYNC);
    if(c=='b') PlaySound("so.wav",NULL,SND_ASYNC);
}

int main(int argc,char** argv)
{
    mp3.Load("music.mp3");
    mp3.Play();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("小乖的鋼琴");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}*/

/*#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

void keyboard(unsigned char c,int x,int y)
{
    if(c=='z') PlaySound("do.wav",NULL,SND_ASYNC);
    if(c=='x') PlaySound("re.wav",NULL,SND_ASYNC);
    if(c=='c') PlaySound("mi.wav",NULL,SND_ASYNC);
    if(c=='v') PlaySound("fa.wav",NULL,SND_ASYNC);
    if(c=='b') PlaySound("so.wav",NULL,SND_ASYNC);
}

void Mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN)PlaySound("shot.wav",NULL,SND_ASYNC);
}

int main(int argc,char** argv)
{
    mp3.Load("music.mp3");
    mp3.Play();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("小乖的鋼琴");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(Mouse);
    glutMainLoop();
}*/

#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;
CMP3_MCI shot1,shot2,shot3;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

void keyboard(unsigned char c,int x,int y)
{
    if(c=='z') PlaySound("do.wav",NULL,SND_ASYNC);
    if(c=='x') PlaySound("re.wav",NULL,SND_ASYNC);
    if(c=='c') PlaySound("mi.wav",NULL,SND_ASYNC);
    if(c=='v') PlaySound("fa.wav",NULL,SND_ASYNC);
    if(c=='b') PlaySound("so.wav",NULL,SND_ASYNC);
}

void Mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN&&button==GLUT_LEFT_BUTTON)shot1.Play();
    if(state==GLUT_DOWN&&button==GLUT_MIDDLE_BUTTON)shot2.Play();
    if(state==GLUT_DOWN&&button==GLUT_RIGHT_BUTTON)shot3.Play();
}

int main(int argc,char** argv)
{
    shot1.Load("1.mp3");shot2.Load("2.mp3");shot3.Load("3.mp3");
    mp3.Load("music.mp3");
    mp3.Play();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("小乖的鋼琴");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(Mouse);
    glutMainLoop();
}
