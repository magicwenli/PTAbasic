/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-17 10:58:17
 * @Description  : 
 * @FilePath     : /PTAbasic/1008.cpp
 */

#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    m %= n;
    for (int i = 0; i < m; i++)
    {
        cout << arr[n - m + i] << " " ;
    }
    for (int i = 0; i < (n-m); i++)
    {
        cout << arr[i];
        if(i!=(n-m-1))
            cout << " ";
    }

    return 0;
}