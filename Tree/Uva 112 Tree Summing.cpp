#include <bits/stdc++.h>

using namespace std;
int t;
bool ok;
struct Treenode{
    int val;
    Treenode *left;
    Treenode *right;
};
Treenode* buildtree(){
    int num;
    char ch1, ch2;
    Treenode* tnode = NULL;
    while(scanf("%c", &ch1) == 1){
        if(ch1 == '(') break;
    }
    if(scanf("%d", &num) == 1){
        tnode = new Treenode;
        tnode->val = num;
        tnode->left = buildtree();
        tnode->right = buildtree();
    }
    while(scanf("%c", &ch2) == 1){
        if(ch2 == ')') {
            break;
        }
    }
    return tnode;
}
void root2leaf(int sum, Treenode* node){
    sum += node->val;
    if(t == sum && node->left == NULL && node->right == NULL){
        ok = true;
        return;
    }
    if(node->left != NULL)
        root2leaf(sum, node->left);
    if(node->right != NULL)
        root2leaf(sum, node->right);
}
int main()
{

    while(scanf("%d", &t) == 1){
        ok = false;
        Treenode *root = buildtree();
        if(root == NULL){
            cout << "no\n";
            continue;
        }
        root2leaf(0, root);
        if(ok)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
