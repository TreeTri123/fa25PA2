//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;
extern int weightArr[];

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        data[size] = idx;
        size++;
        upheap(size - 1, weightArr);
        }
        // TODO: insert index at end of heap, restore order using upheap()


    int pop(int weightArr[]) {
        // TODO: remove and return smallest index

        if (size == 0) return -1;

        int min_index = data[0];
        data[0] = data[size - 1];
        size--;

        downheap(0, weightArr);
        return min_index;
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {
            int parent = (pos - 1) / 2;

            if (weightArr[data[pos]] > weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        int smallest = pos;
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;

        if (left < size && weightArr[data[left]] < weightArr[smallest]) {
            smallest = left;
        }

        if (right < size && weightArr[data[right]] < weightArr[smallest]) {
            smallest = right;
        }
        if (smallest != pos) {
            swap(data[pos], data[smallest]);
            downheap(smallest, weightArr);
        }
    }
};

#endif