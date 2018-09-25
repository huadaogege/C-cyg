//
//  single_link_list.h
//  C_command
//
//  Created by 崔玉冠 on 2018/9/24.
//  Copyright © 2018年 崔玉冠. All rights reserved.
//  单向链表的相关操作

#ifndef single_link_list_h
#define single_link_list_h

#include <stdio.h>

/* 定义一个表示单向链表的结构体指针 */
struct Node {
    int e_id;
    char e_data[20];
    struct Node *next;
};

/* 定义一个链表的头部 */
static struct Node *list_head = NULL;

/* 为了保证每个链表元素id不同, 特意把e_id定义成一个全局静态变量 */
static int list_id = 0;

/**
 将制定元素插入到表尾

 @param head 表示操作链表的头部地址
 @param elem 将要插入的元素
 */
void list_add(struct Node **head, struct Node *elem);

/**
 修改表中的元素
 
 @param head 表头指针
 @param e_id 修改的元素
 @param content 修改的内容
 @return fail:-1, success:0
 */
int list_modify(struct Node **head, int e_id, char *content);

/**
 删除链表中元素

 @param head 表头指针
 @param e_id 删除的id
 @return fail:-1, success:0
 */
int list_delete(struct Node**head, int e_id);

/**
 遍历单向链表

 @param head 将要操作的链表的头部指针
 */
void list_traverse(struct Node **head);

/**
 链表逆序

 @param head 表头指针
 @return 新的表头指针
 */
struct Node* list_reverse(struct Node **head);


#endif /* single_link_list_h */
