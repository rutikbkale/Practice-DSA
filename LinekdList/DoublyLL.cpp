// WAP for doubly linkedlist.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList(Node *head)
    {
        this->head = head;
    }

    // Insert at begining
    void insertAtBegin(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at ending
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Insert at specific index
    void insertAtIndex(int val, int index)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            Node *p = head->next;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
                p = p->next;
            }
            temp->next = newNode;
            newNode->next = p;
            newNode->prev = temp;
        }
    }

    // Deleting at bigining
    void deleteAtBegin()
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
        }
        else
        {
            Node *temp = head;
            Node *p = head->next;
            p->prev = NULL;
            head = p;
            delete temp;
        }
    }

    // Delete at ending
    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
        }
        else
        {
            Node *temp = head;
            Node *p = head->next;
            while (p->next != NULL)
            {
                temp = temp->next;
                p = p->next;
            }
            temp->next = NULL;
            delete p;
        }
    }

    // Delete At specific index
    void deleteAtIndex(int index)
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
        }
        else
        {
            Node *temp = head;
            Node *p = head->next;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
                p = p->next;
            }
            temp->next = p->next;
            p->next->prev = temp;
            delete p;
        }
    }

    // Reverse the linkedlist
    void reverseList()
    {
        Node *current = head;
        Node *temp = NULL;
        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp; 
            current = current->prev;
        }
        if (temp != NULL)
        {
            head = temp->prev;
        }
    }

    // Displaying linkedlist
    void displayList()
    {
        Node *temp = head;
        cout << "List Elements : ";
        while (temp != NULL)
        {
            if (temp->next == NULL)
                cout << temp->data << " ";
            else
                cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    Node *head = new Node(10);

    LinkedList *list = new LinkedList(head);
    cout << "\nInsert At Begining : \n";
    list->insertAtBegin(5);
    list->insertAtBegin(1);
    list->displayList();
    cout << "\nInsert At Ending : \n";
    list->insertAtEnd(15);
    list->insertAtEnd(20);
    list->displayList();
    cout << "\nInsert At Index : \n";
    list->insertAtIndex(12, 3);
    list->insertAtIndex(17, 5);
    list->displayList();
    cout << "\nDelete At Begining : \n";
    list->deleteAtBegin();
    list->displayList();
    cout << "\nDelete At Ending : \n";
    list->deleteAtEnd();
    list->displayList();
    cout << "\nDelete At Index : \n";
    list->deleteAtIndex(3);
    list->displayList();
    cout << "\nReverse linkedlist : \n";
    list->reverseList();
    list->displayList();
    delete head;
    delete list;
    return 0;
}
