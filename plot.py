import matplotlib.pyplot as plt
import numpy as np

fr = open('range.txt')
r = (fr.read())

#print(r)
arrx = np.loadtxt('maxdistance.txt')
arrn = np.loadtxt('mindistance.txt')

l = arrx.max()
m = arrn.min()
if l > m:
	mvalue = l
else: 
	mvalue = m
#print(mvalue)
bins = []
for x in range(0,int(mvalue+100),int(r)):
	bins.append(x)

plt.figure(1)

plt.subplot(211)
plt.hist(arrx,bins,histtype='bar',color='g')
plt.title('Histogram Of Maxima');
plt.xlabel('Distance Value')
plt.ylabel('Frequency');

plt.subplot(212)
plt.hist(arrn,bins,histtype='bar',color='b')
plt.title('Histogram Of Minima');
plt.xlabel('Distance Value')
plt.ylabel('Frequency');

plt.show()

