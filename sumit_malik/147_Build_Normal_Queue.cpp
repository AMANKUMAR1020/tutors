#include<bits/stdc++.h>
#include<iostream>


//Normal stack
using namespace std;
class Queue{
    int* queue;
    int cap;
    int size;
    int front;
    public:
     Queue(int cap){
        this->cap = cap;
        front = 0;
        size = 0;
        int* temp = new int[cap];
        queue = temp;
    }
    int Len(){
        return size;
    }
    
    void Insert(int val){
        if(size == cap){
            cout<<"Queue overflow\n";
        }else{
            int rear = (front + size) % cap;
            queue[rear] = val;
            size++;
        }
    }

    int Front(){
        if(size == 0){
            cout<<"Queue underflow\n";
            return -1;
        }else{
            return queue[front];
        }
    }

    int Remove(){
        if(size == 0){
            cout<<"Queue underflow\n";
            return -1;
        }else{
            int val = queue[front];
            size--;
            front = (front + 1)%cap;
            return val;
        }
    }

    void Display(){
        if(size==0){
            cout<<"NO element found\n";
            return ;
        }
        for(int i=0; i<size; i++){
            int ind = (front + i)%cap;
            cout<<queue[ind]<<" ";
        }
        cout<<endl;
    }

};
int main(){

    Queue* q = new Queue(5);
    q->Display();
    q->Insert(10);
    q->Insert(20);
    cout<<"Lenght = "<<q->Len()<<endl;
    cout<<"Front = "<<q->Front()<<endl;
    cout<<" Remove = "<<q->Remove()<<endl;
    cout<<" Remove = "<<q->Remove()<<endl;
    cout<<"Lenght = "<<q->Len()<<endl;
    q->Display();
    q->Insert(30);
    q->Insert(40);
    cout<<"Lenght = "<<q->Len()<<endl;
    cout<<" Remove = "<<q->Remove()<<endl;
    q->Insert(50);
    q->Insert(60);
    q->Insert(70);
    q->Insert(80);
    q->Display();
    q->Insert(90);
    cout<<" Remove = "<<q->Remove()<<endl;
    cout<<" Remove = "<<q->Remove()<<endl;
    cout<<" Remove = "<<q->Remove()<<endl;
    q->Insert(-50);
    q->Insert(-60);
    q->Insert(-70);
    q->Insert(-80);
    q->Display();
    return 0;
}