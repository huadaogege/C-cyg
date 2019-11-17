//
//  exercises.c
//  C_study
//
//  Created by 崔玉冠 on 2019/11/16.
//  Copyright © 2019 崔玉冠. All rights reserved.
//

#include "exercises.h"

/* 算法题**算法题**算法题 */

/* 题目一: 双指针法删除倒数第N个节点 */
struct ListNode* removeNthFromEnd(struct ListNode *head, int n) {
    if (n == 0) {
        return head;
    }
    // 快指针, 慢指针, 指向待删除指针的前驱节点
    struct ListNode *fastP = NULL, *slowP = NULL, *slowQ = NULL;
    // 让快指针先跑n步
    for (fastP = head; n > 0; fastP = fastP->next, n--);
    // 之后快慢指针一起走, 直到快指针跑到头, 慢指针就是即将被删除的点
    slowP = head;
    while (fastP != NULL) {
        slowQ = slowP;
        slowP = slowP->next;
        fastP = fastP->next;
    }
    if (slowP == head) {
        head = head->next;
    } else {
        slowQ->next = slowP->next;
    }
    return head;
}

/* 题目二: 双指针判断一个链表是否是循环链表;
   所谓的循环链表不一定是最后一个指向第一个也可能指向中间某个节点 */

int checkIsLoopList(struct ListNode *L) {
    struct ListNode *fast, *slow;
    if (L == NULL) {
        return -1;
    }
    fast = slow = L;
    while (1) {
        if (fast->next == NULL) {
            return -1;
        } else if (fast == slow || fast->next == slow) {
            // 如果他们相遇, 或者快指针的下一个即使慢指针, 证明是循环链表
            return 0;
        } else {
            // 快指针一次走两步, 慢指针一次走一步
            fast = fast->next->next;
            slow = slow->next;
        }
    }
}

/* 题目三: 单链表逆序 */

struct ListNode *reverseList(struct ListNode*head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *p = head;
    struct ListNode *q = head->next;
    head->next = NULL;
    while (q) {
        // 指针交换需要三个指针, 一直往后不停交换
        struct ListNode *temp = q->next;
        q->next = p;
        p = q;
        q = temp;
    }
    return p;
}
