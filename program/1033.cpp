/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-08 13:48:04
 * @Description  : 
 * @FilePath     : /PTAbasic/program/1033.cpp
 */

// 没有一个字符能被打出，则输出空行
// 如果没有坏键，那么应该全部输出

#include <iostream>
#include <ctype.h>
using namespace std;

bool fliter(string &f, char x)
{
    auto p = f.begin();
    while (p != f.end())
    {
        if (*p == '+' && isupper(x))
            return false;
        if (*p == x || *p == tolower(x) || *p == toupper(x))
            return false;
        p++;
    }
    return true;
}

int main()
{
    string f, test;
    bool empty = 1;
    getline(cin, f); // 读取一行
    cin >> test;

    for (auto t = test.begin(); t != test.end(); t++)
    {
        if (fliter(f, *t))
        {
            empty = 0;
            cout << *t;
        }
    }
    if (empty)
        cout << endl;

    return 0;
}