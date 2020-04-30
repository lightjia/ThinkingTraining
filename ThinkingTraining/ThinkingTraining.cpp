#include"CPuls11Test.h"
int main(int argc, char const *argv[])
{
    /* code */
    struct tagLogInitParam stLog;
    sLog->Init(stLog);
    LOG_DBG("Hello Jia");
    test_cpuls();
    for(;;){
        sleep_ms(1000);
    }
    return 0;
}
