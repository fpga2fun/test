#include <stdio.h>
#include "mc20e_ccode_sim.h"
int main () 

{
*((volatile unsigned int *)0x02340028)= 0x00001040;
*((volatile unsigned int *)0x0234042C)= 0x1       ;
*((volatile unsigned int *)0x0234005c)= 0xc000000 ;

*((volatile unsigned int *)0x10034004)= 0x81     ;
*((volatile unsigned int *)0x100381b8)= 0x60     ;
*((volatile unsigned int *)0x100341b8)= 0x1      ;
*((volatile unsigned int *)0x10038014)= 0xC000000;

*((volatile unsigned int *)0x4430004)=  0xf     ;
*((volatile unsigned int *)0x4430008)=  0x1fffff;
*((volatile unsigned int *)0x443000c)=  0x3ff   ;
*((volatile unsigned int *)0x4430010)=  0x0     ;
*((volatile unsigned int *)0x4430078)=  0x22    ;
*((volatile unsigned int *)0x443007C)=  0x190A6 ;
*((volatile unsigned int *)0x4430080)=  0x3A12A ;
*((volatile unsigned int *)0x4430084)=  0x5B1AE ;
*((volatile unsigned int *)0x4430088)=  0x7C232 ;

*((volatile unsigned int *)0x460004C)=  0x1;

*((volatile unsigned int *)0x440700c)=  0x00000007;
*((volatile unsigned int *)0x4407010)=  0x0000000f;
*((volatile unsigned int *)0x4407014)=  0x0000007f;
*((volatile unsigned int *)0x4407020)=  0x00000001;
*((volatile unsigned int *)0x44074ac)=  0x00000001;
*((volatile unsigned int *)0x440742c)=  0x00000000;
*((volatile unsigned int *)0x4407294)=  0x00000000;
*((volatile unsigned int *)0x4407268)=  0x00000001;
*((volatile unsigned int *)0x44072a4)=  0x0000004d;
*((volatile unsigned int *)0x44072a8)=  0x00000096;
*((volatile unsigned int *)0x44072ac)=  0x0000001d;
*((volatile unsigned int *)0x44072b0)=  0x000007d6;
*((volatile unsigned int *)0x44072b4)=  0x000007ac;
*((volatile unsigned int *)0x44072b8)=  0x00000080;
*((volatile unsigned int *)0x44072bc)=  0x00000080;
*((volatile unsigned int *)0x44072c0)=  0x00000796;
*((volatile unsigned int *)0x44072c4)=  0x000007ec;
*((volatile unsigned int *)0x4407324)=  0x0000004d;
*((volatile unsigned int *)0x4407328)=  0x00000096;
*((volatile unsigned int *)0x440732c)=  0x0000001d;
*((volatile unsigned int *)0x4407330)=  0x000007d6;
*((volatile unsigned int *)0x4407334)=  0x000007ac;
*((volatile unsigned int *)0x4407338)=  0x00000080;
*((volatile unsigned int *)0x440733c)=  0x00000080;
*((volatile unsigned int *)0x4407340)=  0x00000796;
*((volatile unsigned int *)0x4407344)=  0x000007ec;
*((volatile unsigned int *)0x44073b0)=  0x0000004d;
*((volatile unsigned int *)0x44073b4)=  0x00000096;
*((volatile unsigned int *)0x44073b8)=  0x0000001d;
*((volatile unsigned int *)0x44073bc)=  0x000007d6;
*((volatile unsigned int *)0x44073c0)=  0x000007ac;
*((volatile unsigned int *)0x44073c4)=  0x00000080;
*((volatile unsigned int *)0x44073c8)=  0x00000080;
*((volatile unsigned int *)0x44073cc)=  0x00000796;
*((volatile unsigned int *)0x44073d0)=  0x000007ec;
*((volatile unsigned int *)0x4407270)=  0x01e002d0;
*((volatile unsigned int *)0x4407274)=  0x0000000a;
*((volatile unsigned int *)0x440727c)=  0x00000000;
*((volatile unsigned int *)0x4407280)=  0x8007f000;
*((volatile unsigned int *)0x4407284)=  0x000002d0;
*((volatile unsigned int *)0x4407288)=  0x00000000;
*((volatile unsigned int *)0x440728c)=  0x800d3600;
*((volatile unsigned int *)0x4407290)=  0x000002d0;
*((volatile unsigned int *)0x440742c)=  0x00000000;
*((volatile unsigned int *)0x4407454)=  0x00000004;
*((volatile unsigned int *)0x4407458)=  0x00000000;
*((volatile unsigned int *)0x4407474)=  0x00000005;
*((volatile unsigned int *)0x4407478)=  0x00000002;
*((volatile unsigned int *)0x4407458)=  0x00000000;
*((volatile unsigned int *)0x440745c)=  0x00390013;
*((volatile unsigned int *)0x4407460)=  0x001e0009;
*((volatile unsigned int *)0x4407464)=  0x00860024;
*((volatile unsigned int *)0x4407468)=  0x000001ad;
*((volatile unsigned int *)0x4407268)=  0x00000001;
*((volatile unsigned int *)0x440726c)=  0x00000001;

    end_simulation();

    while(1)
    {
	}
}