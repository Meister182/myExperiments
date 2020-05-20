#include "myThreadsConfigurator.h"

/* --------------- my Threads variables --------------- */
int number_of_threads = 2;
// counters
int T1_COUNTER = 0;  
int T2_COUNTER = 0;

// Delays
int T1_DELAY = 1000;    
int T2_DELAY = 2000;

// Thread loops
void thread1_loop(void* pValue);
void thread2_loop(void* pValue);
// Job example
void job(int& counter, int increment);


/* ---------------   Arduino methods    --------------- */
void setup()
{
    Serial.begin(9600);
    myThreadsSetup(number_of_threads);
    CorePartition_CreateSecureThread (thread1_loop, NULL, 150, 0);
    CorePartition_CreateSecureThread (thread2_loop, NULL, 150, 0);
}

void loop()
{
    CorePartition_Join();
}


/* ---------------------------------------------------- */
void thread1_loop(void* pValue)
{
    while(1)
    {
        Serial.print("T1: ");
        job(T1_COUNTER, 1);
        //CorePartition_Yield();
        Delay(T1_DELAY);
    }
}

void thread2_loop(void* pValue)
{
    while(1)
    {
        Serial.print("T2: ");
        job(T2_COUNTER, 5);
        //CorePartition_Yield();
        Delay(T2_DELAY);
    }
}

void job(int& counter, int increment)
{
    counter+=increment;
    Serial.println(counter);
}

/* ---------------------------------------------------- */
