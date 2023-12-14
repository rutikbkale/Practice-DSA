// WAP for circular linkedlist.

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this->data=data;
            next = NULL;
        }
};

class LinkedList{

    public:
        Node *head;

        LinkedList(Node *head){
            this->head=head;
        }

        //Insertion at begining
        Node *insertAtBegin(int val){
            Node *newNode = new Node(val);
            Node *temp = head;
            do{
                temp=temp->next;
            }while(temp->next != head);
            temp->next=newNode;
            newNode->next=head;
            head=newNode;
            return head;
        }

        //Insertion at Ending
        void insertAtEnd(int val){
            Node *newNode = new Node(val);
            Node *temp = head;
            do{
                temp=temp->next;
            }while(temp->next != head);
            temp->next=newNode;
            newNode->next=head;
        }

        //Insertion at Specific position
        void insertAtIndex(int val, int index){
            Node *newNode = new Node(val);
            Node *temp = head;
            Node *p = head->next;
            for(int i=0; i<index-1; i++){
                temp=temp->next;
                p=p->next;
            }
            temp->next=newNode;
            newNode->next=p;
        }

        // Deleting At Begining
        void deleteAtBegin(){
            Node *temp = head;
            Node *p=head->next;
            do{
                temp=temp->next;
                p=p->next;
            }while(temp->next != head);
            temp->next=p->next;
            head=p->next;
            delete p;

        }

        // Deleting At Ending
        void deleteAtEnd(){
            Node *temp = head;
            Node *p=head->next;
            do{
                temp=temp->next;
                p=p->next;
            }while(p->next != head);
            temp->next=p->next;
            delete p;

        }

        void deleteAtIndex(int index){
            Node *temp = head;
            Node *p = head->next;
            for(int i=0; i<index-1; i++){
                temp=temp->next;
                p=p->next;
            }
            temp->next=p->next;
            delete p;
        }

        // Displaying elements
        void displayList(){
            Node *temp= head;
            cout<<"List Elements : ";
            do{
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }while(temp != head);
        }
};

int main(int argc, char const *argv[])
{
    Node *head=new Node(10);
    Node *second=new Node(20);
    head->next=second;
    second->next=head;
    LinkedList *list = new LinkedList(head);
    cout<<"\nInsertion At Begining : \n";
    head=list->insertAtBegin(5);
    head=list->insertAtBegin(1);
    list->displayList();
    cout<<"\nInsertion At Ending : \n";
    list->insertAtEnd(15);
    list->insertAtEnd(20);
    list->displayList();
    cout<<"\nInsertion At Specific position : \n";
    list->insertAtIndex(12,3);
    list->insertAtIndex(17,4);
    list->displayList();
    cout<<"\nDeletion At Begining : \n";
    list->deleteAtBegin();
    list->displayList();
    cout<<"\nDeletion At Ending : \n";
    list->deleteAtEnd();
    list->displayList();
    cout<<"\nDeletion At Specific position : \n";
    list->deleteAtIndex(3);
    list->displayList();
    return 0;
}