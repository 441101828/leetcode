/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (45.32%)
 * Likes:    834
 * Dislikes: 0
 * Total Accepted:    190.5K
 * Total Submissions: 420.2K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)return true;
        ListNode *fast=head,*slow=head,*pre=new ListNode(0);
        head = pre;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            ListNode *r;
            r=slow->next;
            slow->next=pre;
            pre=slow;
            slow=r;
        }
        if(fast!=NULL)slow=slow->next;
        while(slow!=NULL){
            if(pre->val!=slow->val)return false;
            pre=pre->next;
            slow=slow->next;
        }
        return true;
    }
};
// @lc code=end

