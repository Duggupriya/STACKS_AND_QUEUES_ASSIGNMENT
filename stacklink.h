#ifndef STACKLINK_H_INCLUDED
#define STACKLINK_H_INCLUDED
#include <stdint.h>

#define STACK_OK 1
#define STACK_EMPTY 2
#define STACK_NOTOK 3

typedef struct _node_ Node;
struct _node_{
    void* data;
    Node *next;
};

typedef struct _stack_ Stack;
struct _stack_{

     int32_t length;
     Node *top;
};

typedef struct _stack_result_ StackResult;
struct _stack_result_{
    void* data;
    uint8_t status;
};

Stack stack_new();
uint8_t stack_empty(Stack *stk);
Stack* stack_match(Stack *stk,void* data,StackResult *res);
Stack* stack_solve(Stack *stk,void* data,StackResult *res);
Stack* stack_pop(Stack *stk,StackResult *res);


#endif // STACKLINK_H_INCLUDED
