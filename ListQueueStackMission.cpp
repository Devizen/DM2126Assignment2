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
    //Initialize head_ to NULL.
    head_ = NULL;
}

LinkedList::~LinkedList()
{
    while ((int)size() != 0)
    {
        pop_back();
    }
}

void LinkedList::push_front(int data)
{
    //Create a new Node
    Node* newNode = new Node(data);

    //If head_ is 0,
    if (!head_)
    {
        //Assign head to newNode.
        head_ = newNode;
        return;
    }

    //Point the newNode to head_
    newNode->next = head_;

    //Assign head_ to newNode so head_ is at the front.
    head_ = newNode;
}

void LinkedList::push_back(int data)
{
    //Create a new Node.
    Node* newNode = new Node(data);
    Node* curr = head_;
    Node* prev = head_;

    //If head_ is 0,
    if (!head_)
    {
        //Assign head_ to newNode.
        head_ = newNode;
        return;
    }

    //While curr is not 0,
    while (curr)
    {
        //Assign prev as curr so that it is one step behind curr->next.
        prev = curr;

        //Move curr to the new Node.
        curr = curr->next;
    }

    //Assign the empty curr to newNode.
    curr = newNode;

    //Point the previous node to current.
    prev->next = curr;
}

int LinkedList::pop_front()
{
    //Create a new Node and assign it to head_.
    Node* curr = head_;

    //Variable to store the data.
    int data = 0;

    //If there is not Node, return 0.
    if (!head_)
    {
        return 0;
    }

    //Assign the data of first Node to data.
    data = curr->data;

    //Assign head to the next Node.
    head_ = curr->next;

    //Delete unused node.
    delete curr;
    curr = NULL;

    return data;

}

int LinkedList::pop_back()
{
    //Create two nodes, one for previous Node and one for current Node.
    Node* prev = head_;
    Node* curr = head_;
    //Node* next = head_;

    //Variable to store data.
    int data = 0;

    //If there is no Node, return 0.
    if (!head_)
    {
        return 0;
    }

    if (size() > 1)
    {//While the next Node of curr is not empty,
        while (curr->next != NULL)
        {
            //Assign prev to curr so it is one step behind.
            prev = curr;

            //Assign curr to the next Node.
            curr = curr->next;
        }

        //Assign data to curr's data when curr's next Node is empty.
        data = curr->data;

        //Delete unused Node.
        delete curr;
        curr = NULL;

        //Assign the next Node of prev to be NULL.
        prev->next = NULL;
    }

    else
    {
        //Assign data with curr data.
        data = curr->data;
        delete curr;
        curr = NULL;
        //Assign curr to empty memory.
        curr = prev->next;
        head_ = NULL;
    }

    return data;
}

void LinkedList::insert_at(int pos, int data)
{
    //Create a new Node for inserting, prev for previous Node and curr for current Node.
    Node* newNode = new Node(data);
    Node* prev = head_;
    Node* curr = head_;

    //If pos is less than 0; negative number, or 0,
    if (pos < 0 || pos == 0)
    {
        //Insert the node to the front.
        push_front(data);
    }

    //If pos is greater than LinkedList size,
    else if (pos > (int)size())
    {
        //Add node to the back.
        push_back(data);
    }


    else
    {
        //Move curr to the position for inserting.
        for (int i = 0; i < (int)pos; i++)
        {
            //Assign prev to curr so it is one step behind curr.
            prev = curr;

            //Assign curr to the next Node.
            curr = curr->next;
        }

        //Assign the new Node next Node to curr.
        newNode->next = curr;

        //Assign the prev next Node to the new Node.
        prev->next = newNode;
    }

}

int LinkedList::pop_at(int pos)
{
    //Create two nodes, one for previous Node and one for current Node.
    Node* prev = head_;
    Node* curr = head_;

    //Variable for storing data.
    int data = 0;

    //If position is negative or 0,
    if (pos < 0 || pos == 0)
    {
        //Pop the front.
        return pop_front();
    }

    //If position is greater than LinkedList,
    else if (pos > ((int)size() - 1))
    {
        //Return 0.
        return 0;
    }

    else
    {
        //Move curr to position for popping.
        for (int i = 0; i < pos; i++)
        {
            //Assign prev to curr so it is one step behind.
            prev = curr;

            //Assign curr to the next Node.
            curr = curr->next;
        }

        //curr's data to data variable.
        data = curr->data;

        //Assign the curr pointing to next Node to prev pointing to next Node.
        prev->next = curr->next;

        //Delete unused Node.
        delete curr;
        curr = NULL;

        //Return data.
        return data;
    }
}

size_t LinkedList::size()
{
    //Create a Node and assign it as the head_.
    Node *head = head_;

    //Count variable for storing how many Nodes in LinkedList.
    int count = 0;

    //If there is no Node,
    if (!head_)
    {
        //Return 0.
        return 0;
    }
    
    //While head_ is not empty,
    while (head_)
    {
        //Add 1 to count.
        count++;

        //Assign curr to next Node.
        head_ = head_->next;
    }
    head_ = head;

    //Return total count.
    return (size_t)count;

}


//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() 
{
    //Initialize front_ and back_ to NULL.
    front_ = NULL;
    back_ = NULL;
}

Queue::~Queue()
{   
    while ((int)size() != 0)
    {
        dequeue();
    }
}

void Queue::enqueue(int data)
{   
    //Create new Node for enqueuing, a node for previous and current. 
    Node* newNode = new Node(data);
    Node* prev = front_;
    Node* curr = front_;
   
    //If front_ and back_ are empty,
    if (!front_ && !back_)
    {
        //Assign both front_ and back_ to the new Node.
        front_ = newNode;
        back_ = front_;
        return;
    }

    else
    {
        //While curr is not empty,
        while (curr)
        {
            //Assign prev to curr so that it is one step behind.
            prev = curr;

            //Assign curr to the next Node.
            curr = curr->next;
        }

        //Assign curr to new Node when it reaches the end.
        curr = newNode;

        //Point prev to curr.
        prev->next = curr;

        //Assign back_ to curr as it is at the end of list.
        back_ = curr;
    }

}

int Queue::dequeue()
{
    //Create curr and assign it to front_.
    Node* curr = front_;

    //Variable for storing data.
    int data = 0;

    //If there is no node,
    if (!front_ && !back_)
    {
        //Return 0.
        return 0;
    }

    //Assign the data at the front to data variable.
    data = curr->data;

    //If the front_ is the same as back_,
    if (front_ == back_)
    {
        //Assign the next Node to back_.
        back_ = back_->next;

        //Assign front_ to back_.
        front_ = back_;
    }
    else
    {
        //Assign front_ to the next Node.
        front_ = front_->next;
    }

    //Delete unused node.
    delete curr;
    curr = NULL;

    //Return data.
    return data;
}

size_t Queue::size()
{
    //Create curr and assign it to front_.
    Node *curr = front_;

    //count variable for storing how many Nodes in list.
    int count = 0;

    //If there is no Node,
    if (!front_ && !back_)
    {
        //Return 0.
        return 0;
    }
    
    //While curr is not empty,
    while (curr)
    {
        //Add count.
        count++;

        //Assign curr to next Node.
        curr = curr->next;
    }

    //Return count.
    return (size_t)count;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{
    //Initialize top_ to NULL.
    top_ = NULL;
}

Stack::~Stack()
{
    while ((int)size() != 0)
    {
        pop();
    }
}

void Stack::push(int data)
{
    //Create new Node for adding.
    Node* newNode = new Node(data);

    //If there is no node,
    if (!top_)
    {
        //Assign top_ to newNode.
        top_ = newNode;
    }
    else
    {
        //Point newNode to top_,
        newNode->next = top_;

        //Assign top_ to the newNode.
        top_ = newNode;
    }
}

int Stack::pop()
{
    //Create a Node to track the current position.
    Node *curr = top_;

    //Data variable for storing the data.
    int data = 0;

    //If there is no Node,
    if (!top_)
    {
        //Return 0.
        return 0;
    }
    else
    {
        //Assign the curr's data to data variable.
        data = curr->data;

        //Assign top_ to the next Node.
        top_ = curr->next;

        //Delete unused Node.
        delete curr;
        curr = NULL;

        //Return data.
        return data;
    }
}

size_t Stack::size()
{
    //Create a Node and assign it to top_.
    Node* curr_ = top_;

    //count variable for storing how many Nodes in Stack.
    int count = 0;

    //If there is no Node in stack,
    if (!top_)
    {
        //Return 0.
        return 0;
    }
    else
    {
        //While curr_ is not empty,
        while (curr_)
        {
            //Add count.
            count++;
            
            //Assign curr_ to next Node.
            curr_ = curr_->next;
        }
    }

    //Return count.
    return (size_t)count;
}

//Balanced parenthesis
bool Brackets(const string& input)
{
    //Use Stack as container.
    Stack* bracket = new Stack();

    //type variable to store the type of brackets.
    char type = ' ';

    //Boolean to keep track of answer.
    bool answer = false;

    //If string is empty,
    if (!input.size())
    {
        //Return false.
        return false;
    }
    else
    {
        //Loop until end of string.
        for (int i = 0; i < (int)input.size(); i++)
        {
            //Assign type to the character in string.
            type = input[i];
            
            //Check if the character is the same as type.
            //If the character is an open bracket, push it into Stack.
            //If it is a closed bracket, check whether popping it is the same as the last pushed character.
            //Keep looping if the checks are true and exit the loop when it doesn't match.
            //const char* input1 = "(<)>";
            if (type == '(' || 
                type == '{' ||
                type == '[' ||
                type == '<')
            {
                bracket->push(type);

            }

            else if (type == ')')
            {
 
                if (bracket->pop() == '(')
                {
                    answer = true;
          
                }
                else
                {
                    return false;

                }
            }

            else if(type == '}')
            {
              
                if (bracket->pop() == '{')
                {
                    answer = true;
           
                }
                else
                {
                    return false;

                }
            }

            else if(type == ']')
            {
            
                if (bracket->pop() == '[')
                {
                    answer = true;
      
                }
                else
                {
                    return false;

                }
            }

            else if(type == '>')
            {
         
                if (bracket->pop() == '<')
                {
                    answer = true;

                }
                else
                {
                    return false;

                }
            }
            else
            {
                return false;

            }
        }

        if (bracket->size() != 0) // if not 0 means not balanced
        {
            //Delete unused container.
            delete bracket;
            bracket = NULL;

            return false;
        }
        else
        {
            //Delete unused container.
            delete bracket;
            bracket = NULL;

            //Return answer.
            return answer;
        }
    }
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
    //Use Stack as container.
    Stack* container = new Stack();

    //count Variable to store how many times the number appeared.
    int count = 0;

    //Push all the characters into Stack.
    //If the next character is the same as what is being query, add 1 to count.
    //Push back the count to results vector after checking for one query.
    //Keep repeating until all the queries are checked.
    for (int i = 0; i < (int)queries.size(); i++)
    {
        count = 0;

        for (int j = 0; j < (int)data.size(); j++)
        {
            container->push(data[j]);
        }

        for (int j = 0; j < (int)data.size(); j++)
        {
            if (container->pop() == queries[i])
            {
                count++;
            }
        }
        results.push_back(count);
    }

    //Delete unused container.
    delete container;
    container = NULL;
}