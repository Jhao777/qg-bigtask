#include "LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>
//链栈

//初始化栈
Status initLStack(LinkStack *s){
    ElemType data;
    LinkStackPtr rawstack = (LinkStackPtr)malloc(sizeof(StackNode));
    printf("please add data:");
    scanf("%d",&data);
    rawstack -> data = data;
    s -> top = rawstack;
    rawstack -> next = s -> top;
    s->count++;
    return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if ( s -> count ==  0){
        printf("None LinkStack!\n");
    }
    else printf("LinkStack exist\n");
    return SUCCESS;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	*e = s -> top -> data;
    printf("the top data is %d\n",*e);
    return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s){
	s -> top -> next = s -> top;
    return SUCCESS;
}

//检测栈长度

//入栈
Status pushLStack(LinkStack *s,ElemType data){
    LinkStackPtr temp = (LinkStackPtr)malloc(sizeof(StackNode));
    temp -> data = data;
    temp -> next = s -> top;
    s -> top = temp;
    s -> count++;
    return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	LinkStackPtr p;
    *data = s -> top -> data;
    printf("the pop data is %d\n",*data);
    p = s -> top;
    s -> top = s -> top ->next;
    free(p);
    s -> count--;
    return SUCCESS;
}






