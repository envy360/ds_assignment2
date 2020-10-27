
#include <iostream>
#include <stdlib.h>

using namespace std;

class twoStacksOneArray {
    int* arr;
    int size;
    int top1, top2;

public:
    twoStacksOneArray(int n) // constructor
    {
        size = n;
        arr = new int[n];
        for(int i=0; i<size; i++) arr[i] = 0;
        top1 = -1;
        top2 = size;
    }

    // Method to push an element x to stack1
    void push_first(int x)
    {
        // There is at least one empty space for new element
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        }
        else {
            cout << "Stack Overflow";
            exit(1);
        }
    }

    // Method to push an element x to stack2
    void push_second(int x)
    {
        // There is at least one empty
        // space for new element
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        }
        else {
            cout << "Stack Overflow";
            // exit(1);

        }
    }

    // Method to pop an element from first stack
    int pop_first()
    {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        }
        else {
            // cout << "Stack 1 UnderFlow";
            throw out_of_range("First Stack UnderFlow");
            // exit(1);
        }
    }

    // Method to pop an element from second stack
    int pop_second()
    {
        if (top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        }
        else {
            // cout << "Stack 2 UnderFlow";
            throw out_of_range("Second Stack UnderFlow");
            exit(1);
        }
    }

    // Size of first stack
    int size_first()
    {
        return (top1 - (-1) );
    }

    // Size of second stack
    int size_second()
    {
        return ( size - top2 );
    }

    void printArray()
    {
        cout << "Array =";
        for(int i=0; i<size; i++) cout << " " << arr[i];
        cout << endl;
        cout << "size 1: " << size_first() << endl;
        cout << "size 2: " << size_second() << endl;
    }
};

/* Driver program to test twStacks class */
int main()
{
    try {
        twoStacksOneArray ts(5);
        ts.push_first(5);
        ts.printArray();
        /*
        cout << "Popped element from stack1 is "
             << ts.pop_first() << endl;
        cout << "Popped element from stack1 is "
             << ts.pop_first() << endl;
        */
        ts.push_second(10);
        ts.printArray();
        ts.push_second(15);
        ts.printArray();
        ts.push_first(11);
        ts.printArray();
        ts.push_second(7);
        ts.printArray();
        ts.push_second(100);
        ts.printArray();
        cout << "Popped element from stack1 is "
             << ts.pop_first() << endl;
        ts.push_second(40);
        ts.printArray();
        cout << "\nPopped element from stack2 is "
             << ts.pop_second() << endl;
        ts.printArray();
    } catch (out_of_range& excpt){
        cout << endl << "Out of Range" << endl;
        cout << excpt.what() << endl;
        exit(1);
    }
    return 0;
}
