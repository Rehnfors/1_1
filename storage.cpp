
#include <iostream>

using namespace std;


/**
 * @brief Assignment 1_1 Datastructures
 * @author Jesper Rehnfors
 * Email: jesper.rehnfors@studerande.movant.se
 */

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data;
        next = NULL;
    }

    // Constructor with data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Storage
{
public:
    Node *head;

    /** Default constructor
     *
     */
    Storage()
    {
        head = NULL;
    }

    /** Create a Node to hold the data, then put it at the head of the list.
     * @param data The data for the new node
     */
    void push(int data)
    {
        Node *node = new Node(data);

        if (this->head == NULL)
        {
            this->head = node; //setting storage head to node, if storage head is a null pointer
            return; 
        }

        node->next = this->head; //connecting new node to the list
        this->head = node; //setting the new node as head
    }

    /** Remove the head Node and return its data.
     *
     * @param [out] The data (only valid if return true)
     * @return True if there is a node to return
     */
    bool pop(int &data)
    {
        Node *node = this->head; // setting node to storage head

        if (node == NULL)
            return false;

        cout << node->data << endl;
        this->head = node->next; // Moving head to the next node
        return true;
    }

    /**
     * Return the data from the head Node, without removing it.
     *
     * @param [out] The data (only valid if return true)
     * @return True if text has been returned successfully (there is a node)
     */
    bool peek(int &data)
    {
        Node *node = this->head;

        if (node == NULL)
        {
            cout << "NULL" << endl;
            return false;
        }

        cout << node->data << endl;
        return true;
    }

    /**
     * Return True if the list is empty, otherwise False
     *
     * @return True if the list is empty, otherwise False
     */
    bool isEmpty(int &data)
    {
        Node *node = this->head;

        if (node == NULL)
            return true;
        else
            return false;
    }

    bool swap(int x, int y)
    {   
        if (x == y) //nothing can be done if they are referring to the same position
            return false;

        Node *prevX = NULL;
        Node *currX = this->head;

        //search for x
        while (currX->data != x)
        {
            prevX = currX;
            currX = currX->next;
        }

        Node *prevY = NULL;
        Node *currY = this->head;

        //search for y
        while (currY->data != y)
        {
            prevY = currY;
            currY = currY->next;
        }

        if (currX == NULL || currY == NULL) //Nodes cant be swapped if one of them is a NULL-pointer
            return false;

        if (prevX != NULL)
            prevX->next = currY;
        else // Else make y as new head
            this->head = currY;

        // If y is not head of linked list
        if (prevY != NULL)
            prevY->next = currX; //
        else // Else make x as new head
            this->head = currX;

        // Swap next pointers
        Node *temp = currY->next; // temp keeps track of the remaining part of the list, or else it will be lost
        currY->next = currX->next;
        currX->next = temp;
        return true;
    }

    void printList()
    {
        Node *node = this->head;

        while (node != NULL)
        {
            cout << node->data << endl;
            node = node->next;
        }
    }
};

int main(int argc, const char *argv[])
{
    Storage *s = new Storage();
    int pop, peek, huh;

    // Pushing 3 elements to the stack
    s->push(2);
    s->push(4);
    s->push(10);

    // popping all elements from the stack
    s->pop(pop);
    s->pop(pop);
    s->pop(pop);

    // peeking at the first element in the stack, should be null
    s->peek(peek);

    // pushing one element to the stack and then peeking. Should show 2.
    s->push(2);
    s->peek(peek);

    // the list is not empty, it should show 0.
    s->isEmpty(huh);
    cout << "Is the list empty?:  " << huh << endl;

    s->push(3);
    s->push(1);

    cout << "Before nodes are swapped: " << endl;
    s->printList();
    if ((s->swap(2, 3)) == true)
    {
        cout << "Nodes swapped" << endl;
    }

    cout << "After nodes are swapped: " << endl;
    s->printList();
}
