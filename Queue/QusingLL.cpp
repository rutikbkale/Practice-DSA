// WAP for queue using linkedlist.

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

class Queue
{
public:
    Node *front, *rear;

    Queue(Node *head)
    {
        front = rear = head;
    }

    void enQueue(int val)
    {
        Node *newNode = new Node(val);
        if (!front)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deQueue()
    {
        if (!front || !rear)
        {
            cout << "Queue is empty.\n";
        }
        else
        {
            Node *temp = front;
            cout << "Poped Element : " << temp->data << endl;
            front = temp->next;
            delete temp;
        }
    }

    void displayQueue()
    {
        if (!front || !rear)
        {
            cout << "Queue is empty.\n";
        }
        else
        {
            Node *temp = front;
            cout << "Queue Element : ";
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
    Queue *q = new Queue(head);
    q->enQueue(20);
    q->enQueue(30);
    q->enQueue(40);
    q->enQueue(50);
    q->displayQueue();
    q->deQueue();
    q->displayQueue();
    delete head;
    delete q;
    return 0;
}
