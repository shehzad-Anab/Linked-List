#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList()
        {
            head = nullptr;
        }

        void Display()
        {
            Node* temp = head;
            while (temp != nullptr)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void insertAtHead(int value)
        {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }

        void insertAtEnd(int value)
        {
            Node* newNode = new Node(value);
            
            if (head == nullptr)
            {
                head = newNode;
                return;
            }
            
            Node* temp = head;
            
            while (temp->next != nullptr)
            {
               temp = temp->next;
            }

            temp->next = newNode;
        }

        int sizeofLinkedlist()
        {
            int count = 0;
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
                count++;
            }
            return count;
        }

        void RemoveAnElement(int tar)
        {
            Node* previous = nullptr;
            Node* temp = head;

            while (temp != nullptr and temp->data != tar)
            {
                previous = temp;
                temp = temp->next;
            }
            
            if (temp == nullptr)
            {
                cout<<"Target Not Found! "<<endl;
                return;
            }
            
            if (previous == nullptr)
            {
                head = temp->next;
            }
            
            else
            {
                previous->next = temp->next;
            }
            
            delete temp;

            cout<<tar<<" Deleted Successfully. "<<endl;
        }

        bool findItem(int value)
        {
            Node* temp = head;
            
            while (temp != nullptr)
            {
                if (value == temp->data)
                {
                    return true;
                }
                
                temp = temp->next;
            }
            
            return false;
        }
};
int main()
{
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.Display();
    list.RemoveAnElement(10);
    list.Display();
    list.insertAtHead(10);
    list.Display();
    return 0;
}