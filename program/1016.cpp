/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-19 14:50:05
 * @Description  : 
 * @FilePath     : /PTAbasic/1016.cpp
 */

#include <iostream>
using namespace std;

int getNum(int one,int length){
    if(length==0)
        return 0;
    int num=0,tmp;
    while (length!=0)
    {
        tmp = 1;
        for (int i = 0; i < length-1; i++)
        {
            tmp *= 10;
        }
        num += one * tmp;
        length--;
    }
    return num;
}

int findNum(string x,int one){
    int num = 0;
    for (size_t i = 0; i < x.size(); i++)
    {
        if(x[i]-'0'==one)
            num++;
    }
    return num;
}

int main()
{
    string a, b;
    int da, db;
    cin >> a >> da >> b >> db;
    cout << getNum(da,findNum(a, da))+getNum(db,findNum(b, db));

    return 0;
}