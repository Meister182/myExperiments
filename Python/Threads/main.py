#!/usr/bin/env python3

import myThreads as mTh
import time

if __name__ == "__main__":
    print("Python threads: main.py running..")

    mT1 = mTh.myThread("Bob", 5)
    mT2 = mTh.myThread("Fred", 5)

    mT1.launch()
    mT2.launch()

    time.sleep(3)
    mT1.stop()

    print("Python threads: main.py is done")
