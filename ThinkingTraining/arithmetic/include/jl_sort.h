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

typedef JL_COMPARE_RESULT (*jl_compare_handler)(void *v1, void *v2);
typedef void (*jl_swap_handler)(void *v1, void *v2);

class CJlSortBase : public CMemOper
{
public:
    CJlSortBase()
    {
        pArray = nullptr;
        iArrayLen = 0;
        iElemSize = 0;
        pCmpHandler = nullptr;
        pSwapHandle = nullptr;
        SetMemOperFunc(MEMMGR_MEM_FUNC);
    }

    ~CJlSortBase()
    {
    }

    void Swap(unsigned iIndex1, unsigned iIndex2)
    {
        if (iIndex1 != iIndex2)
        {
            ASSERT_RET(iIndex1 >= 0 && iIndex1 < iArrayLen && iIndex2 >= 0 && iIndex2 < iArrayLen);
            pSwapHandle(GetElem(iIndex2), GetElem(iIndex1));
        }
    }

    JL_COMPARE_RESULT Cmp(unsigned iIndex1, unsigned iIndex2)
    {
        ASSERT_RET_VALUE(iIndex1 >= 0 && iIndex1 < iArrayLen && iIndex2 >= 0 && iIndex2 < iArrayLen, JL_COMPARE_RESULT_EQUAL);
        return pCmpHandler(GetElem(iIndex1), GetElem(iIndex2));
    }

    virtual void *GetElem(unsigned iIndex)
    {
        ASSERT_RET_VALUE(iIndex >= 0 && iIndex < iArrayLen && pArray, nullptr);
        return (void *)((char *)pArray + iElemSize * iIndex);
    }

    virtual void *AllocExtraSpace(unsigned iNumElem)
    {
        ASSERT_RET_VALUE(iNumElem > 0 && iElemSize > 0, nullptr);
        return MemMalloc(iNumElem * iElemSize);
    }

    virtual void FreeExtraSpace(void *pSpace)
    {
        ASSERT_RET(pSpace);
        MemFree(pSpace);
    }

    void *pArray;
    unsigned iArrayLen;
    size_t iElemSize;
    jl_compare_handler pCmpHandler;
    jl_swap_handler pSwapHandle;
};

#define CHECK_JLSORTPARAM(stSort) ASSERT_RET_VALUE(stSort.pArray &&stSort.pCmpHandler &&stSort.pSwapHandle &&stSort.iArrayLen > 0 && stSort.iElemSize > 0, JL_COMPARE_RET_FAIL)

JL_COMPARE_RET jl_quicksort(CJlSortBase &stSort);
#endif