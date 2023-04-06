#coding: utf-8

from tkinter import *
from tkinter.messagebox import *
# simple inquiry example
import bluetooth

fenetre = Tk()
fenetre['bg'] = 'brown'


def BluetoothScan():
    nearby_devices = bluetooth.discover_devices(lookup_names=True)
    if(len(nearby_devices) == 0):
        showinfo("","No device found")
    print("Found {} devices.".format(len(nearby_devices)))

    for addr, name in nearby_devices:
        print("  {} - {}".format(addr, name))
def BltSend():
    print("envoiedu message ...")
    

#frame 1
Frame1 = Frame(fenetre,borderwidth=2,relief=GROOVE)
Frame1.pack(side=LEFT, padx=30,pady=30)

#frame2
Frame2 = Frame(fenetre,borderwidth=2,relief=GROOVE)
Frame2.pack(side=LEFT,padx=10,pady=10)
btscan = Button(fenetre,text="Bluetooth scan", borderwidth=2,command=BluetoothScan).pack(padx=5,pady=5)
btsend = Button(fenetre,text="Send message", borderwidth=2,command=BltSend).pack(padx=5,pady=10)
Label(Frame1,text="test",bg='black').pack(padx=10,pady=10)
label = Label(fenetre, text="Hello World")
label.pack()


fenetre.mainloop()

