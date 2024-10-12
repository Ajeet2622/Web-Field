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

// Function to detect if a cycle exists in the linked list
bool detectCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;  // Empty list or list with a single element can't have a cycle
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // Move slow by one step
        fast = fast->next->next;     // Move fast by two steps

        if (slow == fast) {
            return true;  // Cycle detected
        }
    }

    return false;  // No cycle found
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

    // Creating a cycle for testing: 5 -> 2
    head->next->next->next->next->next = head->next;

    // Detect if the linked list has a cycle
    if (detectCycle(head)) {
        cout << "Cycle detected in the linked list" << endl;
    } else {
        cout << "No cycle in the linked list" << endl;
    }

    return 0;
}
