Solution:
#include <stdio.h>
#include <stdlib.h>
// Define a structure for a node in the linked list
struct Node {
 int data;
 struct Node* next;
};
// Function to create a new node with the given data
struct Node* newNode(int data) {
 struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 if (node == NULL) {
 printf("Memory allocation failed.\n");
 exit(1);
 }
 node->data = data;
 node->next = NULL;
 return node;
}
// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
 struct Node dummy; // Dummy node to simplify handling the merged list
 struct Node* tail = &dummy;
 dummy.next = NULL;
 while (1) {
 if (list1 == NULL) {
 tail->next = list2;
 break;
 } else if (list2 == NULL) {
 tail->next = list1;
 break;
 }
 if (list1->data <= list2->data) {
 tail->next = list1;
 list1 = list1->next;
 } else {
 tail->next = list2;
 list2 = list2->next;
 }
 tail = tail->next;
 }
return dummy.next;
}
// Function to print a linked list
void printList(struct Node* head) {
 while (head != NULL) {
 printf("%d -> ", head->data);
 head = head->next;
 }
 printf("NULL\n");
}
int main() {
 
 struct Node* list1 = newNode(1);
 list1->next = newNode(3);
 list1->next->next = newNode(5);
 struct Node* list2 = newNode(2);
 list2->next = newNode(4);
 list2->next->next = newNode(6);
 printf("List 1: ");
 printList(list1);
 printf("List 2: ");
 printList(list2);
 struct Node* mergedList = mergeSortedLists(list1, list2);
 printf("Merged List: ");
 printList(mergedList);
 return 0;
}
