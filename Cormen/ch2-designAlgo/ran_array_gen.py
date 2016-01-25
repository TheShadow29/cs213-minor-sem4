import random
f=open('rand-array.txt','w')

N=100;
f.write(str(int (N)) + ' ')
max_id=2000;

for i in xrange(N):
	K=random.random()*max_id;
	f.write(str(int (K)) + ' ')