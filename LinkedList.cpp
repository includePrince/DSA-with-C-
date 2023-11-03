#include<iostream>
using namespace std;

// Doubley Linked List

// Creating Node
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

//
