

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

// Function for insertion in Linked List
// Insertion At Head
void insertAtHead(Node* &head, int data){
    Node* toInsert = new Node(data);
    if(head == NULL){
        head == toInsert;
    }
    else{
        toInsert->next = head;
        head->prev = toInsert;
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
        toInsert->prev = tail;
        tail->next = toInsert;
        tail = toInsert;
    }
}


// Insertion At any Position
void insertAtPosition(Node* &head, int position, int data){
    Node* toInsert = new Node(data);
    if(position == 1){
        if(head == NULL){
            head = toInsert;
        }
        else{
            toInsert->next = head;
            head->prev = toInsert;
            head = toInsert;
        }
    }
    else{
        position -=2;
        Node* temp = head;
        while(position--){
            temp = temp->next;
        }
        if(temp->next == NULL){
            temp->next = toInsert;
            toInsert->prev = temp;
        }
        else{
            toInsert->next = temp->next;
            toInsert->prev = temp;
            temp->next = toInsert;
        }
    }
}

// Function for Deletion of Node
void deleteNodeAtPosition(Node* &head, int position){
    Node* toDelete;
    if(position == 1){
        toDelete = head;
        head = toDelete->next;
        head->prev = NULL;
        delete toDelete;
    }
    else{
        position -= 2;
        Node* temp = head;
        while(position--){
            temp = temp->next;
        }
        toDelete = temp->next;
        temp->next = toDelete->next;
        toDelete->next->prev = temp;
        delete toDelete;
    }
}

// Function for printing Linked List
void printLinkedList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
