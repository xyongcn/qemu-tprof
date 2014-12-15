#!/usr/bin/python
from __future__ import division
import sys

#log=open(sys.argv[1],"r")

log=sys.stdin


def get_tsc(p_line):
    words=line.split(":")
    tsc=words[1].strip()
    v_tsc=int(tsc)
    return v_tsc 




total=0
mean=0
t_list=[]

    

line=log.readline()
t1=get_tsc(line)


while True:
    line=log.readline()
    if not line : break
    t2=get_tsc(line)
    #print str(t2)+","+str(t1)+","+str(t2-t1)
    #print (t2-t1)/10000.0
    t_list.append(t2-t1)
    total=total+(t2-t1)
    t1=t2



mean=total/len(t_list)

print "mean value: %f" % (mean)


for elem in t_list:
    print "%f"  % (  ( elem -mean )/mean *100 )
