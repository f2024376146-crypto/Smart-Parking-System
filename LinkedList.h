#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
public:
    Node<T>* head;
    LinkedList() : head(nullptr) {}

    // To Add new Data
    void add(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    // To search Slot from ID
    Node<T>* search(int id) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data.slotID == id) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    //To remove slot from id
    void remove(int id) {
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        if (temp != nullptr && temp->data.slotID == id) {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->data.slotID != id) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return;
        prev->next = temp->next;
        delete temp;
    }
};
#endif