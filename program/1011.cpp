/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-17 14:59:01
 * @Description  : 
 * @FilePath     : /PTAbasic/1011.cpp
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int64_t a, b, c;
        cin >> a>>b>>c;
        printf("Case #%d: %s\n", i + 1, a + b > c ? "true" : "false");
    }
    return 0;
}