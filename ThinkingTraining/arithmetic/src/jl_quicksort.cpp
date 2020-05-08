#include "jl_sort.h"

static void _quicksort(CJlSortBase &stSort, int iStart, int iEnd)
{
    if (iStart < iEnd)
    {
        int iFlag = iEnd;   //以最后一位作为参照进行二分
        int iStartPos = iStart;
        int iOffPos = iStart - 1;
        while (iEnd > iStartPos)
        {
            if(stSort.Cmp(iFlag, iStartPos) == JL_COMPARE_RESULT_LARGE)
            {
                 ++iOffPos;
                stSort.Swap(iOffPos, iStartPos);
            }

            ++iStartPos;
        }

        ++iOffPos;
        stSort.Swap(iOffPos, iFlag);
        _quicksort(stSort, iStart, iOffPos - 1);
        _quicksort(stSort, iOffPos + 1, iEnd);
    }
}

JL_COMPARE_RET jl_quicksort(CJlSortBase &stSort)
{
    CHECK_JLSORTPARAM(stSort);
    _quicksort(stSort, 0, static_cast<int>(stSort.iArrayLen - 1));

    return JL_COMPARE_RET_OK;
}