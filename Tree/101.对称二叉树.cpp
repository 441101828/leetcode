/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (53.43%)
 * Likes:    1219
 * Dislikes: 0
 * Total Accepted:    258.8K
 * Total Submissions: 484.4K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以运用递归和迭代两种方法解决这个问题吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
# include "link.h"
# include <iostream>
using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool z = true;
        if(root==NULL)return true;
        TreeNode* rootl=root->left;
        TreeNode* rootr=root->right;
        Symmetric(rootl,rootr,z);
        return z;
    }
    void Symmetric(TreeNode *rootl,TreeNode *rootr,bool &z){
        if(rootl==NULL&&rootr==NULL)return;
        if(rootl==NULL||rootr==NULL||rootl->val!=rootr->val){
            z=false;
            return;
        }
        if(z){
            Symmetric(rootl->left,rootr->right,z);
            Symmetric(rootl->right,rootr->left,z);
        }
    }
};
// @lc code=end

