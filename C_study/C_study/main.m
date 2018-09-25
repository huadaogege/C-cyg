//
//  main.m
//  C_study
//
//  Created by 崔玉冠 on 2018/8/7.
//  Copyright © 2018年 崔玉冠. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "order_list_c.h"
#import "single_link_list.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        printf("hello, world.");
//        order_list_operations();
        single_link_list_operations();
    }
    return 0;
}

/**
 顺序表的相关操作
 
 @return status
 */
int order_list_operations(void)
{
    int scores[10] = {3,1,2,5,4,7,8,6,9,0};
    Sqlist L;
    //  初始化顺序表
    InitList(&L);
    //  顺序表的插入
    for (int i = 0; i < 10; i ++) {
        int value = scores[i];
        ListInsert(&L, i+1, value);
    }
    ListTraverse(&L);
    //  取元素
    Element e;
    GetElem(&L, 4, &e);
    //  取前一位元素
    Element pri_e;
    PriorElem(&L, 4, &pri_e);
    //  取后一位元素
    Element nex_e;
    NextElem(&L, 4, &nex_e);
    //  删除元素
    ListDelete(&L, 4);
    ListTraverse(&L);
    //  插入元素
    ListInsert(&L, 5, 13);
    ListTraverse(&L);
    
    printf("表的长度:%d\n", L.length);
    return 0;
}

/**
 单向链表的操作

 @return status
 */
int single_link_list_operations()
{
    struct Node *lists = NULL;
    /* 分配10个元素 */
    lists = malloc(sizeof(struct Node) * 10);
    if (lists == NULL) {
        printf("malloc failed.\n");
        return -1;
    }
    /* 准备填充元素 */
    for (int i = 0; i < 10; i ++) {
        lists[i].e_id = list_id ++;
        sprintf(lists[i].e_data, "elem_content_%d", i);
        list_add(&list_head, &lists[i]);
    }
    /* 遍历数组 */
    list_traverse(&list_head);
    /* 删除操作 */
//    list_delete(&list_head, 6);
    list_modify(&list_head, 5, "cuiyuguan");
    list_reverse(&list_head);
    list_traverse(&list_head);
    return 0;
}
