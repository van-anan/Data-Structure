#include "Heap.h"
void Heapsort(int* data, int size) {
    Heap<int> tree;
    for (int i = 0; i < size; i++) {
        tree.insert(data[i]);
    }
    for (int i = size - 1; i >= 0; i--) {
        data[i] = tree.max();
        tree.remove();
    }
}
