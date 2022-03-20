#include<stdio.h>
#include"linkList.h"

int main(){
    int add;
    int elem;/*add，elem变量均用于交互时数据的交换*/
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    link *p = initLink();/*初始化链表*/
    display(p);/*展示链表*/
    int S;
    while(1)/*用户交互界面*/
    {
        printf("0.退出(任意其他数字也退出)\n");
        printf("1.插入元素\n");
        printf("2.删除元素\n");
        printf("3.查找元素\n");
        printf("4.去除链表\n");
        printf("5.查找中间节点\n");
        printf("6.奇偶调换\n");
        printf("7.反转链表\n");
        printf("8.判断是否为循环链表\n");
        printf("请输入你想要的服务:(0~)");
        scanf("%d",&S);
        switch (S)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("请依次输入插入的元素和插入的位置(按逗号隔开):");
            scanf("%d,%d",&elem,&add);
            insertElem(p,elem,add);
            display(p);
            break;
        case 2:
            printf("请输入要删除的元素的序列:");
            scanf("%d",&add);
            delElem(p,add);
            display(p);
            break;
        case 3:
            printf("请输入要查找的元素(结果返回序列):");
            scanf("%d",&elem);
            printf("序列为:%d\n",selectElem(p,elem));
            display(p);
            break;
        case 4:
            DestroyList(p);
            printf("complete!quit!\n");
            exit(0);
            break;
        case 5:
            FindMidNode(p);
            display(p);
            break;
        case 6:
            ReverseEvenList(p);
            break;
        case 7:
            p = ReverseList(p);
            display(p);
            break;
        case 8:
            elem = IsLoopList(p);
            if(elem == 1)printf("YES\n");
            else printf("NO\n");
            break;
        default:
            exit(0);
            break;
        }
    }

    return 0;
}

//创建链表的函数
link * initLink() {
    link * p = (link*)malloc(sizeof(link));//创建一个头结点
    link * temp = p;//声明一个指针指向头结点，用于遍历链表
    //生成链表
    for (int i = 1; i < 5; i++) {
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

//遍历链表
void display(link *p) {
    link* temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {/*直到遍历到NULL就结束*/
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    printf("\n");
}

link * insertElem(link * p, ElemType elem, ElemType add)/*用于在什么位置插入什么数据的函数*/
 {
    link * temp = p;//创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("插入位置无效\n");
            return p;
        }
    }
    //创建插入结点c
    link * c = (link*)malloc(sizeof(link));
    c->elem = elem;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return  p;
}

link * delElem(link * p, ElemType add) /*用于删除数据的函数*/
{
    link * temp = p;
    //遍历到被删除结点的上一个结点
    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp->next == NULL) {
            printf("没有该结点\n");
            return p;
        }
    }
    link * del = temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
    free(del);//手动释放该结点，防止内存泄漏
    return p;
}

int selectElem(link * p, int elem) /*查找想要的数据的位置*/
{
    link * t = p;
    int i = 1;
    while (t->next) /*遍历到该数据处*/{
        t = t->next;
        if (t->elem == elem) {
            return i;
        }
        i++;
    }
    return -1;
}

void DestroyList(link *head)/*释放链表内存*/
{
    link *temp = head;/*以temp变量代替head头节点，让temp遍历*/
    link *D;/*此变量用于释放内存*/
    while(temp->next==NULL)
    {
        D=temp;
        temp=temp->next;
        free(D);
    }
    free(temp);
}

void FindMidNode(link *p)/*寻找中间节点*/
{
    link * p1 = p->next;
    link * p2 = p->next->next;/*让p1顺序遍历，p2成倍顺序遍历，当p2到达尾部分时，p1就到达中间位置了，这时p2=2*p1（位置）*/
    while(1)
    {
        if(p2->next==NULL)/*偶节点则无中间节点*/
        {
            printf("该链表为偶链表，无中间节点\n");
            break;
        }
        if(p2->next->next==NULL)
        {
            printf("中间节点为:%d\n",p1->next->elem);
            break;
        }
        p1=p1->next;
        p2=p2->next->next;/*继续遍历*/
    }
}

void ReverseEvenList(link *p)/*奇偶调换函数*/
{
    link * p1= p->next;
    link * p2= p->next->next;
    int temp1;
    while(1){
        temp1=p1->elem;
        p1->elem=p2->elem;
        p2->elem=temp1;
        printf("%d %d ",p1->elem,p2->elem);
        if(p2->next==NULL)break;
        if(p2->next->next==NULL)break;
        p1=p1->next->next;
        p2=p2->next->next;/*p1遍历奇数，p2遍历偶数，用temp1这个介质交换p1和p2的数据*/
    }
    printf("%d\n",p2->next->elem);   
}

link *ReverseList(link *p)//非递归反转链表
{
    if (p == NULL || p->next == NULL) {
        return p;
    }
    else {
        link * beg = NULL;
        link * mid = p->next;
        link * end = p->next->next;
        //一直遍历
        while (1)
        {
            //修改 mid 所指节点的指向
            mid->next = beg;
            //此时判断 end 是否为 NULL，如果成立则退出循环
            if (end == NULL) {
                break;
            }
            //整体向后移动 3 个指针
            beg = mid;
            mid = end;
            end = end->next;
        }
        //最后修改 head 头指针的指向
        p -> next = mid;
        return p;
    }
}

link* recursive_reverse(link* head) //此为递归反转链表，在main中并无调用，在此只是为了实现作业要求
{
    //递归的出口
    if (head == NULL || head->next == NULL)     // 空链或只有一个结点，直接返回头指针
    {
        return head;
    }

    else
    {
        //一直递归，找到链表中最后一个节点
        link *new_head = recursive_reverse(head->next);

        //当逐层退出时，new_head 的指向都不变，一直指向原链表中最后一个节点；
        //递归每退出一层，函数中 head 指针的指向都会发生改变，都指向上一个节点。

        //每退出一层，都需要改变 head->next 节点指针域的指向，同时令 head 所指节点的指针域为 NULL。
        head->next->next = head;
        head->next = NULL;
        //每一层递归结束，都要将新的头指针返回给上一层。由此，即可保证整个递归过程中，能够一直找得到新链表的表头。
        return new_head;
    }
}

int IsLoopList(link *p)/*判断是否为循环链表*/
{
    link * H1 = p->next;
    link * H2 = p;
    while (H1)
    {
        if (H1 == H2)
        {
            //链表中有环
            return 1;
        }
        else
        {
            H1 = H1->next;
            if (!H1)
            {
                //链表中无环
                return 0;
            }
            else
            {
                H1 = H1->next;
                H2 = H2->next;
            }
        }
    }
    //链表中无环
    return 0;
}