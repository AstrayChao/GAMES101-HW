#include <Eigen/Core>
#include <iostream>

using std::cout;
using std::endl;

// rotate and translate
Eigen::Vector3d hw0(Eigen::Vector3d &point, double theta, int translateX, int translateY) {
    Eigen::Matrix3d rotateMatrix;
    Eigen::Matrix3d translateMatrix;

    rotateMatrix << cos(theta), -1.0 * sin(theta), 0,
            sin(theta), cos(theta), 0,
            0, 0, 1;

    translateMatrix << 1, 0, translateX,
            0, 1, translateY,
            0, 0, 1;

    return translateMatrix * rotateMatrix * point;
}

int main() {
    Eigen::Vector3d point(2, 1, 1);
    double theta = (45.0 / 180.0) * M_PI;
    cout << hw0(point, theta, 1, 2) << endl;
}