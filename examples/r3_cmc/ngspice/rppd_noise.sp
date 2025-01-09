poly resistor flicker noise

.parameter w=1u l=10u b=0 ps=0.18e-6 m=1 trise=0
+postsim=0 rsh_rppd=1 rsh_rppd_mm=1
+leff=l*(b+1)+(2*w+ps)*b
+leffel=l*(b+1)+(2*w/1.85+ps)*b
+lhead=0.86e-6
+cshunt=(b>0)*(0.14e-18*l/ps)/(b+0.001)+(b==0)*1e-21
+cax=90e-18
+cpx=25e-18
+ax=175e-18*(1-1/(1.5*leff*1e6+1))/cax
+px=115e-18/cpx
+a0=0.5*(leff+lhead)*w-(postsim>0)*w*ax*1e-6
+a=(a0>0)*a0
+p0=leff+lhead+w-(postsim>0)*px*1e-6
+p=(p0>0)*p0
+rshspec=260
+rzspec=35e-6
+rqrc=4.5e-6
+rsh_mm=rshspec*rsh_rppd*(1+(rsh_rppd_mm-1)/sqrt(l*w*m*1e12))  
+rz=rzspec/w*rsh_rppd*(1+(rsh_rppd_mm-1)/sqrt(l*w*m*1e12))-(postsim>0)*rqrc/w

I1 0 out 188u AC 1
Nres_rppd out 0 0 dt rmod_rppd m=m
+w=w
+l=leffel
+a1=a a2=a
+p1=p p2=p
+c1=1 c2=1
+trise=trise
+sw_et=1

.model rmod_rppd r3_cmc
+rsh=rsh_mm
+ecrit=1000
+dfinf=1e-4
+dp=1000
+xw=0.006
+rc=rz
+ca=cax
+cp=cpx
+tc1=170e-6
+tc2=0.4e-6
+tc1rc=-950e-6
+gth0=1e-12
+gtha=6e-6
+gthp=2e-6
+gthc=1e-12
+cth0=0
+cthp=0
+ctha=594e-15
+cthc=0
+kfn=4.601e-11
+afn=1.886
+bfn=0.9963

.control
pre_osdi ../../../osdilibs/r3_cmc.osdi
noise V(out) I1 dec 10 1 100GHZ
setplot noise1
plot onoise_spectrum loglog
.endc
.END
