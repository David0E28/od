#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

int main() {
    int target;
    string input;
    getline(cin, input);
    cin >> target;
    cin.ignore(); // 清理缓冲区

    vector<int> VLAN_POOL;
    stringstream ss(input);
    string vlanItem;
    while (getline(ss, vlanItem, ',')) {
        if (vlanItem.find('-') != string::npos) {
            int max, min;
            char dash;
            stringstream item(vlanItem);
            item >> min >> dash >> max;
            for (int i = min; i <= max; ++i) {
                VLAN_POOL.push_back(i);
            }
        } else {
            VLAN_POOL.push_back(stoi(vlanItem));
        }
    }

    sort(VLAN_POOL.begin(), VLAN_POOL.end());
    auto it = find(VLAN_POOL.begin(), VLAN_POOL.end(), target);
    if (it != VLAN_POOL.end()) {
        VLAN_POOL.erase(it);
    }

    vector<string> res;
    int startNum = 0;
    int endNum = 0;
    int lastNum = -1; // 初始化为 -1
    for (int i = 0; i < VLAN_POOL.size(); i++) {
        if (lastNum == -1) {
            startNum = VLAN_POOL[i];
            endNum = VLAN_POOL[i];
            lastNum = VLAN_POOL[i];
            continue;
        }
        if (lastNum == VLAN_POOL[i] - 1) {
            // 当前数字是连续的
            endNum = VLAN_POOL[i];
        } else {
            // 当前数字不连续，保存之前的范围
            if (startNum == endNum) {
                res.push_back("," + to_string(startNum));
            } else {
                res.push_back("," + to_string(startNum) + "-" + to_string(endNum));
            }
            // 更新范围的起点
            startNum = VLAN_POOL[i];
            endNum = VLAN_POOL[i];
        }
        lastNum = VLAN_POOL[i];
    }

    // 处理最后一个范围
    if (startNum == endNum) {
        res.push_back("," + to_string(startNum));
    } else {
        res.push_back("," + to_string(startNum) + "-" + to_string(endNum));
    }

    if (!res.empty()) {
        res[0] = res[0].substr(1);
    }
    for (string item : res) {
        cout << item;
    }
    cout << endl;
    return 0;
}