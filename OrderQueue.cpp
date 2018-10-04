#include "OrderQueue.h"

#include <iostream>

using namespace std;

void OrderQueue::insert(const LimitBuyOrder &order)
{
    if (queueSize == queueCapacity)
    {
        resizeQueue();
    }

    buffer[queueSize] = order;
    int child = queueSize;

    int parent = (child - 1) / 2;

    while (child != 0 && buffer[parent] < buffer[child])
    {
        swap(buffer[parent], buffer[child]);
        child = parent;
        parent = (parent - 1) / 2;
    }
    queueSize++;
}

void OrderQueue::removeMax()
{
    if (queueSize == 0)
    {
        cerr << "Queue is empty" << endl;
        return;
    }

    swap(buffer[0], buffer[queueSize - 1]);
    queueSize--;
    maxHeapify();
}

void OrderQueue::resizeQueue()
{
    LimitBuyOrder *tempBuffer = buffer;
    queueCapacity *= 2;
    buffer = new LimitBuyOrder[queueCapacity];
    for (int i = 0; i < queueSize; ++i)
    {
        buffer[i] = tempBuffer[i];
    }
    delete[] tempBuffer;
}

void OrderQueue::maxHeapify()
{
    int parent = 0;
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;
    while (queueSize > leftChild && buffer[parent] < buffer[leftChild])
    {
        if (queueSize > rightChild)
        {
            if (buffer[leftChild] < buffer[rightChild])
            {
                swap(buffer[parent], buffer[rightChild]);
                parent = rightChild;
                leftChild = 2 * parent + 1;
                rightChild = 2 * parent + 2;
            }
            else
            {
                swap(buffer[parent], buffer[leftChild]);
                parent = leftChild;
                leftChild = 2 * parent + 1;
                rightChild = 2 * parent + 2;
            }
        }

        else
        {
            swap(buffer[parent], buffer[leftChild]);
            parent = leftChild;
            leftChild = 2 * parent + 1;
            rightChild = 2 * parent + 2;
        }
    }
}
