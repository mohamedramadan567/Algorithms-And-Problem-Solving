#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{   
public:
    class Node
    {
    public:
        T value;
        Node* next;
        Node* prev;

    };
    Node* head;
    clsDblLinkedList()
    {
        head = NULL;
    }

    void InsertAtBeginning(T value)
    {
        Node* newNode = new Node();

        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL)
        {
            head->prev = newNode;
        }

        head = newNode;
    }

    void PrintList()
    {
        Node* Current = head;
        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << endl;
    }

    Node* Find(T Value)
    {
        Node* Current = head;
        while (Current != NULL) {

            if (Current->value == Value)
                return Current;


            Current = Current->next;
        }

        return NULL;

    }

    void InsertAfter(Node* current, T value)
    {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    void InsertAtEnd(T value)
    {
        Node* newNode = new Node();
        newNode->value = value;

        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
        }
        else
        {
            Node* Current = head;
            while (Current->next != NULL)
            {
                Current = Current->next;
            }

            newNode->prev = Current;
            Current->next = newNode;

        }
    }

    void DeleteNode(Node*& NodeToDelete)
    {
        //لو هو شغل دماغه وبعت الليست فاضية او النود اللي هتتحذف مش موجودة 
        if (head == NULL || NodeToDelete == NULL)
        {
            //ارجع يصاحبي مفيش حاجة تتمسح احنا هنهزر
            return;
        }

        if (head == NodeToDelete)
        {
            head = NodeToDelete->next;
        }

        if (NodeToDelete->next != NULL)
        {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }

        if (NodeToDelete->prev != NULL)
        {
            NodeToDelete->prev->next = NodeToDelete->next;
        }

        delete NodeToDelete;
    }

    void DeleteFirstNode()
    {
        if (head == NULL)
        {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
    }

    void DeleteLastNode()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = NULL;
        delete temp;
    }
};

