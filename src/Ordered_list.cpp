#include "../include/Ordered_list.h"

Error_code Ordered_list::insert (const Record &data)
/*
    Post: If the Ordered list is not full, the function succeeds: The Record data
    is inserted into the list, following the last entry of the list with a strictly lesser
    key (or in the first list position if no list element has a lesser key).
    Else: the function fails with the diagnostic Error code overflow.
*/
{
    int s = size();
    int position;
    for (position = 0; position < s; position++)
    {
        Record list_data;
        retrieve(position, list_data);
        if (data >= list_data)
        {
            break;
        }
    }
    return List<Record>::insert(position, data);
}

Error_code Ordered_list::insert (int position, const Record &data)
/*
    Post: If the Ordered list is not full, 0 ≤ position ≤ n, where n is the
    number of entries in the list, and the Record data can be inserted at
    position in the list, without disturbing the list order, then the function
    succeeds: Any entry formerly in position and all later entries have their
    position numbers increased by 1 and data is inserted at position of the List.
    Else: the function fails with a diagnostic Error code.
*/
{
    Record list_data;
    if (position > 0)
    {
        retrieve(position - 1, list_data);
        if (data < list_data)
        {
            return fail;
        }
    }

    if (position < size())
    {
        retrieve(position, list_data);
        if (data > list_data)
        {
            return fail;
        }
    }
    return List<Record>::insert(position, data);
}

Error_code Ordered_list::replace (int position, const Record &data)
{
    Record list_data;
    if (position > 0)
    {
        retrieve(position - 1, list_data);
        if (data < list_data)
        {
            return fail;
        }
    }

    if (position < size() - 1)
    {
        retrieve(position + 1, list_data);
        if (data > list_data)
        {
            return fail;
        }
    }

    return List<Record>::replace(position, data);
}