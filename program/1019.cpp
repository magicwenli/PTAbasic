/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-21 16:00:23
 * @Description  : 
 * @FilePath     : /PTAbasic/1019.cpp
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool CompareUp(char a,char b){
    return a < b;
}
bool CompareDown(char a,char b){
    return a > b;
}

int main()
{
    string num;
    cin >> num;
    while(num.size()<4)
        num.push_back('0');
    int ans = 0;

    if(num[0]==num[1]&&num[1]==num[2]&&num[2]==num[3]){
        cout << num << " - " << num << " = 0000";
        return 0;
    }

    while (ans!=6174)
    {
        char tmp[5];
        strcpy(tmp, num.c_str());
        sort(tmp, tmp + 4, CompareDown);
        string a = tmp;
        sort(tmp, tmp + 4,CompareUp);
        string b = tmp;
        ans = stoi(a) - stoi(b);

        num = to_string(ans);
        while(num.size()<4)
            num.push_back('0');
        printf("%s - %s = %04d\n", a.c_str(), b.c_str(), ans);
        // cout << a << " - " << b << " = "<<num<<endl;

    }
    
    return 0;
}