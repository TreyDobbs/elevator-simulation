// --------------------------------------------------------------------------
// Name: Trey Dobbs
// Description: This C++ project implements all the required pieces for the 
// SimBuilding class to build a building elevator simulation. Creation of the
// class constructor, the step method, and the printServiceStats() method are
// the emphasis of this project.
// --------------------------------------------------------------------------
#ifndef H_unorderedLinkedList
#define H_unorderedLinkedList

#include <iostream>
#include <cassert>

#include "Node.h"

using namespace std;

//*****************  class unorderedLinkedList   ****************
template <class Type>
class unorderedLinkedList
{
public:
    const unorderedLinkedList<Type>& operator=
                         (const unorderedLinkedList<Type>&);
      //Overload the assignment operator.

    void initializeList();
      //Initialize the list to an empty state.
      //Postcondition: first = nullptr, last = nullptr,
      //               count = 0;

    bool isEmptyList() const;
      //Function to determine whether the list is empty.
      //Postcondition: Returns true if the list is empty,
      //               otherwise it returns false.

    void print() const;
      //Function to output the data contained in each node.
      //Postcondition: none

    int length() const;
      //Function to return the number of nodes in the list.
      //Postcondition: The value of count is returned.

    void destroyList();
      //Function to delete all the nodes from the list.
      //Postcondition: first = nullptr, last = nullptr,
      //               count = 0;

    int front() const;
      //Function to return the first element of the list.
      //Precondition: The list must exist and must not be
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the first
      //               element of the list is returned.

    int back() const;
      //Function to return the last element of the list.
      //Precondition: The list must exist and must not be
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the last
      //               element of the list is returned.

    bool search(const Type& );
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the
      //               list, otherwise the value false is
      //               returned.

    void insert(const Type& );
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the list,
      //               and count is incremented by 1.


    void deleteNode(const Type& );
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated
      //               list, and count is decremented by 1.


    unorderedLinkedList();
      //Default constructor
      //Initializes the list to an empty state.
      //Postcondition: first = nullptr, last = nullptr,
      //               count = 0;

    unorderedLinkedList(const unorderedLinkedList<Type>& otherList);
      //copy constructor

    ~unorderedLinkedList();
      //Destructor
      //Deletes all the nodes from the list.
      //Postcondition: The list object is destroyed.

    nodeType<Type>* getFirst();

protected:
    int count;   //variable to store the number of
                 //elements in the list
    nodeType<Type> *first; //pointer to the first node of the list
    nodeType<Type> *last;  //pointer to the last node of the list

private:
    void copyList(const unorderedLinkedList<Type>& otherList);
      //Function to make a copy of otherList.
      //Postcondition: A copy of otherList is created and
      //               assigned to this list.
};

template <class Type>
nodeType<Type>* unorderedLinkedList<Type>::getFirst(){
        return first;
}
template <class Type>
bool unorderedLinkedList<Type>::isEmptyList() const
{
    return (first == nullptr);
}
template <class Type>
unorderedLinkedList<Type>::unorderedLinkedList() //default constructor
{
    first = nullptr;
    last = nullptr;
    count = 0;
}
template <class Type>
void unorderedLinkedList<Type>::destroyList()
{
    nodeType<Type> *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first != nullptr)   //while there are nodes in
    {                          //the list
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }
    last = nullptr; //initialize last to nullptr; first has
               //already been set to nullptr by the while loop
    count = 0;
}
template <class Type>
void unorderedLinkedList<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}
template <class Type>
void unorderedLinkedList<Type>::print() const
{
    nodeType<Type>* current; //pointer to traverse the list

    current = first;    //set current so that it points to
                        //the first node
    while (current != nullptr) //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
}//end print

template <class Type>
int unorderedLinkedList<Type>::length() const
{
    return count;
}  //end length

template <class Type>
int unorderedLinkedList<Type>::front() const
{
    return first->info; //return the info of the first node
}//end front

template <class Type>
int unorderedLinkedList<Type>::back() const
{
    return last->info; //return the info of the last node
}//end back

template <class Type>
void unorderedLinkedList<Type>::copyList(const unorderedLinkedList<Type>& otherList)
{
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list

    if (first != nullptr) //if the list is nonempty, make it empty
       destroyList();

    if (otherList.first == nullptr) //otherList is empty
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.first; //current points to the
                                   //list to be copied
        count = otherList.count;

            //copy the first node
        first = new nodeType<Type>;  //create the node

        first->info = current->info; //copy the info
        first->link = nullptr;        //set the link field of
                                   //the node to nullptr
        last = first;              //make last point to the
                                   //first node
        current = current->link;     //make current point to
                                     //the next node

           //copy the remaining list
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;  //create a node
            newNode->info = current->info; //copy the info
            newNode->link = nullptr;       //set the link of
                                        //newNode to nullptr
            last->link = newNode;  //attach newNode after last
            last = newNode;        //make last point to
                                   //the actual last node
            current = current->link;   //make current point
                                       //to the next node
        }//end while
    }//end else
}//end copyList
template <class Type>
unorderedLinkedList<Type>::~unorderedLinkedList() //destructor
{
   destroyList();
}//end destructor
template <class Type>
unorderedLinkedList<Type>::unorderedLinkedList(const unorderedLinkedList<Type>& otherList)
{
    first = nullptr;
    copyList(otherList);
}//end copy constructor

template <class Type>         //overload the assignment operator
const unorderedLinkedList<Type>& unorderedLinkedList<Type>::operator=(const unorderedLinkedList<Type>& otherList)
{
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else

     return *this;
}
template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;

    current = first; //set current to point to the first
                     //node in the list

    while (current != nullptr && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == nullptr)   //if the list was empty, newNode is also
                        //the last node in the list
        last = newNode;
}//end insert (at front)

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == nullptr)    //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //Case 2
        {
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)    //the list has only one node
                last = nullptr;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to
                                   //the second node

            while (current != nullptr && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted
                                       //was the last node
                    last = trailCurrent; //update the value
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode
#endif
