#include<iostream>
using namespace std;

class kQueues {
public:

    int n, k, freeslot;
    int* rear;
    int* front;
    int* arr;
    int* next;
    int index;

    kQueues(int n, int k) {
        this->n = n;
        this->k = k;

        rear = new int[k];
        front = new int[k];
        arr = new int[n];
        next = new int[n];

        freeslot = 0;

        for (int i = 0; i < n; i++) {
            next[i] = i + 1;
        }

        next[n - 1] = -1;

        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }
    }

    void enqueue(int x, int i) {

        if (freeslot == -1)
            return;

        index = freeslot;
        freeslot = next[index];

        if (front[i] == -1) {
            front[i] = index;
        }
        else {
            next[rear[i]] = index;
        }

        rear[i] = index;
        next[index] = -1;
        arr[index] = x;
    }

    int dequeue(int i) {

        if (front[i] == -1)
            return -1;

        int val = arr[front[i]];

        index = front[i];
        front[i] = next[index];

        if (front[i] == -1) {
            rear[i] = -1;
        }

        next[index] = freeslot;
        freeslot = index;

        return val;
    }

    bool isEmpty(int i) {
        return front[i] == -1;
    }

    bool isFull() {
        return freeslot == -1;
    }
};