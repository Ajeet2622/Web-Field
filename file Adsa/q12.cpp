#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;       // Data to store in the node
    Node* next;     // Pointer to the next node
};

// Queue class
class Queue {
private:
    Node* frontNode;   // Pointer to the front node
    Node* rearNode;    // Pointer to the rear node

public:
    // Constructor to initialize an empty queue
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    // Enqueue: Add an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = value;      // Set the data
        newNode->next = nullptr;    // The new node will point to nullptr

        if (rearNode == nullptr) {
            // If the queue is empty, front and rear will both point to the new node
            frontNode = newNode;
            rearNode = newNode;
        } else {
            // Add the new node at the end of the queue and update the rear
            rearNode->next = newNode;
            rearNode = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue: Remove the front element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return -1;
        }

        Node* temp = frontNode;     // Temporary node to store the front node
        int value = temp->data;     // Get the data from the front node
        frontNode = frontNode->next; // Move the front to the next node

        // If front becomes null, set rear to null as well (queue becomes empty)
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp; // Delete the old front node
        cout << "Dequeued: " << value << endl;
        return value;
    }

    // Front: Get the front element of the queue
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element.\n";
            return -1;
        }
        return frontNode->data;
    }

    // isEmpty: Check if the queue is empty
    bool isEmpty() {
        return (frontNode == nullptr);
    }
};

int main() {
    Queue q; // Create a Queue instance

    // Testing queue operations
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element is: " << q.front() << endl;

    q.dequeue();
    cout << "Front element after dequeue is: " << q.front() << endl;

    q.dequeue();
    q.dequeue();

    if (q.isEmpty()) {
        cout << "Queue is empty now.\n";
    }

    return 0;
}
