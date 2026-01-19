#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class LinkedList {
public:
    Node<T>* head;
    LinkedList() : head(nullptr) {}

    void add(T item) {
        Node<T>* newNode = new Node<T>;
        newNode->data = item;
        newNode->next = head;
        head = newNode;
    }

    // Ismein aur functions (remove, find) hum Day 3 par add karenge
};

#endif