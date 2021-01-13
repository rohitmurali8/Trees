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

bool lookup(struct Node *node, int elem)
{
    if(node == NULL)
        return false;
    else
    {
        if (node->data == elem)
            return true;
        else if(node->data < elem)
            return lookup(node->right, elem);
        else
            return lookup(node->left, elem);
    }
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

    cout << "Checking if the number 5 is present in the tree is " << lookup(root, 5) << endl;
    return 0;
}