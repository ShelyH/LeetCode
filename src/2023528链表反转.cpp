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
        }
        return head;
    }

    void printLinkList(ListNode* head) {
        ListNode* cur = head;
        while (cur) {
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << "null" << endl;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return last;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* pre = head;
        ListNode* cur = head->next;

        for (int i = 1; i < left; i++) {
            before = pre;
            pre = cur;
            cur = cur->next;
        }

        while (cur != nullptr && left <= right) {
            left++;
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }

        before->next->next = cur;
        before->next = pre;
        return dummy->next;
    }
};

int main() {
    vector<int> values = {1, 2, 3, 4, 5};

    Solution s;
    ListNode* head = s.createLinkList(values);
    s.printLinkList(head);
    cout << "---------------" << endl;
    // ListNode* newHead = s.reverseBetween(head, 1, 6);
    ListNode* reversehead = s.reverseList(head);
    s.printLinkList(reversehead);

    system("pause");
    return 0;
}
