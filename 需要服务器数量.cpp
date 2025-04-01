/* 
题目描述
服务器连接方式包括直接相连，间接连接。

A和B直接连接，B和C直接连接，则A和C间接连接。

直接连接和间接连接都可以发送广播。

给出一个N*N数组，代表N个服务器，

matrix[i][j] == 1，
则代表i和j直接连接；不等于 1 时，代表i和j不直接连接。

matrix[i][i] == 1，

即自己和自己直接连接。matrix[i][j] == matrix[j][i]。

计算初始需要给几台服务器广播， 才可以使每个服务器都收到广播。

输入描述
输入为N行，每行有N个数字，为0或1，由空格分隔，

构成N*N的数组，N的范围为 1 <= N <= 40

输出描述
输出一个数字，为需要广播的服务器的数量

示例1
输入

1 0 0
0 1 0
0 0 1
输出

3 */
#include <iostream>
#include <vector>
using namespace std;

// 查找第一个未访问的节点
int findOneIndex(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == 1) return i;
    }
    return -1;
}

int main() {
    // 数据放入容器
    int temp;
    vector<int> tempVec;
    int n = 0;
    while (cin >> temp) {
        ++n;
        tempVec.push_back(temp);
        if (cin.peek() == '\n') break;
    }

    vector<vector<int>> severMatrix(n, vector<int>(n));
    severMatrix[0] = tempVec;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> severMatrix[i][j];
        }
    }

    vector<int> processVec;
    vector<int> tag(n, 1); // 标记节点是否已访问
    int index = 0;
    int count = 0;

    while (index != -1) {
        ++count; // 每次找到一个新的未访问节点，启动一次广播
        processVec.push_back(index);
        tag[index] = 0; // 标记当前节点为已访问

        while (!processVec.empty()) {
            int current = processVec.front(); // 获取当前节点
            processVec.erase(processVec.begin()); // 弹出当前节点
            for (int i = 0; i < n; ++i) {
                if (severMatrix[current][i] == 1 && tag[i] != 0) {
                    processVec.push_back(i);
                    tag[i] = 0; // 标记为已访问
                }
            }
        }

        index = findOneIndex(tag); // 查找下一个未访问的节点
    }

    cout << count << endl;
    return 0;
}