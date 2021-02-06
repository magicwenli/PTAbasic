/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-05 14:49:59
 * @Description  : 1062 最简分数 (20 分)
 * @FilePath     : /PTAbasic/1062.cpp
 */

/* 先将两个分数通分，然后分子从小到大递增。判断每个分数是否满足题目要求。*/

#include <iostream>
#include <cmath>
using namespace std;

class faction
{
public:
    int child;
    int parent;
    faction(int, int);
    void reduction();            //约分
    void makeCommond(faction &); //通分
    bool operator<(faction &);
    bool operator>(faction &);
};

faction::faction(int a, int b)
{
    child = a;
    parent = b;
}

void faction::reduction()
{
    int a, b, tmp;
    if (parent < 0)
    {
        parent *= -1;
        child *= -1;
    }
    a = abs(child);
    b = abs(parent);
    while (a % b) // 求最大公约数
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    parent /= b;
    child /= b;
}

void faction::makeCommond(faction &b)
{
    int tmp;
    reduction();
    b.reduction();
    child *= b.parent; //通分
    b.child *= parent;
    tmp = parent * b.parent;
    parent = b.parent = tmp;
}

bool faction::operator<(faction &b)
{
    makeCommond(b);
    return child < b.child;
}
bool faction::operator>(faction &b)
{
    makeCommond(b);
    return child > b.child;
}

int main()
{
    int f_child, f_parent, s_child, s_parent, demond;
    scanf("%d/%d %d/%d %d", &f_child, &f_parent, &s_child, &s_parent, &demond);

    faction f = faction(f_child, f_parent);
    faction s = faction(s_child, s_parent);
    bool first = true;
    f.makeCommond(s);

    if (f > s)
    {
        int tmp = f.child;
        f.child = s.child;
        s.child = tmp;
    }

    for (int i = 1; i < demond; i++)
    {
        faction tmp = faction(i, demond);
        if (tmp > f && tmp < s)
        {
            tmp.reduction();
            if (tmp.parent == demond)
            {
                if (first)
                {
                    printf("%d/%d", tmp.child, tmp.parent);
                    first = false;
                }
                else
                    printf(" %d/%d", tmp.child, tmp.parent);
            }
        }
    }

    return 0;
}