#pragma once
class Item
{
public:
	Item();
	~Item();

	void	generateItem();
	void	generateItem(int itemId);
	void	useItem();
	string	getItemName();
	void	gameItems(int id);

	void	setItem(int id);
	void	setItemId(int id)		{ itemId = id; }
	int		getItemId()				{ return itemId; }
	string	getDescription()		{ return itemDescription; }
	string  getItemString();

private:
	int		itemId;
	string	itemName;
	string	itemDescription;
};