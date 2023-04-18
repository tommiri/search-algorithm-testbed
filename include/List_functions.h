#pragma once

#include <iostream>
#include <string>

#include "List.h"

using std::cout, std::endl;

template<typename List_entry>
Error_code insert_first (const List_entry &x, List<List_entry> &a_list)
/*
Post:
Entry x is inserted at position 0 of List a_list.
*/
{
    return a_list.insert(0, x);
}

template<typename List_entry>
Error_code remove_first (List_entry &x, List<List_entry> &a_list)
/*
Post:
A code of underflow is returned if List a_list is
empty.  Otherwise, the first entryof List a_list
is removed and reported as x.
*/
{
    return a_list.remove(0, x);
}

template<typename List_entry>
Error_code insert_last (const List_entry &x, List<List_entry> &a_list)
/*

Post:
Parameter x is inserted as the last entry of the List a_list.
*/
{
    return a_list.insert(a_list.size(), x);
}

template<typename List_entry>
Error_code remove_last (List_entry &x, List<List_entry> &a_list)
/*
Post:
A code of underflow is returned if List a_list is
empty. Otherwise, the last entry of List a_list is
removed and reported as x.
*/
{
    return a_list.remove(a_list.size() - 1, x);
}

template<typename List_entry>
Error_code median_list (List_entry &x, List<List_entry> &a_list)
/*
Post:
A code of underflow is returned if List a_list is
empty. Otherwise, the median entry of List a_list
is reported as x.
*/
{
    return a_list.retrieve((a_list.size() - 1) / 2, x);
}

template<typename List_entry>
Error_code interchange (int pos1, int pos2, List<List_entry> &a_list)
/*
Post:
Any entries at positions pos1 and pos2 of List a_list
are interchanged. If either entry is missing a code of
range_error is returned.
*/
{
    List_entry entry1, entry2;
    Error_code outcome = a_list.retrieve(pos1, entry1);
    if (outcome == success)
    {
        outcome = a_list.retrieve(pos2, entry2);
    }
    if (outcome == success)
    {
        outcome = a_list.replace(pos1, entry2);
    }
    if (outcome == success)
    {
        outcome = a_list.replace(pos2, entry1);
    }
    return outcome;
}


template<typename List_entry>
void reverse_traverse_list (List<List_entry> &a_list,
                            void (*visit) (List_entry &))
/*
Post:
The List a_list is traversed, in reverse order,
and the function *visit is applied to all entries.
*/
{
    List_entry item;
    for (int i = a_list.size() - 1; i >= 0; i--)
    {
        a_list.retrieve(i, item);
        (*visit)(item);
    }
}

template<typename List_entry>
bool reverse (List<List_entry> &a_list)
/*
Post: Reverses the order of all entries in a_list.
A code of fail is returned in case the reversal cannot
be completed.
*/
{
    List<List_entry> temp;
    List_entry item;
    Error_code outcome = success;
    for (int i = 0; i < a_list.size(); i++)
    {
        a_list.retrieve(i, item);
        if (temp.insert(i, item) != success)
        {
            outcome = fail;
        }
    }

    for (int j = 0; j < a_list.size(); j++)
    {
        temp.retrieve(j, item);
        a_list.replace(a_list.size() - 1 - j, item);
    }
    return outcome;
}

template<typename List_entry>
Error_code split (List<List_entry> &source, List<List_entry> &oddlist, List<List_entry> &evenlist)
/*
Post:
Copies all entries from
source so that those in odd-numbered positions make up oddlist and those
in even-numbered positions make up evenlist.
Returns an error code of overflow in case either output list
fills before the copy is complete.
*/
{
    List_entry item;
    Error_code outcome = success;
    for (int i = 0; i < source.size(); i++)
    {
        source.retrieve(i, item);
        if (i % 2 != 0)
        {
            if (oddlist.insert(oddlist.size(), item) == overflow)
            {
                outcome = overflow;
            }
        }
        else if (evenlist.insert(evenlist.size(), item) == overflow)
        {
            outcome = overflow;
        }
    }
    return outcome;
}

template<typename List_entry>
void write_entry (List_entry &c)
{
    cout << c << " ";
}

template<typename List_entry>
Error_code copy (List<List_entry> &dest, const List<List_entry> &source)
/*
Post:
All entries are copied from from
source into dest; source remains unchanged.
A code of fail is returned if a complete copy
cannot be made.
*/
{
    List_entry item;
    Error_code outcome = success;
    while (!dest.empty())
    {
        dest.remove(0, item);
    }

    for (int i = 0; i < source.size(); i++)
    {
        if (source.retrieve(i, item) != success)
        {
            outcome = fail;
            while (!dest.empty())
            {
                dest.remove(0, item);
            }
            return outcome;
        }
        if (dest.insert(i, item) != success)
        {
            outcome = fail;
            while (!dest.empty())
            {
                dest.remove(0, item);
            }
            return outcome;
        }
    }
    return outcome;
}

template<typename List_entry>
Error_code join (List<List_entry> &list1, List<List_entry> &list2)
/*
Post:
All entries from
list1 are copied onto the end of list2.
A code of overflow is returned if list2 is filled up
before the copying is complete.
*/
{
    List_entry item;
    for (int i = 0; i < list1.size(); i++)
    {
        list1.retrieve(i, item);
        if (list2.insert(list2.size(), item) != success)
        {
            return overflow;
        }
    }
    return success;
}

template<typename List_entry>
void printList (List<List_entry> &list, const std::string &msg = "")
{
    if (!msg.empty())
    {
        cout << msg << endl;
    }

    if (!list.empty())
    {
        list.traverse(write_entry);
        cout << endl;
    }
    else
    {
        cout << "List is empty." << endl;
    }
}