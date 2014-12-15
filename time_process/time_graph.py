#!/usr/bin/python
import sys

log=sys.stdin

log.readline()

while True:
    line=log.readline()
    if not line : break
    print line.strip()+",",
