#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "list.c"

int main() {
    Node* head = NULL;
    int choice, key;

    do {
        printf("1. Add element\n");
        printf("2. Delete element\n");
        printf("3. Find element\n");
        printf("4. Sort list\n");
        printf("5. Serialize list\n");
        printf("6. Deserialize list\n");
        printf("7. Print list\n");
        printf("0. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the key of the element: ");
            scanf("%d", &key);
            addElement(&head, key);
            break;
        case 2:
            printf("Enter the key of the element: ");
            scanf("%d", &key);
            deleteElement(&head, key);
            break;
        case 3: {
            printf("Enter the key of the element: ");
            scanf("%d", &key);
            Node* found = searchElement(head, key);
            if (found != NULL) {
                printf("Element found - %d\n", found->key);
            }
            else {
                printf("Element with key %d not found.\n", key);
            }
            break;
        }
        case 4:
            sortList(head);
            printf("List sorted\n");
            break;
        case 5:
            serializeList(head, "serializedlist.txt");
            printf("List serialized\n");
            break;
        case 6:
            head = deserializeList("serializedlist.txt");
            printf("List deserialized\n");
            break;
        case 7:
            printList(head);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
