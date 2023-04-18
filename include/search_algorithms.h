#pragma once

#include "List.h"
#include "Ordered_list.h"
#include "Key.h"
#include "Error_code.h"

Error_code sequential_search (const Ordered_list &the_list,
                              const Key &target, int &position)
/*
Post: If an entry in the_list has key equal to target, then return
      success and the output parameter position locates such an entry
      within the list.
      Otherwise return not_present and position becomes invalid.
*/
{
    int s = the_list.size();
    for (position = 0; position < s; position++)
    {
        Record data;
        the_list.retrieve(position, data);
        if (data == target)
        {
            return success;
        }
    }
    return not_present;
}

Error_code binary_search (const Ordered_list &the_list,
                          const Key &target, int &position)
/*
Post: If a Record in the_list has key equal to target, then position locates
      one such entry and a code of success is returned.
      Otherwise, not_present is returned and position is undefined.
Uses: Methods for classes Ordered_list and Record.
*/
{
    Record data;
    int bottom = 0, top = the_list.size() - 1;
    while (bottom <= top)
    {
        position = (bottom + top) / 2;
        the_list.retrieve(position, data);
        if (data == target)
        {
            return success;
        }
        if (data < target)
        {
            bottom = position + 1;
        }
        else
        {
            top = position - 1;
        }
    }
    return not_present;
}