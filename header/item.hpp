
#ifndef ITEM_H
#define ITEM_H
#include <bits/stdc++.h>
#include "ItemCategory.hpp"//use as header file

using namespace std;

class Item
{

private:
    ItemCategory itemCategory; //category of this item
    double price;              //price of item
    bool imported;             //if it is imported or not

public:
    Item(ItemCategory itemCategory, double price, bool imported);
    ItemCategory getItemCategory() { return itemCategory; }
    double getPrice() { return price; }
    bool isImported() { return imported; }
};

#endif
