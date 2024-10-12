#include <iostream>
using namespace std;

// Definition of a node in a singly linked list
struct Node {
    int data;
    Node* next;

    // Constructor to create a new node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to reverse a singly linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;  // Initialize prev as nullptr
    Node* curr = head;     // Start with the head of the list
    Node* next = nullptr;  // To store the next node temporarily

    while (curr != nullptr) {
        next = curr->next;  // Store the next node
        curr->next = prev;  // Reverse the current node's next pointer
        prev = curr;        // Move prev to the current node
        curr = next;        // Move to the next node
    }

    // After the loop, prev will point to the new head
    return prev;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to append a new node to the end of the list
void append(Node*& head, int new_data) {
    Node* new_node = new Node(new_data);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    Node* last = head;
    while (last->next != nullptr)
        last = last->next;
    last->next = new_node;
}

int main() {
    Node* head = nullptr;

    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    cout << "Original list: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
