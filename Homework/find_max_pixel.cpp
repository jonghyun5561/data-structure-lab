#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
    // 1. 이미지 불러오기 (흑백으로 변환해서 읽기)
    Mat img = imread("Lenna.png", IMREAD_GRAYSCALE);

    if (img.empty()) {
        cerr << "Lenna.png 이미지를 불러올 수 없습니다!" << endl;
        return -1;
    }

    // 2. 최대 픽셀값과 위치 구하기
    double minVal, maxVal;
    Point minLoc, maxLoc;

    minMaxLoc(img, &minVal, &maxVal, &minLoc, &maxLoc);

    // 3. 결과 출력
    cout << "최대 픽셀값: " << maxVal << endl;
    cout << "위치 (x, y): (" << maxLoc.x << ", " << maxLoc.y << ")" << endl;

    // 4. 최대값 위치 표시 (원 그리기)
    circle(img, maxLoc, 5, Scalar(255), 2); // 중심좌표, 반지름, 색상, 두께

    imshow("Lenna 이미지 (최대 픽셀 위치)", img);
    waitKey(0);

    return 0;
}
