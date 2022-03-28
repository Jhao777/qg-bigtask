 #include<stdio.h>
 #include<stdlib.h>
 #include"LinkStack.h"

 extern Status initLStack(LinkStack *s);
 extern Status isEmptyLStack(LinkStack *s);
 extern Status getTopLStack(LinkStack *s,ElemType *e);
 extern Status clearLStack(LinkStack *s);
 extern Status pushLStack(LinkStack *s,ElemType data);
 extern Status popLStack(LinkStack *s,ElemType *data);

 char printMainMenu();

 int main(void){
    ElemType data;
    int e;
    Status status;
    LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
    s ->count=0;
    char menuID;
    while(1){
    menuID = printMainMenu();
    switch (menuID)
    {
    case '1':
        status = initLStack(s);
        getTopLStack(s,&e);
        break;
    case '2':
        status = isEmptyLStack(s);
        break;
    case '3':
        printf("%d\n",s->count);
        break;
    case '4':
        status = clearLStack(s);
        if(status)printf("SUCCESS!\n");
        break;
    case '5':
        printf("please input the data:");
        scanf("%d",&data);
        status = pushLStack(s,data);
        if(status)printf("SUCCESS!");
        getTopLStack(s,&e);
        break;
    case '6':
        status = popLStack(s,&data);
        if(status)printf("SUCCESS!");
        getTopLStack(s,&e);
        break;
    case '0':
        exit(0);
        break;
    default:
        break;
    }
    }
    return 0;
 }

char printMainMenu(){
	char menuID;
	printf("***********!!!   welcome to my linkstack group work !!!***********\n");
	printf("*                                                                *\n");
	printf("*                ---------------------------------               *\n");
	printf("*                |     Powered By lin Jhao       |               *\n");
	printf("*                ---------------------------------               *\n");
	printf("*                                                                *\n");
	printf("*                1)create linkstack                              *\n");
	printf("*                2)check linkstack exist                         *\n");
	printf("*                3)know the linkstack length                     *\n");
	printf("*                4)clear linkstack                               *\n");
    printf("*                5)add linkstack node                            *\n");
    printf("*                6)pop linkstack node                            *\n");
	printf("*                0)exit                                          *\n");
	printf("*                                                                *\n");
	printf("******************************************************************\n");
    printf("please enter the correct number:");
	scanf("%s",&menuID);
	return menuID;
}






