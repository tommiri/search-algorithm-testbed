#pragma once

#include <ctime>

class Timer
{
public:
    Timer ();

    double elapsed_time () const;

    void reset ();

private:
    clock_t start_time;
};