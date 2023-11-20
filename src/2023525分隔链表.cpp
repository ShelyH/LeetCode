
#include <iostream>
using namespace std;
#include "../include/链表.h"

class Solution {
public:
    void insertList(ListNode* list, int pos, int val)
    {
        if (list == NULL) {
            return;
        }

        ListNode* newnode = new ListNode;
        newnode->val = val;

        ListNode* curnode = list;

        for (int i = 0; i < pos; i++) {
            curnode->next = curnode->next;
        }

        newnode->next = curnode->next;
        curnode->next = newnode;
    }

    ListNode* partition(ListNode* head, int x)
    {
        ListNode* d1 = new ListNode;
        ListNode* d2 = new ListNode;

        ListNode* p1 = d1;
        ListNode* p2 = d2;

        ListNode* p = head;

        while (p != NULL) {
            if (p->val < x) {
                p1->next = p;
                p1 = p1->next;
            }
            else {
                p2->next = p;
                p2 = p2->next;
            }

            ListNode* tmp = p->next;
            p->next = nullptr;
            p = tmp;
        }

        p1->next = d2->next;

        return d1->next;
    }
};

int main()
{
    Solution s;

    ListNode* list = new ListNode;
    s.insertList(list, 0, 5);
    s.insertList(list, 0, 2);
    s.insertList(list, 0, 5);
    s.insertList(list, 0, 3);
    s.insertList(list, 0, 4);
    s.insertList(list, 0, 1);

    s.partition(list, 3);

    while (list != NULL) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;

    system("pause");
    return 0;
}
