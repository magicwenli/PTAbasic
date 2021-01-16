/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-16 20:53:52
 * @Description  : 
 * @FilePath     : \PTAbasic\1005.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10000];
bool cmp(int a, int b) { return a > b; }

int main()
{
    int k, n, flag = 0;
    cin >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        v[i] = n;
        while (n != 1)
        {
            if (n & 1)  //Odd
                n = 3 * n + 1;
            n = n / 2;
            if (arr[n] == 1)
                break;
            arr[n] = 1;
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (size_t i = 0; i < v.size(); i++)
    {
        if (arr[v[i]] == 0)
        {
            if (flag == 1)
                cout << " ";
            cout << v[i];
            flag = 1;
        }
    }
    return 0;
}