//
//  list_c.h
//  C_command
//
//  Created by 崔玉冠 on 2018/9/23.
//  Copyright © 2018年 崔玉冠. All rights reserved.
//  顺序表的相关操作

#ifndef list_c_h
#define list_c_h

#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_MAX 20 //长表为20
#define LIST_INCREMENT 2 //短表为2

#define ERROR -1
#define SUCCESS 0

// 初始化顺序表
typedef int Element;

typedef struct
{
    Element *elem;
    int length;
    int listsize;
}Sqlist;

/**
 init orderList

 @param L orderList
 */
void InitList(Sqlist *L);

/**
 destory orderList

 @param L orderList
 */
void DestoryList(Sqlist *L);

/**
 clear orderList

 @param L orderList
 */
void ClearList(Sqlist *L);

/**
 find the elem where the index is i

 @param L orderList
 @param i index
 @return elem
 */
int GetElem(Sqlist *L, int i, Element *e);


/**
 find the elem of index in orderList

 @param L orderList
 @param e elem
 */
void LocateElem(Sqlist *L, Element *e);

/**
 find the prior elem of elem

 @param L orderList
 @param curr_e current elem
 @param pri_e prior elem
 @return status
 */
int PriorElem(Sqlist *L, Element curr_e, int *pri_e);

/**
 find the next elem of elem

 @param L orderList
 @param curr_e current elem
 @param nex_e next elem
 @return status
 */
int NextElem(Sqlist *L, Element curr_e, int *nex_e);

/**
 inset elem into index of orderList

 @param L orderList
 @param i index
 @param e tobe insert elem
 @return status
 */
int ListInsert(Sqlist *L, int i, Element e);

/**
 delete elem of orderList where index == i

 @param L orderList
 @param i index
 @return status
 */
int ListDelete(Sqlist *L, int i);

/**
 traverse the orderList

 @param L orderList
 */
void ListTraverse(Sqlist *L);


#endif /* list_c_h */
