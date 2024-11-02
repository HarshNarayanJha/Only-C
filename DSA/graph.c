#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILD 5

typedef struct Node {
  int val;
  struct Node *childrens[MAX_CHILD];
  int numChildren;
} Node;

Node *createNode(int val) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->val = val;
  newNode->numChildren = 0;

  return newNode;
}

void addChild(Node *node, Node *child) {
  node->childrens[node->numChildren++] = child;
}

void dfs(Node *graph) {
  static Node *seen[100] = {NULL}; // Using array as a set
  static int seenSize = 0;

  if (graph == NULL) {
    return;
  }

  printf("%d ", graph->val);

  seen[seenSize++] = graph;

  for (int i = 0; i < graph->numChildren; i++) {
    bool nodeSeen = false;
    for (int j = 0; j < seenSize; j++) {
      if (seen[j] == graph->childrens[i]) {
        nodeSeen = true;
      }
    }

    if (!nodeSeen)
      dfs(graph->childrens[i]);
  }
}

int main() {
  Node *graph = createNode(0);
  addChild(graph, createNode(1));
  addChild(graph, createNode(2));
  addChild(graph, createNode(3));
  addChild(graph->childrens[0], graph->childrens[2]);
  addChild(graph->childrens[1], graph->childrens[2]);
  addChild(graph->childrens[2], createNode(4));

  dfs(graph);
}
