#include <iostream>
#define MAX_SIZE 10

using namespace std;

class Queue
{
    private:
        int arr[MAX_SIZE];
        int front, rear;
    public:
        Queue()
        {
            front = -1;
            rear = -1;
        }
        
        bool isEmpty()
        {
            return (front == -1 && rear == -1);
        }
        
        bool isFull()
        {
            return (rear + 1) % MAX_SIZE == front ? true : false;
        }
        
        void Enqueue (int x)
        {
            if (isFull())
            {
                cout << "Error: Queue is full\n";
                return;
            }
            
            if (isEmpty())
            {
                front = rear = 0;
            }
            
            else
            {
                rear = (rear + 1) % MAX_SIZE;
            }
            
            arr[rear] = x;
        }
        
        void Dequeue()
        {
            if (isEmpty())
            {
                cout << "Error: Queue is empty\n";
                return;
            }
            else if (front == rear)
            {
                rear = front = -1;
            }
            else
            {
                front = (front + 1) % MAX_SIZE;
            }
        }
        
        int Front()
        {
            if (front == -1)
            {
                cout << "Error: Queue is empty\n";
                return -1;
            }
            return arr[front];
        }
        
        void Print()
        {
            int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
            for (int i = 0; i < count; i++)
            {
                int index = (front + i) % MAX_SIZE;
                cout << arr[index] << " ";
            }
            cout << endl;
        }
};

int main()
{
   Queue Q; 
   Q.Enqueue(2);  Q.Print();  
   Q.Enqueue(4);  Q.Print();  
   Q.Enqueue(6);  Q.Print();
   Q.Dequeue();	  Q.Print();
   Q.Enqueue(8);  Q.Print();
}
