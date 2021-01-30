# include "link.h"
# include <iostream>
# include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> s;
        if(root==NULL)return s;
        vector<int> List;
        int sum1=0;
        findlist(root,List,s,sum,sum1);
        return s;
    }
    void findlist(TreeNode*root,vector<int> List,vector<vector<int>> &s,int sum,int sum1){
        if(root==NULL)return;
        List.push_back(root->val);
        sum1+=root->val;
        findlist(root->left,List,s,sum,sum1);
        findlist(root->right,List,s,sum,sum1);
        if(sum1==sum&&root->right==NULL&&root->left==NULL){
            s.push_back(List);
        }
    }
};