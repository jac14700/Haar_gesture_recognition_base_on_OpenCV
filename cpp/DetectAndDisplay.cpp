#include"../header/header.h"
using namespace std;
using namespace cv;
bool paper=false,scissor=false,stone=false;
Mat subframe1,subframe2,subframe3;
char name1[130],name2[130],name3[130];
int a=1,b=1,m=1,result=0;
void detectAndDisplay( Mat frame,
                       Mat sobel,
                       Mat grad_x,
                       Mat grad_y,
                       Mat abs_grad_x,Mat abs_grad_y,
                       CascadeClassifier hand_cascade1,CascadeClassifier hand_cascade2,CascadeClassifier hand_cascade3)
{

    std::vector<Rect> hands1;
    std::vector<Rect> hands2;
    std::vector<Rect> hands3;

    sobel= sobel1( frame, sobel, grad_x, grad_y, abs_grad_x, abs_grad_y);
    hand_cascade1.detectMultiScale( sobel, hands1,1.01,5, 0, Size(100,100),Size(250,625) );
    /*hand_cascade2.detectMultiScale( sobel, hands2, 1.1,5, 0, Size(147,91),Size(252,156)  );
    hand_cascade3.detectMultiScale( sobel, hands3, 1.1,3, 0, Size(119,98), Size(204,168) );
    */for( int i = 0; i < hands1.size(); i++ )
    {

        Point center( hands1[i].x + hands1[i].width*0.5, hands1[i].y + hands1[i].height*0.5 );
        rectangle(frame, Point(center.x-hands1[i].width*0.5,center.y-hands1[i].height*0.5), Point(center.x+hands1[i].width*0.5,center.y+hands1[i].height*0.5),Scalar( 255, 255, 255 ), 4, 8, 0);
        //putText(frame,"paper",Point(center.x-20,center.y),0,1,Scalar( 255, 255, 255 ));
        //sprintf(name1,"E:\\OPENCV_EX\\HAND FEATURE\\opencv_first\\PAPER_sobel\\%d.jpg",m);
        //subframe1=sobel_sobel(Range(center.y-hands1[i].height*0.5,center.y+hands1[i].height*0.5),Range(center.x-hands1[i].width*0.5,center.x+hands1[i].width*0.5));
        //imwrite(name1,subframe1);
        //m++;
        //Mat faceROI = sobel_sobel( hands1[i] );
        //paper=true;
    }
/*    for( int i = 0; i < hands2.size(); i++ )
    {
        Point center( hands2[i].x + hands2[i].width*0.5, hands2[i].y + hands2[i].height*0.5 );
        rectangle(frame, Point(center.x-hands2[i].width*0.5,center.y-hands2[i].height*0.5), Point(center.x+hands2[i].width*0.5,center.y+hands2[i].height*0.5),Scalar( 0, 255, 0 ), 4, 8, 0);
        putText(frame,"scissor",Point(center.x-40,center.y),0,1,Scalar( 0, 255, 0 ));
        sprintf(name1,"E:\\OPENCV_EX\\HAND FEATURE\\opencv_first\\SCISSOR_sobel\\%d.jpg",a);
        subframe1=sobel_sobel(Range(center.y-hands2[i].height*0.5,center.y+hands2[i].height*0.5),Range(center.x-hands2[i].width*0.5,center.x+hands2[i].width*0.5));
        imwrite(name1,subframe1);
        a++;
        Mat faceROI = sobel_sobel( hands2[i] );
        scissor=true;
    }

    for( int i = 0; i < hands3.size(); i++ )
    {
        Point center( hands3[i].x + hands3[i].width*0.5, hands3[i].y + hands3[i].height*0.5 );
        rectangle(frame, Point(center.x-hands3[i].width*0.5,center.y-hands3[i].height*0.5), Point(center.x+hands3[i].width*0.5,center.y+hands3[i].height*0.5),Scalar( 255, 255, 0 ), 4, 8, 0);
       // putText(frame,"stone",Point(center.x-20,center.y),0,1,Scalar( 255, 255, 0 ));
       // sprintf(name1,"E:\\OPENCV_EX\\HAND FEATURE\\opencv_first\\STONE_sobel\\%d.jpg",b);
       // subframe1=sobel_sobel(Range(center.y-hands3[i].height*0.5,center.y+hands3[i].height*0.5),Range(center.x-hands3[i].width*0.5,center.x+hands3[i].width*0.5));
       //imwrite(name1,subframe1);
       // b++;
       //Mat faceROI = sobel_sobel( hands3[i] );
       // stone=true;
    }
/*
    rectangle(frame, Point(180,140), Point(410,370),Scalar( 0, 255, 255 ), 1, 8, 0);
    result=paper+scissor+stone;
    switch(result)
    {
    case 0:
        putText(frame,"Game start ?",Point(50,300),0,1,Scalar( 160, 115, 255 ),5);
        break;
    case 1:
        putText(frame,"Tie",Point(50,300),0,1,Scalar( 255, 255, 0 ),5);
        break;
     case 2:
        if (stone&&scissor)
        putText(frame,"stone win",Point(50,300),0,1,Scalar( 255, 255, 0 ),5);
        if (scissor&&paper)
        putText(frame,"scissor win",Point(50,300),0,1,Scalar( 255, 255, 0 ),5);
        if (stone&&paper)
        putText(frame,"paper win",Point(50,300),0,1,Scalar( 255, 255, 0 ),5);
        break;
     case 3:
        putText(frame,"Tie",Point(50,300),0,1,Scalar( 255, 255, 0 ),5);
        break;

    }
    paper=false;scissor=false;stone=false;
*/
    imshow("sobel",sobel);
    imshow("Capture",frame);
}

