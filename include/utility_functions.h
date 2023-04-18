#pragma once

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

#include "Key.h"
#include "List_functions.h"
#include "Ordered_list.h"

void printOptions ();

template<typename T>
void getInput (T &input, const std::string &msg, std::vector<T> validOptions = {})
{
    using std::cout, std::cerr, std::cin;
    bool isInvalidInput{};

    do
    {
        cout << msg;
        cin >> input;

        if (!validOptions.empty())
        {
            if (std::find(validOptions.begin(), validOptions.end(), input) != validOptions.end())
            {
                break;
            }
            else
            {
                cin.setstate(std::ios_base::failbit); // Set cin to fail to trigger error
            }
        }

        if (cin.fail())
        {
            isInvalidInput = true;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << "ERROR: Invalid input.\n\n";
        }
    } while (isInvalidInput);

}

Ordered_list generateOddRecordList (int size)
{
    Ordered_list newList;

    int i = 0;
    while (newList.size() < size)
    {
        if (i % 2 != 0)
        {
            insert_last(Record(i), newList);
        }
        i++;
    }

    return newList;
}

void printOptions ()
{
    std::cout << "1. Sequential search\n"
                 "2. Binary search\n"
                 "3. Search algorithm performance run\n";
}