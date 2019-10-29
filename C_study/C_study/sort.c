//
//  sort.c
//  C_study
//
//  Created by 崔玉冠 on 2019/9/23.
//  Copyright © 2019 崔玉冠. All rights reserved.
//

#include "sort.h"

#pragma mark -- 冒泡排序 --
int *bubbleSort(int arr[], int len)
{
    int temp_buf;
    for (int i = 0; i < len-1; i ++) {
        for (int j = 0; j < len-i-1; j ++) {
            if (arr[j] > arr[j+1]) {
                temp_buf = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp_buf;
            }
        }
    }
    int *sort = arr;
    return sort;
}

#pragma mark -- 选择排序 --

int *selectSort(int arr[], int len)
{
    int temp_buf;
    for (int i = 0; i < len; i ++) {
        for (int j = i+1 ; j < len; j ++) {
            if (arr[i] > arr[j]) {
                temp_buf = arr[i];
                arr[i] = arr[j];
                arr[j] = temp_buf;
            }
        }
    }
    int *sort = arr;
    return sort;
}

#pragma mark -- 归并排序 --

void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j = midIndex+1, k = startIndex;
    while(i != midIndex+1 && j != endIndex+1)
    {
        if (sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while (i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    
    while (j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    
    for(i = startIndex; i <= endIndex; i++)
        sourceArr[i] = tempArr[i];
}

//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
        printf("%d", midIndex);
    }
}

#pragma mark -- 快速排序 --

void quick_Sort(int arr[], int low, int high)
{
    if (low < high) {
        // 现寻找基准数索引
        int index = getIndex(arr, low, high);
        // 找到基准数的真事位置之后, 再分别对前后排序, 迭代
        quick_Sort(arr, 0, index-1);
        quick_Sort(arr, index+1, high);
    }
}

int getIndex(int arr[], int low, int high)
{
    // 基准数据
    int temp = arr[low];
    while (low < high) {
        // 当队尾的元素大于等于基准值时, 证明队尾的值一定在基准值之后, 不管它继续前移
        while (low < high && arr[high] >= temp) {
            high --;
        }
        // 如果队尾元素小于基准值了,需要将其赋值给low
        arr[low] = arr[high];
        // 当队首的元素小于等于基准值时, 证明队尾的值一定在基准值之前, 不管它继续后移
        while (low < high && arr[low] <= temp) {
            low ++;
        }
        // 当队首元素大于基准值时,需要将其赋值给high
        arr[high] = arr[low];
    }
    // 跳出循环时low和high相等,此时的low或high就是tmp的正确索引位置
    // 由原理部分可以很清楚的知道low位置的值并不是tmp,所以需要将tmp赋值给arr[low]
    arr[low] = temp;
    return low;
}

# pragma mark -- 插入排序 --

/**
 插入排序
 */
void insert_Sort(int arr[], int len) {
    int i,j;
    int temp;
    int first = 0;
    int last = len-1;
    for(i = first+1 ;i < last; i ++) {
        temp=arr[i];
        j= i-1;
        //与已排序的数逐一比较，大于temp时，该数移后
        while((j >= 0) && (arr[j] > temp)) {
            arr[j+1] = arr[j];
            j--;
        }
        //存在大于temp的数
        if(j != i-1)
            arr[j+1] = temp;
        forIn(arr, len);
    }
}

int forIn(int arr[], len) {
    printf("\n");
    for (int i = 0; i < len; i ++) {
        printf("%d\x20", arr[i]);
    }
    return 0;
}

