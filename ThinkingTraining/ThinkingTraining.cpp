#include "CPuls11Test.h"
#include "sort_test.h"
int main(int argc, char const *argv[])
{
    /* code */
    struct tagLogInitParam stLog;
    sLog->Init(stLog);
    TestQuickSort(10, 10000);
    for (;;)
    {
        sleep_ms(1000);
    }
    return 0;
}
