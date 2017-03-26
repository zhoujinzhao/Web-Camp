#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node, *ptr_Node;

typedef enum Status {
    SUCCESS, ERROR
}Status;
