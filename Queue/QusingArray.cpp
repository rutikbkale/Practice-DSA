// WAP for to implement Queue operation on using array.
#include<iostream>
using namespace std;

class Queue {
public:
    int size;
    int front;
    int rear;
    int *arr;

    Queue(int size) {
        front = rear = -1;
        this->size = size;
        arr = new int[size];
    }

    void enQueue(int val) {
        if (rear == size - 1) {
            cout << "Queue is full.\n";
        } else {
            arr[++rear] = val;
        }
    }

    int deQueue() {
        int a = -1;
        if (front <= rear) {
            a = arr[++front];
        } else {
            cout << "Queue is empty.\n";
        }
        return a;
    }

    void displayQueue() {
        if (front <= rear) {
            cout << "Elements in Queue : ";
            for (int i = front + 1; i <= rear; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Queue is empty.\n";
        }
    }
};

int main() {
    int size = 10;

    Queue *q = new Queue(size);
    q->enQueue(10);
    q->enQueue(20);
    q->enQueue(30);
    q->enQueue(40);
    q->displayQueue();
    cout << "Removed element is : " << q->deQueue() << endl;
    q->displayQueue();

    delete q;  

    return 0;
}
