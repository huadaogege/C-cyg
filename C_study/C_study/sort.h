//
//  sort.h
//  C_study
//
//  Created by 崔玉冠 on 2019/9/23.
//  Copyright © 2019 崔玉冠. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <stdio.h>
#include <stdlib.h>

/**
 冒泡排序
 */
int *bubbleSort(int arr[], int len);

/**
 选择排序
 */
int *selectSort(int arr[], int len);

/**
 归并排序
 */
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex);

/**
 快速排序
 */
void quick_Sort(int arr[], int low, int high);

/**
 插入排序
 */
void insert_Sort(int arr[], int len);

#endif /* sort_h */
