/* 
题目描述
磁盘的容量单位常用的有 M，G，T 这三个等级，它们之间的换算关系为：

1T = 1024G
1G = 1024M
现在给定 n 块磁盘的容量，请对它们按从小到大的顺序进行稳定排序。

例如给定5块盘的容量：

1T，20M，3G，10G6T，3M12G9M

排序后的结果为：

20M，3G，3M12G9M，1T，10G6T

注意单位可以重复出现，上述 3M12G9M 表示的容量即为：3M+12G+9M，和 12M12G 相等。

输入描述
输入第一行包含一个整数 n，表示磁盘的个数

2 ≤ n ≤ 100
接下的 n 行，每行一个字符串（长度大于2，小于30），表示磁盘的容量，由一个或多个格式为mv的子串组成，其中 m 表示容量大小，v 表示容量单位，例如：20M，1T，30G，10G6T，3M12G9M。

磁盘容量 m 的范围为 1 到 1024 的正整数
容量单位 v 的范围只包含题目中提到的 M，G，T 三种，换算关系如题目描述
输出描述
输出 n 行，表示 n 块磁盘容量排序后的结果。

示例1
输入

3
1G
2G
1024M
输出

1G
1024M
2G */
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
int convert(char c) {
    if(c == 'M') return 1 << 10;
    if(c == 'G') return 1 << 20;
    if(c == 'T') return 1 << 30;
    std::cout << "input error" << std::endl;
    return 0;
}
int main() {
    int num;
    std::cin >> num;
    std::vector<std::pair<std::string, long>> diskVec;
    while(num--) {
        std::string temp;
        std::cin >> temp;
        diskVec.push_back({temp, 0});
    }

    for(auto& Capacity : diskVec) {
        int temp;
        char c;
        std::stringstream ss(Capacity.first);
        while(ss >> temp >> c) {
            Capacity.second += temp * convert(c);
        }
    }
    std::sort(diskVec.begin(), diskVec.end(), [](const auto& a,const auto& b) {
        return a.second < b.second;
    });

    for(auto Capacity : diskVec) {
        std::cout << Capacity.first << std::endl;
    }
    return 0;
}