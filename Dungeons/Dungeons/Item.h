#pragma once
class Item
{
public:
	Item();
	~Item();

	
	void	useItem();
	string	getItemName();

	int		getItemId()				{ return itemId; }
	string	getDescription()		{ return itemDescription; }
	string  getItemString();

private:
	int		itemId;
	string	itemName;
	string	itemDescription;

	void	generateItem();
	void	generateItem(int itemId);
	void	gameItems(int id);

	void	setItem(int id);
	void	setItemId(int id) { itemId = id; }

};