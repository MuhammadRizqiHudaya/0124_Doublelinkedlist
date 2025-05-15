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

        // step 1 : traverse the list to find the node
        while(current !=  NULL && current->noMhs != rollNo)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "record not found" << endl;
            return;
        }

        //Step 2
        if (current == START)
        {
            START = current->next; //step 2a : START = START.next
            if (START != NULL)
            {
                START->prev = NULL; // step 2b : START.prev = NULL
            }
        }
        else
        {
            //step 3 : link previous node to next node
            current->prev->next = current->next; 

            //step 4 : if current is not the last node
            if(current->next != NULL)
            current->next->prev = current->prev;
        }

        //step 5 : delete the node
        delete current;
        cout << "record with roll number " << rollNo << " deleted" << endl;
    }
    
    void traverse()
    {
        if(START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        //step 1 : mark first node
        Node *currentNode = START;

        //step 2 : repeat until currentNode == NULL
        cout << "\nrecords in ascending order of roll number are :\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << 1 + 1 << "." << currentNode->noMhs << "" << endl;

            // step 3 : move to next node
            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // step 1 : move to last node
        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }

        //step 2 : traverse backward
        cout << "\nrecords in descending order of roll number are :\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << "." << currentNode->noMhs << "" << endl;

            // step 3 : move to previous node
            currentNode = currentNode->prev;
            i--;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        //Step 1 : traverse to find matching roll number
        while (current != NULL && current->noMhs != rollNo)
        current = current->next;

        //step 2 : ouput result
        if (current == NULL)
        {
            cout << "record not found\n";
        }
        else
        {
            cout << "record found\n";
            cout << "roll number :" << current->noMhs << endl;
        }
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add record\n";
        cout << "2. Delete record\n";
        cout << "3. view ascending\n";
        cout << "4. view descendingt\n";
        cout << "5. Search record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case '1':
                list.addnode();
                break;
            case '2':
                list.hapus();
                break;
            case '3':
                list.traverse();
                break;
            case '4':
                list.revtraverse();
                break;
            case '5':
                list.searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "Invalid option\n" << endl;
        }
        cout << "\nPress any key to continue...\n";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    }while (choice != '6');
}