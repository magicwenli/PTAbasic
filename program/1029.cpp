/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-05 13:21:26
 * @Description  : 1029 旧键盘 (20 分)
 * @FilePath     : /PTAbasic/1029.cpp
 */

#include <iostream>
#include <set>
using namespace std;

int main()
{
    string test, respose;
    set<char> sets;
    cin >> test >> respose;
    auto p = test.begin();
    auto q = respose.begin();

    while (p != test.end())
    {
        if (*p != *q)
        {
            // printf("*p = %c, *q = %c \n", *p, *q);
            if (!sets.count(toupper(*p)))
            {
                sets.insert(toupper(*p));
                printf("%c",toupper(*p));  // 如果 sets 中没有这个元素，则输出
            }
            p++;
        }
        else
        {
            if (q != respose.end())
            {
                p++;
                q++;
            }
            else
                p++;
        }
    }

    return 0;
}