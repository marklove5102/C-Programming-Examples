#include "pch.h"

static
PLINKED_LIST
Merge(
    _In_ PLINKED_LIST LinkedList1,
    _In_ PLINKED_LIST LinkedList2)
{
    PLINKED_LIST Head, Node, List1, List2;

    /* Prepare head node */
    if (LinkedList1->Value < LinkedList2->Value)
    {
        Head = LinkedList1;
        List1 = LinkedList1->Next;
        List2 = LinkedList2;
    } else
    {
        Head = LinkedList2;
        List1 = LinkedList1;
        List2 = LinkedList2->Next;
    }
    Node = Head;

    /* Find the smaller one */
    while (List1 != NULL && List2 != NULL)
    {
        if (List1->Value < List2->Value)
        {
            Node->Next = List1;
            List1 = List1->Next;
        } else
        {
            Node->Next = List2;
            List2 = List2->Next;
        }
        Node = Node->Next;
    }

    /* Join the rest part */
    Node->Next = List1 == NULL ? List2 : List1;

    return Head;
}

_Function_class_(FN_EXAMPLE_PROC)
bool
DataStructure_LinkedList_Merge(void)
{
    PLINKED_LIST MergedLinkedList;
    
    /* Print LinkedListA and LinkedListC, then merge them and print */
    PrintLinkedList(LinkedListA);
    PrintLinkedList(LinkedListC);
    MergedLinkedList = Merge(LinkedListA, LinkedListC);
    PrintLinkedList(MergedLinkedList);

    /* Verify result */
    if (MergedLinkedList->Value != 0 ||
        MergedLinkedList->Next->Value != 1 ||
        MergedLinkedList->Next->Next->Value != 2 ||
        MergedLinkedList->Next->Next->Next->Value != 2 ||
        MergedLinkedList->Next->Next->Next->Next->Value != 3 ||
        MergedLinkedList->Next->Next->Next->Next->Next->Value != 5 ||
        MergedLinkedList->Next->Next->Next->Next->Next->Next->Value != 7 ||
        MergedLinkedList->Next->Next->Next->Next->Next->Next->Next != NULL)
    {
        return false;
    }

    /* Restore LinkedListA and LinkedListC */
    ResetLinkedListA();
    ResetLinkedListC();
    return true;
}
