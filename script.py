import sys

def freq():
	d = {};
	f = open('C:\Drive D\MS UF\Sem 2\Embedded Systems\Project2\original.txt','r')
	for line in f:
		if line not in d:
			d[line] = 1
		else:
			d[line] = d[line] + 1
	
	return d
	
if __name__=='__main__':
	dict = freq()
	print dict
	print len(dict)
	exit(0)
