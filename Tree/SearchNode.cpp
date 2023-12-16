// WAP for searching a node in a BST.

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node *serchingNode(Node *root, int val){
    if(root->data==val || root==NULL){
        return root;
    }
    else if(root->data > val){
        return serchingNode(root->left, val);
    }
    else{
        return serchingNode(root->right, val);
    }
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int val;
    cout<<"Enter the Node To be search : ";
    cin>>val;

    Node *result =serchingNode(root, val);

    if(result == NULL){
        cout<<"Node not found.";
    }
    else{
        cout<<val<<" Node is present in BST.";
    }
    return 0;
}
