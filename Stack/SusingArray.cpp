// // WAP to perform operations of Stack using Array.

#include<iostream>
using namespace std;

class Stack{

    public:
    int size;
    int top;
    int *arr;

    Stack(int size){
        top = -1;
        this->size = size;
        arr = new int[size];
    }

    void push(int val){
        if(top ==size-1){
            cout<<"Stack is full.\n";
        }
        else{
            arr[++top]=val;
        }
    }

    void pop(){
        if(top>=0){
            cout<<"Poped element is : "<<arr[top--]<<endl;
        }
        else{
            cout<<"Stack is empty.\n";
        }
    }

    void displayStack(){
        if(top ==-1){
            cout<<"Stack is empty.\n";
        }
        else{
            cout<<"Stack Element is : ";
            for(int i=top; i>=0; --i){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }

    void peek(){
        if(top ==-1){
            cout<<"Stack is empty.\n";
        }
        else{
            cout<<"Peek of the stack is  : "<<arr[top];
            cout<<endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    int size = 10;
    Stack *s = new Stack(size);
    s->push(5);
    s->peek();
    s->push(51);
    s->push(54);
    s->push(53);
    s->push(50);
    s->peek();
    s->displayStack();
    s->pop();
    s->peek();
    s->displayStack();
    return 0;
}

