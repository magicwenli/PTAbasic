/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-01-31 21:14:47
 * @Description  : 
 * @FilePath     : /PTAbasic/1022.cpp
 */

#include <iostream>
using namespace std;
// ten to any radix below 16
char* itoa(int64_t num,char* str,int radix)
{
    char index[]="0123456789ABCDEF";
    u_int64_t unum;/*中间变量*/
    int i=0,j,k;
    /*确定unum的值*/
    if(radix==10&&num<0)/*十进制负数*/
    {
        unum=(unsigned)-num;
        str[i++]='-';
    }
    else unum=(unsigned)num;/*其他情况*/
    /*转换*/
    do{
        str[i++]=index[unum%(unsigned)radix];
        unum/=radix;
       }while(unum);
    str[i]='\0';
    /*逆序*/
    if(str[0]=='-')
        k=1;/*十进制负数*/
    else
        k=0;
     
    for(j=k;j<=(i-1)/2;j++)
    {       char temp;
        temp=str[j];
        str[j]=str[i-1+k-j];
        str[i-1+k-j]=temp;
    }
    return str;
}

int main()
{
    int64_t a,b;
    int radix;
    cin >> a>>b>>radix;
    char output[1000];
    itoa(a + b, output, radix);
    cout << output;
    return 0;
}