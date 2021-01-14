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

int match_trees(struct Node *n1, struct Node *n2){
    if(n1 == NULL || n2 == NULL)
        return 0;
    if(n1 == NULL && n2 == NULL)
        return 1;
    if(n1->data != n2->data)
        return 0;    
    return match_trees(n1->left, n2->left) && match_trees(n1->right, n2->right);
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

    struct Node *root1 = new Node(8);
    root1->left = new Node(5);
    root1->right = new Node(10);
    root1->left->left = new Node(2);
    root1->left->right = new Node(6);
    root1->right->left = new Node(9);
    root1->right->right = new Node(20);
    root1->left->left->left = new Node(1);
    root1->right->right->right = new Node(30);
    root1->right->right->right->right = new Node(40);

    cout << "Checking if the trees are identical gives " << match_trees(root, root1) << endl;
    return 0;
}