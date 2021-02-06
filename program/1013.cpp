/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-18 20:18:39
 * @Description  : 
 * @FilePath     : /PTAbasic/1013.cpp
 */

#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num)
{
    if (num <= 3)
    {
        return num > 1;
    }
    //大于3的素数p，都满足 p==6t-1 || p==6t+1，t为一正整数
    //排除了偶数和3的倍数
    if (num % 6 != 1 && num % 6 != 5)
    {
        return false;
    }

    int sq = (int)sqrt(num);
    for (int i = 5; i <= sq; i += 6)
    {
        // 判断是否能整除5,7,11,13 ...
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int begin, end;
    cin >> begin >> end;

    int counter = 0, i = 1;
    int tenPrime = 0;
    while (counter != end)
    {
        if (isPrime(i))
        {
            counter++;
            if (counter >= begin)
            {
                tenPrime++;
                cout << i;
                if (tenPrime % 10 == 0)
                    cout << endl;
                else if (counter != end)
                    cout << " ";
            }
        }
        i++;
    }

    return 0;
}