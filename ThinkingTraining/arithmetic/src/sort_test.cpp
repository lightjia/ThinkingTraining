#include "sort_test.h"
#include "jl_array_help.h"
#include <algorithm>

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

void TestQuickSort(int iArrayNum, int iRange)
{
    int *pIntArray = (int *)sMemMgr->MemMalloc(sizeof(int) * iArrayNum);
    RandIntArray(pIntArray, iArrayNum, iRange);
    LOG_INFO("Before Sort");
    PrintIntArray(pIntArray, iArrayNum);
    CJlSortBase stBase;
    stBase.pCmpHandler = IntCmp;
    stBase.pArray = pIntArray;
    stBase.pSwapHandle = [](void *v1, void *v2){if(v1 && v2) std::swap(*(int*)v1, *(int*)v2);};
    stBase.iArrayLen = iArrayNum;
    stBase.iElemSize = sizeof(int);
    jl_quicksort(stBase);
    LOG_INFO("After Sort");
    PrintIntArray(pIntArray, iArrayNum);
    sMemMgr->MemFree(pIntArray);
}