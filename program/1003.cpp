/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:15:53
 * @LastEditTime : 2021-01-16 12:50:18
 * @Description  : 
 * @FilePath     : \PTAbasic\1003.cpp
 */

// 对于 xPyTz ，有1：若|x| = |z| 则 |y| >=1
//              2: 否则 |z| = |x|·|y|
// 注意 P 在 T 前

#include <iostream>
#include <string.h>
using namespace std;

bool checkLeagal(char *str_in)
{
    int l = 0, m = 0, r = 0, counter = 0;
    size_t pp = 0, tp = 0;
    bool leagal = true;

    for (size_t i = 0; i < strlen(str_in); i++)
    {
        if (!leagal)
            break;

        switch (str_in[i])
        {
        case 'A':
            counter++;
            break;
        case 'P':
            l = counter;
            pp = i;
            counter = 0;
            break;
        case 'T':
            m = counter;
            tp = i;
            counter = 0;
            break;
        default:
            leagal = false;
            break;
        }
    }
    r = counter;

    if (!leagal || pp>=tp)
    {
        return false;
    }

    if (m < 1)
    {
        return false;
    }
    else if (l == r)
    {
        return true;
    }
    else if (r == l * m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char str_in[102]{};
    bool save[20]{};
    size_t num;
    cin >> num;

    for (size_t i = 0; i < num; i++)
    {
        cin >> str_in;
        save[i] = checkLeagal(str_in);
    }

    for (size_t i = 0; i < num; i++)
    {
        save[i] ? cout << "YES" << endl : cout << "NO" << endl;
    }
    // system("pause");
    return 0;
}