#!/bin/bash

cd bsim4/nmos
./run ngspice
cd ../../
cd bsim4/pmos
./run ngspice
cd ../../

cd bsimbulk/nmos
./run ngspice
cd ../../
cd bsimbulk/pmos
./run ngspice
cd ../../

echo done

