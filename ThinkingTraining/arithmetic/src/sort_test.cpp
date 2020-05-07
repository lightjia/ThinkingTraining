#include "sort_test.h"
#include "RandTool.h"
#include "jl_array_help.h"
static void RandIntArray(int *pArray, int iArrayNum, int iRange)
{
    if (pArray && iArrayNum > 0)
    {
        for (int i = 0; i < iArrayNum; ++i)
            pArray[i] = sRandTool->RandInt(1, iRange);
    }
}

static JL_COMPARE_RESULT IntCmp(void *v1, void *v2)
{
    if (v1 && v2)
    {
        int *p1 = static_cast<int *>(v1);
        int *p2 = static_cast<int *>(v2);
        if (*p1 > *p2)
        {
            return JL_COMPARE_RESULT_LARGE;
        }
        else if (*p1 < *p2)
        {
            return JL_COMPARE_RESULT_LESS;
        }
    }

    return JL_COMPARE_RESULT_EQUAL;
}

static void IntSwap(void *v1, void *v2)
{
    if (v1 && v2)
    {
        int *p1 = static_cast<int *>(v1);
        int *p2 = static_cast<int *>(v2);
        int iTmp = *p1;
        *p1 = *p2;
        *p2 = iTmp;
    }
}

void TestQuickSort(int iArrayNum, int iRange)
{
    int *pIntArray = (int *)sMemMgr->MemMalloc(sizeof(int) * iArrayNum);
    RandIntArray(pIntArray, iArrayNum, iRange);
    LOG_INFO("Before Sort");
    PrintIntArray(pIntArray, iArrayNum);
    CJlSortBase stBase;
    stBase.pCmpHandler = IntCmp;
    stBase.pArray = pIntArray;
    stBase.pSwapHandle = IntSwap;
    stBase.iArrayLen = iArrayNum;
    stBase.iElemSize = sizeof(int);
    jl_quicksort(stBase);
    LOG_INFO("After Sort");
    PrintIntArray(pIntArray, iArrayNum);
    sMemMgr->MemFree(pIntArray);
}