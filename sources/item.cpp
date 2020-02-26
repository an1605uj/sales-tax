#include <bits/stdc++.h>
#include "item.hpp"
using namespace std;

Item::Item(ItemCategory itemCategory, double price, bool imported)
{
    this->itemCategory = itemCategory;
    this->price = price;
    this->imported = imported;
}
