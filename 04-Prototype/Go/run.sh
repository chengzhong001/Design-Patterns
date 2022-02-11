#!/usr/bin/bash

cmd="go run "
for i in *.go
do
    cmd+=$i" "
done
echo "execute command: $cmd"
$cmd

