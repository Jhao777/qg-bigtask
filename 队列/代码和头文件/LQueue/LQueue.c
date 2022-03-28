#include "LQueue.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hpos;  //记录对头位置
int npos = 0;
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node *newnode = (Node*)malloc(sizeof(Node));
    if(newnode==NULL)
    {
        printf("init ERROR!\n");
    }
    newnode->next = NULL;
    Q->front = Q->rear = newnode;
    Q->length = 0;
    hpos = npos; 
    //为了销毁后能够再将头的数据类型锁定到
    //队尾后一位的数据类型
    printf("init SUCCESS!\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	if(Q==NULL){
        printf("please init the queue first!\n");
        return;
    }
    Node *temp1,*temp2;
    temp1 = Q->front;
    while(temp1!=NULL){
        temp2 = temp1->next;
        free(temp1);
        temp1 = temp2;
    }
    Q->front = NULL;
    Q->rear = NULL;
    printf("Destroy SUCCESS!\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->length == 0){
        return TRUE;
    }
    return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	memcpy(e,Q->front->next->data,30);
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	Node *newnode = (Node *)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("input queue ERROR!\n");
        return FALSE;
    }
    newnode->data = (void *)malloc(30);
    memcpy(newnode->data,data,30);
    newnode->next = NULL;
    Q->rear->next = newnode;
    Q->rear = newnode;
    Q->length++;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(Q==NULL){
        printf("please init queue first!\n");
        return FALSE;
    }
    if(IsEmptyLQueue(Q)){
        printf("the queue is empty!\n");
        return FALSE;
    }
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode=Q->front->next;
    Q->front->next=newnode->next;
    free(newnode);
    if(Q->front->next==NULL){
        Q->rear=Q->front;      //若队列刚好只剩一个元素，则出列后则为空，Q->rear刚好被free掉，需要重新定向
    }
    hpos++;        //队头位置向后一步
    Q->length--;
    printf("out queue SUCCESS!\n");
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q==NULL){
        printf("please init queue first!\n");
        return ;
    }
    if(IsEmptyLQueue(Q)){
        printf("the queue is empty!\n");
        return ;
    }
    Q->front->next=NULL;
    Q->rear=Q->front;
    hpos=npos;
    Q->length=0;
    printf("clear SUCCESS!\n");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(Q==NULL){
        printf("please init queue first!\n");
        return FALSE;
    }
    if(IsEmptyLQueue(Q)){
        printf("the queue is empty!\n");
        return FALSE;
    }
    Node *temp=(Node*)malloc(sizeof(Node));
    temp=Q->front->next;
    npos=hpos;
    foo(temp->data);
    temp = temp->next;
    do{
        printf("-> ");
        foo(temp->data);
        temp=temp->next;
    }while(temp!=NULL);
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
	if(datatype[npos]=='i'){
        printf("%d ",*(int*)q);
    }
    if(datatype[npos]=='f'){
        printf("%.4lf ",*(double*)q);
    }
    if(datatype[npos]=='c'){
        printf("%c ",*(char*)q);
    }
    if(datatype[npos]=='s'){
        printf("%s ",(char*)q);
    }
    npos++;
}



