/* 
给定参数n，从1到n会有n个整数：1,2,3,…,n,这n个数字共有n!种排列。

按大小顺序升序列出所有排列的情况，并一一标记，

当n=3时,所有排列如下:

“123” “132” “213” “231” “312” “321”

给定n和k，返回第k个排列。

输入描述
输入两行，第一行为n，第二行为k，
给定n的范围是[1,9],给定k的范围是[1,n!]。
输出描述
输出排在第k位置的数字。

示例1
输入
3
3
输出

213
 */
#include <iostream>
#include <vector>
using namespace std;
#include <numeric>

int factorial(int n) {
    int res = 1;
    for(int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1); //递增赋值
    --k;
    string res;
    for(int i = 1; i <= n; ++i) {
        int allPermutation = factorial(n - i);
        int index = k / allPermutation;
        res += to_string(nums[index]);
        nums.erase(nums.begin() + index);
        k %= allPermutation;
    }
    cout << res << endl;
    return 0;
}