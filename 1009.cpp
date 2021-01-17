/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-17 11:25:22
 * @Description  : 
 * @FilePath     : /PTAbasic/1009.cpp
 */

#include <iostream>
#include <stack>
using namespace std;
 
int main()
{
    string str;
    stack<string> save;

    while (cin >> str)
    {
        save.push(str);
    }
    cout << save.top();
    save.pop();
    while (!save.empty())
    {
        cout << save.top();
        save.pop();
    }
    return 0;
}