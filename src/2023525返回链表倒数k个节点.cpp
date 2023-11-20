
#include <iostream>
using namespace std;
#include <vector>

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
        // curnode->next = newnode;
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

        // ListNode* newnode = new ListNode;
        // newnode = head;
        while (h1 != NULL) {
            h2 = h2->next;
            h1 = h1->next;
        }

        return h2;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* tmp = new ListNode;
        tmp->next = head;
        ListNode* node = findNthFromEnd(tmp, n + 1);
        node->next = node->next->next;

        return tmp->next;
    }
};

int main()
{
    Solution s;

    ListNode* list1 = new ListNode();
    s.insertList(list1, 0, 3);
    s.insertList(list1, 0, 2);
    // s.insertList(list1, 0, 1);
    // s.insertList(list1, 0, 4);
    // while (list1 != NULL) {
    //	cout << list1->val << " ";
    //	list1 = list1->next;
    // }
    // cout << endl;
    ListNode* l = s.removeNthFromEnd(list1, 1);
    while (l != NULL) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
    system("pause");
    return 0;
}
