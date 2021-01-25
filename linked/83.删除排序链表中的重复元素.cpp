/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (51.90%)
 * Likes:    457
 * Dislikes: 0
 * Total Accepted:    176K
 * Total Submissions: 339.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *q = head;
        if(q==NULL||q->next==NULL) return q;
        ListNode *p = q->next;
        while(p){
            if(p->val==q->val){
                q->next=p->next;
                p->next=NULL;
                delete p;
                p = q->next;
            }
            else{
                p=p->next;
                q=q->next;
            }
        }
        return head;
    }
};
// @lc code=end

