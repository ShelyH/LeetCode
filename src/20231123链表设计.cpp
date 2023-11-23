#include <iostream>

#include "../include/链表.h"
using namespace std;
class MyLinkedList {
public:
    ListNode* _dummyHead;
    int _size;
    MyLinkedList() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }

    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }

        ListNode* cur = _dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead;
        _dummyHead->next = newNode;
        _size++;
    }

    void addAtTail(int val) {
        ListNode* tailNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = tailNode;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size) {
            return;
        }
        if (index < 0) {
            index = 0;
        }
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        ListNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
    }
};

int main(int argc, char const* argv[]) {
    int index = 1;
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(index);
    cout << param_1 << endl;
    // obj->addAtHead(val);
    // obj->addAtTail(val);
    // obj->addAtIndex(index, val);
    // obj->deleteAtIndex(index);
    return 0;
}
