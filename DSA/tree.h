#ifndef TREE_H
#define TREE_H

typedef struct Node {
  int val;
  struct Node* left;
  struct Node* right;
} Node;

Node* createNode(int val);
void printTree_rec(Node* root, int level);
void printTree(Node* root);
int sum(Node* root);
int minNodeIter(Node* root);
int maxNodeIter(Node* root);

#endif
