#include "pch.h"

static
PLINKED_LIST
Reverse(
    _In_ PLINKED_LIST LinkedList)
{
    PLINKED_LIST pPrev, pCurrent, pTemp;

    /* Process the first node */
    pPrev = LinkedList;
    pCurrent = pPrev->Next;
    pPrev->Next = NULL;

    /* Traversal the rest nodes */
    while (pCurrent != NULL)
    {
        /* Let current node points to the previous node */
        pTemp = pCurrent->Next;
        pCurrent->Next = pPrev;

        /* Move to the next node */
        pPrev = pCurrent;
        pCurrent = pTemp;
    }

    /* The last node is the head now */
    return pPrev;
}

_Function_class_(FN_EXAMPLE_PROC)
bool
DataStructure_LinkedList_Reverse(void)
{
    PLINKED_LIST ReverseLinkedList;
    
    /* Print LinkedListA and reversed result */
    PrintLinkedList(LinkedListA);
    ReverseLinkedList = Reverse(LinkedListA);
    PrintLinkedList(ReverseLinkedList);

    /* Verify result */
    if (ReverseLinkedList->Value != 3 ||
        ReverseLinkedList->Next->Value != 2 ||
        ReverseLinkedList->Next->Next->Value != 1 ||
        ReverseLinkedList->Next->Next->Next != NULL)
    {
        return false;
    }
    
    /* Restore LinkedListA and return success */
    LinkedListA = Reverse(ReverseLinkedList);

    /* Test LinkedListB, which has only one node */

    PrintLinkedList(LinkedListB);
    ReverseLinkedList = Reverse(LinkedListB);
    PrintLinkedList(ReverseLinkedList);

    return ReverseLinkedList == LinkedListB;
}
