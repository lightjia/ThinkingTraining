#ifndef __JL_SORT__H_
#define __JL_SORT__H_

#include "Log.h"

enum JL_COMPARE_RESULT
{
    JL_COMPARE_RESULT_LESS = -1,
    JL_COMPARE_RESULT_EQUAL,
    JL_COMPARE_RESULT_LARGE,
};

enum JL_COMPARE_RET
{
    JL_COMPARE_RET_OK = 0,
    JL_COMPARE_RET_FAIL,
};

typedef struct tagJlSortParam
{
    tagJlSortParam()
    {
        pArray = nullptr;
        iArrayLen = 0;
        iElemSize = 0;
        pMemOperFunc = DEFAULT_MEM_FUNC;
        pCmpHandler = nullptr;
        pElem = pMemOperFunc.pMallocFunc(iElemSize);
    }

    ~tagJlSortParam()
    {
        if (pElem)
        {
            pMemOperFunc.pFreeFunc(pElem);
            pElem = nullptr;
        }
    }

    void Swap(unsigned iIndex1, unsigned iIndex2)
    {
        ASSERT_RET(iIndex1 >= 0 && iIndex1 < iArrayLen && iIndex2 >= 0 && iIndex2 < iArrayLen);
        if (pElem)
        {
            memcpy(pElem, GetElem(iIndex1), iElemSize);
            memcpy(GetElem(iIndex1), GetElem(iIndex2), iElemSize);
            memcpy(GetElem(iIndex2), pElem, iElemSize);
        }
    }

    void *GetElem(unsigned iIndex)
    {
        ASSERT_RET_VALUE(iIndex >= 0 && iIndex < iArrayLen, nullptr);
        return pArray + iElemSize * iIndex;
    }

    void *pArray;
    unsigned iArrayLen;
    size_t iElemSize;
    jl_compare_handler pCmpHandler;
    mem_oper_func pMemOperFunc;

private:
    void *pElem;
} tagJlSortParam;

#define CHECK_JLSORTPARAM(stSort) ASSERT_RET_VALUE(stSort.pArray &&stSort.pCmpHandler &&stSort.iArrayLen > 0 && stSort.iElemSize > 0, JL_COMPARE_RET_FAIL)
typedef JL_COMPARE_RESULT (*jl_compare_handler)(const void *v1, const void *v2);
JL_COMPARE_RET jl_quicksort(tagJlSortParam &stSort);
#endif