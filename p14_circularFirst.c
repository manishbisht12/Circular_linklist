#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of a circular linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // To find the last node

    // Assign data to new node
    new_node->data = new_data;

    // If the list is empty, set the new node as the only node
    if (*head_ref == NULL) {
        new_node->next = new_node;
    } else {
        // Otherwise, traverse the list to find the last node
        while (last->next != *head_ref) {
            last = last->next;
        }
        // Point the next of the new node to the first node
        new_node->next = *head_ref;
        // Change the next of the last node to point to the new node
        last->next = new_node;
    }
    // Update head pointer to point to new node
    *head_ref = new_node;
}

// Function to delete a node from the beginning of a circular linked list
void deleteAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) // If the list is empty, nothing to delete
        return;

    struct Node* temp = *head_ref;
    struct Node* last = *head_ref;

    // If the list contains only one node
    if ((*head_ref)->next == *head_ref) {
        *head_ref = NULL;
    } else {
        // Otherwise, traverse to find the last node
        while (last->next != *head_ref) {
            last = last->next;
        }
        // Move head to the next node
        *head_ref = (*head_ref)->next;
        // Point the last node to the new head
        last->next = *head_ref;
    }
    // Free the memory of the deleted node
    free(temp);
}

// Function to print a circular linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

// Driver program to test functions
int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Print the list
    printf("Original Circular Linked List: ");
    printList(head);

    // Delete nodes
    deleteAtBeginning(&head);
    deleteAtBeginning(&head);

    // Print the list after deletion
    printf("Circular Linked List after deletion: ");
    printList(head);

    return 0;
}
