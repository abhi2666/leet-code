/*
This technique is used to traverse a tree in a more efficient manner.
Morris Inorder/Preorder --> TC - O(n) and SC - O(1)
Normal Inorder/Preorder --> TC - O(n) and SC - O(1)

Approach -->
1. Create a threaded Binary Tree and then use that tree to find In or pre order
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

    // default useless constructor
    TreeNode()
    {
        data = 0;
    }

    // to define each node while creating
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }

    vector<int> morrisInorder(TreeNode *root)
    {
        vector<int> inorder(3, -1);
        TreeNode *curr = root;
        if (root == NULL)
            return inorder;
        inorder.clear();
        while (curr != NULL)
        {
            // check if there is no left
            if (curr->left == NULL)
            {
                // there is no left..store the curr element and move right
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                // if there exist left node then create a move one step left
                // and then move to the extreme right from there
                TreeNode *prev = curr->left;               // so that we don't have to move curr
                while (prev->right && prev->right != curr) // checking
                {                                          // if there does exist a thread or not.

                    prev = prev->right;
                }
                // if there does not exist a thread..make a thread
                if (prev->right == NULL) // no thread is there
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    // if there exist a thread..then remove the thread and store
                    //  the curr.
                    prev->right = NULL; // thread removed
                    // store curr value
                    inorder.push_back(curr->data);
                    // move curr to right because left part is already processed.
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }

    vector<int> morrisPreorder(TreeNode *root)
    {
        vector<int> preorder(3, -1);
        TreeNode *curr = root;
        if (root == NULL)
            return preorder;
        preorder.clear();
        while (curr != NULL)
        {

            if (curr->left == NULL)
            {
                preorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                {

                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    preorder.push_back(curr->data);
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};

int main()
{
    // creating a binary tree..
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    root->left = node1;
    root->right = node2;

    TreeNode obj;
    vector<int> Preorder = obj.morrisPreorder(root);
    cout << "Preorder (Morris) is -->"
         << " ";
    for (auto i : Preorder)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
