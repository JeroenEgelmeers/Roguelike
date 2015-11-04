#include "stdafx.h"
#include "Inventory.h"
using namespace std;
//std::list straks nodig

Inventory::Inventory() {}
Inventory::~Inventory() {}

void Inventory::addItem(Item* item)
{
	// if (items.size() < 8) { } // Could be implemented to make sure players can only get 8? items.
	items.push_back(item);
}

bool Inventory::removeItem(Item* item)
{
	bool itemRemoved = false;
	auto iter = find(items.begin(), items.end(), item);
	if (iter != items.end()) {
		items.erase(iter);
		itemRemoved = true;
	}

	return itemRemoved;
}

string Inventory::getItems()
{
	string description = "";

	for (Item* i : items)
	{
		description += i->getItemName() + " [" +  i->getDescription() + " ]";
	}
	if (description == "") { description = "You don't have any items in your inventory!\n"; }
	return description;
}
