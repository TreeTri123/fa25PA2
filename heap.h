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
        upheap(size - 1);
        }
        // TODO: insert index at end of heap, restore order using upheap()

    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
    int left = pos*2 + 1;
    int right = pos*2 + 2;
    int root = (pos - 1) / 2;

    if (root < weightArr[left] && weightArr[right]) {
        //no change
    }
    if (root > weightArr[left]) {
        swap(weightArr[root], weightArr[left]);
    }
    if (root > weightArr[right]) {
        swap(weightArr[root], weightArr[right]);
    }

    //parent
    (i - 1) / 2
    //children
    2*i + 1, 2*i +2;

        // TODO: swap child upward while smaller than parent

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif