/*
题目描述
给定一个由若干整数组成的数组nums ，可以在数组内的任意位置进行分割，将该数组分割成两个非空子数组
（即左数组和右数组），分别对子数组求和得到两个值，计算这两个值的差值，请输出所有分割方案中，差值最大的值。

输入描述
第一行输入数组中元素个数n，1 < n ≤ 100000
第二行输入数字序列，以空格进行分隔，数字取值为4字节整数

输出描述
输出差值的最大取值

示例:
输入
6
1 -2 3 4 -9 7
输出
10
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int sum = 0;
    int res = 0;
    int max = 0;
    vector<int> numVec;
    for (int i = 0; i < num; ++i)
    {   
        int temp;
        cin >> temp;
        numVec.push_back(temp);
        sum += temp;
    }

    for (int i = 0; i < num; ++i)
    {
        res += numVec[i];
        max = abs(res - (sum - res)) > max ? abs(res - (sum - res)) : max;
    }
    cout << max << endl;
    return 0;
    
}