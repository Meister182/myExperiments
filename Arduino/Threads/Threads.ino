

/* --------------- my Threads variables --------------- */
// counters
int T1_COUNTER = 0;  
int T2_COUNTER = 0;

// Delays
int T1_DELAY = 1000;    
int T2_DELAY = 2000;

// Thread loops
void thread1_loop(); 
void thread2_loop();
// Job example
void job(int& counter, int incrment,  int sleep);


/* ---------------   Arduino methods    --------------- */
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    thread1_loop();
    thread2_loop();
}


/* ---------------------------------------------------- */
void thread1_loop()
{
    Serial.print("T1: ");
    job(T1_COUNTER, 1, T1_DELAY);
}

void thread2_loop()
{
    Serial.print("T2: ");
    job(T2_COUNTER, 5, T2_DELAY);
}

void job(int& counter, int incrment,  int sleep)
{
    counter+=incrment;
    Serial.println(counter);
    delay(sleep);
}

/* ---------------------------------------------------- */
