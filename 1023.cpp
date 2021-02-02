/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-02 17:12:48
 * @Description  : 
 * @FilePath     : /PTAbasic/1023.cpp
 */

#include <iostream>
using namespace std;

int main()
{
    int a[10] = {0};
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    for (int i = 0; i < 10; i++)
    { 
        if (a[i] != 0 && i != 0)
        {
            cout << i;
            a[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (a[i] != 0)
        {
            while (a[i] != 0)
            {
                cout << i;
                a[i]--;
            }
        }
    }
    return 0;
}