#include <stdio.h>
#include <seek/seek.h>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char **argv)
{
	LibSeek::SeekThermal s_cam(argc == 2 ? argv[1] : "");
	cv::Mat frame, g_frame,  f_frame, b_frame;
    if (!s_cam.open()) {
        std::cout << "failed to open seek cam" << std::endl;
        return -1;
    }

    //while(1) {
        if (!s_cam.read_raw_ffc_corrected(frame)) {
            std::cout << "no LWIR img" << std::endl;
            return -1;
        }

        cv::normalize(frame, g_frame, 0, 65535, cv::NORM_MINMAX);
		//g_frame.convertTo(f_frame,  CV_32F);
		cv::medianBlur(g_frame,b_frame,3);
		//b_frame.convertTo(frame, CV_16U);
		//cv::normalize(frame,  g_frame,0,65535,cv::NORM_MINMAX);
        cv::imshow("LWIR", b_frame);

        //char c = cv::waitKey(10);
        //if (c == 's') {
		//   cv::waitKey(0);
        //}
    //}
	imwrite("./cookingoil.png",b_frame);
	
	return 0;
}
