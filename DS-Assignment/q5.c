#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertAtBeginning(Node **head, int data) {
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

void insertAtEnd(Node **head, int data) {
  Node *newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

void insertAtPosition(Node **head, int data, int position) {
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }
  if (position == 1) {
    insertAtBeginning(head, data);
    return;
  }
  Node *newNode = createNode(data);
  Node *temp = *head;
  int count = 1;
  while (temp != NULL && count < position - 1) {
    temp = temp->next;
    count++;
  }
  if (temp == NULL) {
    printf("Position out of range\n");
    return;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteAtBeginning(Node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  Node *temp = *head;
  *head = temp->next;
  free(temp);
}

void deleteAtEnd(Node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }
  Node *temp = *head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

void deleteAtPosition(Node **head, int position) {
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }
  if (position == 1) {
    deleteAtBeginning(head);
    return;
  }
  Node *temp = *head;
  int count = 1;
  while (temp != NULL && count < position - 1) {
    temp = temp->next;
    count++;
  }
  if (temp == NULL || temp->next == NULL) {
    printf("Position out of range\n");
    return;
  }
  Node *toDelete = temp->next;
  temp->next = toDelete->next;
  free(toDelete);
}

void printList(Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  Node *head = NULL;

  insertAtEnd(&head, 10);
  insertAtBeginning(&head, 20);
  insertAtPosition(&head, 30, 2);
  insertAtEnd(&head, 40);
  printList(head);

  deleteAtBeginning(&head);
  deleteAtEnd(&head);
  deleteAtPosition(&head, 1);
  printList(head);

  return 0;
}
