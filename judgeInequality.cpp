
/* 
给定一组不等式，判断是否成立并输出不等式的最大差(输出浮点数的整数部分)

要求:

不等式系数为 double类型，是一个二维数组

不等式的变量为 int类型，是一维数组;

不等式的目标值为 double类型，是一维数组

不等式约束为字符串数组，只能是:“>”,“>=”,“<”,“<=”,“=”， 

输入描述
a11,a12,a13,a14,a15,a21,a22,a23,a24,a25, a31,a32,a33,a34,a35,x1,x2,x3,x4,x5,b1,b2,b3,<=,<=,<=

不等式组系数(double类型):

a11,a12,a13,a14,a15

a21,a22,a23,a24,a25

a31,a32,a33,a34,a35

不等式变量(int类型):x1,x2,x3,x4,x5

不等式目标值(double类型):b1,b2,b3

不等式约束(字符串类型):<=,<=,<=

输出描述
true或者 false，最大差

示例1
输入

2.3,3,5.6,7.6;11,3,8.6,25,1;0.3,9,5.3,66,7.8;1,3,2,7,5;340,670,80.6;<=,<=,<=
1
输出

false 458
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <map>
#include <functional>
using namespace std;

int main() {
    string input;
    vector<string> inputVec;
    vector<vector<double>> argMatrix;
    vector<double> xVec;
    vector<double> rightValueVec;
    vector<string> mathType;

    // 读取输入
    string temp;
    getline(cin, temp);
    stringstream ss(temp);
    while (getline(ss, input, ';')) {
        inputVec.push_back(input);
    }

    // 解析不等式系数矩阵
    for (int i = 0; i < 3; ++i) {
        stringstream ss0(inputVec[i]);
        vector<double> tempVec;
        try {
            while (getline(ss0, input, ',')) {
                tempVec.push_back(stod(input));
            }
        } catch (const exception &e) {
            cout << "Invalid input format" << endl;
            return -1;
        }
        argMatrix.push_back(tempVec);
    }

    // 解析变量
    stringstream ss1(inputVec[3]);
    while (getline(ss1, input, ',')) {
        xVec.push_back(stod(input));
    }

    // 解析目标值
    stringstream ss2(inputVec[4]);
    while (getline(ss2, input, ',')) {
        rightValueVec.push_back(stod(input));
    }

    // 解析不等式约束
    stringstream ss3(inputVec[5]);
    while (getline(ss3, input, ',')) {
        mathType.push_back(input);
    }

    // 计算结果
    vector<vector<double>> resultB(2, vector<double>(3, 0));
    for (int i = 0; i < 3; ++i) {
        resultB[0][i] = argMatrix[i][0] * xVec[0] + argMatrix[i][1] * xVec[1] +
                        argMatrix[i][2] * xVec[2] + argMatrix[i][3] * xVec[3] +
                        argMatrix[i][4] * xVec[4];
    }

    // 比较运算符映射
    map<string, function<bool(double, double)>> op_map{
        {">=", greater_equal<double>()},
        {"<", less<double>()},
        {"=", equal_to<double>()},
        {"<=", less_equal<double>()},
        {">", greater<double>()}};

    // 判断不等式是否成立
    bool tag = true;
    double maxDiff = 0;
    for (int i = 0; i < 3; ++i) {
        resultB[1][i] = rightValueVec[i];
        if (!op_map[mathType[i]](resultB[0][i], resultB[1][i])) {
            tag = false;
        }
        maxDiff = max(abs(resultB[1][i] - resultB[0][i]), maxDiff);
    }

    // 输出结果
    cout << (tag ? "true" : "false") << " " << static_cast<int>(maxDiff) << endl;
    return 0;
}