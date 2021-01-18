/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-18 21:09:29
 * @Description  : 
 * @FilePath     : /PTAbasic/1014.cpp
 */

#include <iostream>
using namespace std;

int main()
{
    char str1[60], str2[60], str3[60], str4[60];
    char *p1 = str1, *p2 = str2, *p3 = str3, *p4 = str4;
    int counter = 0;
    char week[][7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cin >> str1 >> str2 >> str3 >> str4;

    while (*p1 != '\0' || *p2 != '\0')
    {
        if (*p1 == *p2 && counter == 0)
        {
            if (*p1 >= 'A' && *p1 <= 'G')
            {
                counter++;
                cout << week[*p1 - 'A'] << " ";
            }
        }
        else if (*p1 == *p2 && counter == 1)
        {
            if (*p1 >= '0' && *p1 <= '9')
            {
                cout << '0' << *p1 - '0' << ":";
                counter++;
            }
            else if (*p1 >= 'A' && *p1 <= 'N')
            {
                cout << *p1 - 'A' + 10 << ":";
                counter++;
            }
        }
        p1++;
        p2++;
    }

    int pos = 0;
    while (*p3 != '\0' || *p4 != '\0')
    {
        if (*p3 == *p4)
        {
            if ((*p3 >= 'A' && *p3 <= 'Z') || (*p3 >= 'a' && *p3 <= 'z'))
            {
                if (pos <= 9)
                    cout << '0' << pos;
                else
                    cout << pos;
            }
        }
        pos++;
        p3++;
        p4++;
    }
    return 0;
}