/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-02-03 15:29:07
 * @Description  : 1025 反转链表 (25 分)
 * @FilePath     : /PTAbasic/1025.cpp
 */

#include <iostream>
using namespace std;
constexpr int MAXSIZE = 100010;
struct ListNode
{
    int data;
    ListNode *next;
    ListNode *pre;
};

ListNode *flap(int start, int length, ListNode *head)
{
    ListNode *it, *curr, *next;
    int cnt = 0;
    while (cnt < start)
    {
        head = head->next;
        cnt++;
    }

    it = head; //遍历 确定节点pre指针地址
    while (it->next!=nullptr)
    {
        curr = it;
        it = it->next;
        it->pre = curr;
        // cout << "xxxx..Address: " << it << ",Data: " << (*it).data << ",Next: " << (*it).next << ",Pre: " << (*it).pre <<endl;
    }
    cnt = 0; //遍历 将指向上一个的指针和指向下一个的指针互换
    it = head;
    while (cnt++ < length)
    {
        next = it->next;
        it->next = it->pre;
        it->pre = next;
        it = next;
    }
    head->next = it;
    ListNode *newhead = it->pre; //将头指针改为原来的尾指针
    return newhead;
}

int main()
{
    ListNode *base;
    base = (ListNode *)malloc(MAXSIZE * sizeof(ListNode));

    int start, length, K;
    int address, data, next;
    cin >> start >> length >> K;
    for (int i = 0; i < length; i++)
    {
        ListNode *nextNode, *self;
        cin >> address >> data >> next;
        self = base + address;
        if (next == -1)
            nextNode = nullptr;
        else
            nextNode = base + next;
        (*self).data = data;
        (*self).next = nextNode;
        // cout << "......Address: " << self << ",Data: " << (*self).data << ",Next: " << (*self).next << ",Pre: " << (*self).pre <<endl;
    }

    ListNode *head = base + start;

    for (int i = 0; i < (length - (length % 4)); i += K)
    {
        head = flap(i, K, head);
    }

    while (head->next != nullptr)
    {
        int adr = head - base;
        int nextAdr = head->next - base;
        printf("%05d %d %05d\n", adr, head->data, nextAdr);
        head = head->next;
    }
    int adr = head - base;
    printf("%05d %d -1\n", adr, head->data);

    free(base);
    return 0;
}