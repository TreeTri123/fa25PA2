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
        size--;

        if (size > 0) {
            data[0] = data[size];
            //rearrange heap back
            downheap(0, weightArr);
        }
        return min_index;
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {
            int parent = (pos - 1) / 2;

            //fill up position moved, parent should be less
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                int tmp = data[pos];
                data[pos] = data[parent];
                data[parent] = tmp;

                pos = parent;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int small = left;

            if (left >= size) break; {//has no children
            }

            if (right < size) {
                if (weightArr[data[right]] < weightArr[data[left]]) {
                    small = right;
                }
            }
            //fill up position, small (left) should be less
            if (weightArr[data[small]] < weightArr[data[pos]]) {
                int tmp = data[small];
                data[small] = data[pos];
                data[pos] = tmp;
                pos = small;
            } else {
                break;
            }
        }
    }
};

#endif