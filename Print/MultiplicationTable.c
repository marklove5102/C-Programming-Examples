#include "pch.h"

_Function_class_(FN_EXAMPLE_PROC)
bool
Print_MultiplicationTable(void)
{
    for (unsigned int nRow = 1; nRow <= 9; nRow++)
    {
        for (unsigned int nCol = 1; nCol <= nRow; nCol++)
        {
            printf("%lu * %lu = %-2lu  ", nCol, nRow, nCol * nRow);
        }
        puts("");
    }

    return true;
}
