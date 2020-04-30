#include "CPuls11Test.h"
void test_cpuls()
{
    int array[] = {1, 2, 3, 4, 5};
    for (int &x : array)
    {
        x *= 2;
    }

    for(int i : array)
    {
        LOG_DBG("i=%d", i);
    }
}