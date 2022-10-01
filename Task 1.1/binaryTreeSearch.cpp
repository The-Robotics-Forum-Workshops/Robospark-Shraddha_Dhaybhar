
# include <iostream>
# include <stack>
# include <stdlib.h>

struct BstNode 
{
 int value;
 BstNode* left;
 BstNode* right;
 //Bstnode* root;
};
struct BstNode* Insert(struct BstNode* node, int v)
{
 if(node == NULL)
 {
  node = new BstNode;
  node->value = v;
  node->left = NULL;
  node->right = NULL;
 }
 else if (node->value < v)
 {
  node->right = Insert(node->right, v);
 }
 else
 {
  node->left = Insert(node->left, v);
 }
 return node;
}
bool Search(struct BstNode* node, int k) 
{
 while (node != NULL) {

  if (k < node->value) 
  node = node->left;

  else if (k > node->value) 
   node = node->right;

  else {
   return true; 
  }
 }
 return false;
}

void inorder(struct Bstnode* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
int main(){
   struct Bstnode* root = NULL;
    root=Insert(root ,34);
    Insert(root, 89);
    Insert(root, 78);
    Insert(root, 45);
    Insert(root, 24);
    
};
