/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (50.02%)
 * Likes:    437
 * Dislikes: 0
 * Total Accepted:    82.2K
 * Total Submissions: 164.4K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
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
# include <map>
using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> s;
        ListNode *p=head;
        if(p==NULL||p->next==NULL) return p;
        while(p!=NULL){
            if(s.count(p->val)==0)s[p->val]=1;
            else s[p->val]=s[p->val]+1;
            p=p->next;
        }
        ListNode *q=head;
        p=head;
        while(p!=NULL){
            if(s[p->val]>1){
                if(p==q){
                    head=head->next;
                    p=head;
                    q=head;
                } 
                else{
                    q->next=p->next;
                    p=q->next;
                }
            }
            else{
                if(p==q){
                    p=p->next;
                    continue;
                }
                p=p->next;
                q=q->next;
            }
        }
        return head;
    }
};
// @lc code=end

