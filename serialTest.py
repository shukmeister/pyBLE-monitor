#comm test with micro

import time
import serial

serial_speed = 9600
serial_port = '/dev/cu.HC-05-DevB' #address: 98-D3-31-40-3E-94

s = serial.Serial(serial_port, serial_speed, timeout = 1)

# s.write('i want cereal')
# s.read()

while True:
	s.write('i want cereal')
	# time.sleep(0.5)
	print('waiting..')
	if s.inWaiting():
		message = s.read(s.inWaiting())
		print(message)
	# s.readline()
	time.sleep(0.5)