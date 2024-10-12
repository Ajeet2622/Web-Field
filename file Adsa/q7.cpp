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

// Function to find the middle element of the linked list
Node* findMiddle(Node* head) {
    if (head == nullptr) {
        return nullptr;  // If the list is empty, return nullptr
    }

    Node* slow = head;
    Node* fast = head;

    // Move slow by one step and fast by two steps
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // Move slow by one step
        fast = fast->next->next;     // Move fast by two steps
    }

    // When fast reaches the end, slow will be at the middle
    return slow;
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
    append(head, 34);
    append(head, 4);
    append(head, 5);
    append(head, 5);

    // Find the middle element
    Node* middle = findMiddle(head);

    if (middle != nullptr) {
        cout << "The middle element is: " << middle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
