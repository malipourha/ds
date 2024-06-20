#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int val, Node* nextNode = nullptr) : value(val), next(nextNode) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* node = new Node(value, head);
        if (head == nullptr) {
            head = node;
            head->next = node;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    void deleteHead() {
        Node* deletedNode = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
        }
        delete deletedNode;
    }

    void deleteNode(int value) {
        if (head) {
            if (head->value == value) {
                deleteHead();
                return;
            } else {
                Node* temp = head->next;
                Node* prev = head;
                while (temp != head) {
                    if (temp->value == value) {
                        prev->next = temp->next;
                        delete temp;
                        return;
                    } else {
                        prev = temp;
                        temp = temp->next;
                    }
                }
            }
        }
        
    }

    void traverse() {
        if (head) {
            Node* temp = head;
            do {
                std::cout << temp->value << "\t";
                temp = temp->next;
            } while (temp != head);
            std::cout << std::endl;
        }
    }

    bool isLastNode() {
        return head && (head->next == head);
    }
};

Node* getKthNode(Node* start, int k) {
    Node* temp = start;
    for (int i = 1; i < k; ++i) {
        temp = temp->next;
    }
    return temp;
}

CircularLinkedList initializeLinkedList(int n) {
    CircularLinkedList ll;
    for (int i = 0; i < n; ++i) {
        ll.insert(i);
    }
    return ll;
}

int josephusProblem(int n, int k) {
    CircularLinkedList ll = initializeLinkedList(n);
    if (ll.head == nullptr) {
        return -1;  
    }
    Node* start = ll.head;
    while (!ll.isLastNode()) {
        Node* kNode = getKthNode(start, k);
        start = kNode->next;
        ll.deleteNode(kNode->value);
    }
    return start->value;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, k;
        std::cin >> n >> k;

        int lastPersonIndex = josephusProblem(n, k + 1);
        std::cout <<  lastPersonIndex + 1 << std::endl;
    }

    return 0;
}
