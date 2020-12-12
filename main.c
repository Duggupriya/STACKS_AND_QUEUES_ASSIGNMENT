#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "stacklink.h"

void test_new(){
    Stack s1 = stack_new();
    Stack *stk = &s1;
    assert(stack_empty(stk)==1);
}

void test_balance(){
    Stack s1 = stack_new();
    Stack *stk = &s1;
    StackResult res;
    stk=stack_match(stk,"{",&res);
    assert(res.status==STACK_OK && strcmp(res.data,"{")==0);
    stk=stack_match(stk,"}",&res);
    assert(strcmp(res.data,"{")==0);
    stk=stack_match(stk,"{",&res);
    stk=stack_match(stk,"(",&res);
    assert(res.status==STACK_OK);
    stk=stack_match(stk,")",&res);
    assert(strcmp(res.data,"(")==0);

}
void test_solve(){
     Stack s1 = stack_new();
    Stack *stk = &s1;
    StackResult res;
    stk=stack_solve(stk,2,&res);
    assert(res.status==STACK_OK && res.data==2);
    stk=stack_solve(stk,3,&res);
    assert(res.status==STACK_OK && res.data==3);
    stk=stack_solve(stk,"*",&res);
    assert(res.data==6);
}

int main()
{
    test_new();
    test_balance();
    test_solve();
    return 0;
}
