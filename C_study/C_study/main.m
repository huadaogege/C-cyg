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
#import "stack.h"
#import "binary_tree.h"
#import "sort.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        /*
        printf("hello, world.");
        order_list_operations();
        single_link_list_operations();
        stack_operations();
        Dinary_Tree_operations();
         */
        
    }
    return 0;
}

/**
 排序
 */
int sort_actions(void)
{
    // 冒泡排序
    /*
    int arr[] = {3, 1, 4, 2, 7, 5, 6, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    int *result = bubbleSort(arr, len);
    for (int i = 0; i < len; i ++) {
        printf("%d\x20", result[i]);
    }
     */
    
    // 选择排序
    /*
    int arr[] = {3, 1, 4, 2, 7, 5, 6, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    int *result = selectSort(arr, len);
    for (int i = 0; i < len; i ++) {
        printf("%d\x20", result[i]);
    }
     */
    
    // 归并排序
    /*
    int a[8] = {50, 10, 20, 30, 70, 40, 80, 60};
    int i, b[8];
    MergeSort(a, b, 0, 7);
    for(i=0; i<8; i++)
        printf("%d ", a[i]);
    printf("\n");
     */
    
    // 快速排序
    /*
    int arr[] = { 49, 38, 65, 97, 23, 22, 76, 1, 5, 8, 2, 0, -1, 25 };
    int len = sizeof(arr) / sizeof(arr[0]);
    quick_Sort(arr, 0, len-1);
    for (int i = 0; i < len; i ++) {
        printf("%d\x20", arr[i]);
    }
     */
    
    // 插入排序
    int arr[] = { 49, 38, 65, 97, 23, 22, 76, 1, 5, 8, 2, 0, -1, 25 };
    int len = sizeof(arr) / sizeof(arr[0]);
    insert_Sort(arr, len);
    for (int i = 0; i < len; i ++) {
        printf("%d\x20", arr[i]);
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

int stack_operations()
{
    Stack s;
    int N = 0;
    int temp = 0;
    InitStack(&s);
    printf("初始化时，栈的大小为：%d\n", s.stackSize);
    printf("请输入你想输入的数据进栈:\n");
    scanf("%d", &N) ;
    while (N--)
    {
        scanf("%d", &temp);
        Push(&s, &temp);
        printf("进栈的大小为：%d\t",temp);
        printf("压栈后，栈的大小为：%d,%d\n", temp, s.stackSize);
    }
    
    /**得到栈顶元素**/
    GetTop(&s, temp);
    printf("得到栈顶元素为：%d", temp);
    
//    Destroy_Stack(&s);
    printf("销毁栈完成！！\n");
    scanf("%d",&temp);
    return 0;
}

int Dinary_Tree_operations()
{
    Tree tree;
    tree.root = NULL;
    tree.cnt = 0;
    
    insert_data(&tree, 50);
    PreOrderTraverl(&tree);
    insert_data(&tree,70);
    PreOrderTraverl(&tree);
    insert_data(&tree,20);
    PreOrderTraverl(&tree);//20 50 70
    insert_data(&tree,60);
    PreOrderTraverl(&tree);
    int depth = depth_Tree(tree.root);
    return 0;
}
