
using namespace std;

class Inventory
{
public:
	Inventory();
	~Inventory();

	void addItem(Item item);
	bool removeItem(Item item);
	string getItems();

private:
	vector<Item> items;
};
