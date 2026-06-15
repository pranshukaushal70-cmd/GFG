        while (idx > 0) {
            int parent = (idx - 1) / 2;

            if (heap[parent] < heap[idx]) {
                swap(heap[parent], heap[idx]);
                idx = parent;
            } else {
                break;
            }
        }
    }
    void pop() {
        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;
        int n = heap.size();

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }
    int peek() {
        if (heap.empty())
            return -1;

        return heap[0];
    }
    int size() {
        return heap.size();
    }
};
