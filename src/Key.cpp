#include "../include/Key.h"

int Key::comparisons = 0;

Key::Key (int aKey)
{
    key = aKey;
};

int Key::getKey () const
{
    return key;
};

bool Key::operator== (const Key &x) const
{
    Key::comparisons++;
    return getKey() == x.getKey();
}

bool Key::operator> (const Key &x) const
{
    Key::comparisons++;
    return getKey() > x.getKey();
}

bool Key::operator< (const Key &x) const
{
    Key::comparisons++;
    return getKey() < x.getKey();
}

bool Key::operator>= (const Key &x) const
{
    Key::comparisons++;
    return getKey() >= x.getKey();
}

bool Key::operator<= (const Key &x) const
{
    Key::comparisons++;
    return getKey() <= x.getKey();
}

bool Key::operator!= (const Key &x) const
{
    Key::comparisons++;
    return getKey() != x.getKey();
}

std::ostream &Key::operator<< (std::ostream &os) const
{
    os << getKey();
    return os;
}