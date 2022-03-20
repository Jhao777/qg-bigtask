/***************************************************************************************
 *	File Name				:	duLinkedList.h
 *	CopyRight				:	lin jia hao
 *	SYSTEM					:   macOS Monterey
 *	Create Data				:	2022.3.20
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct line{
    struct line * prior;
    int data;
    struct line * next;
}line;

/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : line* initLine(line * head)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : head(the head node)
 *	@return		 : head
 *  @notice      : None
 */
line* initLine(line * head);

/**
 *  @name        : void DestroyList_DuL(line *head)
 *	@description : destroy a linked list
 *	@param		 : head(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList_DuL(line *head);

/**
 *  @name        : void display(line * head)
 *	@description : display
 *	@param		 : head(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void display(line * head);

/**
 *  @name        : line * insertLine(line * head,int data,int add)
 *	@description : insert node add->prior before node add
 *	@param		 : data,add
 *	@return		 : head
 *  @notice      : None
 */
line * insertLine(line * head,int data,int add);

/**
 *  @name        : line * delLine(line * head,int data)
 *	@description : delete the data which you want
 *	@param		 : head,data
 *	@return		 : head
 *  @notice      : None
 */
line * delLine(line * head,int data);

/**
 *  @name        : int selectData(line * head,int data)
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : head(the head node), data
 *	@return		 : 序列
 *  @notice      : None
 */
int selectData(line * head,int data);


 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
