//
//  list_c.c
//  C_command
//
//  Created by 崔玉冠 on 2018/9/23.
//  Copyright © 2018年 崔玉冠. All rights reserved.
//

#include "order_list_c.h"


void InitList(Sqlist *L)
{
    L->elem = (Element *)malloc(LIST_INIT_MAX*sizeof(Element));//初始化指针
    if (!L->elem) {
        exit(-1);
    }
    L->length = 0;//初始化当前元素
    L->listsize = LIST_INIT_MAX;//初始化表长
    printf("线性表初始化成功.\n");
}

void DestoryList(Sqlist *L)
{
    free(L->elem);//释放空间
    L->elem = NULL;//将指针置为空
    L->length = 0;
    L->listsize = 0;
}

void ClearList(Sqlist *L)
{
    L->length = 0;
}

int GetElem(Sqlist *L, int i, Element *e)
{
    printf("元素获取:\n");
    if (i < 1 || i > L->length) {
        printf("index is error.\n");
        return ERROR;
    }
    *e = *(L->elem + i-1);
    printf("取到第%d位的元素为:%d\n", i, *e);
    return SUCCESS;
}

void LocateElem(Sqlist *L, Element *e)
{
    printf("元素定位:\n");
    int *p = L->elem;
    for (int i = 0; i < L->length; i ++) {
        if (p == e) {
            printf("find the elem:%d, index is:%d\n", *e, i+1);
            return;
        }
    }
    printf("can not find the elem:%d\n", *e);
}

int PriorElem(Sqlist *L, Element curr_e, int *pri_e)
{
    printf("上一位元素查找:\n");
    int *p = L->elem;
    for (int i = 0; i < L->length; i ++, p ++) {
        if (i == 0 && *p == curr_e) {
            printf("current elem is first , no prior.\n");
            return ERROR;
        }
        if (*p == curr_e) {
            *pri_e = *--p;
            printf("查找到%d的上一位的元素是:%d\n", curr_e, *pri_e);
            return SUCCESS;
        }
    }
    printf("the current elem is not in orderList.\n");
    return ERROR;
}

int NextElem(Sqlist *L, Element curr_e, int *nex_e)
{
    printf("下一位元素查找:\n");
    int *p = L->elem;
    for (int i = 0; i < L->length; i ++, p ++) {
        if (i == L->length - 1 && *p == curr_e) {
            printf("current elem is the last one, no next.\n");
            return ERROR;
        }
        if (*p == curr_e) {
            *nex_e = * ++p;
            printf("查找到%d的下一位元素是:%d\n", curr_e, *nex_e);
            return SUCCESS;
        }
    }
    printf("the current elem is not in orderList.\n");
    return ERROR;
}

int ListInsert(Sqlist *L, int i, Element e)
{
    printf("列表插入:\n");
    if (i < 1 || i > L->length+1) {
        printf("insert index is illegal.\n");
        return ERROR;
    }
    if (L->length == LIST_INIT_MAX) {
        exit(-1);
    }
    for (int j = L->length - 1; j >= i; j --) {
        L->elem[j+1] = L->elem[j];
    }
    L->elem[i-1] = e;
    ++L->length;
    return SUCCESS;
}


int ListDelete(Sqlist *L, int i)
{
    printf("列表元素删除:\n");
    if (i < 1 || i > L->length) {
        printf("delete index is illegal.\n");
        return ERROR;
    }
    for (int j = i; j < L->length; j ++) {
        L->elem[j-1] = L->elem[j];
    }
    L->length --;
    return SUCCESS;
}

void ListTraverse(Sqlist *L)
{
    printf("列表遍历:\n");
    Element *p = L->elem;
    for (int i = 0; i < L->length; i ++, p ++) {
        printf("第%d个元素为:%d.\n", i+1, *p);
    }
}
