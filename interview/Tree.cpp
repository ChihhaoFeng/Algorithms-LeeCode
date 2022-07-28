#include<iostream>
#include<vector>
#include<stdlib.h>
#include <queue>

#include "Tree.h"
using namespace std;


TreeNode* Tree::CreateTree(vector<int> tree)   // 建立二叉樹
{
    TreeNode* root = NULL;

    for (int i = 0; i < tree.size(); i++)
    {
        root = BuildNode(root, tree[i]);
    }

    return root;
}

void Tree::LevelOrder(TreeNode* root) //將樹結構一層一層印出
{
    queue<TreeNode*> list;

    list.push(root);

    while (!list.empty())
    {
        TreeNode* temp = list.front();

        list.pop();

        cout << temp->val << ", ";

        if (temp->left) list.push(temp->left);
        if (temp->right) list.push(temp->right);
    }

}

void Tree::WhetherHeightBalance(TreeNode* root) //檢查是否為高度平衡樹
{
    if (BalanceTree(root))
    {
        cout << "\nIt is a balance tree" << endl;
    }
    else
    {
        cout << "\nIt is not a balance tree" << endl;
    }
}

void Tree::FreeTree(TreeNode* root)
{
    queue<TreeNode*> list;
    list.push(root);
    while (!list.empty())
    {
        TreeNode* temp = list.front();

        list.pop();

        if (temp->left) list.push(temp->left);
        if (temp->right) list.push(temp->right);

        free(temp);
    }
    cout << "Free whole Tree" << endl;

}

vector<int> Tree::preorderTraversal(TreeNode* root) {     //前序遍历

    vector<int> result = {};

    if (!root)
    {
        return result;
    }
    cout << "preorderTraversal: ";
    _preorderTraversal(root, result);

    cout << endl;

    return result;
}

vector<int> Tree::postorderTraversal(TreeNode* root) {   //後序遍历

    vector<int> result = {};

    if (!root)
    {
        return result;
    }
    cout << "postorderTraversal: ";

    _postorderTraversal(root, result);

    cout << endl;

    return result;
}




/// <summary>
/// private
/// </summary>

TreeNode* Tree::BuildNode(TreeNode* root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode();
        root->val = val;
        return root;
    }
    if (val < root->val)
    {
        root->left = BuildNode(root->left, val);
    }
    else
    {
        root->right = BuildNode(root->right, val);
    }

    return root;

}

bool Tree::BalanceTree(TreeNode* root)
{
    if (!root)
    {
        return true;
    }

    int righth, lefth;

    righth = Height(root->right, 0);


    lefth = Height(root->left, 0);



    if (abs(righth - lefth) > 1)
    {
        return false;
    }
    else
    {
        return BalanceTree(root->right) & BalanceTree(root->left);
    }

}

int Tree::Height(TreeNode* root, int height)
{
    int righth, lefth;

    if (!root)
    {
        return height;
    }


    height++;

    righth = Height(root->right, height);
    lefth = Height(root->left, height);

    return max(righth, lefth);

}

void Tree::_preorderTraversal(TreeNode* root, vector<int>& result)
{
    result.push_back(root->val);
    cout << root->val << ",";

    if (root->left) _preorderTraversal(root->left, result);
    if (root->right) _preorderTraversal(root->right, result);
}

void Tree::_postorderTraversal(TreeNode* root, vector<int>& result)
{



    if (root->left) _postorderTraversal(root->left, result);
    if (root->right) _postorderTraversal(root->right, result);

    result.push_back(root->val);
    cout << root->val << ",";
}
