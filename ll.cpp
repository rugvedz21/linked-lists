#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node *next;
};

class LinkedList {
public:
    Node *head;

    LinkedList() {
        head = NULL;
    }

    void insertAtBegin(string data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(string data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtPosition(string data, int pos) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node *temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteByValue(string data) {
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL) {
            if (temp->data == data) {
                if (temp == head) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Song not found!" << endl;
    }

    void printList() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList playlist;
    int choice;
    string song;
    int position;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add song at beginning\n";
        cout << "2. Add song at end\n";
        cout << "3. Add song at position\n";
        cout << "4. Delete song by name\n";
        cout << "5. Display playlist\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the song to add at the beginning: ";
                cin >> song;
                playlist.insertAtBegin(song);
                break;

            case 2:
                cout << "Enter the song to add at the end: ";
                cin >> song;
                playlist.insertAtEnd(song);
                break;

            case 3:
                cout << "Enter the position to add the song: ";
                cin >> position;
                cout << "Enter the song: ";
                cin >> song;
                playlist.insertAtPosition(song, position);
                break;

            case 4:
                cout << "Enter the song to delete: ";
                cin >> song;
                playlist.deleteByValue(song);
                break;

            case 5:
                cout << "Displaying playlist:\n";
                playlist.printList();
                break;

            case 6:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 6);
    return 0;
}

