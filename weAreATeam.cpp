#include <iostream>
#include <sstream>
#include <set>

#define MAX 99999
using namespace std;
 int main() {
    int n, m;
    cin >> n >> m;
    if(n < 1 || m > MAX) {
        cout << "Null" << endl;
        return -1;
    }

    vector<set<int>> setVector;
    int iForSet = 0;
    while(m--) {
        int a,b,c;
        string input;
        getline(cin, input);
        cin >> a >> b >> c;
        if(a < 1 || a > MAX || b < 1 || b > MAX) {
            cout << "da pian zi" << endl;
        }
        if(c == 0) {
            setVector[iForSet].insert(a);
            setVector[iForSet].insert(b);
        }
        if(c != 0) {
            
        }
    }
 }