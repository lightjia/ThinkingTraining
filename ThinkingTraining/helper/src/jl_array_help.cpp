#include "jl_array_help.h"

void PrintIntArray(int *pArray, int iArrayNum)
{
    if (pArray && iArrayNum > 0)
    {
        LOG_INFO("Print Array");
        char szData[500];
        memset(szData, '\0', 500);
        int iPos = 0;
        CMemBuffer cMem;
        for (int i = 0; i < iArrayNum; ++i)
        {
            if (iPos > 450)
            {
                cMem.Append(szData, iPos);
                memset(szData, '\0', 500);
                iPos = 0;
            }

            iPos += sprintf(szData + iPos, "%d ", pArray[i]);
        }

        if (iPos > 0)
        {
            cMem.Append(szData, iPos);
            cMem.AppendNul();
        }

        LOG_INFO("%s", (char *)cMem.GetBuffer());
    }
}
