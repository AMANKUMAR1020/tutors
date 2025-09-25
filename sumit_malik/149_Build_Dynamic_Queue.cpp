#include<bits/stdc++.h>
#include<iostream>


//Dynamic stack
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
    
    void SizeIncrese(){
        int newCap = 2*cap;
        int* tempArr = new int[newCap];
        for(int i=0; i<size; i++){
            tempArr[i] = queue[(i+front)%cap];
        }
        
        queue = tempArr;
        cap = newCap;
        front = 0;
    }
    
    void SizeDecrese(){
        int newCap = cap/2;
        if(newCap < 1) return;
        if(size > newCap) return;
        int* tempArr = new int[newCap];
        for(int i=0; i<size; i++){
            tempArr[i] = queue[(i+front)%cap];
        }
        delete[] queue;
        queue = tempArr;
        cap = newCap;
        front = 0;
    }
    
    void Insert(int val){
        if(size == cap){
        //    cout<<"Queue overflow\n";
        SizeIncrese();
        }
        int rear = (front + size) % cap;
        queue[rear] = val;
        size++;
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
            if(size == cap/2){
                SizeDecrese();
            }
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
    
    ~Queue(){
        delete[] queue;
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