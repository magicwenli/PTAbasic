/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-17 14:26:19
 * @Description  : 
 * @FilePath     : /PTAbasic/1010.cpp
 */

#include <iostream>
using namespace std;

int main()
{
    int coefficients[1001];
    int index[1001];
    int i = 0, flag = 0; //flag 判断是否需要输出" “

    while (cin >> coefficients[i] >> index[i])
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        if (index[j] == 0)
            ;
        else
        {
            if(flag)
                cout << " ";
            cout << coefficients[j] * index[j] << " " << index[j] - 1;
            flag = 1;
        }
    }
    if(flag==0)
        cout << "0 0";

    return 0;
}