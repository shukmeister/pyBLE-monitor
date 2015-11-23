#python bluetooth monitor console for debugging arduino code

#ben code:

import serial

serial_speed = 9600
serial_port = '/dev/'

s = serial.Serial(serial_port, serial_speed, timeout = 1)

	# Measure data from the sensor
	def measure(self):

		# Request data and read the answer
		ser.write("m")
		data = ser.readline()

		# If the answer is not empty, process & display data
		if (data != ""):
			processed_data = data.split(",")

			self.temp_data.set("Temperature: " + str(processed_data[0]))
			self.temperature.pack()

			self.hum_data.set("Humidity: " + str(processed_data[1]))
			self.humidity.pack()

		# Wait 1 second between each measurement
		self.after(1000,self.measure)

def readData(self):
	#request data and read answer
	s.write("m")
	data = s.readline()

	#if the answer is not empty, process & display data
	if (data != ""):
		processed_data = data.split(",")
		



#simple inquiry example -- from pybluez
import bluetooth

nearby_devices = bluetooth.discover_devices(lookup_names=True)
print("found %d devices" % len(nearby_devices))

for addr, name in nearby_devices:
    print("  %s - %s" % (addr, name))



#from arduino-bluetooth-temperature: https://github.com/openhomeautomation/arduino-bluetooth-temperature/blob/master/sensor_gui.py

# Graphical User Interface for the Bluetooth sensor

# Imports
import time
import serial
from Tkinter import *

# Serial port parameters
serial_speed = 115200
serial_port = '/dev/cu.AdafruitEZ-Link06d5-SPP'

# Test with USB-Serial connection
# serial_port = '/dev/tty.usbmodem1421'

ser = serial.Serial(serial_port, serial_speed, timeout=1)

# Main Tkinter application
class Application(Frame):

	# Measure data from the sensor
	def measure(self):

		# Request data and read the answer
		ser.write("m")
		data = ser.readline()

		# If the answer is not empty, process & display data
		if (data != ""):
			processed_data = data.split(",")

			self.temp_data.set("Temperature: " + str(processed_data[0]))
			self.temperature.pack()

			self.hum_data.set("Humidity: " + str(processed_data[1]))
			self.humidity.pack()

		# Wait 1 second between each measurement
		self.after(1000,self.measure)

	# Create display elements
	def createWidgets(self):

		self.temperature = Label(self, textvariable=self.temp_data, font=('Verdana', 40, 'bold'))
		self.temp_data.set("Temperature")
		self.temperature.pack()

		
		self.humidity = Label(self, textvariable=self.hum_data, font=('Verdana', 40, 'bold'))
		self.hum_data.set("Humidity")
		self.humidity.pack()

	# Init the variables & start measurements
	def __init__(self, master=None):
		Frame.__init__(self, master)
		self.temp_data = StringVar()
		self.hum_data = StringVar()
		self.createWidgets()
		self.pack()
		self.measure()

# Create and run the GUI
root = Tk()
app = Application(master=root)
app.mainloop()