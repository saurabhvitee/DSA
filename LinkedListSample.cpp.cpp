#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        // Constructor
        Node(int val) {
            data = val;
            next = nullptr;
            prev = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() {
            head = nullptr;
        }

        // Function to insert at end
        void insertAtEnd(int val) {
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
                return;
            }

            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;

            // addition for Doubly linkedList 
            newNode->prev = temp;
        }

        // Function to forward display the linked list
        void displayForward() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }

        // Function to insert at Middle 
        void insertAtJustAfterHead(int val){
            Node* newNode = new Node(val);

            newNode->next = head->next;
            head->next->prev = newNode;
            newNode->prev = head;
            head->next = newNode;
        }

        // Function to insert at Start
        void insertAtStart(int val){
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
                return;
            }

            head->prev = newNode;
            newNode->next = head;

            head = newNode;

        }
};


int main() {
    LinkedList list;
    int n, val;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        list.insertAtStart(val);
    }

    list.insertAtJustAfterHead(11);
    list.insertAtStart(0);

    cout << "Linked List: ";
    list.displayForward();

    return 0;
}
