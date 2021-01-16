/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:15:53
 * @LastEditTime : 2021-01-16 12:26:08
 * @Description  : 
 * @FilePath     : \PTAbasic\1003.cpp
 */

// 对于 xPyTz ，有1：若|x| = |z| 则 |y| >=1
//              2: 否则 |z| = |x|·|y|

#include <iostream>
#include <string.h>
using namespace std;

bool checkLeagal(char *str_in)
{
    int l = 0, m = 0, r = 0, counter = 0;
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
            counter = 0;
            break;
        case 'T':
            m = counter;
            counter = 0;
            break;
        default:
            leagal = false;
            break;
        }
    }
    r = counter;

    if (!leagal)
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
    char str_in[100]{};
    bool save[10]{};
    size_t num;

    cin >> num;
    for (size_t i = 0; i < num; i++)
    {
        cin >> str_in;
        save[i] = checkLeagal(str_in);
    }

    for (size_t i = 0; i < num; i++)
    {
        save[i] ? cout << "Yes" : cout << "No";
        if (i+1!=num)
        {
            cout << endl;
        }
        
    }

    return 0;
}