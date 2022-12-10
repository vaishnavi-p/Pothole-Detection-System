import serial


ser = serial.Serial("COM9", 115200)

#ser.write("Hello world")
i = 0
output_string = ''
while(i<1000):
    x = ser.readline()
    output_string = output_string + str(x)
    print(x)
    i = i+1
text = output_string.split('b')
f = open("Pothole_data.log", "w")
y = ''
for i in text:
    if(len(i) > 6):
        y = y + i[3:-3] + '\n'
f.write("Pothole detection system log data \n" + y)
f.close()