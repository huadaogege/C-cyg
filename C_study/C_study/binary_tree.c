//
//  binary_tree.c
//  C_study
//
//  Created by 崔玉冠 on 2018/10/13.
//  Copyright © 2018 崔玉冠. All rights reserved.
//

#include "binary_tree.h"

#pragma mark -- 插入操作 --
/* 插入新节点的递归函数 */
void insert(TNode** pRoot,TNode* pn)
{
    //1.判断二叉树是否为空,如果为空则让根节点指针直接指向新节点
    if(NULL == *pRoot)
    {
        *pRoot = pn;
        return;
    }
    //2.如果二叉树非空,比较根节点和新节点大小
    //2.1 如果根节点大于新节点，插入左子树
    if((*pRoot)->data > pn->data)
    {
        insert(&(*pRoot)->left,pn);
    }
    //2.2 如果根节点小于等于新节点,插入右子树
    else
    {
        insert(&(*pRoot)->right,pn);
    }
}

/* 实现向有序二叉树中插入新节点的操作 */
void insert_data(Tree* pt,int data)
{
    //1.创建新节点，进行初始化 create_node
    //Node* pn = (Node*)malloc(sizeof(Node));
    //pn->data = data;
    //pn->left = NULL;
    //pn->right = NULL;
    //2.插入新节点到二叉树中,调用递归函数
    insert(&pt->root,create_node(data));
    //3.二叉树中节点个数加1
    pt->cnt++;
}

#pragma mark -- 遍历二叉树操作 --
/* 遍历的递归函数 */
void travel(TNode* pRoot)
{
    //判断二叉树不为空时才需要遍历
    if(pRoot != NULL)
    {
        //1.遍历左子树
        travel(pRoot->left);
        //2.遍历根节点
        printf("%d ",pRoot->data);
        //3.遍历右子树
        travel(pRoot->right);
    }
}

/* 采用中序遍历方法进行遍历 */
void travel_data(Tree* pt)
{
    //调用递归函数进行遍历
    travel(pt->root);
    //打印换行
    printf("\n");
}

/* 非递归遍历二叉树 */
void PreOrderTraverl(Tree *t)
{
    TNode *root = t->root;
    TNode *stack[100];
    int top = -1;
    TNode *p;
    if (root != NULL)
    {
        top ++;
        stack[top] = root;
        while (top > -1)
        {
            p = stack[top];
            top--;
            printf("%d \n", p->data);
            if (p->right != NULL)
            {
                top ++;
                stack[top] = p->right;
            }
            if (p->left != NULL)
            {
                top ++;
                stack[top] = p->left;
            }
        }
    }
}

#pragma mark -- 二叉树查找 --
/* 实现查找一个指定的节点 */
/* 返回 指向目标元素所在节点的指针 的地址 */
TNode** find_data(Tree* pt,int data)
{
    //调用递归函数实现查找
    return find(&pt->root,data);
}

/* 查找的递归函数 */
TNode** find(TNode** pRoot,int data)
{
    //1.判断二叉树是否为空，为空直接返回
    if(NULL == *pRoot)
    {
        return pRoot;//&pt->root;
    }
    //2.比较根节点元素和目标元素的大小，如果相等，直接返回
    if(data == (*pRoot)->data)
    {
        return pRoot;//&pt->root;
    }
    //3.若目标元素小于根节点元素值,左子树查找
    else if(data < (*pRoot)->data)
    {
        return find(&(*pRoot)->left,data);
    }
    //4.若目标元素大于根节点元素,去右子树查找
    else
    {
        return find(&(*pRoot)->right,data);
    }
}

#pragma mark -- 二叉树删除 --
/* 实现删除指定的节点 */
void del_data(Tree* pt,int data)
{
    //1.查找目标元素所在节点的地址
    TNode** pp = find_data(pt,data);
    //2.判断查找失败情况,不需要删除
    if(NULL == *pp)
    {
        printf("目标元素不存在，删除失败\n");
        return;
    }
    //3.合并左右子树,左子树插入到右子树中
    if((*pp)->left != NULL)
    {
        //左子树不为空时，需要插入到右子树中
        insert(&(*pp)->right,(*pp)->left);
    }
    //4.寻找指针记录要删除的节点地址
    TNode* q = *pp;
    //5.将原来指向要删除节点的指针 重新指向 合并之后的右子树
    *pp = (*pp)->right;
    //6.删除目标元素所在的节点
    free(q);
    q = NULL;
    //7.节点个数减1
    pt->cnt--;
}

/* 实现清空的递归函数 */
void clearT(TNode** pRoot)
{
    //判断二叉树是否为空
    if(*pRoot != NULL)
    {
        //1.清空左子树
        clearT(&(*pRoot)->left);
        //2.清空右子树
        clearT(&(*pRoot)->right);
        //3.清空根节点
        free(*pRoot);
        *pRoot = NULL;
    }
}

/* 实现清空树中的所有节点 */
void clear_data(Tree* pt)
{
    //调用递归函数实现清空
    clearT(&pt->root);
    //二叉树的节点个数清零
    pt->cnt = 0;
}

/* 修改指定元素的操作 */
/* 旧元素不存在时，直接插入新元素即可 */
void modify(Tree* pt,int data,int new_data)
{
    //1.删除旧元素
    del_data(pt,data);
    //2.插入新元素
    insert_data(pt,new_data);
}

#pragma mark -- 二叉树的判断 --
/* 判断二叉树是否为空 */
int empty(Tree* pt)
{
    return NULL == pt->root;
}
/* 判断二叉树是否为满 */
int isFullTree(TNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
    {
        return -1;
    }
    return isFullTree(root->left) && isFullTree(root->right);
}

/* 获取根节点的元素值 */
int get_root(Tree* pt)
{
    if(empty(pt))
    {
        return -1;//表示失败(以后讲到)
    }
    return pt->root->data;
}

/* 实现创建新节点 */
TNode* create_node(int data)
{
    TNode* pn = (TNode*)malloc(sizeof(TNode));
    pn->data = data;
    pn->left = NULL;
    pn->right = NULL;
    return pn;
}

#pragma mark -- 二叉树的计算 --
/* 计算二叉树中节点的个数 */
int size(Tree* pt)
{
    return pt->cnt;
}

/* 计算二叉树的深度 */
int depth_Tree(TNode *root)
{
    int LDepth = 0;
    int RDepth = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        LDepth = depth_Tree(root->left);
        RDepth = depth_Tree(root->right);
        if (LDepth > RDepth)
        {
            return LDepth + 1;
        }
        else
        {
            return RDepth + 1;
        }
    }
}






