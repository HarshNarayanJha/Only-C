#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

Node* createNode(int val) {
  Node* newNode = (Node*)malloc(sizeof(Node));

  if (newNode != NULL) {
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
  }

  return newNode;
}

void printTabs(int numtabs) {
  for (int i = 0; i < numtabs; i++) {
    printf("\t");
  }
}

void printTree_rec(Node* root, int level) {
  if (root == NULL) {
    printTabs(level);
    printf("\n");
    return;
  }

  printTabs(level);
  printf("%d\n", root->val);
  printTree_rec(root->left, level + 1);
  printTree_rec(root->right, level + 1);
}

void printTree(Node* root) {
  printTree_rec(root, 0);
}

int sum(Node* root) {
  if (root == NULL) {
    return 0;
  }

  return root->val + sum(root->left) + sum(root->right);
}

int minNodeIter(Node* root) {
  if (root == NULL) {
    return -1;
  }

  Node* current = root;
  while (current->left != NULL) {
    current = current->left;
  }

  return current->val;
}

int maxNodeIter(Node* root) {
  if (root == NULL) {
    return -1;
  }

  Node* current = root;
  while (current->right != NULL) {
    current = current->right;
  }

  return current->val;
}

int this_main() {
  Node* n1 = createNode(10);
  Node* n2 = createNode(11);
  Node* n3 = createNode(56);
  Node* n4 = createNode(13);
  Node* n5 = createNode(6);
  Node* n6 = createNode(20);
  Node* n7 = createNode(35);

  n1->left = n2;
  n1->right = n3;

  n2->left = n4;
  n2->right = n5;

  n3->left = n6;
  n3->right = n7;

  printTree(n1);

  printf("Sum of Tree: ");

  printf("%d\n", sum(n1));

  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);
  free(n6);
  free(n7);
}
