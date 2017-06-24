#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node* left, *right;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
 
void findLeafDown(Node *root, int lev, int *minDist)
{
    if (root == NULL)
        return ;
    if (root->left == NULL && root->right == NULL)
    {
    
        if (lev < (*minDist))
            *minDist = lev;
        return;
    }
    findLeafDown(root->left, lev+1, minDist);
    findLeafDown(root->right, lev+1, minDist);
}
 
int findThroughParent(Node * root, Node *x, int *minDist)
{
    if (root == NULL) return -1;
    if (root == x) return 0;
 
    int l = findThroughParent(root->left, x,  minDist);
 
    if (l != -1)
    {
        findLeafDown(root->right, l+2, minDist);
        return l+1;
    }
 
    int r = findThroughParent(root->right, x, minDist);
 
    if (r != -1)
    {
        findLeafDown(root->left, r+2, minDist);
        return r+1;
    }
 
    return -1;
}
 
int minimumDistance(Node *root, Node *x)
{
    int minDist = INT_MAX;

    findLeafDown(x, 0, &minDist);
 
    findThroughParent(root, x, &minDist);
 
    return minDist;
}
 
int main ()
{
    Node *root  = newNode(1);
    root->left  = newNode(12);
    root->right = newNode(13);
 
    root->right->left   = newNode(14);
    root->right->right  = newNode(15);
 
    root->right->left->left   = newNode(21);
    root->right->left->right  = newNode(22);
    root->right->right->left  = newNode(23);
    root->right->right->right = newNode(24);
 
    root->right->left->left->left  = newNode(1);
    root->right->left->left->right = newNode(2);
    root->right->left->right->left  = newNode(3);
    root->right->left->right->right = newNode(4);
    root->right->right->left->left  = newNode(5);
    root->right->right->left->right = newNode(6);
    root->right->right->right->left = newNode(7);
    root->right->right->right->right = newNode(8);
 
    Node *x = root->right;
 
    cout << "The closest leaf to the node with value "
         << x->key << " is at a distance of "
         << minimumDistance(root, x) << endl;
 
    return 0;
}
