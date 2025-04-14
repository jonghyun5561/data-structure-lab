#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
    // 1. �̹��� �ҷ����� (������� ��ȯ�ؼ� �б�)
    Mat img = imread("Lenna.png", IMREAD_GRAYSCALE);

    if (img.empty()) {
        cerr << "Lenna.png �̹����� �ҷ��� �� �����ϴ�!" << endl;
        return -1;
    }

    // 2. �ִ� �ȼ����� ��ġ ���ϱ�
    double minVal, maxVal;
    Point minLoc, maxLoc;

    minMaxLoc(img, &minVal, &maxVal, &minLoc, &maxLoc);

    // 3. ��� ���
    cout << "�ִ� �ȼ���: " << maxVal << endl;
    cout << "��ġ (x, y): (" << maxLoc.x << ", " << maxLoc.y << ")" << endl;

    // 4. �ִ밪 ��ġ ǥ�� (�� �׸���)
    circle(img, maxLoc, 5, Scalar(255), 2); // �߽���ǥ, ������, ����, �β�

    imshow("Lenna �̹��� (�ִ� �ȼ� ��ġ)", img);
    waitKey(0);

    return 0;
}
