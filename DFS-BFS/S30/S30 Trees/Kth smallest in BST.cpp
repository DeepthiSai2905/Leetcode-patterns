#include <bits/stdc++.h>
using namespace std;
/*


*/
void inOrderTraversal(TreeNode* root, int &count, int &result){
    if(!root) return ;
    inOrderTraversal(root->left, count, result);
    count--;
    if(count==0) {
        result=root->val;
        return ;
    }
    inOrderTraversal(root->right, count, result);
}
int kthSmallest(TreeNode* root, int k) {
    int count=k;
    int result;
    inOrderTraversal(root, count, result);
    return result;
}