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
// Function to calculate the height of a binary tree
int findHeight(struct Node* root) {
 if (root == NULL) {
 return -1; // Height of an empty tree is -1
 }
 
 int leftHeight = findHeight(root->left);
 int rightHeight = findHeight(root->right);
 
 return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int main() {
 // Construct a binary tree
 struct Node* root = createNode(1);
 root->left = createNode(2);
 root->right = createNode(3);
 root->left->left = createNode(4);
 root->left->right = createNode(5);
 
 int height = findHeight(root);
 printf("Height of the binary tree is: %d\n", height);
 return 0;
}
