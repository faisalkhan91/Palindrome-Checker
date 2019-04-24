/** File: StackType.cpp
 *
 * Source file for array-based Stack implementation.
 * Size of new Stack is defined by MAX_ITEMS constant
 * defined in ItemType.h.
 *
 */

#include "tools.hpp"
#include "StackType.h"

StackType::StackType()
{
    top = -1;
}

bool StackType::IsEmpty() const
{
    return ( top == -1 );
}

bool StackType::IsFull() const
{
    return ( top ==  MAX_ITEMS - 1 );
}

void StackType::Push ( ItemType newItem )
{
    if ( IsFull() )
        throw FullStackException();

    top++;
    items[top] = newItem;
}

void StackType::Pop()
{
    if ( IsEmpty() )
        throw EmptyStackException();

    top--;
}

ItemType StackType::Top()
{
    if ( IsEmpty() )
        throw EmptyStackException();

    return items[top];
}



