#pragma once
#include <iostream>

using namespace std;

class LinkedList { //элементы из прошлой лабораторной работы
private:
    struct Node {
        int val;
        Node* next;

        Node(int value) : val(value), next(nullptr) {}
    };

    Node* last;

public:
    LinkedList() : last(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = last;
        last = newNode;
    }

    int remove() {
        if (isEmpty()) {
            cout << "Список пуст." << endl;
            return 0;
        }
        int value = last->val;
        Node* temp = last;
        last = last->next;
        delete temp;

        return value;
    }

    bool isEmpty() const {
        return last == nullptr;
    }
};

class Stack {
private:
    LinkedList list;

public:
    bool isEmpty() const {
        return list.isEmpty();
    }

    void push(int value) {
        list.push(value);
    }

    int remove() {
        return list.remove();
    }
};