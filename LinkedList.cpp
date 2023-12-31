//*******************************************************LINKED LIST********************************************************

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

// Function for Deletion Of Node
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

// Function for Printing the Linked List
void printLinkedList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}



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
// Insertion At Head in DLL
void insertAtHeadInDLL(Node* &head, int data){
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

// Insertion At Tail In DLL
void insertAtTailInDLL(Node* &tail, int data){
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


// Insertion At any Position in Doubly Linked List
void insertAtPositionInDLL(Node* &head, int position, int data){
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

// Function for Deletion of Node in Doubly Linked List
void deleteNodeAtPositionInDLL(Node* &head, int position){
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

// Function for printing Doubly Linked List
void printDLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}



// Circular Linked List

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

// Function for insertion in Circular Linked List
void insertNodeInCLL(Node* &head, int positionAfterElement, int data){
    Node* toInsert = new Node(data);
    if(head == NULL){
        head = toInsert;
        toInsert->next = toInsert;
    }
    else{
        Node* temp = head;
        while(temp->data != positionAfterElement){
            temp = temp->next;
        }
        toInsert->next = temp->next;
        temp->next = toInsert;
    }
}

// Function for Deletion of Node in Circular Linked List
void deleteNodeInCLL(Node* &head, int value){
    Node* temp = head;
    while(temp->next->data != value){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if(head == toDelete){
        head = temp;
    }
    delete toDelete;
}

// Function for printing Circular Linked List
void printCLL(Node* &head){
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}
