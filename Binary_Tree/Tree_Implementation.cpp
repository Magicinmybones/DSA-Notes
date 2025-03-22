#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
    
};
Node* createTree(){
        cout<<"Enter the value: "<<endl;
        int data;
        cin>>data;
        if(data==-1){
            return NULL;
        }
       
        Node* root = new Node(data);
        root->left=createTree();
        root->right=createTree();
        return root;
    }
void PreOrderTraversal_NLR(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrderTraversal_NLR(root->left);
    PreOrderTraversal_NLR(root->right);
}
void InOrderTraversal_LNR(Node* root){
    if(root==NULL){
        return;
    }
    InOrderTraversal_LNR(root->left);
    cout<<root->data<<" ";
    InOrderTraversal_LNR(root->right);
}
void PostOrderTraversal_LRN(Node* root){
    if(root==NULL){
        return;
    }
    PostOrderTraversal_LRN(root->left);
    PostOrderTraversal_LRN(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root = createTree();
    PreOrderTraversal_NLR(root);
    InOrderTraversal_LNR(root);
}