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
        data[size] = weightArr[idx];
        size++;
        upheap(size - 1, weightArr);
        }
        // TODO: insert index at end of heap, restore order using upheap()


    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        int min_index = data[0];
        data[0] = data[size - 1];
        size--;

        downheap(0, weightArr);
        return min_index;
    }

    void upheap(int pos, int weightArr[]) {
        int parent = (pos - 1) / 2;

        if (weightArr[data[pos]] > weightArr[data[parent]]) {
            swap(data[pos], data[parent]);
            pos = parent;
        }
    }

    void downheap(int pos, int weightArr[]) {
        int parent = (pos - 1) / 2;

        if (weightArr[data[parent]] > weightArr[data[parent]]) {
            swap(data[parent], data[pos]);
            parent = pos;
        }
    }
};

#endif