/* 题目描述
一个有N个选手参加比赛，选手编号为1~N（3<=N<=100），有M（3<=M<=10）个评委对选手进行打分。

打分规则为每个评委对选手打分，最高分10分，最低分1分。

请计算得分最多的3位选手的编号。

如果得分相同，则得分高分值最多的选手排名靠前

(10分数量相同，则比较9分的数量，以此类推，用例中不会出现多个选手得分完全相同的情况)。

​

输入描述
第一行为半角逗号分割的两个正整数，第一个数字表示M（3<=M<=10）个评委，第二个数字表示N（3<=N<=100）个选手。

第2到M+1行是半角逗号分割的整数序列，表示评委为每个选手的打分，0号下标数字表示1号选手分数，1号下标数字表示2号选手分数，依次类推。

输出描述
选手前3名的编号。

**注：**若输入为异常，输出-1，如M、N、打分不在范围内。

示例1
输入

4,5
10,6,9,7,6
9,10,6,7,5
8,10,6,5,10
9,10,8,4,9

输出

2,1,5  
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main () {
    string inputTemp;
    int m, n;
    char douHao;

    // 读取第一行输入
    getline(cin, inputTemp);
    stringstream ss(inputTemp);
    ss >> m >> douHao >> n;

    // 检查输入合法性
    if (m < 3 || m > 10 || n < 3 || n > 100 || douHao != ',') {
        return -1;
    }

    // 初始化分数矩阵
    vector<vector<int>> VectorMatrix(m + 1, vector<int>(n, 0));

    // 读取评委打分
    for (int i = 0; i < m; ++i) {
        getline(cin, inputTemp);
        stringstream markLine(inputTemp);
        for (int j = 0; j < n - 1; ++j) {
            markLine >> VectorMatrix[i][j] >> douHao;
            if(VectorMatrix[i][j] < 0 || VectorMatrix[i][j] > 10) return -1;
            VectorMatrix[m][j] += VectorMatrix[i][j]; // 累加总分
        }
        markLine >> VectorMatrix[i][n - 1];
        if(VectorMatrix[i][n - 1] < 0 || VectorMatrix[i][n - 1] > 10) return -1;
        VectorMatrix[m][n - 1] += VectorMatrix[i][n - 1]; // 累加最后一个选手的总分
    }

    // 构建选手信息：{总分, 高分分布, 编号}
    vector<pair<pair<int, vector<int>>, int>> players;
    for (int j = 0; j < n; ++j) {
        vector<int> highScoreCount(11, 0); // 记录每个分数的数量（1~10）
        for (int i = 0; i < m; ++i) {
            highScoreCount[VectorMatrix[i][j]]++;
        }
        players.push_back({{VectorMatrix[m][j], highScoreCount}, j + 1}); // 编号从 1 开始
    }

    // 排序规则
    sort(players.begin(), players.end(), [](const auto &a, const auto &b) {
        // 按总分降序
        if (a.first.first != b.first.first) {
            return a.first.first > b.first.first;
        }
        // 按高分分布降序
        for (int score = 10; score >= 1; --score) {
            if (a.first.second[score] != b.first.second[score]) {
                return a.first.second[score] > b.first.second[score];
            }
        }
        // 按编号升序
        return a.second < b.second;
    });

    // 输出前 3 名选手编号
    for (int i = 0; i < 3; ++i) {
        cout << players[i].second;
        if (i < 2) cout << ",";
        
    }
    cout << endl; 

    return 0;
}