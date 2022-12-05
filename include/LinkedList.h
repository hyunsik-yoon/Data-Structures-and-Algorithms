#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <cassert>
#include <stdexcept>

namespace ds
{

template <typename T>
class Node
{
public:    
    Node(const T& v) : _val(v), _next(nullptr) { /* empty */ }
    
    const T& val() { return this->_val; }
    Node* next() { return this->_next; }

    void val(const T& v) { this->_val = v; }
    void next(Node* const node) { this->_next = node; }
private:
    T _val;
    Node* _next;
};

template <typename T>
class LinkedList
{
public:    
    LinkedList() : _head(nullptr), _tail(nullptr) { /* empty */ }
    ~LinkedList() 
    {
        auto node_to_delete = _head;
        while (node_to_delete != nullptr)
        {
            auto next_node = node_to_delete->next();
            delete node_to_delete;

            node_to_delete = next_node;
        }
    }

    Node<T>* head() { return this->_head; };
    Node<T>* tail() { return this->_tail; };
    void head(Node<T>* node) { this->_head = node; };
    void tail(Node<T>* node) { this->_tail = node; };

    void append(const T& item)
    {
        if (_head == nullptr) 
        {
            assert(_tail == nullptr);

            auto node = new Node<T>(item);
            _head = _tail = node;
        }
        else 
        {
            auto node = new Node<T>(item);
            _tail->next(node);
            _tail = node;
        }
    }

    void insert_head(const T& item)
    {
        if (_head == nullptr) 
        {
            assert(_tail == nullptr);

            auto node = new Node<T>(item);
            _head = _tail = node;
        }
        else 
        {
            auto node = new Node<T>(item);
            node->next(_head);
            _head = node;
        }
    }

    bool is_empty()
    {
        return (_head == nullptr);
    }

    // Call This after checking is_empty()
    const T remove_head()
    {
        if (_head ==  nullptr)
        {
            throw std::runtime_error("LinkedList is already empty.");
        }
        else if (_head == _tail)
        {
            // When only 1 Node in LinkedList
            auto old_head = _head;
            T ret = old_head->val();

            _head = _tail = nullptr;
            delete old_head;

            return ret;
        }
        else
        {
            // More than 1 Nodes in LinkedList
            auto old_head = _head;
            T ret = old_head->val();

            _head = _head->next();
            delete old_head;
            
            return ret;
        }
    }

private:
    Node<T>* _head;
    Node<T>* _tail;
};

} // namespace ds


#endif //  __LINKED_LIST__
