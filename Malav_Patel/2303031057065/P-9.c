#include <stdio.h>
#include <stdlib.h>
// Define the structure for a binary tree node
struct Node {
 int data;
 struct Node* left;
 struct Node* right;
};
// Function to create a new node
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}
// Function to find the minimum value node in a BST
struct Node* findMin(struct Node* node) {
 while (node->left != NULL) {
 node = node->left;
 }
 return node;
}
// Function to delete a node from a BST
struct Node* deleteNode(struct Node* root, int key) {
 if (root == NULL) {
 return root;
 }
 
 if (key < root->data) {
 root->left = deleteNode(root->left, key);
 } else if (key > root->data) {
 root->right = deleteNode(root->right, key);
 } else {
 // Node with only one child or no child
 if (root->left == NULL) {
 struct Node* temp = root->right;
 free(root);
 return temp;
 } else if (root->right == NULL) {
 struct Node* temp = root->left;
 free(root);
 return temp;
 }
 // Node with two children: Get the inorder successor (smallest in the right subtree)
 struct Node* temp = findMin(root->right);
 root->data = temp->data;
 
 // Delete the inorder successor
 root->right = deleteNode(root->right, temp->data);
 }
 return root;
}
// Function to perform inorder traversal of a BST
void inorderTraversal(struct Node* root) {
 if (root != NULL) {
 inorderTraversal(root->left);
 printf("%d ", root->data);
 inorderTraversal(root->right);
 }
}
int main() {
 struct Node* root = createNode(50);
 root->left = createNode(30);
 root->right = createNode(70);
 root->left->left = createNode(20);
 root->left->right = createNode(40);
 root->right->left = createNode(60);
 root->right->right = createNode(80);
 printf("Inorder traversal before deletion: ");
 inorderTraversal(root);
 printf("\n");
 int keyToDelete = 50;
 root = deleteNode(root, keyToDelete);
 printf("Inorder traversal after deleting %d: ", keyToDelete);
 inorderTraversal(root);
 printf("\n");
 return 0;
}
