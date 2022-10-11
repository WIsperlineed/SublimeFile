

前序遍历

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
            if(!root)return{};
            TreeNode* p=root;
            stack<TreeNode*>s;
            vector<int>ans;
        while(s.size()||p){
            while(p){
                s.push(p);
                ans.push_back(p->val);
                p=p->left;
            }
            p=s.top()->right;   
            s.pop();
        }
        return ans;
    }
};



lc94 中序遍历

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
                if(!root)return{};
                vector<int>ans;
                stack<TreeNode*>s;
                auto p=root;
                while(p||s.size()){
                    while(p){
                        s.push(p);
                        p=p->left;
                    }
                    ans.push_back(s.top()->val);
                    p=s.top()->right;
                    s.pop();
                }
            return ans;
    }
};


后序遍历的递归写法：

class Solution {
public:
     vector<int>ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)return{};
        findnode(root);
        return ans;  
    }
    
    void findnode(TreeNode* u){
        if(u){
            findnode(u->left);
            findnode(u->right);
            ans.push_back(u->val);
        }
    }
};




后序遍历的非递归写法：









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


lc102. 二叉树的层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return{};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(q.size()){
            int cur=q.size();
           
            vector<int>tmp;
            while(cur--){
            TreeNode* qq=q.front();
                if(qq->left)
                    q.push(qq->left);
                if(qq->right)
                    q.push(qq->right);
                tmp.push_back(q.front()->val);
                q.pop();    
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};

lc104. 二叉树的最大深度

class Solution {
public:
    int maxDepth(TreeNode* root) {
            if(!root)return 0;
            int hh=max(maxDepth(root->left),maxDepth(root->right))+1;
            return hh;
    }
};

lc

lc105. 从前序与中序遍历序列构造二叉树

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            TreeNode* ans=TreeBuild(0,preorder.size()-1,0,preorder.size()-1,preorder,inorder);
            return ans;
    }

    TreeNode* TreeBuild(int pl,int pr,int il,int ir,vector<int>& pre, vector<int>& mid){
        if(pl>pr)return;
        int x=pre[pl];
        int i=il;
        while(mid[i]!=x)i++;
        TreeNode* a=new TreeNode(x);
        a->left=TreeBuild(pl+1,pl+i-il,il,i-1,pre,mid);//左边前序
        a->right=TreeBuild(pr-(ir-i)+1,pr,i+1,ir,pre,mid);
        return a;
    }
};




lc 98. 验证二叉搜索树

解法1：中序遍历
class Solution {
public:
    bool isValidBST(TreeNode* root) {
                 if(!root)return{};
                long long inorder = (long long)INT_MIN - 1;
                stack<TreeNode*>s;
                auto p=root;
                while(p||s.size()){
                    
                    while(p){
                        s.push(p);
                        p=p->left;
                    }
                    int u=s.top()->val;
                    if(inorder>=u)return false;
                    inorder=u;
                    p=s.top()->right;
                    s.pop();
                }
        return true;
            
    }
};


class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};



114. 二叉树展开为链表

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)return;
            TreeNode* p=root;
            TreeNode* tmp=root;
            stack<TreeNode*>s;
            vector<TreeNode*>ans;
        while(s.size()||p){
            while(p){
                s.push(p);
                ans.push_back(p);
                p=p->left;
            }
            p=s.top()->right;   
            s.pop();
        }
        for(int i=1;i<ans.size();i++){
            ans[i-1]->left=nullptr;
            ans[i-1]->right=ans[i];
        }

    }
};








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



lc617. 合并二叉树

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
            
    }
};