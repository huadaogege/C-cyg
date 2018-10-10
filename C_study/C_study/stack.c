//
//  stack.c
//  C_study
//
//  Created by 崔玉冠 on 2018/10/5.
//  Copyright © 2018 崔玉冠. All rights reserved.
//

#include "stack.h"

Status InitStack(Stack *s)
{
    s->base = (ElemType *)malloc(DEFSIZE * sizeof(ElemType));
    if (s->base == NULL)
    {
        exit(OVERFLOW);
    }
    s->top = s->base;
    s->stackSize = DEFSIZE;
    s->realSize = 0;
    return OK;
}

Status Push(Stack *s, ElemType *e)
{
    if (s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType *)realloc(s->base, (s->realSize + INCREAMSIZE) * sizeof(ElemType));
        if (s->base == NULL)
        {
            exit(OVERFLOW);
        }
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + INCREAMSIZE;
    }
    *s->top++ = *e;
    s->realSize ++;
    return OK;
}

Status Pop(Stack *s, ElemType *e)
{
    if (s->base == s->top)
    {
        exit(ERROR);
    }
    *e = * -- s->top;
    s->realSize --;
    return OK;
}

Status GetTop(Stack *s, ElemType **e)
{
    if (s->base == s->top)
    {
        exit(ERROR);
    }
    *e = (s->top - 1);
    return OK;
}

Status IsEmpty(Stack *s)
{
    if (s-> realSize > 0)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }
}

Status Destory_Stack(Stack *s)
{
    s->top = s->base;
    free(s->base);
    s->realSize = 0;
    s->stackSize = DEFSIZE;
    return OK;
}



