/*
 * @Author       : magicwenli
 * @Date         : 2021-01-15 20:23:34
 * @LastEditTime : 2021-01-15 20:43:56
 * @Description  : 1001
 */


#include <iostream>
using namespace std;
 
bool checkAndDivide(int* number){
    if(*number==1)
        return true;

    int tmp = *number % 2;
    if (tmp==0)
    {
        *number /= 2;
    }
    else
    {
        *number = (3 * *number + 1) / 2;
    }

    return false;
}

int main()
{
    int int_in;
    cin >> int_in;

    int counter = 0;
    while (!checkAndDivide(&int_in))
    {
        counter++;
    }

    cout << counter;

    return 0;
}