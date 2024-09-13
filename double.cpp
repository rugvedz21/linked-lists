#include <iostream>
using namespace std;

class text {
public:
    string data;
    text *next;
    text *prev;
};

void insert(text **head, string data) {
    text *newNode = new text();
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void deleteNode(text **head, string data) {
    text *temp = *head;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            delete temp;
            return; 
        }
        temp = temp->next; 
    }
    cout << "Text not found.\n";
}

void display(text *head) {
    text *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void search(text *head, string data) {
    text *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            cout << "Found\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found\n";
}

void displayReverse(text *head) {
    if (head == NULL) {
        cout << "The list is empty.\n";
        return;
    }
    
    
    text *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    text *head = NULL;
    int choice;
    string data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert text\n";
        cout << "2. Delete text\n";
        cout << "3. Display text\n";
        cout << "4. Search text\n";
        cout << "5. Display text in reverse\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the text to insert: ";
                cin >> data;
                insert(&head, data); 
                break;
            case 2:
                cout << "Enter the text to delete: ";
                cin >> data;
                deleteNode(&head, data); 
                break;
            case 3:
                cout << "Displaying text: ";
                display(head);
                break;
            case 4:
                cout << "Enter the text to search: ";
                cin >> data;
                search(head, data);
                break;
            case 5:
                cout << "Displaying text in reverse: ";
                displayReverse(head);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
