#!/usr/bin/env python3

from sys import argv
import configparser
from Constants import *
import Rpican
import can

if __name__ == "__main__":
    print("in main..\n Running Rpican test..w")

    if len(argv) < 2:
        #send radom message
        pass
    else:
        #send radom message
        msg = argv[1]
        pass



    # CAN parameters
    config = configparser.ConfigParser()
    config.read(CONFIG_FILE)

    interface = config[PROTOCOL][INTERFACE]
    channel = config[PROTOCOL][CHANNEL]
    can_id = 101

    pycan = Rpican.RpiCan()
    pycan.connect(interface=interface, channel=channel)

    msg = can.Message(arbitration_id=can_id, data=[0x01, 0x02, 0x03, 0x04])
    pycan.send_message(msg)

    while True:
        can_frame = pycan.get_can_frames(timeout=None)
        for frame in can_frame:
            print("ID: {} | {}".format(hex(frame.arbitration_id),frame.data))