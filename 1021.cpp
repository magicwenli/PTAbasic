/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-31 21:01:24
 * @Description  : 
 * @FilePath     : /PTAbasic/1021.cpp
 */

#include <iostream>
using namespace std;

int main()
{
    string num;
    cin >> num;
    int counter[10]{};
    auto it = num.cbegin();

    while (it != num.cend())
    {
        switch (*it)
        {
        case '0':
            counter[0]++;
            break;
        case '1':
            counter[1]++;
            break;
        case '2':
            counter[2]++;
            break;
        case '3':
            counter[3]++;
            break;
        case '4':
            counter[4]++;
            break;
        case '5':
            counter[5]++;
            break;
        case '6':
            counter[6]++;
            break;
        case '7':
            counter[7]++;
            break;
        case '8':
            counter[8]++;
            break;
        case '9':
            counter[9]++;
            break;
        default:
            break;
        }
        it++;
    }

    for (int i = 0; i < 10; i++)
    {
        if(counter[i]!=0)
            printf("%d:%d\n", i, counter[i]);
    }
    

    return 0;
}