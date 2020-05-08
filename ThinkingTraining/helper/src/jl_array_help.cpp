#include "jl_array_help.h"
#include "RandTool.h"

void RandIntArray(int *pArray, int iArrayNum, int iRange)
{
    if (pArray && iArrayNum > 0)
    {
        for (int i = 0; i < iArrayNum; ++i)
            pArray[i] = sRandTool->RandInt(1, iRange);
    }
}

void PrintIntArray(int *pArray, int iArrayNum)
{
    if (pArray && iArrayNum > 0)
    {
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
