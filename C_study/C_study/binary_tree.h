//
//  binary_tree.h
//  C_study
//
//  Created by 崔玉冠 on 2018/10/13.
//  Copyright © 2018 崔玉冠. All rights reserved.
//

#ifndef binary_tree_h
#define binary_tree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;//数据内容
    struct TNode* left;//指向左子树
    struct TNode* right;//指向右子树
}TNode;

//定义有序二叉树的数据类型
typedef struct
{
    TNode* root;//记录根节点的地址
    int cnt;//记录节点的个数
}Tree;

/* 实现向有序二叉树中插入新节点的操作 */
void insert_data(Tree* pt,int data);

/* 插入新节点的递归函数 */
void insert(TNode** pRoot,TNode* pn);

/* 采用中序遍历方法进行遍历 */
void travel_data(Tree* pt);

/* 遍历的递归函数 */
void travel(TNode* pRoot);

/* 非递归遍历二叉树 */
void PreOrderTraverl(Tree *t);

/* 实现创建新节点 */
TNode* create_node(int data);

/* 实现查找一个指定的节点 */
TNode** find_data(Tree* pt,int data);

/* 查找的递归函数 */
TNode** find(TNode** pRoot,int data);

/* 实现删除指定的节点 */
void del_data(Tree* pt,int data);

//实现清空的递归函数
void clearT(TNode** pRoot);

//实现清空树中的所有节点
void clear_data(Tree* pt);

/* 修改指定元素的操作 */
void modify(Tree* pt,int data,int new_data);

/* 判断二叉树是否为空 */
int empty(Tree* pt);

/* 判断二叉树是否为满 */
int full(Tree* pt);

/* 计算二叉树中节点的个数 */
int size(Tree* pt);

/* 获取根节点的元素值 */
int get_root(Tree* pt);

/* 计算二叉树的深度 */
int depth_Tree(TNode *root);

#endif /* binary_tree_h */
