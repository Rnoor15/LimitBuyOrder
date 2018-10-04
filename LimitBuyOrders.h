#ifndef INCLUDED_LIMIT_BUY_ORDER
#define INCLUDED_LIMIT_BUY_ORDER

#include <iostream>

class LimitBuyOrder
{
  private:
	std::string d_buyerName;
	int d_sharesQuantity;
	double d_maxPrice;
	int d_orderTime;

  public:
	LimitBuyOrder() = default;
	LimitBuyOrder(const std::string &buyerName, int sharesQuantity, double maxPrice, int orderTime);
	LimitBuyOrder(const LimitBuyOrder &order);
	LimitBuyOrder &operator=(const LimitBuyOrder &order);
	friend bool operator<(const LimitBuyOrder &left, const LimitBuyOrder &right);
	friend std::ostream &operator<<(std::ostream &os, const LimitBuyOrder &order);
};

inline LimitBuyOrder::LimitBuyOrder(const std::string &buyerName, int sharesQuantity, double maxPrice, int orderTime)
	: d_buyerName(buyerName), d_sharesQuantity(sharesQuantity), d_maxPrice(maxPrice), d_orderTime(orderTime)
{
}

inline LimitBuyOrder::LimitBuyOrder(const LimitBuyOrder &order)
	: d_buyerName(order.d_buyerName), d_sharesQuantity(order.d_sharesQuantity), d_maxPrice(order.d_maxPrice), d_orderTime(order.d_orderTime) {}

inline LimitBuyOrder &LimitBuyOrder::operator=(const LimitBuyOrder &order)
{
	d_buyerName = order.d_buyerName;
	d_sharesQuantity = order.d_sharesQuantity;
	d_maxPrice = order.d_maxPrice;
	d_orderTime = order.d_orderTime;
	return *this;
}

inline bool operator<(const LimitBuyOrder &left, const LimitBuyOrder &right)
{
	if (left.d_maxPrice == right.d_maxPrice)
	{
		return left.d_orderTime > right.d_orderTime;
	}

	return left.d_maxPrice < right.d_maxPrice;
}

inline std::ostream &operator<<(std::ostream &os, const LimitBuyOrder &order)
{
	os << order.d_buyerName << " " << order.d_sharesQuantity << " " << order.d_maxPrice << " " << order.d_orderTime;
	return os;
}

#endif
