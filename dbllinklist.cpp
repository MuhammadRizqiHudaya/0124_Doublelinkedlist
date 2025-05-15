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

        Node *newNode = new Node();


        newNode->noMhs = nim;

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
    }
};