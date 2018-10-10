//
//  stack.h
//  C_study
//
//  Created by 崔玉冠 on 2018/10/5.
//  Copyright © 2018 崔玉冠. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

#define OK 0            //正常
#define ERROR -1        //出错
#define OVERFLOW -2        //内存申请不成功
#define DEFSIZE 10      //栈的默认大小
#define INCREAMSIZE 10     //每次当栈空间满时，增量

typedef int Status;//定义状态
typedef int ElemType;//定义元素类型

typedef struct {
    ElemType *base;//栈底指针
    ElemType *top;//栈顶指针
    int stackSize;//栈大小
    int realSize;//当前栈大小
}Stack;

/**
 初始化栈

 @param s 栈指针
 @return 操作状态
 */
Status InitStack(Stack *s);

/**
 入栈

 @param s 栈指针
 @param e 入栈元素
 @return 操作状态
 */
Status Push(Stack *s, ElemType *e);

/**
 出栈

 @param s 栈指针
 @param e 出栈元素
 @return 操作状态
 */
Status Pop(Stack *s, ElemType *e);

/**
 获取栈顶元素

 @param s 栈指针
 @param e 栈顶元素指针
 @return 操作状态
 */
Status GetTop(Stack *s, ElemType **e);

/**
 判断栈是否为空

 @param s 栈指针
 @return 操作状态
 */
Status IsEmpty(Stack *s);

/**
 销毁栈

 @param s 栈指针
 @return 操作状态  
 */
Status Destory_Stack(Stack *s);

#endif /* stack_h */
