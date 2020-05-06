import can

class RpiCan:
    def __init__(self):
        self.bus = None

    def connect(self, interface='socketcan', channel='vcan0', rcv_own=False):
        """
        Connect to a virtual CAN channel
        :param interface: type of interface, default is 'socketcan'
        :param channel: can channel, default is 'vcan0'
        """
        self.bus = can.Bus(interface=interface, channel=channel, receive_own_messages=rcv_own)

    def send_message(self, message):
        """
        Send a message to the connected CAN channel
        :param message: can.Message object
        """
        self.bus.send(message, timeout=0.2)

    def send_msgs_list(self, msgs_list):
        """
        Sends a list of messages to the connected CAN channel
        :param msgs_list: list of can.Message objects
        """
        for msg in msgs_list:
            self.send_message(msg)

    def get_can_frames(self, timeout=1):
        """
        Get all can frames in the buffer as a list
        :return: list of can.Message objects
        """
        msg_list = []
        msg = self.bus.recv(timeout=timeout)
        msg_list.append(msg)
        while msg is not None and timeout is not None:
            msg_list.append(msg)
            msg = self.bus.recv(timeout=timeout)
        return msg_list
        
   

