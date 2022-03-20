#include<stdio.h>
#include"duLinkedList.h"

int main(void){
    int data,add;
    line * head=NULL;
    //创建双链表
    head=initLine(head);
    display(head);
    int S;
    while(1)
    {
        printf("0.退出(任意其他数字也退出)\n");
        printf("1.插入元素\n");
        printf("2.删除元素\n");
        printf("3.查找元素\n");
        printf("4.去除链表\n");
        printf("请输入您想要的服务:(0~)");
        scanf("%d",&S);
        switch (S)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("在表中第几的位置插入元素几:(用逗号隔开)");
            scanf("%d,%d",&add,&data);
            head = insertLine(head,data,add);
            display(head);
            break;
        case 2:
            printf("请输入你想删除的数据:");
            scanf("%d",&data);
            head = delLine(head,data);
            display(head);
            break;
        case 3:
            printf("请输入要查找的元素:");
            scanf("%d",&data);
            if(selectData(head,data)==-1)printf("查找失败！\n");
            printf("序列为%d\n",selectData(head,data));
            display(head);
            break;
        case 4:
            DestroyList_DuL(head);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}

line* initLine(line * head){
    head=(line*)malloc(sizeof(line));
    head->prior=NULL;
    head->next=NULL;
    head->data=1;
    line * list=head;
    for (int i=2; i<=5; i++) {
        line * body=(line*)malloc(sizeof(line));
        body->prior=NULL;
        body->next=NULL;
        body->data=i;
        list->next=body;
        body->prior=list;
        list=list->next;
    }
    return head;
}

//输出链表的功能函数
void display(line * head){
    line * temp=head;
    while (temp) {
        if (temp->next==NULL) {
            printf("%d\n",temp->data);
        }else{
            printf("%d->",temp->data);
        }
        temp=temp->next;
    }
}

void DestroyList_DuL(line *head)
{
    line *temp=head;
    line *D;
    while(temp->next!=NULL)
    {
        D=temp;
        temp=temp->next;
        free(D);
    }
}

line * insertLine(line * head,int data,int add){
    //新建数据域为data的结点
    line * temp=(line*)malloc(sizeof(line));
    temp->data=data;
    temp->prior=NULL;
    temp->next=NULL;
    //插入到链表头，要特殊考虑
    if (add==1) {
        temp->next=head;
        head->prior=temp;
        head=temp;
    }else{
        line * body=head;
        //找到要插入位置的前一个结点
        for (int i=1; i<add-1; i++) {
            body=body->next;
        }
        //判断条件为真，说明插入位置为链表尾
        if (body->next==NULL) {
            body->next=temp;
            temp->prior=body;
        }else{
            body->next->prior=temp;
            temp->next=body->next;
            body->next=temp;
            temp->prior=body;
        }
    }
    return head;
}

line * delLine(line * head,int data){
    line * temp=head;
    //遍历链表
    while (temp) {
        //判断当前结点中数据域和data是否相等，若相等，摘除该结点
        if (temp->data==data) {
            temp->prior->next=temp->next;
            temp->next->prior=temp->prior;
            free(temp);
            return head;
        }
        temp=temp->next;
    }
    printf("链表中无该数据元素");
    return head;
}  

int selectData(line * head,int data){
//新建一个指针t，初始化为头指针 head
    line * t=head;
    int i=1;
    while (t) {
        if (t->data==data) {
            return i;
        }
        i++;
        t=t->next;
    }
    //程序执行至此处，表示查找失败
    return -1;
}