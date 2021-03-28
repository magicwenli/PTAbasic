/*
 * @Author       : magicwenli
 * @Date         : 2021-01-16 11:16:21
 * @LastEditTime : 2021-03-28 10:34:17
 * @Description  : 1025 反转链表 (25 分)
 * @FilePath     : /PTAbasic/program/1025_.cpp
 */

#include <iostream>
using namespace std;
constexpr int MAXSIZE = 100010;
struct ListNode {
    int data;
    ListNode *next;
};

// 迭代反转法 http://c.biancheng.net/view/8105.html
ListNode *reverse(ListNode *head, ListNode *next_head) {
    // 判断链表是否为空
    if (head == nullptr || head->next == nullptr) {
        return head;
    } else {
        ListNode *beg = next_head;
        ListNode *mid = head;
        ListNode *end = head->next;
        while (1) {
            mid->next = beg;
            if (end == next_head) {
                break;
            }
            beg = mid;
            mid = end;
            end = end->next;
        }
        head = mid;
        return head;
    }
}

ListNode *NextN(ListNode *head, int n) {
    ListNode *new_head = head;
    for (int i = 0; i < n; i++) {
        new_head = new_head->next;
    }
    return new_head;
}

int main() {
    ListNode *base;
    base = (ListNode *)malloc(MAXSIZE * sizeof(ListNode));

    int start, length, K;
    int address, data, next;
    cin >> start >> length >> K;
    for (int i = 0; i < length; i++) {
        ListNode *nextNode, *self;
        cin >> address >> data >> next;
        self = base + address;
        if (next == -1)
            nextNode = nullptr;
        else
            nextNode = base + next;
        (*self).data = data;
        (*self).next = nextNode;
        // cout << "......Address: " << self << ",Data: " << (*self).data <<
        // ",Next: " << (*self).next << ",Pre: " << (*self).pre <<endl;
    }

    ListNode *head = base + start;
    ListNode *new_head;
    for (int i = 0; i < (length - (length % K)); i += K) {
        ListNode *beg_head = NextN(head, i);
        ListNode *next_head = NextN(beg_head, K);
        new_head=reverse(beg_head, next_head);
    }

    head = new_head;

    while (head->next != nullptr) {
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