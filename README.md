# Verilog-A Models for Circuit Simulation

<br>

This repository is a collection of compact models written in Verilog-A with the purpose of simulation of state-of-the-art electronic circuits.

The models covering a wide range of devices :

* **MOS** with different flavours like SOI, FinFET and bulk processes
* **HV-MOS** like hisim_hv
* **BJT** like HICUM, MEXTRAM and VBIC
* **Passive devices** like diodes, varactors and non-linear resistors
* **HEMT** like ASMHEMT, mvsg_cmc
* **Sensors**

All models are checked for syntax belong Verilog-AMS Language Reference Manual Version 2.4.0. https://accellera.org/downloads/standards/v-ams 
The models are modified mostly for convergence improvements. Equations are untouched.
So few parameter limits are changed to prevent division by zero and especially bipolar models lacks suitable limit function to prevent divergence in Newton-Raphson iteration process. Changes are noticed in Changelog.

At the moment this code modifications are adapted to NGSPICE simulator. But in future the code can adapted to the requirements and restrictions of ADMS like compilers e.g. for XYCE or QUCS.

Any code directory has a set of test cases for NGSPICE to show main functionality and performance of the models. Contributions for more practical use cases are welcome.

## Related Projects

The usage of the model code is mainly dependent from two projects: OpenVAF and NGSPICE.

### OpenVAF

OpenVAF can be build as a standalone CLI program that can compile Verilog-A files to shared objects that comply with the simulator independent OSDI interface.

Detailed documentation, examples and precompiled binaries of all release are **available on the [website](https://openvaf.semimod.de)**. To test the latest development version you can download nightly version of OpenVAF for linux [here](https://openva.fra1.cdn.digitaloceanspaces.com/openvaf_devel_linux_amd64.tar.gz).

OpenVAF has been tested with NGSPICE version 39. It can already support a large array of compact models.

Furthermore, some Verilog-A language features are currently not supported by openVAF:

* Noise analysis (white_noise(), flicker_noise())
* Laplace transform filters
* Language constructs: $abstime(), @cross()

### NGSPICE

**NGSPICE [website](https://ngspice.sourceforge.io/)** is the open source simulator for electronic circuit simulation. Source code, examples and precompiled binaries of all release are **available on the [website](https://sourceforge.net/projects/ngspice/)**.

NGSPICE is stable and in an regulary update process. 

## How to build the models

Download OpenVAF (Linux or Windows) from https://openvaf.semimod.de/download/ and place the executable here in the PATH.

Linux:
``` shell
cd code
openvaf-compile-va.sh for Linux
```
Windows:
``` shell
cd code
openvaf-compile-va.bat for MS Windows
```

## General Usage Instructions 

Copy the *.osdi files from directory osdilibs to the place where then code models (*.cm) are located, typically in lib/ngspice or similar.

Edit file 'spinit', typically found in share/ngspice/scripts: Comment out the line

'unset osdi_enabled'


## Acknowledgement

The team of openVAF developer from Semimod GmbH https://semimod.de/.

The NGSPICE development team https://ngspice.sourceforge.io/ .

Geoffrey Coram for his excellent tool VAMPyRe https://si2.org/download-links/ .

And last but not least: All the model authors for their elaborate and complex work.

## Copyright

Copyright of various owners, see individual code directories.

Most model codes are licensed under the
Educational Community License, Version 2.0 (the "License"); you may
not use this file except in compliance with the License. You may
obtain a copy of the License at

    http://www.osedu.org/licenses/ECL-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an "AS IS"
BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
or implied. See the License for the specific language governing
permissions and limitations under the License.