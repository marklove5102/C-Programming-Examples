#include "pch.h"

#pragma region List

/* Linked list */

void
PrintLinkedListEx(
    _In_z_ wchar_t* ListName,
    _In_ PLINKED_LIST List)
{
    PLINKED_LIST Next;

    wprintf(L"%ls = { ", ListName);
    while (List != NULL)
    {
        Next = List->Next;
        wprintf(Next != NULL ? L"%lu," : L"%lu ", List->Value);
        List = Next;
    }
    _putws(L"}");
}

static LINKED_LIST LinkedListANode3 = { NULL, 3 };
static LINKED_LIST LinkedListANode2 = { &LinkedListANode3, 2 };
static LINKED_LIST LinkedListANode1 = { &LinkedListANode2, 1 };
PLINKED_LIST LinkedListA = &LinkedListANode1;

static LINKED_LIST LinkedListBNode1 = { NULL, 1 };
PLINKED_LIST LinkedListB = &LinkedListBNode1;

#pragma endregion
