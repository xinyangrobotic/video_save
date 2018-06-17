#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    //打开摄像头
    VideoCapture captrue(0);
    captrue.set(CV_CAP_PROP_FRAME_WIDTH, 1920);
    captrue.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);
    captrue.set(CV_CAP_PROP_FPS, 5);
    captrue.set(CAP_PROP_AUTOFOCUS,0);
    cout<<captrue.get(CV_CAP_PROP_FPS)<<endl;
    //视频写入对象
//    VideoWriter write;
    //写入视频文件名
//    string outFlie = "video.mp4";
//    Size S(640, 360);
    //获得帧率
//    double r = captrue.get(CV_CAP_PROP_FPS);
    //打开视频文件，准备写入
VideoWriter writer("video.avi",CV_FOURCC('M', 'J', 'P', 'G'), 5.0, Size(1920, 1080));//1080P只能以5帧的频率录制,720P,10帧,360P,30帧
    //打开失败
    if (!captrue.isOpened())
    {
        return 1;
    }
    bool stop = false;
    Mat frame;
    //循环
    while (!stop)
    {
        //读取帧
        if (!captrue.read(frame))
            break;
        imshow("Video", frame);
        //写入文件
        writer.write(frame);
        if (waitKey(10) == 'q')
            break;
    }
}