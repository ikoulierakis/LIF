import sys

fname=str(sys.argv[1])
fout = open("freq.out","w") 
freq = [0]*1000
i=0
threshold=0
duration_time = 0
with open(fname) as f:
	l = f.readlines()
	for line in l:
		w = line.split()
		if(float(w[2]) >= 1000):
			i = i + 1
			freq[i%1000] = freq[i%1000] + float(w[3])
			if (i%1000 == 0):
				duration_time = duration_time + 1
for i in range(1000):
	fout.write(str(i))
	fout.write("	")
	fout.write(str(2*3.14159265*freq[i] / duration_time))
	fout.write('\n')	
