#!/usr/bin/python
from __future__ import division
import sys

log=sys.stdin

def get_tusec(p_line):
    words=line.split(":")
    words2=words[1].split(",")
    sec=words2[0].strip()
    usec=words2[1].strip()
    tusec=int(sec)*1000000+int(usec)
    return tusec

total=0
mean=0
t_list=[]

line=log.readline()
t1=get_tusec(line)

while True:
    line=log.readline()
    if not line : break
    t2=get_tusec(line)
    #print str(t2)+","+str(t1)+","+str(t2-t1)
    t_list.append(t2-t1)
    total=total+(t2-t1)
    t1=t2


mean=total/len(t_list)

print "mean value: %f" % (mean)


for elem in t_list:
    print "%f"  % (  ( elem -mean )/mean *100 )
