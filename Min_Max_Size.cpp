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

int size(struct Node *node)  
{  
    if (node == NULL)  
        return 0;  
    else
        return(size(node->left) + 1 + size(node->right));  
}

int min_BST(struct Node *node){
    if(node != NULL)
        node = node->left;
    return node->left->data;
}

int max_BST(struct Node *node){
    if(node != NULL)
        node = node->right;
    return node->right->data;
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

    cout << "Size of the tree is " << size(root) << endl;
    cout << "Minimum element in a BST is " << min_BST(root) << endl;
    cout << "Maximum element in a BST is " << max_BST(root) << endl;
    return 0;
}