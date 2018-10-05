//
//  single_link_list.c
//  C_command
//
//  Created by 崔玉冠 on 2018/9/24.
//  Copyright © 2018年 崔玉冠. All rights reserved.
//

#include "single_link_list.h"
#include <string.h>

void list_add(struct Node **head, struct Node *elem)
{
    struct Node *temp;
    /* 链表为空*/
    if (*head == NULL)
    {
        *head = elem;
        (*head)->next = NULL;
    }
    else
    {
        /* 链表不为空*/
        temp = *head;
        while (temp)
        {
            if (temp->next == NULL)
            {
                temp->next = elem;
                elem->next = NULL;
            }
            temp = temp->next;
        }
    }
}

int list_delete(struct Node**head, int e_id)
{
    struct Node *temp, *p;
    temp = *head;
    /* 链表为空,删除失败 */
    if (temp == NULL)
    {
        printf("链表为空!\n");
        return -1;
    }
    else
    {
        /* 要删除的元素在表头, 表头指针指向下一个元素 */
        if (e_id == temp->e_id)
        {
            *head = temp->next;
            return 0;
        }
        else
        {
            while (temp->next)
            {
                p = temp;
                temp = temp->next;
                if (e_id == temp->e_id)
                {
                    p->next = temp->next;
                    return 0;
                }
            }
            return -1;
        }
    }
    return -1;
}

int list_modify(struct Node **head, int e_id, char *content)
{
    struct Node *temp;
    temp = *head;
    while (temp)
    {
        if (e_id == temp->e_id)
        {
            memset(temp->e_data, 0, sizeof(temp->e_data));
            sprintf(temp->e_data, "%s", content);
            temp->e_data[strlen(content)] = '\0';
            return 0;
        }
        temp = temp->next;
    }
    return -1;
}

void list_traverse(struct Node **head)
{
    struct Node *temp;
    temp = *head;
    printf("list information:\n");
    while (temp)
    {
        printf("list id:%d data:%s\n", temp->e_id, temp->e_data);
        temp = temp->next;
    }
}

struct Node* list_reverse(struct Node **head)
{
    struct Node *pf, *pb, *temp;
    pf = *head;
    if (*head == NULL)
    {
        printf("链表为空, 无需逆序.\n");
        return *head;
    }
    else if (pf->next == NULL)
    {
        printf("链表的长度为1, 无需逆序.\n");
        return *head;
    }
    else
    {
        pb = pf->next;
        pf->next = NULL;
        while (pb != NULL)
        {
            temp = pb;
            pb = pb->next;
            temp->next = pf;
            pf = temp;
        }
        *head = pf;
        printf("链表逆序完成.\n");
        return *head;
    }
}

int JudgeCircularList(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("该链表不是一个循环链表.\n");
        return -1;
    }
    struct Node *tail;
    tail = head->next;
    while (tail != NULL && tail != head)
    {
        tail = tail->next;
    }
    if (tail == NULL) {
        printf("该链表不是一个循环链表.\n");
        return -1;
    }
    printf("该链表是一个循环链表.\n");
    return 0;
}
