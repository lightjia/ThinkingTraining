#include "jl_sort.h"

static void _quicksort(tagJlSortParam &stSort, unsigned iStart, unsigned iEnd)
{
    if (iStart < iEnd)
    {
        unsigned iFlag = iStart;
        unsigned iStartPos = iStart;
        unsigned iEndPos = iEnd;

        while (iEndPos > iStartPos)
        {
            if (stSort.pCmpHandler(stSort.GetElem(iEndPos), stSort.GetElem(iFlag)) != JL_COMPARE_RESULT_LESS)
            {
                --iEndPos;
                continue;
            }

            while (iEndPos > iStartPos && stSort.pCmpHandler(stSort.GetElem(iStartPos), stSort.GetElem(iFlag)) != JL_COMPARE_RESULT_LARGE)
            {
                ++iStartPos;
            }

            if (iEndPos > iStartPos)
            {
                stSort.Swap(iStartPos, iEndPos);
            }
        }
        
    }
}

JL_COMPARE_RET jl_quicksort(tagJlSortParam &stSort)
{
    CHECK_JLSORTPARAM(stSort);
    _quicksort(stSort, 0, stSort.iArrayLen - 1);

    return JL_COMPARE_RET_OK;
}