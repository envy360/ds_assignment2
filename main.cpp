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
        // Initialize array to 0; redundant step but to better illustrate the result
        for(int i=0; i<size; i++) arr[i] = 0;
        // Initialize pointer position for empty stacks
        top1 = -1;
        top2 = size;
    }

    // Method to push an element x to stack1
    void push_first(int x)
    {
        cout << "Push " << x << " into first stack." << endl;
        if (top1 == top2 - 1) { // If stack array full
            cout << "Stack Overflow! Doubling Array size." << endl;
            doubleStackArray();
        }
        top1++;
        arr[top1] = x;
    }

    // Method to push an element x to stack2
    void push_second(int x)
    {
        cout << "Push " << x << " into second stack." << endl;
        if (top1 == top2 - 1) { // If stack array full
            cout << "Stack Overflow! Doubling Array size." << endl;
            doubleStackArray();
        }
        top2--;
        arr[top2] = x;
    }

    // Method to pop an element from first stack
    int pop_first()
    {
        if (top1 >= 0) {
            int x = arr[top1];
            arr[top1] = 0; // redundant step to reset but just for illustartion
            top1--;
            return x;
        }
        else {
            throw out_of_range("First Stack UnderFlow");
        }
    }

    // Method to pop an element from second stack
    int pop_second()
    {
        if (top2 < size) {
            int x = arr[top2];
            arr[top2] = 0; // redundant step to reset but just for illustartion
            top2++;
            return x;
        }
        else {
            throw out_of_range("Second Stack UnderFlow");
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
        cout << "First stack size: " << size_first() << endl;
        cout << "Second stack size: " << size_second() << endl<<endl;
    }

    void doubleStackArray()
    {
        int old_size = size;
        int new_size = 2*size;
        int* newArr = new int[new_size];
        // initialize array
        for (int i=0; i<new_size; i++) newArr[i] = 0;
        // copy stack 1
        for (int i=0; i<=top1; i++) newArr[i] = arr[i];
        // copy stack 1
        for (int i=1; i<= size_second() ; i++) newArr[new_size - i] = arr[old_size - i];
        // delete old array
        delete[] arr;
        // original array pointer to point to new array
        arr = newArr;
        size = new_size;
        top2 += old_size;
    }
};

/* Driver program to test twStacks class */
int main()
{
    try {
        twoStacksOneArray ts(5);
        ts.printArray();
        ts.push_first(5);
        ts.printArray();
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
        cout << "Popped element from first stack is "
             << ts.pop_first() << endl;
        ts.printArray();
        ts.push_second(40);
        ts.printArray();
        cout << "Popped element from second stack is "
             << ts.pop_second() << endl;
        ts.printArray();
    } catch (out_of_range& excpt){
        cout << endl << "Out of Range" << endl;
        cout << excpt.what() << endl;
        exit(1);
    }
    return 0;
}
