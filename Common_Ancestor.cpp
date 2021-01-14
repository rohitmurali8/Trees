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

struct Node *ancestor(struct Node *root, int first, int second){
    if(root == NULL)
        return NULL;
    if(root->data == first || root->data == second)
        return root;
    if (ancestor(root->left, first, second) && ancestor(root->right, first, second))
        return root;
    else
        return ancestor(root->left, first, second) ? ancestor(root->left, first, second) : ancestor(root->right, first, second);
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

    Node *LCA = ancestor(root, 9, 20);
    cout << "Data at node which is the Lowest Common Ancestor is " << LCA->data << endl;
    return 0;
}