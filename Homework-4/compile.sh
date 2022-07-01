#!/bin/bash

cd source
mkdir img
make
./paperpicgen
cd ..
mv source/img/ .
make