/*
 * @Author       : magicwenli
 * @Date         : 2021-01-31 20:51:43
 * @LastEditTime : 2021-01-31 20:51:43
 * @Description  : 
 * @FilePath     : /PTAbasic/1020.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 注意题目说总库存，总售价都是正数，而月饼种类、需求是正整数

struct mooncake
{
    float storge;
    float total_price;
    float unit_price;
};

bool compare(mooncake &a, mooncake &b)
{
    return a.unit_price > b.unit_price;
}

int main()
{
    int series, need;
    cin >> series >> need;
    vector<mooncake> mks(series);

    for (int i = 0; i < series; i++)
    {
        cin >> mks[i].storge;
    }
    for (int i = 0; i < series; i++)
    {
        cin >> mks[i].total_price;
        mks[i].unit_price = mks[i].total_price / mks[i].storge;
    }

    sort(mks.begin(), mks.end(), compare);

    float margin = 0;

    for (auto iter = mks.cbegin(); iter != mks.cend(); iter++)
    {
        if (need > (*iter).storge)
        {
            need -= (*iter).storge;
            margin += (*iter).total_price;
        }
        else
        {
            margin += (*iter).unit_price * need;
            need = 0;
            break;
        }
    }

    printf("%.2f", margin);
    return 0;
}