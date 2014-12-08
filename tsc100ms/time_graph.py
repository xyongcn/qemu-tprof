#!/usr/bin/python
import sys

log=sys.stdin


while True:
    line=log.readline()
    if not line : break
    print line.strip()+",",
