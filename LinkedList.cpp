//*********************************LINKED LIST*****************************************

// Singly Linked List

// Creating Node 
class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Function for insertion in Node
// Insertion At Head
void insertAtHead(Node* &head, int data){
    Node* toInsert = new Node(data);
    if(head == NULL){
        head = toInsert;
    }
    else{
        toInsert->next = head;
        head = toInsert;
    }
}

// Insertion At Tail
void insertAtTail(Node* &tail, int data){
    Node* toInsert = new Node(data);
    if(tail == NULL){
        tail = toInsert;
    }
    else{
        tail->next = toInsert;
        tail = toInsert;
    }
}

// Insertion At any position
void insertAtPosition(Node* &head, int position, int data){
    Node* toInsert = new Node(data);
    if(position == 1){
        if(head == NULL){
            head = toInsert;
        }
        else{
            toInsert->next = head;
            head = toInsert;
        }
    }
    else{
        position -= 2;
        Node* temp = head;
        while(position--){
            temp = temp->next;
        }
        if(temp->next == NULL){
            temp->next = toInsert;
        }
        else{
            toInsert->next = temp->next;
            temp->next = toInsert;
        }
    }
}

// Deletion Of Node
void deleteNodeAtPosition(Node* &head, int position){
    Node* toDelete; 
    if(position == 1){
        toDelete = head;
        head = head->next;
        delete toDelete;
    }
    else{
        position -=2;
        Node* temp = head;
        while(position--){
            temp = temp->next;
        }
        toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
}

// Printing the Node data
void printNode(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

