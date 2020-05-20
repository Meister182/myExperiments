#include "CorePartition.h"
#include <sys/types.h>

/* --------------- CorePartition methods --------------- */
void Delay (uint64_t nSleep)
{
    uint32_t nMomentum =  millis();
    
    do {
        CorePartition_Yield();
    } while ((millis() - nMomentum ) <  nSleep);    
}

static uint32_t getTimeTick()
{
   return (uint32_t)millis();
}

static void sleepTick(uint32_t nSleepTime)
{
    delayMicroseconds(nSleepTime * 1000);
}

void StackOverflowHandler()
{
    Serial.print("ERROR:: Stack Overflow detected!!!!");
}


/* --------------- Auxiliar setup method --------------- */

void myThreadsSetup(int nThreads)
{
    CorePartition_Start(nThreads);

    CorePartition_SetCurrentTimeInterface(getTimeTick);
    CorePartition_SetSleepTimeInterface (sleepTick);
    CorePartition_SetStackOverflowHandler (StackOverflowHandler);
}









/* ----------------------------------------------------- */
