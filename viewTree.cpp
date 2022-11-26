/*
Program to see the left and the right view of a tree

Approach-->
Right-view of Tree --
0. use postorder type of traversal where you move root-right-left.
1. We will use a DS to store all nodes on the right according to their level.
2. Once over..we will move to left sub-Tree and there we will look for new
level if there exist any and add that node to DS.
*/

#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode() { data = 0; }
    // Init
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }

    void preOrder(TreeNode *root)
    {
        if (root)
        {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void rightView(TreeNode* root, int level, vector<int> &ansr)
    {
        if(root == NULL)
        {
            return;
        }
        if(level == ansr.size()) 
        {
            ansr.push_back(root->data); //store the node
        }
        rightView(root->right, level + 1, ansr);
        // now move to left because there can also be a node that is 
        // visible from left
        rightView(root->left, level + 1, ansr);
    }

    void leftView(TreeNode* root, int level, vector<int> &ansl)
    {
        if(root == NULL)
        {
            return;
        }
        if(level == ansl.size()) 
        {
            ansl.push_back(root->data); //store the node
        }
        leftView(root->left, level + 1, ansl);
        // now move to left because there can also be a node that is 
        // visible from left
        leftView(root->right, level + 1, ansl);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(5);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);

    root->left = n1;
    root->right = n2;
    root->left->right = n3;
    root->left->right->left = n4;

    // preorder traversal of tree
    TreeNode obj;
    // obj.preOrder(root);
    vector<int> ansRight;
    obj.rightView(root, 0, ansRight); // (root, level(initally = 0), vector)

    cout<< "Right View --> ";
    for(auto i : ansRight)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //left view
    vector<int> ansLeft;
    obj.leftView(root, 0, ansLeft);

     cout<< "left View --> ";
    for(auto i : ansLeft)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}