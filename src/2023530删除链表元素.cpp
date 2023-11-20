
#include <iostream>
using namespace std;
#include <vector>

#include "../include/链表.h"

class Solution {
public:
    ListNode* cteateListNode(vector<int> values) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for (int value : values) {
            ListNode* newNode = new ListNode(value);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        return head;
    }

    ListNode* deleteListNode(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        if (!head) {
            return head;
        }

        ListNode* low = head;
        ListNode* fast = head->next;
        while (fast) {
            if (fast->val == val) {
                low->next = fast->next;
                fast = fast->next;
            } else {
                low = low->next;
                fast = fast->next;
            }
        }

        return head;
    }

    void ptintList(ListNode* head) {
        while (head) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    vector<int> values = {1, 5, 2, 3, 4, 5, 5, 5};

    Solution s;
    ListNode* list = s.cteateListNode(values);
    s.ptintList(list);
    ListNode* newHead = s.deleteListNode(list, 5);
    cout << "-------------------" << endl;
    s.ptintList(newHead);

    system("pause");
    return 0;
}
