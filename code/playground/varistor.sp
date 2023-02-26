Verilog-A varistor test circuit

.model varistor varistor T=1 C=700pF L=13.0nH B1=2.7233755 B2=0.0258453 
+ B3=-0.0005746 B4=0.0046033

nx1 top 0 varistor
i1 0 top dc=1e-5 sin(1e3 1e7 1e3)

* these three sweeps replicate Figure 2: V-I characteristic
* with 10% tolerance bands
*dc1 dc dev=i1 start=1e-5 stop=1e4 dec=10

*alter1 alter dev=x1 param=T value=0.9
*dc2 dc dev=i1 start=1e-5 stop=1e4 dec=10

*alter2 alter dev=x1 param=T value=1.1
*dc3 dc dev=i1 start=1e-5 stop=1e4 dec=10

* can you replicate the transient pulse of Figure 3?
.control
pre_osdi varistor.osdi
*to verify the linear interpolation
dc i1 -0.2e-6 0.2e-6 1e-9
plot v(top)
tran 1n 10m 0 100p
plot v(top)/nx1#flow(br_rseries)
.endc
.end
