import serial

serialPortName="COM4"
list = []
ser = serial.Serial(serialPortName, 9600)
while True:
    fromArduino = ser.readline()
    fromArduino = fromArduino.replace("\n","")
    fromArduino = fromArduino.replace("\r","")
    temp=float(fromArduino)
    list.append(temp)
    print "Naa verdi:", temp
    print "Min verdi:", min(list)
    print "Max verdi:",max(list)
    print "Antall verdier i listen er", len(list)

