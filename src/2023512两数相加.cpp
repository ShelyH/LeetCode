#include <iostream>

#include "../include/链表.h"
#include "vector"
using namespace std;

class Solution {
public:
    ListNode *createList(const vector<int> &v)
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        for (int i = 0; i < v.size(); i++) {
            ListNode *node = new ListNode(v[i]);
            if (head == nullptr) {
                head = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }

        return head;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        int t = 0;

        while (l1 || l2 || t) {
            if (l1) {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                t += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(t % 10);
            cur = cur->next;
            t /= 10;
        }

        return dummy->next;
    }
};

int main()
{
    vector<int> v1 = {9, 9, 9};
    vector<int> v2 = {9, 9};

    Solution s;
    ListNode *l1 = s.createList(v1);
    ListNode *l2 = s.createList(v2);

    ListNode *sum = s.addTwoNumbers(l1, l2);
    // cout << sum->val << endl;
    while (sum) {
        cout << sum->val << " ";
        sum = sum->next;
    }
    cout << " " << endl;
}