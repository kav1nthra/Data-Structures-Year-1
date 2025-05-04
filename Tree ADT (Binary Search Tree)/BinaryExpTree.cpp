//Program to construct expression tree
#include <iostream>
using namespace std;

class Tree{ //Design of tree
    typedef struct node{
        node* right;
        node* left;
        char data;
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

        //Function declarations
        node* constructExpressionTree(string);
        void preorder(node*);
        void inorder(node*);
        void postorder(node*);
};

int main(){
    Tree tree;
    int choice;
    string postfix;
    cout<<"Menu:\n\t";
    cout<<"1.Postfix Expression\n\t2.Construct Expression Tree\n\t3.Preorder\n\t4.Inorder\n\t5.Postorder\n\t6.Exit\n";
    cout<<"Enter choice: ";
    cin>>choice;
    while(true){ //Run till choice is 6
        if(choice<1 || choice>6){
            cout<<"Please enter a valid choice\n";
        }
        switch(choice){
            case 1:
                cout<<"Enter a valid postfix expression: ";
                cin>>postfix;
                break;
            case 2:
                tree.set(tree.constructExpressionTree(postfix));
                cout<<"Expression Tree Constructed";
                break;
            case 3:
                cout<<"Preorder: ";
                tree.preorder(tree.get());
                break;
            case 4:
                cout<<"Inorder: ";
                tree.inorder(tree.get());
                break;
            case 5:
                cout<<"Postorder: ";
                tree.postorder(tree.get());
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
Tree::node* Tree::constructExpressionTree(string postfix){ //Function to construct postfix expression from postfix
  stack<node*> st;
  for(char ch:postfix){
      node* newNode=(node*)malloc(sizeof(node));
      newNode->data=ch;
      newNode->left=newNode->right=NULL;

      if(isalnum(ch)){
          st.push(newNode);
      } 
      else {
          newNode->right=st.top(); 
          st.pop();
          newNode->left=st.top();
          st.pop();
          st.push(newNode);
      }
  }
  return st.top();
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

  