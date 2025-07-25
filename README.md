# Verilog-A Models for Circuit Simulation

<br>

This repository is a collection of compact models written in Verilog-A with the purpose of simulation of state-of-the-art electronic circuits.

The models covering a wide range of devices :

* **MOS** with different flavours like SOI, FinFET and bulk processes
* **HV-MOS** like hisim_hv
* **BJT** like HICUM, MEXTRAM and VBIC
* **HEMT** like ASMHEMT, mvsg_cmc
* **IGBT** the well known Hefner model in Verilog-A
* **Passive devices** like diodes, varactors and non-linear resistors
* **Sensors**

Actual version status:

| Model         | Version      |ngspice| Xyce   | Model         | Version       |ngspice| Xyce  |
| ------------- | -------------|-------|------- | ------------- | ------------- |-------|-------|
| **Resistor**  |              |       |        | **MG MOSFET** |               |       |       |
| r2_cmc        | 1.0.1        |  [x]  |        | bsim-img      | 102.9.6       |  [x]  |       |
| r3_cmc        | 1.1.2        |  [x]  |  [x]   | bsim-cmg      | 111.2.1       |  [x]  |  [x]  |
| **Diode**     |              |       |        | **HV-MOS**    |               |       |       |
| diode_cmc     | 2.0.0        |  [x]  |  [x]   | hisim_hv      | 2.5.1         |  [x]  |       |
| juncap        | 200.6.1      |  [x]  |  [x]   | psphv         | 1.0.6         |  [x]  |       |
| **Varactor**  |              |       |        | **BJT**       |               |       |       |
| mosvar        | 1.3.0        |  [x]  |  [x]   | hicum0        | 2.1.0         |  [x]  |  [x]  |
| **MOSFET**    |              |       |        | hicum2        | 3.1.0         |  [x]  |  [x]  |
| bsim4         | 4.8.0        |  [x]  |  [x]   | mextram       | 505.5.0       |  [x]  |  [x]  |
| bsim6         | 6.1.1        |  [x]  |  [x]   | vbic          | 1.3           |  [x]  |  [x]  |
| bsimbulk      | 107.2.1      |  [x]  |  [x]   | fbh_hbt       | 2.3           |  [x]  |       |
| ekv26         | 2.6          |  [x]  |  [x]   | **HEMT**      |               |       |       |
| ekv3          | 302.00       |  [x]  |  [x]   | angelov       | 2.0           |  [x]  |  [x]  |
| hisim2        | 3.2.0        |  [x]  |        | angelov_gan   | 2.0           |  [x]  |  [x]  |
| psp102        | 102.5.0      |  [x]  |        | asmhemt       | 101.4.0       |  [x]  |       |
| psp103        | 103.8.2      |  [x]  |  [x]   | epfl-hemt     | 3.0.0         |  [x]  |       |
| psp104        | 104.0.0      |  [x]  |        | mvsg_cmc      | 3.2.0         |  [x]  |       |
| **SOI MOSFET**|              |       |        | **IGBT**      |               |       |       |
| l-lutsoi      | 102.7.0      |  [x]  |  [x]   | igbt3         | 1.0.0         |  [x]  |  [x]  |
| bsim-soi      | 4.6.1        |  [x]  |  [x]   |               |               |       |       |
| hisim-soi     | 1.5.0        |  [x]  |        |               |               |       |       |
| hisim-sotb    | 1.3.0        |  [x]  |        |               |               |       |       |

All models are checked for syntax belong Verilog-AMS Language Reference Manual Version 2.4.0. https://accellera.org/downloads/standards/v-ams
The models are modified mostly for convergence improvements. Equations are untouched.
So few parameter limits are changed to prevent division by zero and especially bipolar models lacks suitable limit function to prevent divergence in Newton-Raphson iteration process. Changes are noticed in Changelog.

At the moment this code modifications are adapted to NGSPICE and Xyce simulators. But in future the code can adapted to the requirements and restrictions of other simulators e.g. Qucs etc.

Any code directory has a set of test cases to show main functionality and performance of the models. Contributions for more practical use cases are welcome.

## Related Projects

The usage of the model code is mainly dependent from following projects: OpenVAF, NGSPICE, ADMS and Xyce.

### OpenVAF

OpenVAF can be build as a standalone CLI program that can compile Verilog-A files to shared objects that comply with the simulator independent OSDI interface.

Detailed documentation, examples and precompiled binaries of all release are available on the **[website](https://openvaf.semimod.de)**. To test the latest development version you can download nightly version of OpenVAF for linux [here](https://openva.fra1.cdn.digitaloceanspaces.com/openvaf_devel_linux_amd64.tar.gz).

OpenVAF has been tested with NGSPICE version 39. It can already support a large variety of compact models.

Furthermore, some Verilog-A language features are currently not supported by openVAF:

* Laplace transform filters
* Language constructs: $abstime(), @cross()
* Indirect branch contribution
* Paramset definition

### NGSPICE

**[NGSPICE](https://ngspice.sourceforge.io/)** is a open source simulator for electronic circuit simulation. Source code, examples and precompiled binaries of all release are available on the **[website](https://sourceforge.net/projects/ngspice/)**.

NGSPICE is stable and in an regulary update process.

### Xyce

**[Xyce](https://xyce.sandia.gov/)** is a open source simulator for electronic circuit simulation. Source code, documentation and precompiled binaries of all release are available on the **[website](https://xyce.sandia.gov/sign-in/)**.

Xyce is stable and in an regulary update process. ADMS/Xyce is supporting small signal noise analysis.

## How to build the models

### NGSPICE

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

### Xyce

Xyce must be installed and their executables in the PATH. These days only Linux executables with the ability to load shared libraries are available.
Another prerequisite is the availability of ADMS. ADMS source code may be downloaded from the Qucs/ADMS GitHub project **[website](https://github.com/Qucs/ADMS)** .

A user guide for Verilog-A models for Xyce can be found under the **[website](https://xyce.sandia.gov/documentation-tutorials/xyce-adms-users-guide/)** .

Linux:
``` shell
cd code
adms-compile-va.sh for Linux
```
Windows:
``` shell
cd code
adms-compile-va.bat for MS Windows
```

## Binary packages

Released are pre-compiled models for linux (Ubuntu 22.04 checked) and Windows 10 (64bit) ready for usage with osdi configured ngspice version > 39.

For Windows (only 64 bit versions 10 and 11 are verified) [Microsoft Visual C++ 2015 - 2022 Redistributable](https://www.microsoft.com/en-us/download/details.aspx?id=52685) package has to be installed.

    * 32-Bit-Version: https://aka.ms/vs/17/release/vc_redist.x86.exe
    * 64-Bit-Version: https://aka.ms/vs/17/release/vc_redist.x64.exe

## Project structure

VA-Models
   * admslibs    The place where the binaries reside after execution the adms-compile script
   * code        Below this folder all the VA models reside
   * examples
     * ngspice   ngspice example scripts
     * Qucs-S    qucs-s example schematics
     * Xyce      Xyce example scripts
   * memory_test Script for memory check (Linux only), only for debugging purpose
   * osdilibs    The place where the binaries reside after execution the osdi-compile script

## General Usage Instructions NGSPICE

Copy the *.osdi* files from directory osdilibs to the place where the NGSPICE code models (*.cm*) are located, e.g. */usr/local/share/ngspice/osdi (linux)*, *C:\Spice64\lib\ngspice (Windows)*.

Other way (as shown in the example files) is the load command *pre_osdi ../../osdilibs/bsimcmg.osdi* in the NGSPICE control section. 
You can also extend the ngspice environment variable SPICE_LIB_DIR to your_path/code/osdilibs

Third and preferable option is to use NGSPICE_OSDI_DIR environment variable in your $HOME/.profile (linux) or Windows environment variables with the path to the *.osdi file.

It is important that the *.model* card use the name of the Verilog-A module, e.g. in case of bsimcmg: *.model BSIMCMG_N bsimcmg_va*.

Edit file 'spinit', typically found in share/ngspice/scripts: To enable OSDI usage comment out the line

'unset osdi_enabled'

## General Usage Instructions Xyce

General instruction to build shared library from Verilog-A source with the Xyce provided tool buildxyceplugin:
``` shell
buildxyceplugin -o ekv26 -d ekv26.va ..
```

Copy the *.so* files from directory admslibs to your working directory.

This ekv example will use the compiled shared library and simulate the simple MOS amplifier circuit file:
``` shell
Xyce -plugin ekv26.so mosamp2.cir
```

The results are written into ASCII file and can plotted with gnuplot in persist mode:
``` shell
gnuplot -p mosamp2.plt
```

## General Usage Instructions Qucs-S

General the usage instructions from ngspice are applicable and preferred.

For several models Qucs-S example schematics are provided. Because qucs-s doesn't support loading osdi shared libs
with relative pathes in schematics "Nutmeg script" the user have to edit the local .spiceinit file for ngspice
and add the load command for the wanted osdi model, e.g. for linux (perhaps under $HOME):

osdi ~/Projects/spice/Verilog-A/VA-Models/osdilibs/ekv3.osdi

Windows (perhaps under C:\Users\<User name>):

osdi C:\Projects\spice\Verilog-A\VA-Models\osdilibs\ekv3.osdi


## Acknowledgement

The team of openVAF developer from Semimod GmbH https://semimod.de/ .

The NGSPICE development team https://ngspice.sourceforge.io/ .

The Xyce development team https://xyce.sandia.gov/ .

Geoffrey Coram for his excellent tool VAMPyRE https://github.com/analogdevicesinc/vampyre .

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