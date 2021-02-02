/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-03 00:10:44
 * @Description  : 
 * @FilePath     : /PTAbasic/1024.cpp
 */

#include <iostream>
#include <regex>
using namespace std;

int main()
{
    string sciNotation;
    cin >> sciNotation;
    regex baseAndIndex("^([\+\-])([0-9])\.([0-9]*)E([\+\-])([0-9]*)$");
    smatch result;
    regex_search(sciNotation, result, baseAndIndex);
    // for (int i = 0; i < result.size(); ++i)
    // {
    //     cout << "result.str(" << i << "): " << result.str(i) << endl;
    // }
    // result.str(0): +1.23400E-03
    // result.str(1): +
    // result.str(2): 1
    // result.str(3): 23400
    // result.str(4): -
    // result.str(5): 03
    const string baseBeforeDot = result.str(2);
    const string baseAfterDot = result.str(3);
    const string index = result.str(5);
    string sign;
    if (result.str(1) == "+")
        sign = "";
    else
        sign = "-";
    size_t sizeOfBAD = baseAfterDot.size();
    size_t valueOfIndex = stoi(index);
    if (result.str(4) == "-")
    {
        if (valueOfIndex == 0)
        {
            cout << sign << result.str(2) << "." << result.str(3);
        }
        else
        {
            cout << sign << "0.";
            for (size_t i = 0; i < valueOfIndex - 1; i++)
            {
                cout << "0";
            }
            cout << baseBeforeDot << baseAfterDot;
        }
    }
    else
    {
        if (valueOfIndex == 0)
        {
            cout << sign << baseBeforeDot << "." << baseAfterDot;
        }
        else
        {
            cout << sign << baseBeforeDot;
            size_t i, cnt;
            for (i = 0, cnt = 0; i < sizeOfBAD && cnt < valueOfIndex; i++, cnt++)
            {
                if (baseBeforeDot != "0" || baseAfterDot[i] != '0')
                    cout << baseAfterDot[i];
            }
            if (i == sizeOfBAD)
            {
                for (size_t j = 0; j < valueOfIndex - cnt; j++)
                    cout << '0';
            }
            else
            {
                cout << ".";
                for (size_t j = i; j < sizeOfBAD; j++)
                    cout << baseAfterDot[j];
            }
        }
    }
    return 0;
}