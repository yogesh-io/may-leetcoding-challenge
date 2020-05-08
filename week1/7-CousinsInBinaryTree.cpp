'''
Cousins in Binary Tree
======================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.
Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
'''

//Method 1
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
    bool findPath(TreeNode *root, vector<int> &path, int k) { 
        // base case 
        if (root == NULL) return false; 

        // Store this node in path vector. The node will be removed if 
        // not in path from root to k 
        path.push_back(root->val); 

        // See if the k is same as root's key 
        if (root->val == k) 
            return true; 

        // Check if k is found in left or right sub-tree 
        if ( (root->left && findPath(root->left, path, k)) || 
             (root->right && findPath(root->right, path, k)) ) 
            return true; 

        // If not present in subtree rooted with root, remove root from 
        // path[] and return false 
        path.pop_back(); 
        return false;
    }
    bool isCousins(TreeNode* root, int x, int y) {
       vector<int> path1, path2; 
  
    // Find paths from root to n1 and root to n1. If either n1 or n2 
    // is not present, return -1 
    findPath(root, path1, x);
    findPath(root, path2, y);
    if(path1.size()!=path2.size())
        return 0;
    int i,n=path1.size();
    for(i=0;i<n;i++){
        if(path1[i] != path2[i])
            break;
    }
    if(n - i > 1)
        return 1;
    else 
        return 0;  
    }
};

//Method2
class Solution {
public:
    vector<int> findInfo(TreeNode* root, int x, int level, int parent)
    {
        if(root == NULL)
            return {-1,-1};
        if(root->val == x)
            return {level, parent};
        vector<int> xInfo = findInfo(root->left, x, level+1, root->val);
        vector<int> yInfo = findInfo(root->right, x, level+1, root->val);
        if(xInfo[0]!=-1)
            return xInfo;
        else
            return yInfo;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> xInfo = findInfo(root, x, 0, root->val);
        vector<int> yInfo = findInfo(root, y, 0, root->val);
        if((xInfo[0]==yInfo[0])&&(xInfo[1]!=yInfo[1]))
            return true;
        return false;
    }
};