// // WAP for singly linkedlist.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
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

    // Insertion At Begining
    void insertAtBegin(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insertion At Ending
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }

    // Insertion At Specific Position
    void insertAtIndex(int val, int index)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        Node *p = head->next;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
            p = p->next;
        }
        temp->next = newNode;
        newNode->next = p;
    }

    // Deleting At Begining
    void deleteAtBegin()
    {
        if (!head)
        {
            cout << "List is empty.\n";
        }
        else
        {
            Node *temp = head;
            head = temp->next;
            delete temp;
        }
        //return head;
    }

    // Deleting At Ending
    void deleteAtEnd()
    {
        if (!head)
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

    // Deleting At specific position
    void deleteAtIndex(int index)
    {
        if (!head)
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
            delete p;
        }
    }

    // Reverse the Linkedlist
    void reverseList()
    {
        Node *temp = head;
        Node *next = NULL;
        Node *prev = NULL;
        while (temp != NULL)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head=prev;
    }

    // Displaying LinkedList
    void displayList()
    {
        if (!head)
        {
            cout << "List is empty.\n";
        }
        else
        {
            Node *temp = head;
            cout << "List Elements : ";
            while (temp != NULL)
            {
                if (temp->next != NULL)
                    cout << temp->data << " -> ";
                else
                    cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Node *head = new Node(10);
    LinkedList *list = new LinkedList(head);
    cout << "\nInsertion At Begining : \n";
    list->insertAtBegin(5);
    list->insertAtBegin(1);
    list->displayList();
    cout << "\nInsertion At Ending : \n";
    list->insertAtEnd(15);
    list->insertAtEnd(20);
    list->displayList();
    cout << "\nInsertion At Specific position : \n";
    list->insertAtIndex(12, 3);
    list->insertAtIndex(17, 5);
    list->displayList();
    cout << "\nDeletion At Begining : \n";
    list->deleteAtBegin();
    list->displayList();
    cout << "\nDeletion At Ending : \n";
    list->deleteAtEnd();
    list->displayList();
    cout << "\nDeletion At Specific Index : \n";
    list->deleteAtIndex(2);
    list->displayList();
    cout << "\nReverse linkedlist : \n";
    list->reverseList();
    list->displayList();
    delete head;
    delete list;
    return 0;
}
