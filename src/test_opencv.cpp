
#include <opencv2/opencv.hpp>



int main() {


    cv::Mat img = cv::imread("../data/test.png", cv::IMREAD_COLOR);
    cv::resize(img, img, cv::Size(300, 300));
    cv::imshow("test", img);
    cv::waitKey(0);

}





