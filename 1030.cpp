/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-05 15:29:25
 * @Description  : 1030 完美数列 (25 分)
 * @FilePath     : /PTAbasic/1030.cpp
 */

// 先排序，头尾两个指针遍历
// # # p . . . . . . q @ @ @
// 第一次找到解 cnt = 8;
// 第二次 p++; q = p+length;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    size_t num, p, length = 1, maxlength = 1;
    vector<size_t> save;
    cin >> num >> p;
    for (size_t i = 0; i < num; i++)
    {
        size_t tmp;
        cin >> tmp;
        save.push_back(tmp);
    }
    sort(save.begin(), save.end());
    auto start = save.begin();

    while (start < save.end())
    {
        auto end = start + maxlength;
        while (end < save.end())
        {
            if (*start * p >= *end)
            {
                length = end - start + 1;
                if (length > maxlength)
                    maxlength = length;
            }
            else
            {
                break; // 找不到直接跳出
            }
            end++;
        }
        start++;
    }
    cout << maxlength;

    return 0;
}