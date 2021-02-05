/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-05 13:46:03
 * @Description  : 1030 完美数列 (25 分)
 * @FilePath     : /PTAbasic/1030.cpp
 */

#include <iostream>
using namespace std;

int main()
{
    size_t num, p, min = SIZE_MAX, max = 0;
    size_t tmp,cnt=0;
    cin >> num >> p;
    
    for (size_t i = 0; i < num; i++)
    {
        cin >> tmp;
        if (tmp < min)
            min = tmp;
        if (tmp > max)
            max = tmp;
        
        if(min*p<max)
            cnt++;
    }
    cout << cnt;

    return 0;
}