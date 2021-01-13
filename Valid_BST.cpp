#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Node{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void inorder(struct Node *node){
    if(node != NULL){
        inorder(node->left);
        int data = node->data;
        cout << data << " ";
        inorder(node->right);
    }
}

int isBST(struct Node *node, int min, int max){
    if(node == NULL)
        return 1;
    
    if(node->data < min || node->data > max)
        return 0;

    return isBST(node->left, min, node->data - 1) && isBST(node->right, node->data + 1, max);
}

int main(){
    struct Node *root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(20);
    root->left->left->left = new Node(1);
    root->right->right->right = new Node(30);
    root->right->right->right->right = new Node(40);

    cout << "Checking if modified tree is a BST is " << isBST(root, INT16_MIN, INT16_MAX) << endl;

    return 0;
}