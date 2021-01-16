/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-16 13:37:11
 * @Description  : 
 * @FilePath     : \PTAbasic\1005.cpp
 */

#include <iostream>
using namespace std;

size_t getChain(size_t number, size_t *ans)
{
    size_t length = 0;
    *ans = number;
    ans++;
    length++;
    
    while (number-1)
    {
        if (number & 1)
        {
            number = 3 * number + 1;
        }else
        {
            number /= 2;
        }

        *ans = number;
        ans++;
        length++;
    }

    return length;
}

int main()
{
    size_t num;
    size_t numbers[100];
    cin >> num;
    for (size_t i = 0; i < num; i++)
    {
        cin >> numbers[i];
    }

    size_t tmp[100]{};
    size_t len;
    for (size_t i = 0; i < num; i++)
    {
        len=getChain(numbers[i], tmp);
        for (size_t j = 0; j < len; j++)
        {
            cout << tmp[j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}