#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int val) {
  Node *newNode = (Node *)malloc(sizeof(Node));

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
  printTree_rec(root->left, level + 1);
  printTree_rec(root->right, level + 1);
}

void printTree(Node *root) { printTree_rec(root, 0); }

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

bool searchNode(Node *root, int val) {
  if (root == NULL) {
    return false;
  }

  if (root->val == val) {
    return true;
  }

  if (val > root->val) {
    return searchNode(root->right, val);
  } else {
    return searchNode(root->left, val);
  }
}

void traverseInOrder(Node *root) {
  if (root == NULL) {
    return;
  }

  traverseInOrder(root->left);
  printf("%d ", root->val);
  traverseInOrder(root->right);
}

void traversePostOrder(Node *root) {
  if (root == NULL) {
    return;
  }

  traversePostOrder(root->left);
  traversePostOrder(root->right);
  printf("%d ", root->val);
}

void traversePreOrder(Node *root) {
  if (root == NULL) {
    return;
  }

  printf("%d ", root->val);
  traversePreOrder(root->left);
  traversePreOrder(root->right);
}

int minNodeIter(Node *root) {
  if (root == NULL) {
    return -1;
  }

  Node *current = root;
  while (current->left != NULL) {
    current = current->left;
  }

  return current->val;
}

int maxNodeIter(Node *root) {
  if (root == NULL) {
    return -1;
  }

  Node *current = root;
  while (current->right != NULL) {
    current = current->right;
  }

  return current->val;
}

int sum(Node *root) {
  if (root == NULL) {
    return -1;
  }

  return root->val + sum(root->left) + sum(root->right);
}

int height(Node *root) {
  if (root == NULL) {
    return -1;
  }

  int left = height(root->left);
  int right = height(root->right);

  return (left > right) ? left + 1 : right + 1;
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

  printf("Searching 6 in tree: %d\n", (int)searchNode(root, 6));
  printf("Searching 20 in tree: %d\n", (int)searchNode(root, 20));
  printf("Searching 100 in tree: %d\n", (int)searchNode(root, 100));

  printf("Sum of Tree: ");

  printf("%d\n", sum(root));

  printf("\nTraverse\n1. In Order: \n");
  traverseInOrder(root);

  printf("\nTraverse\n1. Post Order: \n");
  traversePostOrder(root);

  printf("\nTraverse\n1. Pre Order: \n");
  traversePreOrder(root);

  printf("\nMin and Max (Iterative): %d %d", minNodeIter(root),
         maxNodeIter(root));

  printf("\nHeight is: %d", height(root));

  free(root);
}
