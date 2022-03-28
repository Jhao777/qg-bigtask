/***************************************************************************************
 *    File Name                :    逆波兰计算器.h
 *    CopyRight                :    
 *
 *    SYSTEM                    :   Mac OS Menterey
 *    Create Data                :    2022.3.28
 *    Author/Corportation        :   Lin Jhao
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_INCLUDED

/**************************************************************
 *    Struct Define Section
 **************************************************************/
typedef double ElemType;
typedef struct
{
    ElemType *base;//栈底
    ElemType *top;//栈顶
    int stackSize;//栈的长度
}sqStack;		

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitStack(sqStack *s)
 *    @description : 初始化栈
 *    @param         s 栈指针s
 *  @notice      : None
 */
void InitStack(sqStack *s);

/**
 *  @name        : void Push(sqStack *s, ElemType e)
 *    @description : 入栈
 *    @param         s栈指针，e为数据
 *  @notice      : None
 */
void Push(sqStack *s, ElemType e);

/**
 *  @name        : void Pop(sqStack *s, ElemType *e)
 *    @description : 弹栈
 *    @param         s 为栈顶指针，e为数据
 *  @notice      : None
 */
void Pop(sqStack *s, ElemType *e);

/**
 *  @name        : int StackLen(sqStack s)
 *    @description : 计算栈的长度
 *    @param         s栈
 *    @return         : 栈的长度
 *  @notice      : NONE
 */
int StackLen(sqStack s);

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // CALCULATOR_H_INCLUDED


