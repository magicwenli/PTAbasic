/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-08 13:58:28
 * @Description  : 1034 有理数四则运算 (20 分)
 * @FilePath     : /PTAbasic/program/1034.cpp
 */

#include <iostream>
using namespace std;

class faction
{
private:
    int child;
    int parent;
public:
    faction(int, int);
    void reduction();            //约分
    void makeCommond(faction &); //通分
    bool operator<(faction &);
    bool operator>(faction &);
    void print(){
        reduction();
        if (this->child<0 && this->parent==1){
            printf("(%d)", child);
        }else if (this->child<0 && this->parent!=1){
            printf("(%d/%d)", child,parent);
        }else if (this->child>0 && this->parent==1){
            printf("%d", child);
        }else if (this->child>0 && this->parent!=1){
            printf("%d/%d", child,parent);
        }else if (this->child==0){
            printf("0");
        }
    }
};

faction::faction(int a, int b)
{
    child = a;
    parent = b;
}

void faction::reduction()
{
    int a, b, tmp;
    if (parent < 0)
    {
        parent *= -1;
        child *= -1;
    }
    a = abs(child);
    b = abs(parent);
    while (a % b) // 求最大公约数
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    parent /= b;
    child /= b;
}

void faction::makeCommond(faction &b)
{
    int tmp;
    reduction();
    b.reduction();
    child *= b.parent; //通分
    b.child *= parent;
    tmp = parent * b.parent;
    parent = b.parent = tmp;
}

bool faction::operator<(faction &b)
{
    makeCommond(b);
    return child < b.child;
}
bool faction::operator>(faction &b)
{
    makeCommond(b);
    return child > b.child;
}


int main()
{
    int num;
    cin >> num;
    


    return 0;
}