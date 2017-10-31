import csv
import re

with open('new dataset/portmanteau.csv','r') as r:
	with open('in2.txt','w') as w:
		for line in r:
			m = []
			x = line.split(',')
			for u in x:
				s = re.sub('[^0-9a-zA-Z ]+', '', u)
				s = s.lower()
				#z = re.sub(r'\W+', '', u)
				m.append(s)
			y = (" ").join(m)

			print y
			y = (" ").join(y.split())

			w.write(y+"\n")
