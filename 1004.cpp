/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-16 13:17:12
 * @Description  : 
 * @FilePath     : \PTAbasic\1004.cpp
 */

#include <iostream>
#include <algorithm>

using namespace std;
struct student
{
    char name[11]{};
    char id[11]{};
    int grade=-1;
};

bool compare(student a,student b){
    return a.grade > b.grade;
}

int main()
{
    size_t num;
    student stu[110];

    cin >> num;
    for (size_t i = 0; i < num; i++)
    {
        cin >> stu[i].name >> stu[i].id >> stu[i].grade;
        // cout << stu[i].name << stu[i].id << stu[i].grade << endl;
    }

    sort(stu, stu+110, compare);

    cout << stu[0].name << ' ' << stu[0].id << endl;
    cout << stu[num-1].name << ' ' << stu[num-1].id << endl;
    return 0;
}