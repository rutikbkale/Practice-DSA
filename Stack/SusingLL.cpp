// WAP for performing operations on stack using linkedlist.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
public:
    Node *top;

    Stack(Node *top)
    {
        this->top = top;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (!top)
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            Node *temp = top;
            cout << "poped Element is : " << temp->data << endl;
            top = temp->next;
            delete temp;
        }
    }

    void displayStack()
    {
        if (!top)
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            Node *temp = top;
            cout << "Element is : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Node *head = new Node(10);
    Stack *s = new Stack(head);
    s->push(20);
    s->push(30);
    s->push(40);
    s->push(50);
    s->displayStack();
    s->pop();
    s->displayStack();
    return 0;
}
