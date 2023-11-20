
#include <iostream>
#include <unordered_map>
using namespace std;

// 节点类
class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k, int v)
    {
        this->key = k;
        this->value = v;
    }
};

// 双链表
class DoubleList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    // 初始化
    DoubleList()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // 添加节点
    void addLast(Node* x)
    {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }

    // 删除节点
    void remove(Node* x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }

    // 删除链表第一个节点
    Node* removeFirst()
    {
        if (head->next == tail) {
            return nullptr;
        }
        Node* first = head->next;
        remove(first);

        return first;
    }

    // 返回链表长度
    int getsize()
    {
        return size;
    }
};

class LRUCache {
    unordered_map<int, Node*> map;
    DoubleList cache;
    int cap;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }
};

int main()
{
    system("pause");
    return 0;
}
