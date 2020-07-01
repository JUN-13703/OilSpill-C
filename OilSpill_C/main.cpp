#include <stdio.h>
#include <seek/seek.h>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <unistd.h>

#define NUM_IMG 750
#define DELAY_SEC 1

int main(int argc, char **argv)
{
	LibSeek::SeekThermal s_cam(argc == 2 ? argv[1] : "");
	cv::Mat frame, g_frame,  f_frame, b_frame;
    if (!s_cam.open()) {
        std::cout << "failed to open seek cam" << std::endl;
        return -1;
    }

	int i = 0;
	char img_name[96];
	std::vector<int> cmp_params;
	cmp_params.push_back(cv::IMWRITE_PNG_COMPRESSION);
	cmp_params.push_back(0);
	//double minT, maxT;
    while(i < NUM_IMG) {
        if (!s_cam.read_raw_ffc_corrected(frame)) {
            std::cout << "no LWIR img" << std::endl;
            return -1;
        }

		cv::medianBlur(frame,g_frame,3);
		cv::normalize(g_frame, b_frame, 0, 65535, cv::NORM_MINMAX);
		g_frame.convertTo(f_frame,  CV_32F);
		//f_frame = 0.5*0.03762687965*f_frame-273.15; //0.03762687965
		sprintf(img_name,"/home/pi/Desktop/OilSpill-C/OilSpill_C/Debug/thermv_images/i%d.png",i);
		imwrite(img_name,b_frame);
		sprintf(img_name,"/home/pi/Desktop/OilSpill-C/OilSpill_C/Debug/raw_images/r%d.png",i);
		imwrite(img_name,frame);
		//sprintf(img_name,"radiometry/t%d.tiff",i);
		//cv::minMaxLoc(f_frame,&minT,&maxT);
		//std::cout<<"Max T: "<<maxT<<" Min T: "<<minT<<std::endl;
		//maxT = 0;
		//minT = 100;
		//imwrite(img_name,f_frame);
		i++;
		sleep(DELAY_SEC);
	}
	sleep(2);
	system("shutdown");
	
	return 0;
}
