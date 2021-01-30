/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
# include "link.h"
# include <iostream>
# include <vector>
using namespace std;
#include <algorithm>
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        vector<int> s;
        int x = 0;
        postOrder(root,s,x);
        vector<int>::iterator itMax = max_element(s.begin(), s.end());
        return *itMax;
    }
    int postOrder(TreeNode* root,vector<int> &s,int x){
        x++;
        if(root->left != NULL){
            postOrder(root->left,s,x);
	    }
	    if(root->right != NULL){
            postOrder(root->right,s,x);
	    }
        s.push_back(x);
        return x;
    }
};