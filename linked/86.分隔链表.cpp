/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (62.33%)
 * Likes:    355
 * Dislikes: 0
 * Total Accepted:    85.7K
 * Total Submissions: 137.5K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：head = 1->4->3->2->5->2, x = 3
 * 输出：1->2->2->4->3->5
 * 
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
# include <set>
using namespace std;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *p = head;
        if(p==NULL||p->next==NULL) return p;
        ListNode *q = new ListNode(0),*r;
        q->next=head;
        head = q;
        r=q;
        while(p!=NULL){
            if(p->val<x){
                if(r==q){
                    r=r->next;
                    q=q->next;
                    p=p->next;
                }
                else{
                    r->next=p->next;
                    p->next=q->next;
                    q->next=p;
                    q=q->next;
                    p=r->next;
                }
            }
            else{
                r=r->next;
                p=p->next;
            }
        }
        return head->next;
    }
};
// @lc code=end
