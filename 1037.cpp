/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-03 01:06:03
 * @Description  : 
 * @FilePath     : /PTAbasic/1037.cpp
 */

#include <iostream>
using namespace std;

class Money
{
public:
    int galleon;
    int sickle;
    int knut;

    Money operator-(const Money &m)
    {
        Money res;
        res.knut = this->knut - m.knut;
        if (res.knut < 0)
        {
            this->sickle--;
            res.knut += 29;
        }
        res.sickle = this->sickle - m.sickle;
        if (res.sickle < 0)
        {
            this->galleon--;
            res.sickle += 17;
        }
        res.galleon = this->galleon - m.galleon;
        return res;
    }
    bool operator>(const Money &m)
    {
        if (this->galleon > m.galleon)
            return true;
        else if (this->galleon == m.galleon && this->sickle > m.sickle)
            return true;
        else if (this->galleon == m.galleon && this->sickle == m.sickle && this->knut > m.knut)
            return true;
        else
            return false;
    }
};

int main()
{
    Money a, b, c;
    scanf("%d.%d.%d %d.%d.%d", &a.galleon, &a.sickle, &a.knut, &b.galleon, &b.sickle, &b.knut);
    if (a > b)
    {
        c = a - b;
        printf("-%d.%d.%d", c.galleon, c.sickle, c.knut);
    }
    else
    {
        c = b - a;
        printf("%d.%d.%d", c.galleon, c.sickle, c.knut);
    }

    return 0;
}