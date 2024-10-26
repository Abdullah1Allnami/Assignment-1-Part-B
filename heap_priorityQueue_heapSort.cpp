#include <vector>
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

class Heap {
private:
    int *array;
    int size;
    int capacity;

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
        int parent_pos = parent(child_position);

        while (parent_pos != -1 && array[parent_pos] < array[child_position]) {
            swap(array[parent_pos], array[child_position]);
            child_position = parent_pos;
            parent_pos = parent(child_position);
        }
    }

    void heapify_down(int parent_position) {
        int largest = parent_position;
        int left_child = left(parent_position);
        int right_child = right(parent_position);

        if (left_child != -1 && array[left_child] > array[largest])
            largest = left_child;
        if (right_child != -1 && array[right_child] > array[largest])
            largest = right_child;

        if (largest != parent_position) {
            swap(array[parent_position], array[largest]);
            heapify_down(largest);
        }
    }

    void heapify() {
        for (int i = size / 2 - 1; i >= 0; --i)
            heapify_down(i);
    }

public:
    Heap(int initial_capacity = 1000) {
        capacity = initial_capacity;
        array = new int[capacity];
        size = 0;
    }

    Heap(int _array[], int n) : capacity(n + 500), size(n) {
        array = new int[capacity];
        for (int i = 0; i < n; ++i)
            array[i] = _array[i];
        heapify();
    }

    ~Heap() {
        delete[] array;
    }

    void push(int value) {
        if (size == capacity)
            throw std::runtime_error("No available capacity");
        array[size++] = value;
        heapify_up(size - 1);
    }

    int get_max() {
        if (size == 0)
            throw std::runtime_error("Heap is empty");
        return array[0];
    }

    int get_min() {
        if (size == 0)
            throw std::runtime_error("Heap is empty");

        int min_element = array[0];
        for (int i = 1; i < size; ++i) {
            min_element = min(array[i], min_element);
        }
        return min_element;
    }

    bool isEmpty() {
        return size == 0;
    }

    int pop_max() {
        if (size == 0)
            throw std::runtime_error("Heap is empty");
        int max_value = array[0];
        array[0] = array[--size];
        heapify_down(0);
        return max_value;
    }
};

class PriorityQueue {
private:
    Heap heap;

public:
    void push(int value) {
        heap.push(value);
    }

    int get_max() {
        return heap.get_max();
    }

    bool isEmpty() {
        return heap.isEmpty();
    }

    int pop_max() {
        return heap.pop_max();
    }
};

void heapSort(int arr[], int n) {
    Heap heap(arr, n);

    for (int i = n - 1; i >= 0; --i) {
        arr[i] = heap.pop_max();
    }
}

int main() {
    int testArr[] = {3, 2, 15, 5, 4, 45};
    int n = sizeof(testArr) / sizeof(testArr[0]);

    // Test heap operations
    Heap heap(testArr, n);
    cout << "Max element in heap: " << heap.get_max() << endl;
    cout << "Min element in heap: " << heap.get_min() << endl;

    heap.push(50);
    cout << "Max after pushing 50: " << heap.get_max() << endl;

    // Test Priority Queue
    PriorityQueue pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    cout << "Priority Queue Max: " << pq.get_max() << endl;
    cout << "Priority Queue Pop Max: " << pq.pop_max() << endl;
    cout << "Priority Queue New Max: " << pq.get_max() << endl;

    // Test heap sort
    int arr[] = {3, 1, 6, 5, 2, 4};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, arr_size);

    cout << "Sorted array using heapSort: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
