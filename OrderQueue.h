#ifndef INCLUDED_ORDER_QUEUE
#define INCLUDED_ORDER_QUEUE

#include "LimitBuyOrders.h"

#include <iostream>

class OrderQueue
{
  private:
    LimitBuyOrder *buffer;
    int queueSize;
    int queueCapacity;

  public:
    OrderQueue();
    ~OrderQueue();
    void insert(const LimitBuyOrder &order);
    LimitBuyOrder &getMax() const;
    void removeMax();
    bool isEmpty() const;
    int getSize() const;
    void resizeQueue();
    void maxHeapify();
};

inline OrderQueue::OrderQueue() : buffer(new LimitBuyOrder[1]), queueSize(0), queueCapacity(1) {}

inline OrderQueue::~OrderQueue()
{
    delete[] buffer;
}

inline LimitBuyOrder &OrderQueue::getMax() const
{
    return buffer[0];
}

inline bool OrderQueue::isEmpty() const
{
    return queueSize == 0;
}

inline int OrderQueue::getSize() const
{
    return queueSize;
}

#endif