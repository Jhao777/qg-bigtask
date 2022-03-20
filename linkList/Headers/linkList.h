/***************************************************************************************
 *	File Name				:	linkList.h
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
#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>

/**************************************************************
*	Macro Define Section
**************************************************************/


/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct Link {
	ElemType elem;
  	struct Link *next;
} link;

// define Status



/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : link * initLink();
 *	@description : 创建链表的函数
 *	@param		 : p(the head node),temp
 *	@return		 : link
 *  @notice      : None
 */
link * initLink();

/**
 *  @name        : void DestroyList(link *head)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : head(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(link *head);

/**
 *  @name        : link * insertElem(link * p, ElemType elem, ElemType add)
 *	@description : insert node c after node temp
 *	@param		 : c,temp
 *	@return		 : link
 *  @notice      : None
 */
link * insertElem(link * p, ElemType elem, ElemType add);

/**
 *  @name        : link * delElem(link * p, ElemType add)
 *	@description : delete the first node after the node p and assign its value to add
 *	@param		 : p, add
 *	@return		 : link
 *  @notice      : None
 */
link * delElem(link * p, ElemType add);

/**
 *  @name        : void display(link *p)
 *	@description : traverse the linked list
 *	@param		 : p(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void display(link *p); 

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : p(the head node), elem
 *	@return		 : ElemType
 *  @notice      : None
 */
ElemType selectElem(link * p, ElemType elem);

/**
 *  @name        : link *ReverseList(link *p)
 *	@description : reverse the linked list
 *	@param		 : p(the head node)
 *	@return		 : p
 *  @notice      : None
 */
link *ReverseList(link *p);

/**
 *  @name        : int IsLoopList(link *p)
 *	@description : judge whether the linked list is looped
 *	@param		 : p(the head node)
 *	@return		 : 0/1
 *  @notice      : None
 */
int IsLoopList(link *p);

/**
 *  @name        : link* ReverseEvenList(link *p)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : p(the head node)
 *	@return		 : head(the new head node)
 *  @notice      : choose to finish
 */
void ReverseEvenList(link *p);//    奇偶

/**
 *  @name        : void FindMidNode(link *p)
 *	@description : find the middle node in the linked list
 *	@param		 : p(the head node)
 *	@return		 : head
 *  @notice      : choose to finish
 */
void FindMidNode(link *p);

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
