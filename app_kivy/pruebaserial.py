import serial
import keyboard as k

try:
    seriall = serial.Serial("com6",9600)
        
    while True:
        if k.is_pressed("y"):
            seriall.write(b'y')
        elif k.is_pressed("n"):
            seriall.write(b'n')
        if k.is_pressed("ENTER"):
            ser.close()
            break
        
except TimeoutError:
    print("error")
finally:
    print("done")