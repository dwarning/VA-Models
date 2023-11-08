/***********************************************************************

 HiSIM (Hiroshima University STARC IGFET Model)
 Copyright (C) 2000-2016 Hiroshima University and STARC
 Copyright (C) 2016-2023 Hiroshima University
 HiSIM_HV (High-Voltage Model)
 Copyright (C) 2007-2016 Hiroshima University and STARC
 Copyright (C) 2016-2023 Hiroshima University

 MODEL NAME : HiSIM_HV
 ( VERSION : 2  SUBVERSION : 5  REVISION : 1 )
 Model Parameter 'VERSION' : 2.51
 FILE : HSMHV_temp_eval_rdri.inc

 Date : 2023.02.09

 released by Hiroshima University

***********************************************************************/
//
////////////////////////////////////////////////////////////////
//
//
//
//
//Licensed under the Educational Community License, Version 2.0
//(the "License"); you may not use this file except in
//compliance with the License.
//
//You may obtain a copy of the License at:
//
//      http://opensource.org/licenses/ECL-2.0
//
//Unless required by applicable law or agreed to in writing,
//software distributed under the License is distributed on an
//"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
//either express or implied. See the License for the specific
//language governing permissions and limitations under the
//License.
//
//
//The HiSIM_HV standard has been supported by the members of
//Silicon Integration Initiative's Compact Model Coalition. A
//link to the most recent version of this standard can be found
//at:
//
//http://www.si2.org/cmc
//
////////////////////////////////////////////////////////////////
//


// Phonon Scattering(temperature-dependent part) //
T1 =  `Fn_Pow( Tratio, RDRMUETMP ) ;
RRDRMUE = MKS_RDRMUE / T1 ;

// Velocity Temperature Dependence //
T0 = 1.8 + 0.4 * Tratio + 0.1 * Tratio * Tratio - RDRVTMP * ( 1.0 - Tratio ) ;
RRDRVMAX = MKS_RDRVMAX / T0 ;

//Toshiba model //
UC_RDRBB = UC_RDRBB + RDRBBTMP * (TTEMP-KTNOM) ;

// Check the value after temperature dependence
`MINRESET(UC_RDRBB, 0.1 , "RDRBB@T dependence")

// end of HSMHVtemp_eval_rdri.h //
