#!/usr/bin/python
import sys

log=sys.stdin
v=0

while True:
    line=log.readline()
    if not line : break
    line=int(line.strip())
    v=v+line

print v/199
