/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-04 18:09:29
 * @Description  : 1026 程序运行时间 (15 分)
 * @FilePath     : /PTAbasic/1026.cpp
 */

#include <iostream>
using namespace std;

int main()
{
    const double CLK_TCK = 100.0;
    uint start, end;
    uint h, m, s;
    cin >> start >> end;
    s = (end - start) / CLK_TCK + 0.5; //整数四舍五入
    h = s / 3600;
    m = (s % 3600) / 60;
    s = s % 60;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}