#!/usr/bin/env bash

for file in $(ls "assets/maps/invalid");
# do echo "$file";
do ./test "assets/maps/invalid/$file";
done