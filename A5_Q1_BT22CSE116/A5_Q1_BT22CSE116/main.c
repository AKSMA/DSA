#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct MinHeap {
    int* arr;
    int maxSize;
    int heapSize;
};

struct MinHeap* createMinHeap(int maxSize) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->arr = (int*)malloc(sizeof(int) * maxSize);
    minHeap->maxSize = maxSize;
    minHeap->heapSize = 0;
    return minHeap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i) {
    return (i - 1) / 2;
}

int lChild(int i) {
    return (2 * i + 1);
}

int rChild(int i) {
    return (2 * i + 2);
}

void minHeapify(struct MinHeap* minHeap, int i);

int extractMin(struct MinHeap* minHeap) {
    if (minHeap->heapSize <= 0)
        return INT_MAX;
    if (minHeap->heapSize == 1) {
        minHeap->heapSize--;
        return minHeap->arr[0];
    }

    int root = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->heapSize - 1];
    minHeap->heapSize--;

    minHeapify(minHeap, 0);

    return root;
}

void insertKey(struct MinHeap* minHeap, int x) {
    if (minHeap->heapSize == minHeap->maxSize) {
        printf("\nOverflow: Could not insertKey\n");
        return;
    }

    minHeap->heapSize++;
    int i = minHeap->heapSize - 1;
    minHeap->arr[i] = x;

    while (i != 0 && minHeap->arr[parent(i)] > minHeap->arr[i]) {
        swap(&minHeap->arr[i], &minHeap->arr[parent(i)]);
        i = parent(i);
    }
}

void decreaseKey(struct MinHeap* minHeap, int i, int newVal) {
    minHeap->arr[i] = newVal;
    while (i != 0 && minHeap->arr[parent(i)] > minHeap->arr[i]) {
        swap(&minHeap->arr[i], &minHeap->arr[parent(i)]);
        i = parent(i);
    }
}

void deleteKey(struct MinHeap* minHeap, int i) {
    decreaseKey(minHeap, i, INT_MIN);
    extractMin(minHeap);
}

void minHeapify(struct MinHeap* minHeap, int i) {
    int l = lChild(i);
    int r = rChild(i);
    int smallest = i;
    if (l < minHeap->heapSize && minHeap->arr[l] < minHeap->arr[i])
        smallest = l;
    if (r < minHeap->heapSize && minHeap->arr[r] < minHeap->arr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(&minHeap->arr[i], &minHeap->arr[smallest]);
        minHeapify(minHeap, smallest);
    }
}

int main() {
    struct MinHeap* h = createMinHeap(15);

    int i;
    int keys[] = {1,5,6,8,9,7,3};
    int n = sizeof(keys) / sizeof(keys[0]);
    printf("Entered %d keys: ", n);
    for (i = 0; i < n; i++) {
        printf("%d ", keys[i]);
        insertKey(h, keys[i]);
    }
    printf("\n");

    printf("The current size of the heap is %d\n", h->heapSize);
    printf("The current minimum element is %d\n", h->arr[0]);
    insertKey(h, 0);


    for (i = 0; i < n+1; i++) {
        printf("%d ", h->arr[i]);
    }

    free(h->arr);
    free(h);

    return 0;
}
