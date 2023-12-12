#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void addElement(Node** head, int key) {
    Node* newNode = createNode(key);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void deleteElement(Node** head, int key) {
    Node* prev = NULL;
    Node* curr = *head;

    while (curr != NULL && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        return;
    }

    if (prev == NULL) {
        *head = curr->next;
    }
    else {
        prev->next = curr->next;
    }

    free(curr);
}

Node* searchElement(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->key == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


void sortList(Node* head) {
    int swapped;
    int i;
    Node* ptr1;
    Node* lptr = NULL;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->key > ptr1->next->key) {
                int temp = ptr1->key;
                ptr1->key = ptr1->next->key;
                ptr1->next->key = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void serializeList(Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("������ ��� �������� �����\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        fprintf(file, "%d ", temp->key);
        temp = temp->next;
    }

    fclose(file);
}


Node* deserializeList(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("empty\n");
        return NULL;
    }

    Node* head = NULL;
    int key;
    while (fscanf(file, "%d ", &key) != EOF) {
        addElement(&head, key);
    }

    fclose(file);
    return head;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}