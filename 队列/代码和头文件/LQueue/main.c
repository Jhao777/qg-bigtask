#include"LQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int hpos;             //用于定位数据类型的位置
int npos;
void foo(void *q)
{
    LPrint(q);
}

void menu()
{
    printf("	****************欢迎来到Jhao的范型链式结构队列****************\n");
	printf("				1:初始化队列\n");
	printf("				2:销毁队列\n");
	printf("				3:队列是否为空\n");
	printf("				4:队头元素\n");
	printf("				5:队列长度\n");
	printf("				6:入队\n");
	printf("				7:出队\n");
	printf("				8:清空队列\n");
	printf("				9:遍历\n");
	printf("				0:退出\n");
	printf("	*********************************************************\n");
    return;
}

int main(void){
    int menuID,menuID2,num;
    int x,j,c,z;
    char a[20];//存放输入流中的整数
    LQueue *Q=NULL; 
    menu();
start:
    printf("input number(0-9):");
	scanf("%d", &menuID);
	switch (menuID)
	{
	    case 1:
	        Q=(LQueue*)malloc(sizeof(LQueue));
            InitLQueue(Q);
            hpos=0;
            npos=0;
            break;
        case 2:
            DestoryLQueue(Q);
            hpos=npos;
            printf("1.init queue again\n");
            printf("2.exit\n");
            scanf("%d",&menuID2);
            if(menuID2==1){
                InitLQueue(Q);
                break;
            }
            if(menuID2==2){
                exit(0);
            }
            else
                break;
        case 3:
            if(Q==NULL){
                printf("please init queue first!\n");
                break;
            }
            menuID2=IsEmptyLQueue(Q);
            if(menuID2==1){
                printf("the queue is empty!\n");
            }
            else
                printf("the queue is not empty!\n");
            break;
        case 4:
            if(Q==NULL){
                printf("please init queue first!\n");
                break;
            }
            if(IsEmptyLQueue(Q)){
                printf("the queue is empty!\n");
                break;
            }
            if(datatype[hpos]=='i'){
                int i;
                GetHeadLQueue(Q,&i);
                printf("head queue data is:%d\n",i);
            }
            if(datatype[hpos]=='f'){
                double f;
                GetHeadLQueue(Q,&f);
                printf("head queue data is:%.4lf\n",f);
            }
            if(datatype[hpos]=='c'){
                char c;
                GetHeadLQueue(Q,&c);
                printf("head queue data is:%c\n",c);
            }
            if(datatype[hpos]=='s'){
                char s[30];
                GetHeadLQueue(Q,s);
                printf("head queue data is:%s\n",s);
            }
            break;
        case 5:
            if(Q==NULL){
                printf("please init queue first!\n");
                break;
            }
            num=LengthLQueue(Q);
            printf("the queue have %d datas\n",num);
            break;
        case 6:
            if(Q==NULL){
                printf("please init queue first!\n");
                break;
            }
            printf("input typedata (i:int ,f:float ,c:char ,s:string)\n");
            printf("enter initials:");
            fflush(stdin);
            type=getchar();
            while(type!='i'&&type!='f'&&type!='c'&&type!='s'){
                printf("The input is incorrect, please try again!\n");
                fflush(stdin);
                type=getchar();
            }
            datatype[npos]=type;
            npos++;
            if(type=='i'){
                printf("Please enter an integer to enqueue:\n");
                int i;
                while(1){
                scanf("%s",a);
                for(x=0,j=0;x<strlen(a);x++)                  //遍历整个输入流的字符串
                {
                    if(a[x]<=57&&a[x]>=48)                  //使用0～9的啊西卡码来截取整数
                        j++;
                }
                if(j==strlen(a)){                           //如果j不等于字符串长度，说明不是有效输入，需重新输入
                    i=0;
                    for(c=1;j>0;j--){ //将数组的数字转化成我们需要的整数。例如数组中的，123，转化过程：3+2*10+1*100=123存入变量中
                        z=(int)a[j-1]-48;
                        i+=z*c;
                        c*=10;
                    }
                    break;
                }
                else
                    printf("Please enter the integer correctly!\nre-enter:");
                }
                EnLQueue(Q,&i);
            }
            if(type=='f'){
                printf("Please enter a float number to enqueue:\n");
                double f;
                scanf("%lf",&f);
                EnLQueue(Q,&f);
            }
            if(type=='c'){
                printf("Please enter characters to enqueue:\n");
                char c;
                fflush(stdin);     //去掉缓冲区的回车键
                scanf("%c",&c);
                EnLQueue(Q,&c);
            }
            if(type=='s'){
                printf("tips : do not enter spaces!\n");//没有做优化，不能输入空格
                printf("Please enter a string to enqueue:\n");
                char s[30];
                scanf("%s",s);
                EnLQueue(Q,s);
            }
            fflush(stdin);
            break;
        case 7:
            menuID2=DeLQueue(Q);
            break;
        case 8:
            ClearLQueue(Q);
            break;
        case 9:
            TraverseLQueue(Q,foo);
            printf("\n");
            break;
        case 0:
            exit(0);
	default: printf("请输入正确的数字！\n");
	}

	goto start;                         //实现循环
    return 0;
}

