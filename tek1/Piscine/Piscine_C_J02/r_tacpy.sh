#!/bin/sh

sed -n '2~2p' |cut -d: -f1 | rev | sort -rd | sed -n "${MY_LINE1},${MY_LINE2}p" | tr '\n' ',' | sed 's/,/,\ /g' | sed 's/, $/./'
