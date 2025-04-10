/*
题目描述
儿园两个班的小朋友在排队时混在了一起，每位小朋友都知道自己是否与前面一位小朋友同班，请你帮忙把同班的小朋友找出来。

小朋友的编号是整数，与前一位小朋友同班用Y表示，不同班用N表示。

输入描述
输入为空格分开的小朋友编号和是否同班标志。

比如：6/N 2/Y 3/N 4/Y，表示4位小朋友，2和6同班，3和2不同班，4和3同班。

其中，小朋友总数不超过999，每个小朋友编号大于0，小于等于999。

不考虑输入格式错误问题。

输出描述
输出为两行，每一行记录一个班小朋友的编号，编号用空格分开，且：

编号需按照大小升序排列，分班记录中第一个编号小的排在第一行。
若只有一个班的小朋友，第二行为空行。
若输入不符合要求，则直接输出字符串ERROR。
示例1
输入

1/N 2/Y 3/N 4/Y
输出

1 2
3 4
 */

#include <iostream>
#include <vector>
#include <sstream>
int main()
{
    std::string temp;
    std::vector<std::string> input;
    std::vector<std::vector<int>> classAB(2, std::vector<int>(0));
    int isSameClass = 1;
    while (std::cin >> temp)
    {
        input.push_back(temp);
        if (std::cin.peek() == '\n')
            break;
    }
    for (const auto &item : input)
    {
        std::stringstream ss{item};
        int num;
        std::string tag;
        ss >> num >> tag;
        if (tag == "/N")
            isSameClass = !isSameClass;
        classAB[isSameClass].push_back(num);
    }
    for (const auto &item : classAB[0])
        std::cout << item << " ";
    std::cout << std::endl;
    for (const auto &item : classAB[1])
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}