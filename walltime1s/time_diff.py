#!/usr/bin/python
import sys

log=sys.stdin

def get_tusec(p_line):
    words=line.split(":")
    words2=words[1].split(",")
    sec=words2[0].strip()
    usec=words2[1].strip()
    tusec=int(sec)*1000000+int(usec)
    return tusec


line=log.readline()
t1=get_tusec(line)

while True:
    line=log.readline()
    if not line : break
    t2=get_tusec(line)
    #print str(t2)+","+str(t1)+","+str(t2-t1)
    print (t2-t1-1000000)/1000.0
    t1=t2
