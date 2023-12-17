// WAP to traverse binary tree.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *insertNode(Node *root,int val){
if(root==NULL)
return new Node(val);
if(root->data < val)
root->right=insertNode (root->right,val);
else
root->left=insertNode (root->left,val);
return root;
}

    void inOrder(Node *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

    void preOrder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void postOrder(Node *root)
    {
        if (root != NULL)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }
    }

int main()
{
    Node *root =  NULL;
root=insertNode (root,5);
insertNode (root,2);
insertNode (root,4);
insertNode (root,3);
insertNode (root,6);
insertNode (root,7);
insertNode (root,8);

    cout << "Inorder Traversal : \n";
    inOrder(root);
    cout << endl;
    cout << "Preorder Traversal : \n";
    preOrder(root);
    cout << endl;
    cout << "Postorder Traversal : \n";
    postOrder(root);
    return 0;
}
