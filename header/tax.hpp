#ifndef TAX_H
#define TAX_H
#include <bits/stdc++.h>
#include "ItemCategory.hpp"
#include "item.hpp"
using namespace std;
class Tax
{
private:
    const double BASIC_RATE = 0.1;                                         //Basic sales tax rate
    const double IMPORT_RATE = 0.05;                                       //Import tax rate
    const vector<ItemCategory> canTaxOnCategory = {ItemCategory::General}; //Stores categories on which basic tax applies ie. NON EXEMPTED
    double round(double value);                                            // to round up to nearest 0.05

public:
    double getTaxOnItem(Item item);
    double getBasicRate() { return BASIC_RATE; }
    double getImportRate() { return IMPORT_RATE; }
};
#endif
