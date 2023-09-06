#!/usr/bin/env python3

import sys
import math

if len(sys.argv) < 4 :
    print("Usage : ./102cipher message key flag", file = sys.stderr)
    sys.exit(84)

msg = str(sys.argv[1])
key = str(sys.argv[2])
flag = int(sys.argv[3])
klen = len(key)
keymat = {}
msgmat = {}
j = int(0)
k = int(0)
l = int(1)
tmp = {}
det = float(0)

while klen > pow(l, 2) :
    l += 1

for i in range(0, klen) :
    keymat[i] = ord(key[i])
for i in range(klen, pow(l, 2)) :
    keymat[i] = flag
for i in range(0, len(msg)) :
    msgmat[i] = ord(msg[i])
for i in range(len(msg), len(msg) + (l - len(msg) % l)) :
    msgmat[i] = flag
klen = l

while j < int(len(msgmat)) :
    for k in range(0, klen) :
        tmp[k] = 0
        for l in range(0, klen) :
            tmp[k] += msgmat[j + l] * keymat[k + l * klen]
    for k in range(0, klen) :
        msgmat[j + k] = tmp[k]
    j += klen

print("Key matrix :", end = "")
for i in range(0, len(keymat)) :
    if i % klen == 0 : print()
    print("%i" %(keymat[i]), end = "\t")
print(end = "\n\n")

for m in range(0, klen) :
    tmp[m] = float(1)
    for i in range(0, klen) :
        tmp[m] *= keymat[i * klen + i]
tmp[0] = float(0)
for m in range(0, klen) :
    tmp[0] += tmp[m]
for m in range(1, klen + 1) :
    tmp[m] = float(1)
    for i in range(0, klen) :
        tmp[m] *= keymat[klen * i + (klen - i)]
tmp[1] = float(0)
for m in range(0, klen) :
    tmp[1] += tmp[m]
det = tmp[0] - tmp[1]

print("det = ", det)


print("Msg matrix :", end = "")
for i in range(0, len(msgmat)) :
    if i % klen == 0 : print()
    print("%i" %(msgmat[i]), end = "\t")
print(end = "\n\n")
