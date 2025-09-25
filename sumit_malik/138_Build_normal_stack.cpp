#include <bits/stdc++.h>
using namespace std;

// Normal Stack

template <typename T>

class Stack{
  private:
    int size;
    int top;
    T *st;

  public:
    Stack(int size){
        this->size = size;
        this->top = -1;
        st = new T[size];
    }

    void push(T val){
        if(top+1 < size)
            st[++top] = val;
        else
            cout<<"Stack is full\n";
    }

    T peek(){
        return top != -1 ? st[top] : (T)-1;
    }
    
    void pop(){
        if(top != -1){
            --top;
        }else{
            cout<<"Stack is empty\n";
        }
    }
    
    void print(){
        if(top == -1){
            cout<<"stack is empty\n";
            return ;
        }
            
        for(int i=0; i<=top; i++)
            cout<<st[i]<<" ";
        cout<<endl;
    }
};

template <typename T>

/*
Got it 👍, the error is clear now.

---

### ❌ Why this happens

Your `Structure` class **inherits** from `Stack<T>`:

```cpp
template <typename T>
class Structure: public Stack<T> {
```

But your `Stack<T>` class only has a **constructor with parameter**:

```cpp
Stack(int size) {
    this->size = size;
    this->top = -1;
    st = new T[size];
}
```

No **default constructor** is defined.

When you do:

```cpp
Structure(char start) {
    ...
}
```

The compiler tries to call the **default constructor of `Stack<T>`** (because `Structure` inherits from `Stack<T>`).
But since `Stack<T>` has **no default constructor**, compilation fails.

---

### ✅ Fix Options

#### **Option 1: Don’t inherit, just use composition**

Remove `: public Stack<T>`.
You already have `Stack<T>* st;` inside `Structure`. That’s enough.

```cpp
template <typename T>
class Structure {
    char start;
    Stack<T>* st;
    ...
};
```

This is the cleanest fix.

---

#### **Option 2: Call `Stack<T>` constructor explicitly**

If you want to keep inheritance, you must call the parent constructor:

```cpp
Structure(char start) : Stack<T>(10) {   // <-- pass some size
    cout << "To start press 'y' or quit 'n': ";
    this->start = start;
    st = nullptr;
    startStack();
}
```

But then you’re maintaining **two stacks**:

* One from inheritance (`Stack<T>`)
* One as pointer (`st`)

That’s redundant and confusing.

---

### ⚡ Recommendation

Go with **Option 1 (composition)**:
Drop inheritance. Just keep `Stack<T>* st;` in `Structure`.

---

👉 Do you want me to rewrite your `Structure` class cleanly with **only composition** (no inheritance, no duplicate stacks), so it compiles and works?

*/
class Structure{
    char start;
    Stack<T> *st;
    
    public:
    Structure(char start){
        cout<<"To start press 'y' or quit 'n': ";
        this->start = start;
        st = nullptr;
        startStack();
    }
    
    void intialisation(){
        cout<<"Enter Stack Size\n";
        int size; cin>>size;
        st = new Stack<T>(size);
    }
    
    void startStack(){
        
        if(start == 'y'){
            intialisation();
        }
        
        while(start == 'y'){

            cout<<"Options\n1.push\n2.pop\n3.top\n4.print\n5.quit";
            
            int temp; cin>>temp;

            switch(temp){
                case 1:{
                    cout<<"enter value";
                    T val; cin>>val;
                    st->push(val);
                    break;
                }
                case 2:{
                    if (st->peek() != (T)-1) {
                        cout << "popped " << st->peek() << endl;
                        st->pop();
                    } else {
                        cout << "Stack is empty\n";
                    }                    
                    break;
                }
                case 3:{
                    cout<<st->peek()<<endl;
                    break;
                }
                case 4:{
                    st->print();
                    break;
                }
                case 5:
                default:{
                    start = 'n';
                }
            }
        }
    }
    
    ~Structure() {
        delete st;
    }
};

int main() {
    Structure<int> st('y');
}



int main() {
    Stack<int> *st = new Stack<int>(10);
    // or
    // Stack<int> st(10);
    st->push(10);
    st->push(20);
    st->push(30);
    st->pop();
    st->print();
    st->push(40);
    st->push(50);
    st->push(60);
    st->print();
    cout<<st->peek()<<endl;
}



#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
    int size;
    int top;
    T* st;

public:
    Stack(int size) {
        this->size = size;
        this->top = -1;
        st = new T[size];
    }

    ~Stack() {
        delete[] st;
    }

    void push(T val) {
        if (top + 1 < size)
            st[++top] = val;
        else
            cout << "Stack is full\n";
    }

    T peek() {
        if (top != -1) return st[top];
        cout << "Stack is empty\n";
        return (T)-1; // careful: valid only for numeric T
    }

    void pop() {
        if (top != -1)
            --top;
        else
            cout << "Stack is empty\n";
    }

    void print() {
        if (top == -1) {
            cout << "stack is empty\n";
            return;
        }
        for (int i = 0; i <= top; i++) cout << st[i] << " ";
        cout << endl;
    }
};

template <typename T>
class Structure {
    char start;
    Stack<T>* st;

public:
    Structure(char start) {
        cout << "To start press 'y' or quit 'n': ";
        this->start = start;
        st = nullptr;
        startStack();
    }

    ~Structure() {
        delete st;
    }

    void intialisation() {
        cout << "Enter Stack Size\n";
        int size;
        cin >> size;
        st = new Stack<T>(size);
    }

    void startStack() {
        if (start == 'y') {
            intialisation();
        }

        while (start == 'y') {
            cout << "Options:\n"
                 << "1. push\n"
                 << "2. pop\n"
                 << "3. top\n"
                 << "4. print\n"
                 << "5. quit\n";

            int temp;
            cin >> temp;

            switch (temp) {
                case 1: {
                    cout << "enter value: ";
                    T val;
                    cin >> val;
                    st->push(val);
                    break;
                }
                case 2: {
                    T val = st->peek();
                    if (val != (T)-1) {
                        cout << "popped " << val << endl;
                        st->pop();
                    }
                    break;
                }
                case 3: {
                    cout << st->peek() << endl;
                    break;
                }
                case 4: {
                    st->print();
                    break;
                }
                case 5:
                default: {
                    start = 'n';
                }
            }
        }
    }
};

int main() {
    Structure<int> st('y');
}





/*
Great question 👍 — this touches the difference between **objects** and **pointers** in C++.

---

### 1. ✅ This is correct:

```cpp
int main() {
    Stack<int> st(10);
}
```

* Here, `st` is an **object of type `Stack<int>`**.
* The constructor `Stack(int size)` is called directly.
* When `main` ends, the destructor `~Stack()` is called automatically.
* No manual `delete` is required.
* This is the idiomatic way in C++.

---

### 2. ❌ This is wrong:

```cpp
int main() {
    Stack<int> st = new Stack(10);
}
```

Problems:

1. `new Stack(10)` creates a **pointer** (`Stack<int>*`) on the heap.
   But `st` is declared as an **object** (`Stack<int>`), not a pointer.
   → Type mismatch: cannot assign `Stack<int>*` to `Stack<int>`.

2. If you really wanted a pointer, you’d have to write:

   ```cpp
   Stack<int>* st = new Stack<int>(10);
   ```

   But then you must also call:

   ```cpp
   delete st;   // to avoid memory leak
   ```

3. Using raw `new`/`delete` is **not recommended** in modern C++ unless you have a very specific reason.
   Prefer stack allocation (`Stack<int> st(10);`) or smart pointers (`std::unique_ptr`, `std::shared_ptr`).

---

### ✅ Summary

* Use **automatic object allocation** most of the time:

  ```cpp
  Stack<int> st(10);
  ```

  → clean, safe, destructor auto-called.

* If you really need heap allocation:

  ```cpp
  auto st = new Stack<int>(10);   // returns Stack<int>*
  ...
  delete st;  // manual cleanup
  ```

* Or, even better (C++11+):

  ```cpp
  auto st = std::make_unique<Stack<int>>(10); // smart pointer
  ```

---

👉 Do you want me to show you a version of your `Stack` implemented with **`std::vector<T>` internally + smart pointers for allocation**, so you never need to worry about `new/delete` at all?

*/