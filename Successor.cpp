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

int successor(struct Node *root, struct Node *node){
    int key = node->data;
    Node *current = root;
    while (current->left != NULL && current->right != NULL)
    {
        if(current->data < key)
            current = current->right;
        else
            current = current->left;
    }
    if(current->left != NULL)
        current = current->left;
    return current->data;
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

    struct Node *succc = new Node(10);
    cout << "The successor node is " << successor(root, succc) << endl;    
    return 0;
}