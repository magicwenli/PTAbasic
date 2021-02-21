/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-21 17:04:27
 * @Description  : 1034 有理数四则运算 (20 分)
 * @FilePath     : /PTAbasic/program/1034.cpp
 */

// from https://www.liuchuo.net/archives/492

#include <iostream>
using namespace std;

/**
 * @description: 最大公约数
 * @param {int64_t} child
 * @param {int64_t} parent
 * @return {*}
 */
int64_t gcd(int64_t child, int64_t parent)
{
    return parent == 0 ? child : gcd(parent, child % parent);
}

/**
 * @description: 化简
 * @param {int64_t} child
 * @param {int64_t} parent
 * @return {*}
 */
void func(int64_t child, int64_t parent)
{
    if (child * parent == 0)
    {
        printf("%s", parent == 0 ? "Inf" : "0");
        return;
    }
    // flag：负数为真
    bool flag = ((child < 0 && parent > 0) || (child > 0 && parent < 0));

    child = abs(child);
    parent = abs(parent);
    int64_t x = child / parent;
    printf("%s", flag ? "(-" : "");

    if (x != 0)
        printf("%lld", x);

    if (child % parent == 0)
    {
        if (flag)
            printf(")");
        return;
    }
    if (x != 0)
        printf(" ");
    child = child - x * parent;
    int64_t t = gcd(child, parent);
    child = child / t;
    parent = parent / t;
    printf("%lld/%lld%s", child, parent, flag ? ")" : "");
}

int main()
{
    int64_t a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);

    func(a, b);
    printf(" + ");
    func(c, d);
    printf(" = ");
    func(a * d + b * c, b * d);
    printf("\n");

    func(a, b);
    printf(" - ");
    func(c, d);
    printf(" = ");
    func(a * d - b * c, b * d);
    printf("\n");

    func(a, b);
    printf(" * ");
    func(c, d);
    printf(" = ");
    func(a * c, b * d);
    printf("\n");

    func(a, b);
    printf(" / ");
    func(c, d);
    printf(" = ");
    func(a * d, b * c);
    return 0;
}