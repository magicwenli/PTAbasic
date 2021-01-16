/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-16 14:06:23
 * @Description  : 
 * @FilePath     : \PTAbasic\1005.cpp
 */

#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

void getChain(size_t number, vector<size_t> chain)
{
    chain.push_back(number);

    while (number - 1)
    {
        if (number & 1)
        {
            number = 3 * number + 1;
        }
        else
        {
            number /= 2;
        }
        chain.push_back(number);
        }

    return;
}

bool check(size_t num, vector<size_t> chain)
{
    vector<size_t>::iterator it;
    it = find(chain.begin(), chain.end(), num);
    if (it != chain.end())
        return true;
    else
        return false;
}

int main()
{
    size_t num;
    vector<size_t> numbers(100,0);
    vector<vector<size_t>> curr;

    cin >> num;
    for (size_t i = 0; i < num; i++)
    {
        cin >> numbers[i];
    }

    vector<size_t> tmp1(100,0);
    getChain(numbers[0], tmp1);
    curr.push_back(tmp1);
    for (size_t i = 1; i < num; i++)
    {
        for (size_t j = 0; j < sizeof(curr); j++)
        {
            if (check(numbers[i],curr[j]))
            {
                ;
            }else
            {
                vector<size_t> tmp2(100,0);
                getChain(numbers[i], tmp2);
                if (check(curr[j][0],tmp2))
                {
                    curr[j] = tmp2;
                }else
                {
                    curr.push_back(tmp2);
                }
            }
        }
    }

    for (size_t i = 0; i < sizeof(curr); i++)
    {
        cout << curr[i][0] << ' ';
    }
    
    

    return 0;
}