#!/bin/bash

if [ ! -e img/ ];then mkdir img; fi

cd bin
bash paperpicgen1.sh
cd ..
mv bin/img img/fig1

cd bin
bash paperpicgen2.sh
cd ..
mv bin/img img/fig2

cd bin
mkdir img
./paperpicgen3 0.2542099079452338 -0.0004374588482306643
cd ..
mv bin/img img/fig3

cd bin
mkdir img
./paperpicgen4 0.2542099079452338 -0.0004374588482306643
cd ..
mv bin/img/ img/fig4