#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

typedef struct Node {
  int val;
  struct Node* left;
  struct Node* right;
  int height;
} Node;

Node* createNode(int val) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  node->height = 0;

  return node;
}

int getHeight(Node* node) {
  if (node == NULL) {
    return -1;
  }

  int l = 1 + getHeight(node->left);
  int r = 1 + getHeight(node->right);

  int h = (l > r) ? l : r;

  return h;
}

Node* searchNode(Node* root, int val) {
  Node* x = root;

  while (x != NULL && x->val != val) {
    if (val < x->val) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  if (x == root) {
    x = NULL;
  }

  return x;
}

Node* leftRotate(Node* node) {
  Node* B = node->right;
  Node* Y = B->left;

  B->left = node;
  node->right = Y;

  // Recalculate Height
  node->height = 1 + getHeight(node);
  B->height = 1 + getHeight(B);

  return B;
}

Node* rightRotate(Node* node) {
  Node* A = node->left;
  Node* Y = A->right;

  A->right = node;
  node->left = Y;

  // Recalculate Height
  node->height = 1 + getHeight(node);
  A->height = 1 + getHeight(A);

  return A;
}

int getBalanceFactor(Node* root) {
  return (getHeight(root->left)) - (getHeight(root->right));
}

Node* insert(Node* root, int val) {
  if (root == NULL) {
    return createNode(val);
  } else if (val < root->val) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }

  root->height = 1 + getHeight(root);

  // balance factors
  int bf = getBalanceFactor(root);

  if (bf > 1 && val < root->left->val) {
    return rightRotate(root);
  } else if (bf < -1 && val > root->right->val) {
    return leftRotate(root);
  } else if (bf > 1 && val > root->left->val) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  } else if (bf < -1 && val < root->right->val) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

Node* deleteNode(Node* root, int val) {
  if (root == NULL) {
    return root;
  } else if (val < root->val) {
    root->left = deleteNode(root->left, val);
  } else if (val > root->val) {
    root->right = deleteNode(root->right, val);
  } else {
    if (root->left == NULL) {
      Node* move = root->right;
      free(root);
      return move;
    } else if (root->right == NULL) {
      Node* move = root->left;
      free(root);
      return move;
    } else {
      Node* successor = root->right;
      while (successor->left != NULL) {
        successor = successor->left;
      }
      root->val = successor->val;
      root->right = deleteNode(root->right, successor->val);
    }
  }

  // Update height and rebalance
  root->height = 1 + getHeight(root);

  int bf = getBalanceFactor(root);

  if (bf > 1 && getBalanceFactor(root->left) >= 0) {
    return rightRotate(root);
  } else if (bf > 1 && getBalanceFactor(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  } else if (bf < -1 && getBalanceFactor(root->right) <= 0) {
    return leftRotate(root);
  } else if (bf < -1 && getBalanceFactor(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void printInOrder(Node* root) {
  if (root == NULL) {
    return;
  }

  printInOrder(root->left);
  printf("%d ", root->val);
  printInOrder(root->right);
}

void printLevelOrder(Node* root) {
  if (root == NULL) {
    return;
  }

  queue_t* q = queue_create();
  queue_enqueue(q, root);

  while (!queue_is_empty(q)) {
    Node* node = queue_dequeue(q);
    printf("%d ", node->val);
    if (node->left != NULL) {
      queue_enqueue(q, node->left);
    }
    if (node->right != NULL) {
      queue_enqueue(q, node->right);
    }
  }
}

int main() {
  Node* avl = NULL;
  avl = insert(avl, 2);
  avl = insert(avl, 8);
  avl = insert(avl, 92);
  avl = insert(avl, 37);
  avl = insert(avl, 17);
  avl = insert(avl, 6);

  printInOrder(avl);
  printf("\n");
  printLevelOrder(avl);
  printf("\n");

  avl = deleteNode(avl, 37);

  printLevelOrder(avl);
}
