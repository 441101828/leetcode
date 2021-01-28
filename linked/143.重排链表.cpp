/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (59.50%)
 * Likes:    500
 * Dislikes: 0
 * Total Accepted:    78K
 * Total Submissions: 131.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        map <int,ListNode*> idx;
        if(head==NULL||head->next==NULL||head->next->next==NULL)return;
        ListNode *p=head;
        int n=0;
        while(p!=NULL){
            idx[n]=p;
            n++;
            p=p->next;
        }
        n--;
        p=head;
        for(int i=1;i<n;i++){
            p->next=idx[n];
            p->next->next=idx[i];
            n--;
            p=p->next->next;
            if(i==n){
                p->next=NULL;
                break;
            }
            if(i+1==n){
                p->next->next=NULL;
                break;
            }
        }
        return;
    }
};
// @lc code=end

