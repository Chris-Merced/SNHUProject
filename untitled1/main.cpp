#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "GroceryItem.h"

using namespace std;

void MainMenuGreeting();
void MainMenuDisplay();
void FindFrequency();
vector<GroceryItem> CreateGroceryList();
void PrintAll();
void PrintHistogram();
void OutputBackup();

ifstream inputFile("CS210_Project_Three_Input_File.txt");
ofstream outputFile("frequency.dat");


int main() {
    //display menu options
    MainMenuDisplay();
    //backup files and close out
    OutputBackup();
}

//Display main menu greeting and options
void MainMenuGreeting(){
    cout << "Please choose one of the options for our store Inventory:  " << endl;
    cout << "1. Find Frequency of Specific word input" << endl;
    cout << "2. Print full list of all items purchased with frequency of purchases." << endl;
    cout << "3. Print a histogram of the frequency of all items purchased" << endl;
    cout << "4. Exit" << endl << endl;
}

//take user input and point to appropriate functions
void MainMenuDisplay(){
    int userInput = 0;

    MainMenuGreeting();

    while (userInput != 4) {

        cin >> userInput;

        switch (userInput) {
            case 1: {
                FindFrequency();
                MainMenuGreeting();
                break;
            }
            case 2: {
                PrintAll();
                MainMenuGreeting();
                break;
            }
            case 3: {
                PrintHistogram();
                MainMenuGreeting();
                break;
            }
            case 4: {
                break;
            }
            default: {
                cout << "Please input a number 1-4";

            }
        }
    }
}
//find the number of times a user input item occurs
void FindFrequency(){
    string searchItem;
    string line;
    int frequency = 0;

    cout << "Please input the item you would like to search: " << endl;
    cin >> searchItem;

    //clear() resets flags and seekg() returns cursor to the beginning of the input file to be read
    inputFile.clear();
    inputFile.seekg(0, inputFile.beg);

    //Every time searchItem is found frequency is increased by one
    while (getline(inputFile, line)){
        if (line == searchItem){
            frequency++;
        }

    }

    //After the file has been read output the frequency at which searchItem was found
    cout << frequency << endl << endl;
}

void PrintAll(){
    vector<GroceryItem> GroceryList = CreateGroceryList();

    //output unique item and the number of times that item occurs
    for (int i = 0; i < GroceryList.size(); i++){
        cout << GroceryList[i].GetStoreItem() << " ";
        cout << GroceryList[i].GetFrequency() << endl;
    }
}
//print the amount of times that each unique item is bought


vector<GroceryItem> CreateGroceryList(){
    vector<GroceryItem> GroceryList;
    vector<string> itemList;
    string tmpValue;
    string line;

    //clear() resets flags and seekg() returns cursor to the beginning of the input file to be read
    inputFile.clear();
    inputFile.seekg(0, inputFile.beg);

    //create vector itemList containing all unique elements in inputfile
    while (getline(inputFile, line)){
        if (find(itemList.begin(), itemList.end(), line) != itemList.end()){
        }
        else{
            itemList.push_back(line);
        }
    }

    //While loop until all items in itemList vector are deleted
    while (itemList.size() > 0){
        int frequency = 0;
        GroceryItem tmpItem;
        inputFile.clear();
        inputFile.seekg(0, inputFile.beg);

        //while loop to increase frequency every time unique element occurs in input file
        while (getline(inputFile, line)) {
            if (itemList[0] == line){
                frequency++;
            }

        }
        //Set both item name and frequency in class variables and then store class object in class object array
        tmpItem.SetStoreItem(itemList[0]);
        tmpItem.SetFrequency(frequency);
        GroceryList.push_back(tmpItem);
        //delete first element in array and loop again
        itemList.erase(itemList.begin());

    }
    return GroceryList;
}

void PrintHistogram(){
    vector<GroceryItem> GroceryList = CreateGroceryList();

    //Output unique store item and print number of stars for how many times the item occurs
    for (int i = 0; i < GroceryList.size(); i++){
        cout << GroceryList[i].GetStoreItem() << " ";
        for (int j = 0; j < GroceryList[i].GetFrequency(); j++){
            cout << "*";
        }
        cout << endl;
    }
    cout << endl << endl;
}

//Output item name and frequency of occurance to frequency.dat backup file
void OutputBackup(){
    vector<GroceryItem> GroceryList = CreateGroceryList();

    //output unique item and number of times item occurs to backup file frequency.dat
    for (int i = 0; i < GroceryList.size(); i++){
        outputFile << GroceryList[i].GetStoreItem() << " ";
        outputFile << GroceryList[i].GetFrequency() << endl;
    }

    cout << endl << endl;
}