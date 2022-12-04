#ifndef __LINKED_LIST__
#define __LINKED_LIST__

namespace ds
{

class Node
{
public:    
    Node(int v) : _val(v), _next(nullptr) { /* empty */ }
    
    int val() { return this->_val; }
    Node* next() { return this->_next; }

    void val(int v) { this->_val = v; }
    void next(Node* const node) { this->_next = node; }
private:
    int _val;
    Node* _next;
};

class LinkedList
{
public:    
    LinkedList() : _head(nullptr), _tail(nullptr) { /* empty */ }

    Node* head() { return this->_head; };
    Node* tail() { return this->_tail; };
    void head(Node* node) { this->_head = node; };
    void tail(Node* node) { this->_tail = node; };
private:
    Node* _head;
    Node* _tail;
};

} // namespace ds


#endif //  __LINKED_LIST__
