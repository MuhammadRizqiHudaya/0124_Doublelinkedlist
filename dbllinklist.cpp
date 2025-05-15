#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
        {
            START = NULL;
        }

    void addnode()
    {
        int nim;
        cout << "\n enter the roll number of the student :";
        cin >> nim;

        // step 1 allocate memory for new node
        Node *newNode = new Node();

        //step 2 assign value
        newNode->noMhs = nim;

        //step 3 insert at the beginning
        if (START == NULL || nim == START ->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate not allowed" << endl;
                return;
            }
            //step 4 newnode.next = start
            newNode->next = START;

            //step 5  START.prev = newNode
            if(START !=NULL)
            START->prev = newNode;

            //Step 6 Newnode. prev = NULL
            newNode->prev = NULL;

            //step 7 START = newNode
            START = newNode;
            return;
        }

        //Step 8 locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate not allowed" << endl;
            return;
        }

        //step 9 insert between current and current->next
        newNode->next = current->next; // step 9a: newNode.next = current.next
        newNode->prev = current; //step 9b: newNode.prev = current 

        //insert last node
        if(current->next != NULL)
            current->next->prev = newNode; //step 9c : current.next.prev = newNode
        current->next = newNode; // step 9d : current.next = newbie
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nMasukkan nim yang akan dihapus:";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        
    }   

};