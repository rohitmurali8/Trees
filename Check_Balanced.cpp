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

int max_depth(struct Node *node){
    if(node == NULL)
        return 0;
    else
    {
        return (max_depth(node->right) > max_depth(node->left)) ? max_depth(node->right)+1 : max_depth(node->left)+1;
    }
}

int min_depth(struct Node *node){
    if(node == NULL)
        return 0;
    else
    {
        return (min_depth(node->right) > min_depth(node->left)) ? min_depth(node->left)+1 : min_depth(node->right)+1;
    }
}

bool balanced(struct Node *node){
    int max = max_depth(node);
    int min = min_depth(node);
    if(max - min <= 1)
        return true;
    else
        return false;
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

    cout << "Maximum Depth of the BST is " << max_depth(root) << endl;
    cout << "Minimum Depth of the BST is " << min_depth(root) << endl;
    cout << "Checking if the BST is balanced is " << balanced(root) << endl;
    return 0;
}    