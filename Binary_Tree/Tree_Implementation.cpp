#include <iostream>
#include <cstdlib>
#include <cstdio>
#include<queue>
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
void levelorderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
   
    while(q.size()>1){
        Node* front = q.front();
        q.pop(); 
        if(front == NULL){
        cout<<endl;
        q.push(NULL); 
        }
        else{
        cout<<front->data<<" ";
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
    }
    }
}
int main(){
    Node* root = createTree();
    // Example input for a tree with 4 levels:
    // Enter the following values when prompted:
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    // This will create the following tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    PreOrderTraversal_NLR(root);
    cout<<endl;
    InOrderTraversal_LNR(root);
    cout<<endl;
    PostOrderTraversal_LRN(root);
    cout<<endl;
    levelorderTraversal(root);
}