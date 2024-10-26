#include<vector>
#include<iostream>
#include<cassert>

using namespace std;


class Heap {
private:
    int *array;
    int size;
    int capacity;
    bool is_Max;

    int left(int n) {
        int pos = 2 * n + 1;
        return pos >= size ? -1 : pos;
    }

    int right(int n) {
        int pos = 2 * n + 2;
        return pos >= size ? -1 : pos;
    }

    int parent(int child) {
        return child == 0 ? -1 : (child - 1) / 2;
    }

    void heapify_up(int child_position) {

    }

    void heapify_down(int parent_position) {

    }

    void heapify() {
        for (int i = size / 2 - 1; i < size; ++i) {
            heapify_down(i);
        }
    }

public:

    Heap(bool is_Max = true) {
        this->is_Max = is_Max;
        capacity = 1000;
        array = new int[capacity];
        size = 0;
    }


    Heap(int _array[], int n) {
        assert((int) n <= capacity);
        array = new int[capacity];
        size = n;

        for (int i = 0; i < n; ++i)
            array[i] = _array[i];

        heapify();
    }
};