//Program to construct a Tree ADT
#include <iostream>
using namespace std;

class Tree{ //Design of tree
    typedef struct node{
        node* right;
        node* left;
        int data;
    }node;

    node* root;

    public:
        Tree(){
            root=NULL;
        }

        void set(node* value){
            root=value;
        }

        node* get(){
            return root;
        }
        
        //Functions Declarations
        node* insert(int,node*);
        void preorder(node*);
        void inorder(node*);
        void postorder(node*);
        bool search(node*,int);
};

int main(){
    Tree tree;
    int choice,value;
    cout<<"Menu:\n\t";
    cout<<"1.Insert\n\t2.Preorder\n\t3.Inorder\n\t4.Postorder\n\t5.Search\n\t6.Exit\n";
    cout<<"Enter choice: ";
    cin>>choice;
    while(true){ //Runs till choice is 6
        if(choice<1 || choice>6){
            cout<<"Please enter a valid choice\n";
        }
        switch(choice){
            case 1:
                cout<<"Enter value to insert: ";
                cin>>value;
                tree.set(tree.insert(value,tree.get()));
                break;
            case 2:
                cout<<"Preorder: ";
                tree.preorder(tree.get());
                break;
            case 3:
                cout<<"Inorder: ";
                tree.inorder(tree.get());
                break;
            case 4:
                cout<<"Postorder: ";
                tree.postorder(tree.get());
                break;
            case 5:
                cout<<"Enter character to search: ";
                cin>>value;
                cout<<(tree.search(tree.get(),value)?"Found":"Not Found");
                break;
            case 6:
                cout<<"Exiting program...\nProgram terminated\n";
                break;
        }
    if(choice==6){ //To exit loop 
        break;
    }
    cout<<"\n\nEnter choice: ";
    cin>>choice;
    }
    return 0;
}

//Function Declarations
Tree::node* Tree::insert(int value,node* temp){ //To insert new elements
    if(temp==NULL){
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=value;
        newnode->right=newnode->left=NULL;
        temp=newnode;
        return temp;
    }
    if(temp->data>value){
        temp->left=insert(value,temp->left);
        return temp;
    }
    temp->right=insert(value,temp->right);
    return temp;
}
void Tree::preorder(node* node){ //For preorder traversal and print nodes
    if(!node){
      return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
  }
  
  void Tree::inorder(node* node){ //For inorder traversal and print nodes
    if(!node){
      return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
  }
  
  void Tree::postorder(node* node){ //For postorder traversal and print nodes
    if(!node){
      return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
  }

  bool Tree::search(node* node,int key){ //To see if an element exists in the tree
    if(!node){
      return false;
    }
    if(node->data==key){
      return true;
    }
    return search(node->left,key)||search(node->right,key);
  }
  