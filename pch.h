#pragma once

#include <sal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <errno.h>

typedef
_Function_class_(FN_EXAMPLE_PROC)
bool
FN_EXAMPLE_PROC(void);

#pragma region List

/* Linked list */

typedef struct _LINKED_LIST
{
    struct _LINKED_LIST* Next;
    unsigned int Value;
} LINKED_LIST, *PLINKED_LIST;

void
PrintLinkedListEx(
    _In_z_ wchar_t* ListName,
    _In_ PLINKED_LIST List);

#define PrintLinkedList(x) PrintLinkedListEx(L###x, x)

extern PLINKED_LIST LinkedListA; // { 1, 2, 3 }
extern PLINKED_LIST LinkedListB; // { 1 }

#pragma endregion
