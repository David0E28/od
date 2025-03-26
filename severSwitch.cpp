/* 
题目描述
服务之间交换的接口成功率作为服务调用关键质量特性，某个时间段内的接口失败率使用一个数组表示，

数组中每个元素都是单位时间内失败率数值，数组中的数值为0~100的整数，

给定一个数值(minAverageLost)表示某个时间段内平均失败率容忍值，即平均失败率小于等于minAverageLost，

找出数组中最长时间段，如果未找到则直接返回NULL。

输入描述
输入有两行内容，第一行为{minAverageLost}，第二行为{数组}，数组元素通过空格(” “)分隔，

minAverageLost及数组中元素取值范围为0~100的整数，数组元素的个数不会超过100个。

输出描述
找出平均值小于等于minAverageLost的最长时间段，输出数组下标对，格式{beginIndex}-{endIndx}(下标从0开始)，

如果同时存在多个最长时间段，则输出多个下标对且下标对之间使用空格(” “)拼接，多个下标对按下标从小到大排序。

 */
#include <iostream>
#include <vector>
#include <utility>

int main() {
    int minAverageLost;
    std::cin >> minAverageLost;

    if (minAverageLost < 0 || minAverageLost > 100) {
        std::cout << "Invalid input" << std::endl;
        return -1;
    }

    std::vector<int> lostPerMin;
    int temp;
    while (std::cin >> temp) {
        if (temp < 0 || temp > 100) {
            std::cout << "Invalid input" << std::endl;
            return -1;
        }
        lostPerMin.push_back(temp);
        if(std::cin.peek() == '\n') break;
    }

    // 滑动窗口法
    int left = 0, right = 0, sum = 0, maxLength = 0;
    std::vector<std::pair<int, int>> res;

    while (right < lostPerMin.size()) {
        sum += lostPerMin[right];
        while (static_cast<double>(sum) / (right - left + 1) > minAverageLost) {
            sum -= lostPerMin[left];
            ++left;
        }
        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
            res.clear();
            res.push_back({left, right});
        } else if (right - left + 1 == maxLength) {
            res.push_back({left, right});
        }
        ++right;
    }

    if (res.empty()) {
        std::cout << "NULL" << std::endl;
    } else {
        for (const auto &item : res) {
            std::cout << item.first << "-" << item.second << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
