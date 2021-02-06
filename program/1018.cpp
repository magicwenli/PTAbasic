/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-21 15:14:44
 * @Description  : 
 * @FilePath     : /PTAbasic/1018.cpp
 */

#include <iostream>
using namespace std;
struct status
{
    int win_gestures[3]{};
    int win_even_loses[3]{};
};

short judge(char a, char b)
{
    if (a == 'C' && b == 'J')
        return 1;
    else if (a == 'C' && b == 'B')
        return 2;
    else if (a == 'J' && b == 'C')
        return 2;
    else if (a == 'J' && b == 'B')
        return 1;
    else if (a == 'B' && b == 'C')
        return 1;
    else if (a == 'B' && b == 'J')
        return 2;
    else
        return 0;
}

int getGesture(char a)
{
    if (a == 'B')
        return 0;
    else if (a == 'C')
        return 1;
    else
        return 2;
}

char Compare(int cntB, int cntC, int cntJ) //比较各赢的手势次数
{
    if (cntB >= cntJ && cntB >= cntC)
        return 'B';
    else if (cntC > cntB && cntC >= cntJ)
        return 'C';
    else
        return 'J';
}

int main()
{
    int num;
    status A, B;
    char ga, gb;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> ga >> gb;
        switch (judge(ga, gb)) // 0:equal 1:A win 2:B win
        {
        case 0:
            A.win_even_loses[1]++;
            B.win_even_loses[1]++;
            break;
        case 1:
            A.win_even_loses[0]++;
            B.win_even_loses[2]++;
            A.win_gestures[getGesture(ga)]++; // B,C,J
            break;
        case 2:
            A.win_even_loses[2]++;
            B.win_even_loses[0]++;
            B.win_gestures[getGesture(gb)]++; // B,C,J
            break;
        default:
            break;
        }
    }

    cout << A.win_even_loses[0] << " " << A.win_even_loses[1] << " " << A.win_even_loses[2] << endl;
    cout << B.win_even_loses[0] << " " << B.win_even_loses[1] << " " << B.win_even_loses[2] << endl;

    cout << Compare(A.win_gestures[0], A.win_gestures[1], A.win_gestures[2]) << " " << Compare(B.win_gestures[0], B.win_gestures[1], B.win_gestures[2]);

    return 0;
}