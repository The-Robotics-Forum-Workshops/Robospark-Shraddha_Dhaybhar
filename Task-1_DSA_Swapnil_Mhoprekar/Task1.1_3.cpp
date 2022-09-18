
//Implement binary search tree

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node* left;
    node* right;
}node;

node* create(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;

    return newnode;
}

void insert(node* root, int data){

    if(root==NULL)
        root = create(data);
    else if(data >= root->data)
        insert(root->right, data);
    else
        insert(root->left, data);
}

void inorder(node* root){
    if (root == NULL)  
        return;  
    inorder(root->left);
    cout<< root->data << "   "; 
    inorder(root->right); 
}

bool doesExist(node* root, int data)  
{  
    if (root == NULL)
        return false;
 
    if (root->data == data)
        return true;
 
    if(doesExist(root->left, data))
        return true;
    
    return doesExist(root->right, data);
} 

node* findMin(node* temp) 
{  
    while(temp->left != NULL) {  
        temp = temp->left;  
    }  
    return temp;  
}  

struct node* remove(node* root, int data)
{
    if (root == NULL)
        return root;
  
    if (data < root->data)
        root->left = remove(root->left, data);
  
    else if (data > root->data)
        root->right = remove(root->right, data);

    else {
        if (root->left==NULL and root->right==NULL)
            return NULL;
        
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
  
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    return root;
}

int main(){
    node* root = NULL;
    insert(root, 10);
    insert(root, 5);
    insert(root, 23);
    insert(root, 7);
    insert(root, 12);
    
    cout<<"The inorder traversal: ";
    inorder(root);
    doesExist(root, 4);
    doesExist(root, 5);

    remove(root, 5);
    cout<<"The inorder traversal: ";
    inorder(root);
}