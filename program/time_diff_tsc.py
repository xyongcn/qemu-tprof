#!/usr/bin/python
import sys

log=sys.stdin

def get_tsc(p_line):
    words=line.split(":")
    tsc=words[1].strip()
    v_tsc=int(tsc)
    return v_tsc 


line=log.readline()
t1=get_tsc(line)

while True:
    line=log.readline()
    if not line : break
    t2=get_tsc(line)
    #print str(t2)+","+str(t1)+","+str(t2-t1)
    print (t2-t1)/10000.0
    t1=t2
