/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (52.03%)
 * Likes:    651
 * Dislikes: 0
 * Total Accepted:    98.1K
 * Total Submissions: 188.5K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 * 
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
# include <iostream>
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *h = new ListNode(0),*p=head,*r,*s,*x;
        if(p==NULL||p->next==NULL||n==m)return p;
        bool tra = false;
        h->next=head;
        head=h;
        r=h;
        for(int i=1;i<=n;i++){
            if(tra){
                r->next=h;
                h=r;
                if(i==m+1)s=h;  
            }
            if(i==m){
                tra=true;
                x=r;
            }
            if(i==n){
                s->next=p->next;
                p->next=r;
                break;
            }
            r=p;
            p=p->next;
        }
        x->next=p;
        return head->next;
    }
};
// @lc code=end

