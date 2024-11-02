#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

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

void dfs_iter(Node *graph) {
  static Node *seen[100] = {NULL}; // Using array as a set
  static int seenSize = 0;

  if (graph == NULL) {
    return;
  }

  Stack s;
  initStack(&s);
  push(&s, graph);

  while (!isEmpty(&s)) {
    Node *node = pop(&s);

    printf("%d ", node->val);
    seen[seenSize++] = node;

    for (int i = 0; i < node->numChildren; i++) {

      bool nodeSeen = false;
      for (int j = 0; j < seenSize; j++) {
        if (seen[j] == node->childrens[i]) {
          nodeSeen = true;
        }
      }

      if (!nodeSeen) {
        push(&s, node->childrens[i]);
      }
    }
  }
}

void dfs_post(Node *graph) {
  static Node *seen[100] = {NULL}; // Using array as a set
  static int seenSize = 0;

  if (graph == NULL) {
    return;
  }

  for (int i = 0; i < graph->numChildren; i++) {
    bool nodeSeen = false;
    for (int j = 0; j < seenSize; j++) {
      if (seen[j] == graph->childrens[i]) {
        nodeSeen = true;
      }
    }

    if (!nodeSeen)
      dfs_post(graph->childrens[i]);
  }

  printf("%d ", graph->val);
  seen[seenSize++] = graph;
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
  printf("\n");
  dfs_iter(graph);
  printf("\n");
  dfs_post(graph);
  printf("\n");
}
