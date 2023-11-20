#include <iostream>
using namespace std;
#include <vector>

#include "../include/链表.h"

class Solution {
public:
    ListNode* createLinkList(vector<int>& values) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for (int value : values) {
            ListNode* newNode = new ListNode(value);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            // head = head->next;
        }
        return head;
    }

    void printLinkList(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << "null" << endl;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) {
            slow = slow->next;
        }

        ListNode* left = head;

        ListNode* right = reverse(slow);
        while (right != nullptr) {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<int> val = {3};

    ListNode* list = s.createLinkList(val);
    // ListNode* newhead = new ListNode;
    // newhead = list;
    // s.printLinkList(list);

    // ListNode* last = s.reverse(list);
    // s.printLinkList(newhead);
    bool res = s.isPalindrome(list);
    cout << res << endl;
    system("pause");
    return 0;
}
