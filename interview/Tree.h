#pragma once
#include<vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Tree
{
public:

    TreeNode* CreateTree(vector<int> tree);   // 建立二叉樹


    void LevelOrder(TreeNode* root); //將樹結構一層一層印出
    

    void WhetherHeightBalance(TreeNode* root); //檢查是否為高度平衡樹
    

private:
    TreeNode* BuildNode(TreeNode* root, int val);
    

    bool BalanceTree(TreeNode* root);
    

    int Height(TreeNode* root, int height);
    
};