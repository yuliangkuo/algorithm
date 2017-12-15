#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

/*
 * You are given a pointer to the root of a binary tree. Print the top view of the binary tree.
 * Top view means when you look the tree from the top the nodes you will see will be called the top view of the tree. See the example below.
 * You only have to complete the function.
 * For example :
 *
 *  1
 *   \
 *    2
 *     \
 *      5
 *     /  \
 *    3    6
 *     \
 *      4
 *
 *   Top View : 1 -> 2 -> 5 -> 6
 */

/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

/*                
 * Specify a distence map where root is 0, -1 if go left and +1 if go right. The number of distance will be
 * (2 * height) + 1. We need to record the value of the topmost node among all nodes with the same distance (level-order)
 * 
 *  -3   -2   -1    0   +1   +2   +3
 *             +----o----+
 *             |         |
 *        +----o----+----o----+
 *        |         |         |
 *   +----o----+----o----+----o----+
 *   |         |         |         |
 *   o         o         o         o
 *
 */

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

// function to create a new node
node* newNode(int key)
{
    node *n = (node *)malloc(sizeof(node));
    n->data= key;
    n->left = n->right = NULL;

    return n;
}

/***
 *  @param root: The tree root
 *  @return: the node printed and separated by space
 */
void topView(node *root) {    
    queue <pair<node *, int> > q;
    unordered_map<int, int> m;
    
    if (!root) return;
    
    q.push(make_pair(root, 0));
    
    while (!q.empty()) {
        pair<node *, int> elem = q.front();
        int distance = elem.second;
        node *p = elem.first;

        q.pop();

        if (m.find(distance) == m.end()) {
            m.insert(make_pair(distance, p->data));
            cout << p->data << " ";
        }
        
        if (p->left)
            q.push(make_pair(p->left, elem.second-1));

        if (p->right)
            q.push(make_pair(p->right, elem.second+1));
    }   
}


int main(void)
{
    /* Create following Binary Tree
             1
           /  \
          2    3
           \
            4
             \
              5
               \
                6*/
                 
    node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->right=newNode(4);
    root->left->right->right=newNode(5);
    root->left->right->right->right=newNode(6);
     
    topView(root);
    return 0;

    // Wrong Answer below but passed in Hackerrank

/*
void for_left(node * root)
{
    if(root->left!=NULL)
        for_left(root->left);

    cout<<root->data<<" ";
}


void for_right(node * root)
{
    cout<<root->data<<" ";
    if(root->right!=NULL)
        for_right(root->right);
}

void topView(node * root)
{
    if(root->left!=NULL)
        for_left(root->left);

    cout<<root->data<<" ";
    
    if(root->right!=NULL)
        for_right(root->right);
    
}
 */

}
