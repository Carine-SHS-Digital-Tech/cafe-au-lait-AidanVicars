#pragma once

#define GST_MULTIPLIER 1.1;

class menu_item
{
	const char* item_name;
	const float item_price;
	uint16_t times_ordered{ 0 };	
public:
	//Constructor
	menu_item(const char* name, const float price)
		: item_name(name), item_price(price)
	{
	}

	//Getters
	//__forceinline makes the compiler put the function's asm code where it is called instead of having a function call.
	__forceinline const float price()
	{
		return item_price;
	}

	__forceinline const float gst()
	{
		return item_price * GST_MULTIPLIER;
	}

	__forceinline const char* name()
	{
		return item_name;
	}

	__forceinline void order()
	{
		times_ordered++;
	}

	__forceinline uint16_t order_count()
	{
		return times_ordered;
	}

};

namespace menu
{

	//vector which holds our menu items
	std::vector<menu_item> menu_items = {
		{ "cappuccino", 3.0f },
		{ "espresso", 2.0f },
		{ "iced coffee", 2.0f },
		{ "latte", 2.0f, },
	};

	void iterate_items(std::function<void(menu_item&)> callback)
	{

		//For each item invoke the callback
		for (auto & current_item : menu_items)
			callback(current_item);

	}

}