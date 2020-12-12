#include <stdint.h>
#include <assert.h>
#include "stacklink.h"
#include <string.h>
#include <ctype.h>
Stack stack_new(){
    Stack s1 = {0,NULL};
    return s1;
}

uint8_t stack_empty(Stack *stk){
    assert(stk!=NULL);
    return (stk->length==0);
}

static Node* _get_new_node_(void* data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
}

Stack* stack_match(Stack *stk,void* data,StackResult *res){
    assert(stk!=NULL);
    Node *newnode = _get_new_node_(data);
    if((strcmp(newnode->data,"{")==0) || (strcmp(newnode->data,"[")==0) || (strcmp(newnode->data,"(")==0)){
        newnode->next=stk->top;
        stk->top=newnode;
        ++stk->length;
        res->data=data;
        res->status=STACK_OK;
        assert(stk->length>0);
    }else if((strcmp(newnode->data,"}")==0)||(strcmp(newnode->data,"]")==0)||(strcmp(newnode->data,")")==0)){
        if(stk->top!=NULL){
            if(strcmp(newnode->data,"}")){
                 if(strcmp(stk->top->data,"{")==0){
                     Node *temp;
                     res->data=stk->top->data;
                     temp=stk->top;
                     stk->top=stk->top->next;
                     --stk->length;
                     res->status=STACK_OK;
                     free(temp);
                }else{
                    res->status=STACK_NOTOK;
                }


                }else if(strcmp(stk->top->data,"[")==0)
                  if(strcmp(stk->top->data,"]")==0){
                     Node *temp;
                     res->data=stk->top->data;
                     temp=stk->top;
                     stk->top=stk->top->next;
                     --stk->length;
                     res->status=STACK_OK;
                     free(temp);
                }else{
                    res->status=STACK_NOTOK;
                }
                else if(strcmp(stk->top->data,"(")==0)
                   if(strcmp(stk->top->data,"(")==0){
                     Node *temp;
                     res->data=stk->top->data;
                     temp=stk->top;
                     stk->top=stk->top->next;
                     --stk->length;
                     res->status=STACK_OK;
                     free(temp);

            }else{
                res->status=STACK_NOTOK;
            }



        }else{
            res->status=STACK_EMPTY;
        }

    }else{
        res->status=STACK_NOTOK;
    }

    return stk;
}
Stack* stack_solve(Stack *stk,void* data,StackResult *res){
    assert(stk!=NULL);
    Node *newnode = _get_new_node_(data);

    if(isdigit(newnode->data)==0){
        newnode->next=stk->top;
        stk->top=newnode;
        ++stk->length;
        res->data=data;
        res->status=STACK_OK;
        assert(stk->length>0);
    }else{
        Node *temp;
        void *s1;
        void *s2;
        float s3;
        s1 = stk->top->data;
        temp=stk->top;
        stk->top=stk->top->next;
        --stk->length;
        free(temp);
        s2 = stk->top->data;
        temp=stk->top;
        stk->top=stk->top->next;
        --stk->length;
        free(temp);
        if(strcmp(newnode->data,"*")==0){
            s3=(*(int*)s1) * (*(int*)s2);
            void * S3 = &s3;
            Node *newnode = _get_new_node_(S3);
            newnode->next=stk->top;
            stk->top=newnode;
            ++stk->length;
            res->data=data;
            res->status=STACK_OK;
            assert(stk->length>0);

        }else if(strcmp(newnode->data,"+")==0){
            s3=*(int*)s1 + *(int*)s2;
            void * S3 = &s3;
            Node *newnode = _get_new_node_(S3);
            newnode->next=stk->top;
            stk->top=newnode;
            ++stk->length;
            res->data=data;
            res->status=STACK_OK;
            assert(stk->length>0);
        }else{
            res->status=STACK_NOTOK;
        }

    }






}
