#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *pre;
};

node *head = nullptr;

void insert(int n) {
    node *newnode = new node;
    newnode->data = n;
    newnode->next = head;
    newnode->pre = NULL;
    if (head != NULL) {
        head->pre = newnode;
    }
    head = newnode;
}

void print() {
    cout << "Data elements: " << endl;
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void insertAtEnd(int n) {
    node *newnode = new node;
    newnode->data = n;
    newnode->next = NULL;
    newnode->pre = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->pre = temp;
}

void insertAtPos(int pos, int n) {
    node *newnode = new node;
    newnode->data = n;

    if (pos == 1) {
        newnode->next = head;
        newnode->pre = NULL;
        if (head != NULL) {
            head->pre = newnode;
        }
        head = newnode;
        return;
    }

    node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position " << pos << " does not exist" << endl;
        return;
    }

    newnode->next = temp->next;
    newnode->pre = temp;

    if (temp->next != NULL) {
        temp->next->pre = newnode;
    }

    temp->next = newnode;
}
bool search(int n) {
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == n) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}


void deleteAtBeg() {
    if (head == NULL) {
        cout << "Double linked list is empty";
        return;
    }

    node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->pre = NULL;
    }
    delete temp;
}

void deleteAtEnd() {
    if (head == NULL) {
        cout << "Double linked list is empty";
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->pre != NULL) {
        temp->pre->next = NULL;
    } else {
        head = NULL;
    }
    delete temp;
}

void deleteAtPos(int pos) {
    if (head == NULL) {
        cout << "Double linked list is empty";
        return;
    }

    node *temp = head;
    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->pre = NULL;
        }
        delete temp;
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position " << pos << " does not exist";
        return;
    }

    if (temp->next != NULL) {
        temp->next->pre = temp->pre;
    }

    if (temp->pre != NULL) {
        temp->pre->next = temp->next;
    }

    delete temp;
}


int main() {
    insert(10);
    insert(9);
    insert(8);
    insert(7);
    insertAtEnd(12);
    insertAtPos(3, 15);
    print();
    
    int valueToSearch = 15;
    if (search(valueToSearch)) {
        cout << "Value " << valueToSearch << " found in the list." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the list." << endl;
    }

    return 0;
}
