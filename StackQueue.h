
/*Implementations of a stack and queue*/

#include <iostream>
#include <cstdlib>
using namespace std;

/*Queue*/
// A class to store a queue
class Waitlist
{
    int* people;    // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue

public:
    Waitlist(int size = 15);     // constructor
    ~Waitlist();                   // destructor

    int dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor to initialize a queue
Waitlist::Waitlist(int size)
{
    people = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
Waitlist::~Waitlist() {
    delete[] people;
}

// Utility function to dequeue the front element
int Waitlist::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "No people are waiting for a room\n";
        return 0;
    }
    else {

        int x = people[front];
        front = (front + 1) % capacity;
        count--;

        return x;
    }
}

// Utility function to add an item to the queue
void Waitlist::enqueue(int checker)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Sorry, the whole waitlist is busy now!\n";
    }
    else {

        cout << "The person is waiting in the waitlist" << endl;

        rear = (rear + 1) % capacity;
        people[rear] = checker;
        count++;
    }
}

// Utility function to return the front element of the queue
int Waitlist::peek()
{
    if (isEmpty())
    {
        cout << "No people are waiting for a room\n";
        exit(EXIT_FAILURE);
    }
    return people[front];
}

// Utility function to return the current size of the queue
int Waitlist::size() {
    return count;
}

// Utility function to check if the queue is empty or not
bool Waitlist::isEmpty() {
    return (size() == 0);
}

// Utility function to check if the queue is full or not
bool Waitlist::isFull() {
    return (size() == capacity);
}

void combination(int, Waitlist);

class Stack {
    int top;

public:
    int* a;
    int size;

    Stack(int size = 5)
    {
        top = -1;
        a = new int[size];
        this->size = size;
    }
    int push(int);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

bool Stack::isFull()
{
    if (this->top == (this->size - 1))
    {
        return true;
    }
    else { return false; }

}

int Stack::push(int checker)
{
    if (top >= (size - 1)) {
        cout << "No space left in the stack\nSending the person to the waitlist\n";
        return 0;
    }
    else {
        a[++top] = checker;
        cout << "The peron is pushed into stack\n";
        return checker;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "There are no people in the stack\n";
        return 0;
    }
    else {
        int x = a[top--];
        cout << "The user with the ID of " << x << " is popped from stack" << endl;
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

class BookingReady
{
public:
    int id;
    int capacity;

    BookingReady()
    {
        this->id = 0;
        this->capacity = 0;
    }

    void setID(int id)
    {
        this->id = id;
    }

    void setCapacity(int capacity)
    {
        this->capacity = capacity;
    }

    int getID()
    {
        return this->id;
    }

    int getCapacity()
    {
        return this->capacity;
    }

    BookingReady returnOrder(Waitlist person, Stack room_capacity_check) {

        int checker = 1;

            // when the stack is full
            if (room_capacity_check.isFull())
            {
                person.enqueue(checker);
            }
        // when the stack is not full
            else
            {
                room_capacity_check.push(checker);
            }

        BookingReady ready;
        ready.setID(id);
        ready.setCapacity(capacity);

        return ready;

    }
};