
#include <iostream>
#include <vector>

#include "../include/链表.h"
using namespace std;

class Solution {
public:
    // 创建链表
    ListNode* cteateListNode(vector<int> values)
    {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for (int value : values) {
            ListNode* newNode = new ListNode(value);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        return head;
    }

    // 删除重复项
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* low = head;
        ListNode* fast = head->next;
        while (fast) {
            if (fast->val == low->val) {
                low->next = fast->next;
                low = low->next;
            }
            fast = fast->next;
        }
        return head;
    }
};

// int main()
//{
//	vector<int> values = { 1,1,2 };
//
//
//	Solution s;
//	ListNode* list = s.cteateListNode(values);
//	s.deleteDuplicates(list);
//
//	system("pause");
//	return 0;
// }
