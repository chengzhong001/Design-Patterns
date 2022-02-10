#!/usr/bin/bash

cmd="go run "
for i in *.go
do
    cmd+=$i" "
done

echo "command: $cmd: "

$cmd

