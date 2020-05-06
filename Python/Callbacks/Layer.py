class Parent():
    def __init__(self):
        pass

    def register_callback(self, callback):
        self.callback = callback


class Layer(Parent):
    def __init__(self, name = "Layer"):
        self.name = name

    def write(self, msg):
        self.callback(msg)
