import random

f=open('q2-input.txt','w')

#N=random.random()*100000
N=100000
f.write(str(int(N))+'\n')
#P=random.random()*100000
P=10
f.write(str(int(P))+'\n')
#M=random.random()*100000
M=50
f.write(str(int(M))+'\n')

for i in xrange(int(M)):
	K=random.random()*N
	f.write(str(int(K))+'\n')
