#!/usr/bin/bash
# go run adidas.go adidasShoe.go iShoe.go main.go nikeShirt.go adidasShirt.go iShirt.go iSportsFactory.go nike.go nikeShoe.go

cmd="go run "
for i in *.go
do
    cmd+=$i" "
done
$cmd


