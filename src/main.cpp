#include <iostream>
#include <vector>

#include "../include/utility_functions.h"
#include "../include/search_options.h"

using std::cout, std::cin, std::cerr;

int main()
{
    system("clear");
    int option{};
    bool isInvalidOption{};
    cout << "Test bed for search algorithms\n"
            "-------------------------------\n";

    do
    {
        isInvalidOption = false;
        printOptions();
        getInput(option, "Enter option: ");

        switch (option)
        {
        case 1:
            runSearch(sequential_search, "Sequential search");
            break;
        case 2:
            runSearch(binary_search, "Binary search");
            break;
        case 3:
            doPerformanceRun();
            break;
        default:
            isInvalidOption = true;
            cerr << "ERROR: Invalid option.\n\n";
        }
    } while (isInvalidOption);

    return EXIT_SUCCESS;
}