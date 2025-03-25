/* 
最新华为OD机试
题目描述
近些年来，我国防沙治沙取得显著成果。某沙漠新种植N棵胡杨（编号1-N），排成一排。

一个月后，有M棵胡杨未能成活。

现可补种胡杨K棵，请问如何补种（只能补种，不能新种），可以得到最多的连续胡杨树？

输入描述
N 总种植数量，1 <= N <= 100000

M 未成活胡杨数量，M 个空格分隔的数，按编号从小到大排列，1 <= M <= N

K 最多可以补种的数量，0 <= K <= M

输出描述
最多的连续胡杨棵树

示例1
输入

5
2
2 4
1

输出

3
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
     int numOfTree, numOfDead, leftTreeToPlant;  
    cin >> numOfTree;
    cin >> numOfDead;
    vector<int> whereDeadTree(numOfTree, 0);
    for(int i = 0; i < numOfDead; ++i) {
        int temp;
        cin >> temp;
        whereDeadTree[temp - 1] = 1;
    }
    cin >> leftTreeToPlant;

    //滑动窗口法
    int maxLength = 0, left = 0, subDeadCount = 0, length = 0;
    for(int right = 0; right < numOfTree; ++right, ++length) {
        subDeadCount += whereDeadTree[right];
        while(subDeadCount > leftTreeToPlant) {
            ++left;
            subDeadCount -= whereDeadTree[left];
            --length;
        }
        maxLength = max(maxLength, length);
    }
    cout << maxLength << endl;
    return 0;
}