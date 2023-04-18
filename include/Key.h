#pragma once

#include <iostream>

class Key
{
public:
    static int comparisons;

    Key (int aKey = 0);

    int getKey () const;

    bool operator== (const Key &x) const;

    bool operator> (const Key &x) const;

    bool operator< (const Key &x) const;

    bool operator>= (const Key &x) const;

    bool operator<= (const Key &x) const;

    bool operator!= (const Key &x) const;

    std::ostream &operator<< (std::ostream &os) const;

private:
    int key;
};

typedef Key Record;