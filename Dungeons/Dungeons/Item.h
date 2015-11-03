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

	void	generateItem();
	void	generateItem(int itemId);

	bool	operator==(const Item& other);

private:
	int		itemId;
	string	itemName;
	string	itemDescription;

	void	gameItems(int id);

	void	setItem(int id);
	void	setItemId(int id) { itemId = id; }

};