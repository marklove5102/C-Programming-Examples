#include "pch.h"

typedef struct _EXAMPLE_PROC
{
    wchar_t* Name;
    FN_EXAMPLE_PROC* Proc;
} EXAMPLE_PROC;

#define DECL_EXAMPLE_PROC(x) { L###x, &x }

/* Append new example here in alphabetical order */

extern FN_EXAMPLE_PROC DataStructure_LinkedList_Reverse;
extern FN_EXAMPLE_PROC Print_MultiplicationTable;

static const EXAMPLE_PROC ExampleList[] = {
    DECL_EXAMPLE_PROC(DataStructure_LinkedList_Reverse),
    DECL_EXAMPLE_PROC(Print_MultiplicationTable),
};

static
bool
RunExample(
    _In_ const EXAMPLE_PROC* Example)
{
    bool bRet;

    wprintf(L"======== Running example: %ls ========\n", Example->Name);
    bRet = Example->Proc();
    wprintf(L"======== %ls ========\n\n", bRet ? L"Succeeded" : L"Failed");

    return bRet;
}

int wmain(
    _In_ int argc,
    _In_reads_(argc) _Pre_z_ wchar_t** argv)
{
    _wsetlocale(LC_ALL, L".ACP");

    if (argc == 1)
    {
        /* No argument, run all examples */
        for (int i = 0; i < __crt_countof(ExampleList); i++)
        {
            if (!RunExample(&ExampleList[i]))
            {
                return EFAULT;
            }
        }
        return 0;
    } else if (argc == 2)
    {
        /* One argument, run specified example */
        for (int i = 0; i < __crt_countof(ExampleList); i++)
        {
            if (_wcsicmp(argv[1], ExampleList[i].Name) == 0)
            {
                return RunExample(&ExampleList[i]) ? 0 : EFAULT;
            }
        }
        return ENOENT;
    }

    /* Invalid parameter */
    return EINVAL;
}
