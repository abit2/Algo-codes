import pickle
import csv

kaam = []
with open('train.csv', 'w') as cr:
	writer = csv.writer(cr, lineterminator='\n')
	with open('in.txt', 'r') as fi:
		with open('words.pkl', 'rb') as fp:
			d = pickle.load(fp)
			c=0
			t=0
			for line in fi:
				x = line.split()
				# words.extend(x)
			# print(len(words))
				f = 0
				for w in x:
					if w not in d:
						f = 1

				if f == 0:
					if len(x)>0:
						writer.writerow(x)
						kaam.append(x[0])
					c+=1
				t+=1
			print(c,t)
			mila = (1.0*c)/t
			print(mila)
print(len(kaam))
with open('mila.pkl', 'wb') as fo:
	pickle.dump(kaam, fo)