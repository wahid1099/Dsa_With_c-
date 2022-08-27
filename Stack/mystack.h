// #include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<typename N> class Node{
    public:
    N value;
    Node* next;
    Node* prev;
    Node(N val){
        value = val;
        next=NULL;
        prev=NULL;
    }
};

//stack st--> 
template<typename S>  class Stack{
    Node <S>*head;
    Node <S>*top;
    Node <S> *mid;
       int count=0;
    public:

    Stack(){
        head=NULL;
        top=NULL;
        mid=NULL;
    }
     
    //push
    void push(S val) {
        Node <S> *newnode = new Node<S>(val);
        //////
       
       // int count=0;
        if(head==NULL){
            head=top=newnode;
             count++;
             mid=head;
            return;
        }
        top->next = newnode;
        newnode->prev =top;
        top=newnode;
         count++;
         if(count%2==0){
            mid=mid->prev;
         }
    }
    //pop
    S pop() {
        Node <S> *delnode ;
        delnode=top;
        S chk;
          if(head==NULL){
            cout<<"stack underflowed"<<endl;
           
            return chk;
          }
        if(top==head){
            head=top=NULL;
        }else{
            top=delnode->prev;
            top->next=NULL;
        }

        chk=delnode->value;
        count--;
        if(count%2!=0){
            mid=mid->next;
        }
        delete delnode;
         
        return chk;

    }
    //find mid
    // S Mid(){
    //     S midvalue;
    //     if(count==0){
    //         cout<<"Stack is empty!"<<endl;
    //         return -1;
    //     }
    //     midvalue=mid->value;
    //     return midvalue;
    // }
    //empty
    bool empty() {
        if(head==NULL) return true;
        else return false;
    }
    //size
    int size() {
       return count;
    }
    //top
    S Top(){
        S chk;
        if(top==NULL){
           cout<<"stack underflowed! there is no element on top"<<endl;
        }
        else{
            chk=top->value;
            
        }
        return chk;
    }

};
// int main()
// {
 

 
 
//   return 0;
// }