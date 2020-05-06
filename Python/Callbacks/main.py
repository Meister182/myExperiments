#!/usr/bin/env python3
from Layer import *

def callback_1(msg):
    print("callback 1")
    print(msg)

def callback_2(msg):
    print("callback 2")
    print(msg)

if __name__ == "__main__":
    print("Running main.py")

    myLayer = Layer()
    msg = "  Simple Test message."

    myLayer.register_callback(callback_1)
    myLayer.write(msg)

    myLayer.register_callback(callback_2)
    myLayer.write(msg)

    