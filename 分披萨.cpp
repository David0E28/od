/*
题目描述
"吃货"和"馋嘴"两人到披萨店点了一份铁盘（圆形）披萨，并嘱咐店员将披萨按放射状切成大小相同的偶数个小块。但是粗心的服务员将披萨切成了每块大小都完全不同奇数块，且肉眼能分辨出大小。

由于两人都想吃到最多的披萨，他们商量了一个他们认为公平的分法：从"吃货"开始，轮流取披萨。除了第一块披萨可以任意选取外，其他都必须从缺口开始选。

他俩选披萨的思路不同。"馋嘴"每次都会选最大块的披萨，而且"吃货"知道"馋嘴"的想法。

已知披萨小块的数量以及每块的大小，求"吃货"能分得的最大的披萨大小的总和。

输入描述
第 1 行为一个正整数奇数 N，表示披萨小块数量。

3 ≤ N < 500
接下来的第 2 行到第 N + 1 行（共 N 行），每行为一个正整数，表示第 i 块披萨的大小

1 ≤ i ≤ N
披萨小块从某一块开始，按照一个方向次序顺序编号为 1 ~ N

每块披萨的大小范围为 [1, 2147483647]
输出描述
"吃货"能分得到的最大的披萨大小的总和。

用例
输入

5
8
2
10
5
7
输出

19 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 计算最大收益的函数,返回为L到R区间的最优收益
int valueSum(int L, int R, vector<int> &pizza, vector<vector<int>>& dp, int N)
{
    if (dp[L][R] != -1)
        return dp[L][R];
    // 模拟馋嘴策略
    if (pizza[L] > pizza[R])
        L = (L + 1) % N;
    else
        R = (R + N - 1) % N;
    if (L == R)
        dp[L][R] = pizza[L];
    else
        dp[L][R] = max(valueSum((L + 1) % N, R, pizza, dp, N) + pizza[L], valueSum(L, (R + N - 1) % N, pizza, dp, N) + pizza[R]);
    return dp[L][R];
}
int main()
{
    int N;
    cin >> N;

    vector<int> pizza(N); // 存储每块披萨的大小
    for (int i = 0; i < N; ++i)
    {
        cin >> pizza[i];
    }

    // dp[i] 表示从L到R区间披萨，吃货能获得的最大披萨大小的总和
    vector<vector<int>> dp(N, vector<int>(N, -1));
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        ans = max(ans, valueSum((i + 1) % N, (i + N - 1) % N, pizza, dp, N) + pizza[i]);
    }
    cout << ans << endl;
}


