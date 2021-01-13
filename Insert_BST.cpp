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

Node* insert(struct Node *root, int elem){
    Node *new_node = new Node(elem);
    if(root == NULL)
        return new_node;
    Node *current = root;
    while (current->left != NULL && current->right != NULL)
    {
        if(current->data < elem)
            current = current->right;
        else
            current = current->left;
    }
    
    if(current->data < elem)
        current->right = new_node;
    else
        current->left = new_node;

    return root;
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

    Node *add = insert(root, 7);
    cout << "In-Order traversal of new tree is " << endl;
    inorder(add);
    cout << endl;
    Node *add_new = insert(root, 15);
    cout << "In-Order traversal of new tree is " << endl;
    inorder(add_new);
    return 0;
}