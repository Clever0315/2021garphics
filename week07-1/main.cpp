#include <opencv/highgui.h>
int main(int argc,char** argv)
{
    IplImage*img=cvLoadImage("fight.jpg");
    cvShowImage("fight photo",img);
    cvWaitKey(0);
}
