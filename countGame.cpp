#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m;
    cin >> m;  //input m 
    if(m < 1 || m > 100) {
        cout << "ERROR" << endl;
        return 0;
    }
    //init circle 
    int leftPeople = 100;
    vector<int> circle(100, 1);
    int count = 1;
    int j = 0;
    while(leftPeople >= m) {
        if(circle[j] != 0 && count == m) {
            circle[j] = 0;
            --leftPeople;
            count = 1;
        } else if(circle[j] != 0 && count != m) {
            ++count;
        }
        j = (++j) % 100;
    }
    int tag = 1;
    for(int i = 0 ; i < 100; ++i) {
        if(circle[i] == 1) {
            if(tag == 1) {
                tag = 0;
                cout << i + 1;
            }
            else {
                cout << "," << i + 1;
            }
        }
    }
    cout << endl;
    return 0;
}