//Header file containg push, pop and peek function 
#ifndef STACKADT_H
#define STACKADT_H

#include<iostream>
using namespace std;

class Stack{
    public:
    typedef struct node{
        char data;
        node* next;
    }node;

    node* top;

    Stack(){
        top=NULL;
    }

    int push(char);
    char pop();
    char peek();
    void display();
    bool isEmpty();
};

//Function to push a element into a singly linked list.
int Stack::push(char c){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=c;
    if(top==NULL){
        newnode->next=NULL;
        top=newnode;
        return 1;
    }
    newnode->next=top;
    top=newnode;
    return 1;
}

//Function to pop a element from a singly linked list.
char Stack::pop(){
    if(top==NULL){
        cout<<"Stack underflow!!";
        return 0;
    }
    node* temp=top;
    char a=temp->data;
    top=temp->next;
    free(temp);
    return a;
}

//Functio to view the last pushed element.
char Stack::peek(){
    if(top==NULL){
        cout<<"Stack underflow!!";
        return 0;
    }
    char a=top->data;
    return a;
}

// Check if stack is empty
bool Stack::isEmpty() {
    return top == nullptr;
    }

#endif