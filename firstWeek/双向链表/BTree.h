#include <stdio.h>
#include <stdlib.h>
/**  * ˫���������  */
typedef struct TNode {
    int data;
    struct TNode *next;
    struct TNode *pre;
}TNode, *ptr_TNode;
typedef enum Status {
      SUCCESS,ERROR
}Status;
