/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
# include "link.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p,*q,*r,*s;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        p = l1->val<l2->val?l1:l2;
        s = p;
        q = p==l1?l2:l1;
        while(p->next!=NULL&&q!=NULL){
            if(p->next->val>q->val){
                r=q;
                q=q->next;
                r->next=p->next;
                p->next=r;
            }
            p=p->next;
        }
        if(p->next==NULL)p->next=q;
        return s;
    }
};
// @lc code=end
