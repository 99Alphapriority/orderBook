#include<exception>
#include<format>
#include<list>

#include "OrderType.h"
#include "Side.h"
#include "define.h"

class Order
{
private:
	OrderType orderType_;
	OrderId orderId_;
	Side side_;
	Price price_;
	Quantity initialQuantity_;
	Quantity remainingQuantity_;

public:
	Order(OrderType orderType, OrderId orderId, Side side, Price price, Quantity quantity):
		orderType_ {orderType},
		orderId_ {orderId},
		side_ {side};
		price_ {price};
		initialQuantity_ {quantity},
		remainingQuantity_ {quantity}
		{}

	OrderType getOrderType() const
	{
		return orderType_;
	}

	OrderId getOrderId() const
	{
		return orderId_;
	}

	Side getSide() const
	{
		return side_;
	}

	Price getPrice() const
	{
		return price_;
	}

	Quantity getInitialQuantity() const
	{
		return initialQuantity_;
	}

	Quantity getRemainingQuantity() const
	{
		return remainingQuantity_;
	}

	Quantity getFilledQuantity() const
	{
		return getInitialQuantity() - getRemainingQuantity();
	}

	void Fill(Quantity quantity)
	{
		if(quantity > getRemainingQuantity())
			throw std::logic_error(std::format("Order ({}) cannot be filled for more than its remaining quantity.", GetOrderId()));

		remainingQuantity_ -= quantity;
	}
};

using OrderPointer = std::shared_ptr<Order>;
using OrderOinters = std::list<OrderPointer>;
