#include "tree.h"
#include <stdbool.h>
#include <stdio.h>

bool isBST(Node *root);

bool isBST(Node *root) {
  if (root == NULL) {
    return true;
  }

  int leftMax = maxNodeIter(root->left);
  int rightMin = minNodeIter(root->right);

  return (leftMax <= root->val && rightMin >= root->val);
}

int main() {
  Node *root = createNode(10);
  root->left = createNode(5);
  root->right = createNode(20);

  root->left->left = createNode(2);
  root->left->right = createNode(7);

  root->right->left = createNode(15);
  root->right->right = createNode(30);

  printf("%s\n", isBST(root) ? "BST" : "Not a BST");

  return 0;
}
