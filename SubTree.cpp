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
    //cout << endl; 
}

int match_trees(struct Node *first, struct Node *second){
    if(first == NULL || second == NULL)
        return 0;
    if(first == NULL && second == NULL)
        return 1;
    if(first->data != second->data)
        return 0;    
    return match_trees(first->left, second->left) && match_trees(first->right, second->right);
}

int subtree(struct Node *n1, struct Node *n2){
    int key = n2->data;
    Node *current = n1;
    while(current->data != key){
        if(current->data < key)
            current = current->right;
        else
            current = current->left;
    }
    inorder(current);
    inorder(n2);
    int sub = match_trees(current, n2);
    return sub;
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

    struct Node *root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(6);
    root1->left->left = new Node(1);
    //root1->left->right = new Node(6);

    cout << "Checking if the second tree is a subtree of the original tree is " << subtree(root, root1) << endl;
    return 0;
}