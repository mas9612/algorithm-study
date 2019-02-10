#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* next;
};

Node* create()
{
    Node* head = new Node;
    head->next = NULL;
    return head;
}

void destroy(Node* list)
{
    Node* current = list;
    Node* tmp;

    while (current != NULL) {
        tmp = current->next;
        delete current;
        current = tmp;
    }
}

void insert(Node** head, int index, int value)
{
    Node* node = new Node;
    node->value = value;
    node->next = NULL;

    if (index == 0) {
        Node* tmp = *head;
        *head = node;
        node->next = tmp;
    } else {
        Node* previous = *head;
        Node* current = previous->next;
        int i = 1;
        while ((i < index) && (current != NULL)) {
            previous = current;
            current = current->next;
            ++i;
        }
        previous->next = node;
        node->next = current;
    }
}

void remove(Node** head, int index)
{
    if (index == 0) {
        Node* tmp = *head;
        *head = tmp->next;
        delete tmp;
    } else {
        Node* previous = *head;
        Node* current = previous->next;
        int i = 1;
        while ((i < index) && (current != NULL)) {
            previous = current;
            current = current->next;
            ++i;
        }
        previous->next = current->next;
        delete current;
    }
}

void print_list(Node* head)
{
    Node* current = head;
    while (current != NULL) {
        cout << current->value << ' ';
        current = current->next;
    }
    cout << '\n';
}

int main()
{
    Node* head = create();
    print_list(head);

    insert(&head, 0, 10);
    print_list(head);

    insert(&head, 2, 5);
    print_list(head);

    insert(&head, 1, 7);
    print_list(head);

    remove(&head, 0);
    print_list(head);

    remove(&head, 1);
    print_list(head);

    remove(&head, 1);
    print_list(head);

    destroy(head);
}

