#!/usr/bin/python
import sys
import copy

log=sys.stdin


def get_tsc_tusec(p_line):
    words=line.split(":")
    words2=words[1].split(",")
    tsc=words2[0].strip()
    tsc=int(tsc)
    sec=words2[1].strip()
    usec=words2[2].strip()
    tusec=int(sec)*1000000+int(usec)
    r_list=[tsc,tusec]
    return  r_list


line=log.readline()
v_list1=get_tsc_tusec(line)

while True:
    line=log.readline()
    if not line : break
    v_list2=get_tsc_tusec(line)
    #print str(t2)+","+str(t1)+","+str(t2-t1)
    print (v_list2[0]-v_list1[0])/10000.0,
    print ",",
    print (v_list2[1]-v_list1[1]-10000)/1000.0
    v_list1=copy.deepcopy(v_list2)
