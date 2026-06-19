class myStack {
  public:
    int* arr;
    int capacity;
    int top;
    myStack(int n) {
        // Define Data Structures
        capacity=n;
        arr=new int[capacity];
        top=-1;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top==-1;
        
    }

    bool isFull() {
        // check if the stack is full
        return top==capacity-1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(top==capacity-1) return;
        top=top+1;
        arr[top]=x;
    }

    void pop() {
        // removes an element from the top of the stack
        if(top==-1) return;
        top=top-1;
    }

    int peek() {
        // Returns the top element of the stack
        if(top==-1) return -1;
        return arr[top];
    }
};
