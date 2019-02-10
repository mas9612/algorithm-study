// Heap implements heap data structure.
// In this implementation, index-zero will not be used for convenience.
class Heap {
    int* data;
    int heap_size;
    int capacity;

   public:
    Heap(int size) : heap_size(0), capacity(size) { data = new int[size + 1]; }
    ~Heap() { delete[] data; }

    void insert(int n);
    void max_heapify(int root);
    void build_heap();
    void print_heap();
};
