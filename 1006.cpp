/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-16 22:13:16
 * @Description  : 
 * @FilePath     : /PTAbasic/1006.cpp
 */

#include <iostream>
using namespace std;

// 分离各位数字，根据要求输出
 
int main()
{
    size_t num;
    size_t subs[3]{};
    cin >> num;

    for (size_t i = 0; i < 3; i++)
    {
        subs[i] = num % 10;
        num /= 10;
    }

    for (size_t i = 0; i < 3; i++)
    {
        switch (2-i)
        {
        case 0:
            for (size_t j = 1; j <= subs[0]; j++)
            {
                cout << j;
            }
            break;
        case 1:
            for (size_t j = 0; j < subs[1]; j++)
            {
                cout << 'S';
            }
            break;
        case 2:
            for (size_t j = 0; j < subs[2]; j++)
            {
                cout << 'B';
            }
            break;
        default:
            break;
        }
    }
    
    return 0;
}