import random

ran_N=int(random.random()*65536)
#ran_N=100
a = random.sample(xrange(1,ran_N+1),ran_N-1)

f = open('finp.txt','w')

for item in a:
  f.write("%s\n" % item)




