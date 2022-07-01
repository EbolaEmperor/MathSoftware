#!/bin/bash

cd source
mkdir img
make
cd ..
mv source/img/ img/
make