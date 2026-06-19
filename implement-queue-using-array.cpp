class myQueue {
  public:
    int* arr;
    int capacity;
    int start;
    int end;
    int size;

    myQueue(int n) {
        capacity = n;
        arr = new int[capacity];
        start = -1;   
        end = -1;     
        size = 0;     
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int x) {
        if (isFull()) return;          
        if (size == 0) {               
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % capacity; 
        }
        arr[end] = x;
        size++;                 
    }

    void dequeue() {
        if (isEmpty()) return;          
        start = (start + 1) % capacity; 
        size--;                          
        if (size == 0) {                 
            start = -1;
            end = -1;
        }
    }

    int getFront() {
        if (isEmpty()) return -1;        
        return arr[start];
    }

    int getRear() {
        if (isEmpty()) return -1;        
        return arr[end];
    }
};
