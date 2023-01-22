// https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree

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
class Solution {
public:
    vector<int>a;
    void dfs(TreeNode* root){
        if(root!=NULL){
           a.push_back(root->val); 
        }
        if(root->left != NULL) dfs(root->left);
        if(root->right != NULL) dfs(root->right);
            
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        dfs(root);
        sort(a.begin(), a.end());
        //for(auto x : a) cout << x << " ";
        vector<vector<int> > ans;
        int n = a.size();
        for(auto x : q){
            vector<int>temp;
            
            int mini = lower_bound(a.begin(), a.end(), x) - a.begin();
            if(mini>=n) mini = a[n-1];
            
            else if(a[mini]!=x){
                if(mini-1<0) mini = -1;
                else mini = a[mini-1];
            }
            else{
                mini = a[mini];
            }
            
            int maxi = lower_bound(a.begin(), a.end(), x) - a.begin();
            
            
            if(maxi>=n) {
                maxi = -1;
            }
            else maxi = a[maxi];
            
            
            temp.push_back(mini);
            temp.push_back(maxi);
            ans.push_back(temp);
        }
        return ans;
            
    }
};