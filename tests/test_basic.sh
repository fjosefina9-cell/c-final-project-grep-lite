#!/bin/bash

echo "===== Building Project ====="
make clean
make

echo
echo "===== Basic Search ====="
./grep-lite hello data/test.txt

echo
echo "===== Case Insensitive (-i) ====="
./grep-lite -i HELLO data/test.txt

echo
echo "===== Whole Word (-w) ====="
./grep-lite -w hello data/test.txt

echo
echo "===== Line Numbers (-n) ====="
./grep-lite -n hello data/test.txt

echo
echo "===== Count Only (-c) ====="
./grep-lite -c hello data/test.txt

echo
echo "===== Standard Input Test ====="
cat data/test.txt | ./grep-lite hello

echo
echo "===== Combined Flags ====="
./grep-lite -i -n hello data/test.txt
