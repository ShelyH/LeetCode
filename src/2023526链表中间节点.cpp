
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

    ListNode* findNthFromEnd(ListNode* head, int n)
    {
        ListNode* h1 = head;

        for (int i = 0; i < n; i++) {
            h1 = h1->next;
        }

        ListNode* h2 = head;

        while (h1 != NULL) {
            h2 = h2->next;
            h1 = h1->next;
        }

        return h2;
    }

    ListNode* middleNode(ListNode* head)
    {
        ListNode* p = head;
        ListNode* q = head;
        while (q != NULL && q->next != NULL) {
            q = q->next->next;
            p = p->next;
        }
        return p;
    }
};

int main()
{
    Solution s;

    ListNode* list = new ListNode;
    s.insertList(list, 0, 1);
    s.insertList(list, 0, 3);
    s.insertList(list, 0, 2);
    s.insertList(list, 0, 1);
    s.insertList(list, 0, 4);
    s.insertList(list, 0, 5);
    s.insertList(list, 0, 4);
    s.insertList(list, 0, 7);
    s.insertList(list, 0, 7);
    s.insertList(list, 0, 9);

    ListNode* p1 = list;
    while (p1 != NULL) {
        cout << p1->val << " ";
        p1 = p1->next;
    }
    cout << endl;
    ListNode* l = s.middleNode(list);

    while (l != NULL) {
        cout << l->val << " ";
        l = l->next;
    }

    system("pause");
    return 0;
}
