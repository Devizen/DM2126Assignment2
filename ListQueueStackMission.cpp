#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    <John Doe>
 *  \date      2015 
 *  \note      <Admin ID>
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList() 
{
    head_ = new Node();
}

LinkedList::~LinkedList()
{ 
}

void LinkedList::push_front(int data)
{
    Node* newNode = new Node(data);
    if (head_->next == NULL)
    {
        head_->next = newNode;
    }
    else
    {
        newNode->next = head_->next;
        head_->next = newNode;
    }
}

void LinkedList::push_back(int data)
{
    Node* newNode = new Node(data);
    Node* temp = head_->next;

    if (head_->next == NULL)
    {
        push_front(data);
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

int LinkedList::pop_front()
{
    if (head_->next == NULL)
    {
        return 0;
    }
    else
    {
        return head_->next->data;
    }
}

int LinkedList::pop_back()
{    
    Node* nextNext = new Node();

    nextNext = head_->next;
    if (head_->next == NULL)
    {
        return 0;
    }
    else
    {
        while (nextNext->next != NULL)
        {
            nextNext = nextNext->next;
            head_ = head_->next;
        }
        return head_->data;
    }
}

void LinkedList::insert_at(int pos, int data)
{    
    if (pos < 0)
    {
        push_front(data);
    }
    else if (pos > size())
    {
        push_back(data);
    }
    else
    {
        Node* newNode = new Node();
        newNode->data = data;

        for (int i = 0; i < pos; i++)
        {
            head_ = head_->next;
        }
        if (head_ == NULL)
        {
            head_->data = data;
        }
        else
        {
            push_back(data);
        }
    }
}

int LinkedList::pop_at(int pos)
{
    int position = pos;
    if (pos < 0)
    {
        position = 0;
    }
    if (pos == 0)
    {
        pop_front();
    }
    else
    {
        for (unsigned i = 0; i < position; i++)
        {
            head_ = head_->next;
        }
        if (head_ == NULL)
        {
            return 0;
        }
        else
        {
            return head_->data;
            delete head_;
        }
    }
}

size_t LinkedList::size()
{
    unsigned count = 1;
    if (head_->next == NULL)
    {
        return 0;
    }
    else
    {
        if (head_->next != NULL)
        {
            count++;
            head_ = head_->next;
        }
    }
    return count;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() 
{
}

Queue::~Queue()
{   
}

void Queue::enqueue(int data)
{   
}

int Queue::dequeue()
{
    return 0;
}

size_t Queue::size()
{
    return 0;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{

}

Stack::~Stack()
{
}

void Stack::push(int data)
{
}

int Stack::pop()
{
    return 0;
}

size_t Stack::size()
{
    return 0;
}



// Balanced parenthesis
bool Brackets(const string& input)
{
    return true;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
}