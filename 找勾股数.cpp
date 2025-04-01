/* 
题目描述
如果3个正整数(a,b,c)满足a^2 + b^2 = c^2的关系，则称(a,b,c)为勾股数（著名的勾三股四弦五），

为了探索勾股数的规律，我们定义如果勾股数(a,b,c)之间两两互质（即a与b，a与c，b与c之间均互质，没有公约数），则其为勾股数元组（例如(3,4,5)是勾股数元组，(6,8,10)则不是勾股数元组）。

请求出给定范围[N,M]内，所有的勾股数元组。

输入描述
起始范围N，1 <= N <= 10000

结束范围M，N < M <= 10000

输出描述
a,b,c请保证a < b < c,输出格式：a b c；

多组勾股数元组请按照a升序，b升序，最后c升序的方式排序输出；

给定范围中如果找不到勾股数元组时，输出”NA“。

示例1
输入

1
20

输出

3 4 5
5 12 13
8 15 17
 */
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
using namespace std;
bool areCoPrime(int a, int b, int c) {
    if(!(gcd(a, b) == 1)) return 0;
    if(!(gcd(b, c) == 1)) return 0;
    return 1;
}

int main() {
    int m, n;
    vector<vector<int>> res;
    unordered_map<int, pair<int, int>> mp;
    cin >> m >> n;
    for(int i = m; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            if(gcd(i, j) == 1) mp[i * i + j * j] = pair<int, int>(i, j);
        }
    }
    for(int i = m; i < n; ++i) {
        auto iter = mp.find(i * i);
        if (iter!= mp.end()) {
            if(areCoPrime(i, (*iter).second.first, (*iter).second.second)) {
                res.push_back({i, (*iter).second.first, (*iter).second.second});
            }
        }
    }
    for(const auto& item : res) {
        cout << item[0] << " " << item[1] << " " << item[2] << " " << endl;
    }
}