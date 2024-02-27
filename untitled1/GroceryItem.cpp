//
// Created by Chris on 2/25/2024.
//

#include "GroceryItem.h"

void GroceryItem::SetFrequency(int frequency) {
    this->frequency = frequency;
}

int GroceryItem::GetFrequency() {
    return frequency;
}

void GroceryItem::SetStoreItem(string storeItem) {
    this->storeItem = storeItem;
}

string GroceryItem::GetStoreItem(){
    return storeItem;
}