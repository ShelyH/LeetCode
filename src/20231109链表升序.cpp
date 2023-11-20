#include <iostream>
#include <list>

#include "../include/链表.h"
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto p = head;
        int length = 0;
        while (p) {
            ++length;
            p = p->next;
        }
        for (int size = 1; size < length; size <<= 1) {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;

            while (cur) {
                auto left = cur;
                auto right = cut(cur, size);
                cur = cut(right, size);

                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }

    ListNode* cut(ListNode* head, int n) {
        auto p = head;
        while (--n && p) {
            p = p->next;
        }
        if (!p) {
            return nullptr;
        }
        auto next = p->next;
        p->next = nullptr;
        return next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head)
            return NULL;
        int len = 0;
        ListNode *l1 = head, *l2 = head;
        while (l1) {
            l1 = l1->next;
            len++;
        }
        if (len == 1)
            return head;
        int n = len / 2;
        l1 = head;
        while (n) {
            l1 = l2;
            l2 = l2->next;
            n--;
        }
        l1->next = NULL;
        l1 = head;
        l1 = sortList(l1);
        l2 = sortList(l2);
        ListNode* res = NULL;
        if (l1->val < l2->val) {
            res = l1;
            l1 = l1->next;
        } else {
            res = l2;
            l2 = l2->next;
        }
        ListNode* l3 = res;
        while (l1 || l2) {
            if ((!l1) && l2) {
                l3->next = l2;
                l2 = l2->next;
            } else if ((!l2) && l1) {
                l3->next = l1;
                l1 = l1->next;
            } else if (l1->val < l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    // ListNode
    return 0;
}
