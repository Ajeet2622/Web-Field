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

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* l1, Node* l2) {
    // Create a dummy node to act as the start of the merged list
    Node* dummy = new Node(0);
    Node* tail = dummy;  // Pointer to the last node in the merged list

    // Traverse both lists and merge them
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data <= l2->data) {
            tail->next = l1;  // Append the smaller node (l1)
            l1 = l1->next;    // Move l1 forward
        } else {
            tail->next = l2;  // Append the smaller node (l2)
            l2 = l2->next;    // Move l2 forward
        }
        tail = tail->next;    // Move the tail pointer forward
    }

    // Append the remaining nodes of the non-empty list
    if (l1 != nullptr) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    // Return the merged list starting from the next of dummy (since dummy is a placeholder)
    return dummy->next;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
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
    Node* l1 = nullptr;
    Node* l2 = nullptr;

    // Creating first sorted linked list: 1 -> 3 -> 5
    append(l1, 1);
    append(l1, 3);
    append(l1, 5);
    append(l1, 7);

    // Creating second sorted linked list: 2 -> 4 -> 6
    append(l2, 2);
    append(l2, 4);
    append(l2, 6);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    // Merge the two sorted linked lists
    Node* mergedList = mergeSortedLists(l1, l2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
