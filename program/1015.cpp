/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-19 14:29:24
 * @Description  : 
 * @FilePath     : /PTAbasic/1015.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct candidates
{
    int id;
    int morality;
    int telent;
    short type;
    int total_score;
};

/**
 * @description: type ↑ -> total_score ↓ -> morality ↓ -> id ↑ 
 * @param {candidates} cda
 * @param {candidates} cdb
 * @return {*}
 */
bool sortByType(candidates cda, candidates cdb)
{
    if (cda.type < cdb.type)
        return true;
    else if (cda.type == cdb.type)
        if (cda.total_score == cdb.total_score)
            if (cda.morality == cdb.morality)
                return cda.id < cdb.id;
            else
                return cda.morality > cdb.morality;
        else
            return cda.total_score > cdb.total_score;
    else
        return false;
}

int main()
{
    int total, pass_line, excellent_line;
    int pass = 0;
    cin >> total >> pass_line >> excellent_line;
    vector<candidates> cds;
    for (int i = 0; i < total; i++)
    {
        candidates cd;
        cin >> cd.id >> cd.morality >> cd.telent;
        cd.total_score = cd.morality + cd.telent;

        if (cd.morality >= pass_line && cd.telent >= pass_line)
        {
            if (cd.morality >= excellent_line && cd.telent >= excellent_line)
            {
                cd.type = 1; // 德才皆尽
            }
            else if (cd.morality >= excellent_line && cd.telent < excellent_line)
            {
                cd.type = 2; // 德胜才
            }
            else if (cd.telent < excellent_line && cd.morality < excellent_line && cd.morality >= cd.telent)
            {

                cd.type = 3; // “才德兼亡”但尚有“德胜才”者
            }
            else
            {
                cd.type = 4; // 及格
            }
            pass++;
        }
        else
        {
            cd.type = 5; // 不及格
        }
        cds.push_back(cd);
    }
    sort(cds.begin(), cds.end(), sortByType);

    // cout << "-----------" << endl;
    cout << pass << endl;
    for (int i = 0; i < total; i++)
    {
        if (cds[i].type != 5)
            cout << cds[i].id << " " << cds[i].morality << " " << cds[i].telent << endl;
    }

    return 0;
}