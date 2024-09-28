#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int val;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int val) {
  Node *newNode = (Node *) malloc(sizeof(Node));

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

void printTree_rec(Node *root, int level) {
  if (root == NULL) {
    printTabs(level);
    printf("NULL\n");
    return;
  }

  printTabs(level);
  printf("%d\n", root->val);
  printTree_rec(root->left, level+1);
  printTree_rec(root->right, level+1);
}

void printTree(Node *root) {
  printTree_rec(root, 0);
}

bool insertNode(Node **rootptr, int val) {
  Node *root = *rootptr;

  if (root == NULL) {
    // tree is empty
    (*rootptr) = createNode(val);
    return true;
  }

  if (root->val == val) {
    return false;
  }

  if (val < root->val) {
    return insertNode(&(root->left), val);
  } else {
    return insertNode(&(root->right), val);
  }
}

int sum(Node *root) {
  if (root == NULL) {
    return 0;
  }

  return root->val + sum(root->left) + sum(root->right);
}

int main() {
  Node *root;
  insertNode(&root, 10);
  insertNode(&root, 11);
  insertNode(&root, 56);
  insertNode(&root, 13);
  insertNode(&root, 6);
  insertNode(&root, 20);
  insertNode(&root, 35);

  printTree(root);

  printf("Sum of Tree: ");

  printf("%d\n", sum(root));

  free(root);
}
