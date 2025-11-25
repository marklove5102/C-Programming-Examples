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
void ResetLinkedListA(void)
{
    LinkedListA = &LinkedListANode1;
    LinkedListANode1.Next = &LinkedListANode2;
    LinkedListANode1.Value = 1;
    LinkedListANode2.Next = &LinkedListANode3;
    LinkedListANode2.Value = 2;
    LinkedListANode3.Next = NULL;
    LinkedListANode3.Value = 3;
}

static LINKED_LIST LinkedListBNode1 = { NULL, 1 };
PLINKED_LIST LinkedListB = &LinkedListBNode1;
void ResetLinkedListB(void)
{
    LinkedListB = &LinkedListBNode1;
    LinkedListBNode1.Next = NULL;
    LinkedListBNode1.Value = 1;
}

static LINKED_LIST LinkedListCNode4 = { NULL, 7 };
static LINKED_LIST LinkedListCNode3 = { &LinkedListCNode4, 5 };
static LINKED_LIST LinkedListCNode2 = { &LinkedListCNode3, 2 };
static LINKED_LIST LinkedListCNode1 = { &LinkedListCNode2, 0 };
PLINKED_LIST LinkedListC = &LinkedListCNode1;
void ResetLinkedListC(void)
{
    LinkedListC = &LinkedListCNode1;
    LinkedListCNode1.Next = &LinkedListCNode2;
    LinkedListCNode1.Value = 0;
    LinkedListCNode2.Next = &LinkedListCNode3;
    LinkedListCNode2.Value = 2;
    LinkedListCNode3.Next = &LinkedListCNode4;
    LinkedListCNode3.Value = 5;
    LinkedListCNode4.Next = NULL;
    LinkedListCNode4.Value = 7;
}

#pragma endregion
