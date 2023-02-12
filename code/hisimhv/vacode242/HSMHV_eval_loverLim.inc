/***********************************************************************

 HiSIM (Hiroshima University STARC IGFET Model)
 Copyright (C) 2000-2016 Hiroshima University and STARC
 Copyright (C) 2016-2019 Hiroshima University
 HiSIM_HV (High-Voltage Model)
 Copyright (C) 2007-2016 Hiroshima University and STARC
 Copyright (C) 2016-2019 Hiroshima University

 MODEL NAME : HiSIM_HV
 ( VERSION : 2  SUBVERSION : 4  REVISION : 2 )
 Model Parameter 'VERSION' : 2.42
 FILE : HSMHV_eval_loverLim.inc

 Date : 2019.04.09

 released by Hiroshima University

***********************************************************************/
//
////////////////////////////////////////////////////////////////
//
//Licensed under the Educational Community License, Version 2.0
//(the "License"); you may not use this file except in
//compliance with the License.
//
//You may obtain a copy of the License at:
//
//  http://opensource.org/licenses/ECL-2.0
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


// calc. bias dependent Lover for 2.4.0
if ( Lover_func < 0.0 && SUBVERSION > 3 && QOVJUNC > 0 && COTRENCH == 1 ) begin
    Lover_func = - Lover_func ; // now, Lover_func positive.
    T1 = LOVERLD ;
    Vxb_lim = (T1 * T1 / kjunc) - VBI ;
    if ( OLMDLT > 0 ) begin
        T1 = 1.0 + pow( (Vxbgmt / Vxb_lim) , OLMDLT ) ;
        T2 = pow(T1, 1/OLMDLT) ;
        Vxbgmt = Vxbgmt / T2 ;
        `Fn_SZ( T2 , (Vxbgmt + VBI) , 0.1 , T9 )
        Wjunc0 = sqrt ( kjunc * T2 ) * QOVJUNC ;
        Lover_func = Lover_func - Wjunc0 ;
    end
end // if ( Lover_func < 0.0 && SUBVERSION > 3 && QOVJUNC > 0 && COTRENCH == 1 )
