#include "LimitBuyOrders.h"
#include "OrderQueue.h"

#include <iostream>

using namespace std;

int main()
{
    LimitBuyOrder l1("Rifat", 200, 500.00, 4334);
    LimitBuyOrder l2("risdf", 343, 543.34, 2345);
    LimitBuyOrder l3("Rd", 234, 23.23, 1345);
    LimitBuyOrder l4("gjfd", 232, 500.00, 543);
    OrderQueue q;
    q.insert(l1);
    q.insert(l2);
    q.insert(l3);
    q.removeMax();
    q.insert(l4);
    cout << q.getMax() << endl;
    return 0;
}