#include <iostream>
#include <string>

using namespace std;
int level = 0;
struct Node{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void preorder(struct Node *node){
    if(node == NULL)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node *node){
    if(node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void postorder(struct Node *node){
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout << "Pre-Order traversal of tree is " << endl;
    preorder(root);
    cout << endl;
    cout << "In-Order traversal of tree is " << endl;
    inorder(root);
    cout << endl;
    cout << "Post-Order traversal of tree is " << endl;
    postorder(root);
    return 0;
}