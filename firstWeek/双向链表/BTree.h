#include <stdio.h>
#include <stdlib.h>
/**  * Ë«ÏòÁ´±í²Ù×÷  */
typedef struct TNode {
    int data;
    struct TNode *next;
    struct TNode *pre;
}TNode, *ptr_TNode;
typedef enum Status {
      SUCCESS,ERROR
}Status;
