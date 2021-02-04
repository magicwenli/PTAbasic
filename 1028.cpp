/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-04 20:02:58
 * @Description  : 
 * @FilePath     : /PTAbasic/1028.cpp
 */

#include <iostream>
using namespace std;
int getLeft(int num, int &level)
{
    int left = 0;
    level = 1;

    for (int i = 1; i < num + 1; i++)
    {
        if (2 * i * i - 1 > num) // total = 2*i^2-1
        {
            break;
        }
        left = num - 2 * i * i + 1;
        level = i;
    }
    return left;
}

void printSign(int times, char &sign)
{
    for (int i = 0; i < times; i++)
    {
        cout << sign;
    }
}

int main()
{
    int num, level, left;
    int cnt = 0; //counter for blank char
    char sign, blank = ' ';
    cin >> num >> sign;
    left = getLeft(num, level);
    for (int i = 1; i < 2 * level - 1 + 1; i++)
    {
        printSign(cnt, blank);
        if (i < level)
        {
            printSign(2 * (level - i + 1) - 1, sign);
            cnt++;
        }
        else
        {
            printSign(2 * (i - level + 1) - 1, sign);
            cnt--;
        }
        // printSign(cnt, blank); //右边不输出

        cout << endl;
    }
    cout << left;

    return 0;
}