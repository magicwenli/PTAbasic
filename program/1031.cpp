/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-06 16:57:07
 * @Description  : 1031 查验身份证
 * @FilePath     : /PTAbasic/program/1031.cpp
 */

#include <iostream>
using namespace std;

/**
 * @description: 检查前17位是否为数字
 * @param {string} &id
 * @return {*}
 */
bool isNumbric(string &id)
{
    for (auto it = id.begin(); it != id.end() - 1; it++)
    {
        if (*it < '0' || *it > '9')
            return false;
    }
    return true;
}
/**
 * @description: 检查身份证是否有效
 * @param {string} &id
 * @return {*}
 */
bool isVaild(string &id)
{
    char checkNum[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    int sum = 0, i = 0;
    for (auto it = id.begin(); it != id.end() - 1; it++)
    {
        sum += weight[i] * (*it - '0');
        i++;
    }
    sum %= 11;
    if (*(id.end() - 1) == checkNum[sum])
        return true;
    else
        return false;
}


int main()
{
    string id;
    int num, pass = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> id;
        if (isNumbric(id) && isVaild(id))
        {
            pass++;
        }
        else
        {
            cout << id << endl;
        }
    }
    if (pass == num)
        cout << "All passed";

    return 0;
}