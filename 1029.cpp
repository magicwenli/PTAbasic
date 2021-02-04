/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-04 20:46:50
 * @Description  : 1028 人口普查 (20 分)
 * @FilePath     : /PTAbasic/1029.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>

// 注意有效人口可能为0，此时不输出姓名

using namespace std;

constexpr int MIN_YEAR = 1814;
constexpr int MIN_MON = 9;
constexpr int MIN_DAY = 6;
constexpr int MAX_YEAR = 2014;
constexpr int MAX_MON = 9;
constexpr int MAX_DAY = 6;

struct Person
{
    string name;
    int year;
    int mon;
    int day;
};

bool isValid(Person &p)
{
    if (p.year < MIN_YEAR)
        return false;
    else if (p.year == MIN_YEAR && p.mon < MIN_MON)
        return false;
    else if (p.year == MIN_YEAR && p.mon == MIN_MON && p.day < MIN_DAY)
        return false;
    else
    {
        if (p.year > MAX_YEAR)
            return false;
        else if (p.year == MAX_YEAR && p.mon > MAX_MON)
            return false;
        else if (p.year == MAX_YEAR && p.mon == MAX_MON && p.day > MAX_DAY)
            return false;
    }
    return true;
}

bool compare(Person &a, Person &b)
{
    if (a.year < b.year)
        return true;
    else if (a.year == b.year && a.mon < b.mon)
        return true;
    else if (a.year == b.year && a.mon == b.mon && a.day < b.day)
        return true;
    else
        return false;
}

int main()
{
    vector<Person> ps;
    Person tmp;
    string n;
    int y, m, d;
    int num;
    char slash;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> n >> y >> slash >> m >> slash >> d;
        tmp.name = n;
        tmp.year = y;
        tmp.mon = m;
        tmp.day = d;
        if (isValid(tmp))
        {
            ps.push_back(tmp);
        }
    }
    sort(ps.begin(), ps.end(), compare);
    
    if (ps.size() > 0)
        cout << ps.size() << " " << (*ps.begin()).name << " " << (*(ps.end() - 1)).name;
    else
        cout << 0;

    return 0;
}