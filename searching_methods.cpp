#include<iostream>
#include <string>

using namespace std;

int Sequential_Search(int key, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (key == arr[i]) return i;
    }
    return -1;
}

int Recursive_Sequential_Search(int key, int arr[], int index, int size) {

    if (index >= size) return -1;
    if (arr[index] == key) return index;

    return Recursive_Sequential_Search(key, arr, index + 1, size);
}

int Binary_Search(int key, int arr[], int size) {

    int left = 0, right = size - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int Recursive_Binary_Search(int key, int arr[], int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;

    if (arr[mid] < key) return Recursive_Binary_Search(key, arr, mid + 1, right);
    if (arr[mid] > key) return Recursive_Binary_Search(key, arr, left, mid - 1);
    else {
        return mid;
    }

}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index = Sequential_Search(4, arr, 10);
    int index2 = Recursive_Sequential_Search(5, arr, 0, 10);
    int index3 = Binary_Search(5, arr, 10);
    int index4 = Recursive_Binary_Search(2, arr, 0, 9);

    cout << index << endl;
    cout << index2 << endl;
    cout << index3 << endl;
    cout << index4 << endl;

}
