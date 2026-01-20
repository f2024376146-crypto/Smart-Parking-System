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
    
    Node<T>* search(int id) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data.slotID == id) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    
    void remove(int id) {
        if (head == nullptr) return;

        
        if (head->data.slotID == id) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current != nullptr && current->data.slotID != id) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) return; 

        previous->next = current->next;
        delete current;
    }

    
};

#endif