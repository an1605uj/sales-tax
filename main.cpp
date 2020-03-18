#include<bits/stdc++.h>
#include "header/ItemCategory.hpp"
#include "header/item.hpp"
#include "header/tax.hpp"
using namespace std;
vector<Item> basket; //stores all items of a basket
vector<string> order; // stores each order of item
Tax tax;
void printReceipt()
{

    //print order of each item
    for (int i = 0; i < order.size(); i++)
        cout << order[i] << ": " << (basket[i].getPrice() + tax.getTaxOnItem(basket[i])) << "\n";

    double salesTax = 0.0, total = 0.0;
    for (auto item : basket)
    {
        total += item.getPrice();
        salesTax += tax.getTaxOnItem(item);
    }
    total += salesTax;
    //print sales tax and total bill
    cout << "Sales Taxes: " << salesTax << "\n";
    cout << "Total: " << total << "\n";

}
int main()
{
    string s;

    cout << "Enter your order on each line:\nAt the end type 'stop' on a new line to finish" << endl;

    //read whole line using getline
    while (getline(cin, s))
    {
        //stop if getline gives "stop"
        if (s == "stop")
            break;

        //push orders to our vector
        order.push_back(s.substr(0, s.length() - 8));

        //using string stream to iterate over words of string
        stringstream ss(s);
        string temp;
        ItemCategory itemCategory = ItemCategory::General;
        bool imported = false;

        while (ss >> temp)
        {
            //decide whether item is imported or not and items category based on words in given sample
            if (temp == "imported")
                imported = true;
            if (temp == "chocolates" or temp == "chocolate")
                itemCategory = ItemCategory::Food;
            else if (temp == "burger" or temp == "burgers")
                itemCategory = ItemCategory::Food;
            else if (temp == "pizza" or temp == "pizzas")
                itemCategory = ItemCategory::Food;
            else if (temp == "pills")
                itemCategory = ItemCategory::Medical;
            else if (temp == "capsule" or temp=="capsules")
                itemCategory = ItemCategory::Medical;
            else if (temp == "syrup" or temp=="syrups" )
                itemCategory = ItemCategory::Medical;
            else if (temp == "book")
                itemCategory = ItemCategory::Book;
        }
        //get price from last word of string
        stringstream tempp(temp);
        double price;
        tempp>>price;

        // push item object to basket
        basket.push_back(Item(itemCategory, price, imported));
    }

    printReceipt();

    return 0;
}
