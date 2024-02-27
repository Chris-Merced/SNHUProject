//
// Created by Chris on 2/25/2024.
//

#ifndef UNTITLED1_GROCERYITEM_H
#define UNTITLED1_GROCERYITEM_H

#include <iostream>
using namespace std;

class GroceryItem {
public:
    void SetStoreItem(string storeItem);
    string GetStoreItem();
    void SetFrequency(int frequency);
    int GetFrequency();

private:
    int frequency;
    string storeItem;
};



#endif //UNTITLED1_GROCERYITEM_H
