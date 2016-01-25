f=open("out.txt",'r')
l1=[0]
for word in f.read().split():
	w1=int(word)
	l1.append(w1)
	#print word
	if l1[-2]>l1[-1]:
		print "error"
		break
print "yes"