lc124. 二叉树中的最大路径和

class Solution {
public:
int maxPathSum(TreeNode* root, int &val)
{
    if (root == nullptr) return 0;
    int left = maxPathSum(root->left, val);
    int right = maxPathSum(root->right, val);
    int lmr = root->val + max(0, left) + max(0, right);
    int ret = root->val + max(0, max(left, right));
    val = max(val, max(lmr, ret));
    return ret;
}

int maxPathSum(TreeNode* root) 
{
    int val = INT_MIN;
    maxPathSum(root, val);
    return val;
}
 
};

lc101. 对称二叉树
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
            if(!root)return true;
           return check(root->left,root->right);
    }
    
    bool check(TreeNode* l,TreeNode* r){
        if(!l &&!r)
            return true;
        if(!l||!r||l->val!=r->val)
            return false;
        
        return check(l->left,r->right)&&check(l->right,r->left);       
    }

};



lc 126. 单词接龙 II

lc 128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

    }
}; 



lc 129. Sum Root to Leaf Numbers


class Solution {
public:
     int helper(TreeNode* root, int sum){
        if(!root)
            return 0;
        else if (!root->left && !root->right)
            return 10*sum + root->val;
        return helper(root->left, 10*sum + root->val) + 
            helper(root->right, 10*sum + root->val);
    }
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};



437. 路径总和 III

//前缀和


class Solution {
public:
    using ll=long long;
    unordered_map<ll, int> cnt;
    ll res = 0;

    int pathSum(TreeNode* root, int sum) {
        cnt[0] ++ ;
        dfs(root, sum, 0);
        return res;
    }

    
    
    
    void dfs(TreeNode* root, ll sum, ll cur) {
        if (!root) return;
        cur += root->val;
        res += cnt[cur - sum];
        cnt[cur] ++ ;
        if(root->left)dfs(root->left, sum, cur);
        if(root->right)dfs(root->right, sum, cur);
        cnt[cur] -- ;
    }

   
};