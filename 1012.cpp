/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-18 20:03:38
 * @Description  : 
 * @FilePath     : /PTAbasic/1012.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num, tmp;
    int save[5]{};
    bool plusMinus = 0, ae[5]{}; // a enable
    int sum3 = 0;
    cin >> num;

    while (cin >> tmp)
    {
        switch (tmp % 5)
        {
        case 0:
            if (!(tmp & 1))
            {
                ae[0] = 1;
                save[0] += tmp;
            }
            break;
        case 1:
            ae[1] = 1;
            plusMinus ? save[1] -= tmp : save[1] += tmp;
            plusMinus = !plusMinus;
            break;
        case 2:
            ae[2] = 1;
            save[2]++;
            break;
        case 3:
            ae[3] = 1;
            sum3 += tmp;
            save[3]++;
            break;
        case 4:
            if (tmp > save[4])
            {
                save[4] = tmp;
                ae[4] = 1;
            }
            break;
        default:
            break;
        }
    }
    float save3 = (float)sum3 / save[3];
    for (int i = 0; i < 5; i++)
    {
        if (!ae[i])
            cout << "N";
        else if (i == 3)
            printf("%.1f", save3);
        else
            cout << save[i];

        if (i != 4)
            cout << " ";
    }

    // printf("%d %d %d %.1f %d", save[0], save[1], save[2], save3, save[4]);
    return 0;
}