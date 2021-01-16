/*
 * @Author       : magicwenli
 * @Date         : 2021-01-15 20:23:34
 * @LastEditTime : 2021-01-16 11:12:30
 * @Description  : 1002
 */


#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str_in[101]{};
    char py[][10]={ "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
    cin >> str_in;
     
    int sumi=0;
    for (size_t i = 0; i < strlen(str_in); i++)
    {
        sumi += str_in[i] - '0';
    }

    int z[20]{};
    int index = sumi % 10;
    z[1] = index;
    z[0]++;
    while(sumi/10!=0){
        sumi /= 10;
        index = sumi % 10;
        z[z[0]+1] = index;
        z[0]++;
    }

    cout << py[z[z[0]]];
    z[0]--;
    while (z[0]!=0){
		cout << " " << py[z[z[0]]];
        z[0]--;
    }
	cout << endl;

    return 0;
}