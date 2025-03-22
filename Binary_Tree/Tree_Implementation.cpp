#include <iostream>
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
    
}
Node* createTree{
        cout<<"Enter the value: "<<endl;
        int data;
        cin>>data;
        Node* root = new Node(data);
        root->left=createTree();
        root->right=createTree();
        return root;
    }
int main(){
    Node* root = createTree();
}