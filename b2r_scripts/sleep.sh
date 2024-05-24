#!/bin/bash

m=$(uptime --since | awk '{printf "%s", $2}' | cut -d':' -f2 | awk '{printf "%d", $1 % 10}')
s=$(uptime --since | awk '{printf "%s", $2}' | cut -d':' -f3)

total_s=$((m * 60 + s))

sleep $total_s
