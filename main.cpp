#include "DetectMemoryLeak.h"
#include <string>
#include <vector>
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::vector;


bool Brackets(const string& input);
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results);

double timeTaken(clock_t startTime);

// this ensures that _CrtDumpMemoryLeaks() is called after main() and right before program terminates
struct AtExit
{
    ~AtExit() { _CrtDumpMemoryLeaks(); }
} doAtExit;

int main()
{
    // This sets the boolean values to be represented in a textual format.
    cout << std::boolalpha;

    // Start the clock
    clock_t start = clock();

    // part 1
    cout << "Part 1" << endl;
    LinkedList ll;
    //ll.push_front(1);
    //ll.push_front(2);
    //ll.push_front(3); //321

    ll.push_back(4);
    //ll.push_back(5);
    //ll.push_back(6);//321456
    //ll.insert_at(1, 7); //3721
    //ll.push_back(4);
    //ll.push_back(3);
    //cout << "Total Size: " << ll.size() << endl;
    //cout << "Pop Back: " << ll.pop_back() << endl;
    //cout << "First Size: " << ll.size() << endl;
    ////cout << "Pop Front : " << ll.pop_front() << endl;
    //cout << "Pop Back: " << ll.pop_back() << endl;
    //cout << "Second Size: " << ll.size() << endl;
    cout << "Pop Back: " << ll.pop_back() << endl;
    cout << "Third Size: " << ll.size() << endl;

    //cout << ll.pop_front() << endl; // 3214 214
    //cout << ll.pop_front() << endl; // 14
    //cout << ll.pop_back() << endl; // 1
    //cout << ll.pop_back() << endl; // Nothing
    ////ll.insert_at(2, 10);
    //cout << ll.pop_at(1) << endl;
    //ll.push_front(1);
    //int poploc[3];
    //poploc[0] = 0;
    //poploc[1] = 1;
    //poploc[2] = 2;

    //for (unsigned i = 0; i <= 2; i++)
    //{
    //    cout << ll.pop_at(poploc[i]) << endl;
    //}

    cout << endl;

    // part 2
    cout << "Part 2" << endl;
    Queue q;
    q.enqueue(20);
    q.enqueue(30);
    //q.enqueue(42);
    //q.enqueue(50);
    cout << q.dequeue() << endl;
    cout << q.size() << endl;
    cout << endl;

    // part 3
    cout << "Part 3" << endl;
    Stack s;
    s.push(46);
    s.push(8);
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << endl;

    // part 4
    cout << "Part 4" << endl;
    const char* input = "()";
    const char* input1 = "(<)>";
    const char* input2 = "(<))";
    const char* input3 = "{<[()]>}";
    const char* input4 = "()()[]<>{{[{}]}}";
    const int input5 = 500;

    cout << Brackets(input) << endl;
    cout << Brackets(input1) << endl;
    //cout << Brackets(input2) << endl;
    //cout << Brackets(input3) << endl;
    //cout << Brackets(input4) << endl;
    //cout << Brackets(std::to_string(input5)) << endl;

    cout << endl;


    // part 5
    cout << "Part 5" << endl;
    int dataArray[] = {1, 4, 5, 6, 9, 1, 1, 4};
    //int queryArray[] = {1, 2, 3};
    int queryArray[] = { 1, 2, 4};

    vector<int> data(dataArray, dataArray + sizeof(dataArray) / sizeof(dataArray[0]));
    vector<int> queries(queryArray, queryArray + sizeof(queryArray) / sizeof(queryArray[0]));
    vector<unsigned int> results;
    QueryMachine(data, queries, results);
    for (size_t i = 0; i < results.size(); ++i)
    {
        cout << results[i] << " ";
    }
    cout << endl;

    cout << "Time taken to run the above code is " << timeTaken(start) << "ms" << endl;

    return 0;
}

// If you are curious, this calculates the time taken between the start time and the time that this function is called.
// The return value is in milliseconds (ms)
double timeTaken(clock_t startTime)
{
    return (clock() - startTime) / (double)(CLOCKS_PER_SEC/1000);
}

