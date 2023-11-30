#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node of the singly linked list
struct node {
  int data;
  struct node *next;
};

// Function to create a new node
struct node *create_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a new node at the beginning of the singly linked list
void insert_at_begin(struct node **head, int data) {
  struct node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

// Function to insert a new node at the end of the singly linked list
void insert_at_end(struct node **head, int data) {
  struct node *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
  } else {
    struct node *current_node = *head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
}

// Function to delete the first node of the singly linked list
void delete_first(struct node **head) {
  if (*head == NULL) {
    return;
  } else {
    struct node *current_node = *head;
    *head = current_node->next;
    free(current_node);
  }
}

// Function to delete the last node of the singly linked list
void delete_last(struct node **head) {
  if (*head == NULL) {
    return;
  } else {
    struct node *current_node = *head;
    struct node *previous_node = NULL;
    while (current_node->next != NULL) {
      previous_node = current_node;
      current_node = current_node->next;
    }
    if (previous_node == NULL) {
      *head = NULL;
    } else {
      previous_node->next = NULL;
      free(current_node);
    }
  }
}

// Function to display the singly linked list
void display(struct node *head) {
  if (head == NULL) {
    return;
  } else {
    struct node *current_node = head;
    while (current_node != NULL) {
      printf("%d ", current_node->data);
      current_node = current_node->next;
    }
  }
}

int main() {
  // Create a singly linked list
  struct node *head = NULL;

  // Insert some nodes at the beginning of the singly linked list
  insert_at_begin(&head, 10);
  insert_at_begin(&head, 20);
  insert_at_begin(&head, 30);

  // Insert some nodes at the end of the singly linked list
  insert_at_end(&head, 40);
  insert_at_end(&head, 50);
  insert_at_end(&head, 60);

  // Delete the first node of the singly linked list
  delete_first(&head);

  // Delete the last node of the singly linked list
  delete_last(&head);

  // Display the singly linked list
  display(head);

  return 0;
}