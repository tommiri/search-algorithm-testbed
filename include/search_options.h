#pragma once

#include <iostream>

#include "Random.h"
#include "Timer.h"
#include "utility_functions.h"
#include "search_algorithms.h"

Error_code getSearchResult (Ordered_list &list, int &target, int &position, Error_code (*search) (const Ordered_list &, const Key &, int &),
                            double &elapsed);

void runSearch (Error_code (*search) (const Ordered_list &, const Key &, int &), const std::string &msg);

void doPerformanceRun ();

void printRunResults (const Error_code &, const double &, const int &);

void printPerformance (const double &, const int &, const double &, const int &, const int &, const int &);

void runSearch (Error_code (*search) (const Ordered_list &, const Key &, int &), const std::string &msg)
{
    system("clear");
    int listSize{}, target{}, position{};
    double elapsed{};

    getInput(listSize, "List size: ");
    getInput(target, "Value to find: ");

    auto list = generateOddRecordList(listSize);

    system("clear");
    std::cout << msg <<
              "\n----------------------";
    auto result = getSearchResult(list, target, position, search, elapsed);
    printRunResults(result, elapsed, position);
}

Error_code getSearchResult (Ordered_list &list, int &target, int &position, Error_code (*search) (const Ordered_list &, const Key &, int &),
                            double &elapsed)
{
    Key::comparisons = 0; // Reset comparisons to 0 before search
    auto timer = Timer();
    auto result = search(list, target, position);
    elapsed = timer.elapsed_time();

    return result;
}

void doPerformanceRun ()
{
    system("clear");
    int repetitions{}, position{};
    getInput(repetitions, "How many repetitions?\nEnter value: ");

    int sumSuccessfulRuns{}, sumFailedRuns{};
    int seqSuccessComparisons{}, seqFailComparisons{};
    int binSuccessComparisons{}, binFailComparisons{};
    double elapsed{};
    double seqSuccessElapsed{}, seqFailElapsed{};
    double binSuccessElapsed{}, binFailElapsed{};
    int minList = 100;
    int maxList = 500000;
    Random random{};

    for (int i = 0; i < repetitions; i++)
    {
        int listSize = random.random_integer(minList, maxList);
        int target = random.random_integer(0, listSize);
        auto list = generateOddRecordList(listSize);

        // Sequential search
        auto result = getSearchResult(list, target, position, sequential_search, elapsed);
        if (result == success)
        {
            sumSuccessfulRuns++;
            seqSuccessComparisons += Key::comparisons;
            seqSuccessElapsed += elapsed;
        }
        else
        {
            sumFailedRuns++;
            seqFailComparisons += Key::comparisons;
            seqFailElapsed += elapsed;
        }

        // Binary search
        result = getSearchResult(list, target, position = 0, binary_search, elapsed);
        if (result == success)
        {
            binSuccessComparisons += Key::comparisons;
            binSuccessElapsed += elapsed;
        }
        else
        {
            binFailComparisons += Key::comparisons;
            binFailElapsed += elapsed;
        }
    }

    system("clear");
    std::cout << "Sequential search\n"
                 "-----------------------\n";
    printPerformance(seqSuccessElapsed, seqSuccessComparisons, seqFailElapsed, seqFailComparisons, sumSuccessfulRuns, sumFailedRuns);

    std::cout << "\nBinary search\n"
                 "-----------------------\n";
    printPerformance(binSuccessElapsed, binSuccessComparisons, binFailElapsed, binFailComparisons, sumSuccessfulRuns, sumFailedRuns);

}

void printRunResults (const Error_code &result, const double &elapsed, const int &position)
{
    std::cout << "\nStatus: " << (result == success ? "Successful" : "Unsuccessful") <<
              "\nElapsed time: " << std::fixed << elapsed << " s" <<
              "\nComparisons: " << Key::comparisons <<
              "\nFound at position: " <<
              (result == success ? std::to_string(position) : "Not found") << '\n';
}

void printPerformance (const double &successElapsed, const int &successComparisons, const double &failElapsed, const int &
failComparisons, const int &sumSuccessfulRuns, const int &sumFailedRuns)
{
    double avgSuccessElapsed{}, avgFailElapsed{};
    int avgSuccessComparisons{}, avgFailComparisons{};
    if (sumSuccessfulRuns > 0)
    {
        avgSuccessElapsed = successElapsed / sumSuccessfulRuns;
        avgSuccessComparisons = successComparisons / sumSuccessfulRuns;
    }
    if (sumFailedRuns > 0)
    {
        avgFailElapsed = failElapsed / sumFailedRuns;
        avgFailComparisons = failComparisons / sumFailedRuns;
    }

    std::cout << "Status: Successful"
                 "\nElapsed per search: " << std::fixed << avgSuccessElapsed << " s" <<
              "\nComparisons per search: " << avgSuccessComparisons <<
              "\nSearches: " << sumSuccessfulRuns << '\n';

    std::cout << "\nStatus: Unsuccessful"
                 "\nElapsed per search: " << std::fixed << avgFailElapsed << " s" <<
              "\nComparisons per search: " << avgFailComparisons <<
              "\nSearches: " << sumFailedRuns << '\n';

}