/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-08 13:23:14
 * @Description  : 
 * @FilePath     : /PTAbasic/program/1032.cpp
 */

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> a(N + 1, 0);
    int num, score;
    for (int i = 0; i < N; i++)
    {
        cin >> num >> score;
        a[num] += score;
    }
    int max = a[1], t = 1;
    for (int i = 2; i <= N; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            t = i;
        }
    }
    cout << t << " " << max;
    return 0;
}