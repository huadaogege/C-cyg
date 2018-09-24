//
//  main.m
//  C_study
//
//  Created by 崔玉冠 on 2018/8/7.
//  Copyright © 2018年 崔玉冠. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "order_list_c.h"
#include <stdio.h>
#import <math.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        printf("hello, world.");
//        order_list_operations();
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
