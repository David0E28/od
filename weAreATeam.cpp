#include <iostream>
#include <sstream>
#include <set>

#define MAX 99999
using namespace std;

//并查集路径压缩
int find(int x, vector<int> &parent) {
    if(parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}
int main() {
    int n, m;
    cin >> n >> m;
    if(n < 1 || m > MAX) {
        cout << "Null" << endl;
        return 0;
    }

    vector<vector<int>> v;

    vector<int> parent(n + 1);
    for(int i = 0; i < n + 1; ++i) {
        parent[i] = i;
    }
    for(const auto item : v) {
        int a = item[0], b = item[1], c = item[2];
        if(a < 1 || a > MAX || b < 1 || b > MAX) {
            cout << "da pian zi" << endl;
            continue;
        }

        if(c == 0) {
            int rootA = find(a, parent);
            int rootB = find(b, parent);

            if(rootA != rootB) {
                parent[rootB] = rootA;
            }
        }

        else if(c == 1) {
            if(find(a, parent) == find(b, parent)) {
                cout << "We are a team" << endl;
            }
            else {
                cout << "We are not a team" << endl;
            }
        }

        else {
            cout << "da pian zi" << endl;
        }
    }
    return 0;
 }