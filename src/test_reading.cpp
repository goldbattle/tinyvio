
#include <glob.h>
#include <vector>
#include <iostream>


#include <opencv2/opencv.hpp>


std::vector<std::string> globVector(const std::string& pattern){
    glob_t glob_result;
    glob(pattern.c_str(),GLOB_TILDE,NULL,&glob_result);
    std::vector<std::string> files;
    for(unsigned int i=0;i<glob_result.gl_pathc;++i){
        files.push_back(std::string(glob_result.gl_pathv[i]));
    }
    globfree(&glob_result);
    return files;
}

int main(/*int argc, char* argv[]*/)
{


    std::vector<std::string> files = globVector("/home/goldbattle/V1_01_easy/mav0/cam0/data/*");

    cv::namedWindow("test");
    for(auto const &file : files) {
        
        size_t found = file.find_last_of("/");
        std::string filename = file.substr(found+1);
        double time_ns = std::stod(filename.substr(0, filename.size()-4));
        std::cout << time_ns << std::endl;

        // cv::Mat img = cv::imread(file, cv::IMREAD_COLOR);
        // cv::resize(img, img, cv::Size(300, 300));
        // cv::imshow("test", img);
        // cv::waitKey(5);

    }


}


