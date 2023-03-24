EKV26 mosamp2 - mos amplifier - transient

nm1  15 15  1 32 nch w=88.9u  l=25.4u
nm2   1  1  2 32 nch w=12.7u  l=266.7u
nm3   2  2 30 32 nch w=88.9u  l=25.4u
nm4  15  5  4 32 nch w=12.7u  l=106.7u
nm5   4  4 30 32 nch w=88.9u  l=12.7u
nm6  15 15  5 32 nch w=44.5u  l=25.4u
nm7   5 20  8 32 nch w=482.6u l=12.7u
nm8   8  2 30 32 nch w=88.9u  l=25.4u
nm9  15 15  6 32 nch w=44.5u  l=25.4u
nm10  6 in  8 32 nch w=482.6u l=12.7u
nm11 15  6  7 32 nch w=12.7u  l=106.7u
nm12  7  4 30 32 nch w=88.9u  l=12.7u
nm13 15 10  9 32 nch w=139.7u l=12.7u
nm14  9 11 30 32 nch w=139.7u l=12.7u
nm15 15 15 12 32 nch w=12.7u  l=207.8u
nm16 12 12 11 32 nch w=54.1u  l=12.7u
nm17 11 11 30 32 nch w=54.1u  l=12.7u
nm18 15 15 10 32 nch w=12.7u  l=45.2u
nm19 10 12 13 32 nch w=270.5u l=12.7u
nm20 13  7 30 32 nch w=270.5u l=12.7u
nm21 15 10 14 32 nch w=254u   l=12.7u
nm22 14 11 30 32 nch w=241.3u l=12.7u
nm23 15 20 16 32 nch w=19u    l=38.1u
nm24 16 14 30 32 nch w=406.4u l=12.7u
nm25 15 15 20 32 nch w=38.1u  l=42.7u
nm26 20 16 30 32 nch w=381u   l=25.4u
nm27 20 15 out 32 nch w=22.9u  l=7.6u
cc 7 9 40pf
cl out 0 70pf
vin in 0 dc 0 ac 1 pulse(0 5 1ns 1ns 1ns 5us 10us)
vccp 15 0 dc +15
vddn 30 0 dc -15
vb 32 0 dc -20

.include Modelcards/ekv26_0u5.par

*----------------------------------------
.control
pre_osdi ../osdilibs/ekv26.osdi
ac dec 100 1k 100Meg
plot vdb(out)
plot 180/PI*ph(out)
tran 0.1us 10us
plot v(in) v(20) v(out)
.endc

.end
