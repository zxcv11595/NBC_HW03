#include <iostream>
#include <string>

#include "Inventory.h"

using namespace std;

int main()
{
	Inventory<Item>* itemInventory = new Inventory<Item>();
	for (int i = 0; i < 11; ++i)
	{
		itemInventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();
	std::cout << "ItemCapacity : " << itemInventory->GetCapacity() << std::endl;

	itemInventory->Resize(25);
	for (int i = 0; i < 14; ++i)
	{
		itemInventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();
	std::cout << "ItemCapacity : " << itemInventory->GetCapacity() << std::endl;

	itemInventory->SortItem();
	itemInventory->PrintAllItems();

	Inventory<Item>* itemInventory2 = new Inventory<Item>(*itemInventory);
	itemInventory2->PrintAllItems();

	delete itemInventory;
	delete itemInventory2;
	

}