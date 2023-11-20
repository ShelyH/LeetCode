
#include <iostream>
#include <list>

#include "../include/链表.h"
using namespace std;

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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* tmp = new ListNode();
        ListNode* p = tmp;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val > list2->val) {
                p->next = list2;
                list2 = list2->next;
            }
            else {
                p->next = list1;
                list1 = list1->next;
            }
            p = p->next;
        }

        if (list1 != NULL) {
            p->next = list1;
        }
        if (list2 != NULL) {
            p->next = list2;
        }

        return tmp->next;
    }
};

int main()
{
    Solution s;

    ListNode* list1 = new ListNode();
    ListNode* list2 = new ListNode();
    s.insertList(list1, 0, 3);
    s.insertList(list1, 0, 2);
    s.insertList(list1, 0, 1);

    s.insertList(list2, 0, 5);
    s.insertList(list2, 0, 4);
    s.insertList(list2, 0, 3);

    ListNode* l = s.mergeTwoLists(list1, list2);

    while (l != NULL) {
        cout << l->val << " ";
        l = l->next;
    }

    system("pause");
    return 0;
}
