#include "stdafx.h"
#include "Item.h"


Item::Item(){}
Item::~Item(){}

void Item::generateItem()
{

}

void Item::generateItem(int itemId) 
{ 
	int randomItem = rand() % 21;
	gameItems(randomItem);
}

void Item::setItem(int id) {
	gameItems(id);
}

void Item::useItem() { /* We do not implement this */ }

string Item::getItemName() { return itemName; }

string Item::getItemString() {
	 return getItemName() + ": " + getDescription() + "\n";
}

void Item::gameItems(int id)
{
	switch (id) {
		case 0:
			setItemId(0);
			itemName		= "Knife";
			itemDescription = "A dangerous looking knife.";
			break;
		case 1:
			setItemId(1);
			itemName		= "Pickaxe";
			itemDescription = "Used for mining.";
			break;
		case 2:
			setItemId(2);
			itemName		= "Hatchet";
			itemDescription = "A powerful axe.";
			break;
		case 3:
			setItemId(3);
			itemName		= "Book";
			itemDescription = "Something to read.";
			break;
		case 4:
			setItemId(4);
			itemName		= "Golden key";
			itemDescription = "Opens a door.";
			break;
		case 5:
			setItemId(5);
			itemName		= "Red key";
			itemDescription = "Opens a door.";
			break;
		case 6:
			setItemId(6);
			itemName		= "Green key";
			itemDescription = "Opens a door.";
			break;
		case 7:
			setItemId(7);
			itemName		= "Zombie head";
			itemDescription = "I look 40.000 years old in this..";
			break;
		case 8:
			setItemId(8);
			itemName		= "Tourch";
			itemDescription = "Some light in the darkness.";
			break;
		case 9:
			setItemId(9);
			itemName		= "Skull";
			itemDescription = "A human head.";
			break;
		case 10:
			setItemId(10);
			itemName		= "Rope";
			itemDescription = "A coil of rope.";
			break;
		case 11:
			setItemId(11);
			itemName		= "Hammer";
			itemDescription = "Opens a door.";
			break;
		case 12:
			setItemId(12);
			itemName		= "Brush";
			itemDescription = "To paint.";
			break;
		case 13:
			setItemId(13);
			itemName		= "Hammer";
			itemDescription = "Good for hitting things!";
			break;
		case 14:
			setItemId(14);
			itemName		= "Ice Gloves";
			itemDescription = "Some nice gloves, but I don't know how to wear theam!";
			break;
		case 15:
			setItemId(15);
			itemName		= "Mithril bar";
			itemDescription = "It's a bar of mithril";
			break;
		case 16:
			setItemId(16);
			itemName		= "Iron bar";
			itemDescription = "It's a bar of iron";
			break;
		case 17:
			setItemId(17);
			itemName		= "Steel bar";
			itemDescription = "It's a bar of steel";
			break;
		case 18:
			setItemId(18);
			itemName		= "Chisel";
			itemDescription = "Good for detailed Crafting.";
			break;
		case 19:
			setItemId(19);
			itemName		= "Needle";
			itemDescription = "Used with a thread to make clothes.";
			break;
		case 20:
			setItemId(20);
			itemName		= "Harpoon";
			itemDescription = "Useful for catching really big fish.";
			break;
	}
}