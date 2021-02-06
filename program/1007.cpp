/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-17 10:41:00
 * @Description  : 
 * @FilePath     : /PTAbasic/1007.cpp
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
    int num, pair = 0;
    cin >> num;
    int prePrime = -1, thisPrime = -1;

    for (int i = 2; i <= num; i++)
    {
        if (isPrime(i))
        {
            prePrime = thisPrime;
            thisPrime = i;

            if (thisPrime - prePrime == 2)
            {
                pair++;
            }
        }
    }

    cout << pair << endl;

    return 0;
}