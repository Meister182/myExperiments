import threading
import time


class myThread():
    def __init__(self, name = "Nameless", time_to_live = 1):
        self.name = name
        self.ttl = time_to_live
        self._stop = False
        self.tprint("was born!!")
        self.purpose = threading.Thread(target=self.job)

    def tprint(self, msg):
        print("{} : {}".format(self.name, msg))

    def launch(self):
        self.purpose.start()

    def stop(self):
        self._stop = True

    def job(self):
        self.tprint("Starting my job..")
        counter = 0

        while (counter < self.ttl) and (not self._stop):
            counter+=1
            time.sleep(1)

        if self._stop:
            self.tprint("Thanks for stoping me!")
        else:
            self.tprint("Oh boy..my time to live has ended..")
            time.sleep(.4)
            self.tprint("x_X")
