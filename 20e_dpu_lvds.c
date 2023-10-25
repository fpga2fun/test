#include <stdio.h>
#include "mc20e_ccode_sim.h"
int main () 

{
*((volatile unsigned int *)0x46000bc)= 0x2030    ;
*((volatile unsigned int *)0x46000b0)= 0x218     ;
*((volatile unsigned int *)0x23401fc)= 0x2       ;
*((volatile unsigned int *)0x23401f0)= 0x2       ;
*((volatile unsigned int *)0x23f12b8)= 0x1       ;
*((volatile unsigned int *)0x23f12c0)= 0x1       ;
*((volatile unsigned int *)0x4430004)= 0xf       ;
*((volatile unsigned int *)0x4430008)= 0x1fffff  ;
*((volatile unsigned int *)0x443000c)= 0x3ff     ;
*((volatile unsigned int *)0x4430010)= 0x0       ;
*((volatile unsigned int *)0x4430078)= 0x22      ;
*((volatile unsigned int *)0x443007C)= 0x190A6   ;
*((volatile unsigned int *)0x4430080)= 0x3A12A   ;
*((volatile unsigned int *)0x4430084)= 0x5B1AE   ;
*((volatile unsigned int *)0x4430088)= 0x7C232   ;
*((volatile unsigned int *)0x4630004)= 0x1       ;
*((volatile unsigned int *)0x4630000)= 0x1       ;
*((volatile unsigned int *)0x4630028)= 0x1       ;
*((volatile unsigned int *)0x440700c)= 0x00000007;
*((volatile unsigned int *)0x4407010)= 0x0000000f;
*((volatile unsigned int *)0x4407014)= 0x0000007f;
*((volatile unsigned int *)0x4407020)= 0x00000001;
*((volatile unsigned int *)0x44074ac)= 0x00000001;
*((volatile unsigned int *)0x440742c)= 0x00000000;
*((volatile unsigned int *)0x4407294)= 0x00000000;
*((volatile unsigned int *)0x4407268)= 0x00000001;
*((volatile unsigned int *)0x44072a4)= 0x0000004d;
*((volatile unsigned int *)0x44072a8)= 0x00000096;
*((volatile unsigned int *)0x44072ac)= 0x0000001d;
*((volatile unsigned int *)0x44072b0)= 0x000007d6;
*((volatile unsigned int *)0x44072b4)= 0x000007ac;
*((volatile unsigned int *)0x44072b8)= 0x00000080;
*((volatile unsigned int *)0x44072bc)= 0x00000080;
*((volatile unsigned int *)0x44072c0)= 0x00000796;
*((volatile unsigned int *)0x44072c4)= 0x000007ec;
*((volatile unsigned int *)0x4407324)= 0x0000004d;
*((volatile unsigned int *)0x4407328)= 0x00000096;
*((volatile unsigned int *)0x440732c)= 0x0000001d;
*((volatile unsigned int *)0x4407330)= 0x000007d6;
*((volatile unsigned int *)0x4407334)= 0x000007ac;
*((volatile unsigned int *)0x4407338)= 0x00000080;
*((volatile unsigned int *)0x440733c)= 0x00000080;
*((volatile unsigned int *)0x4407340)= 0x00000796;
*((volatile unsigned int *)0x4407344)= 0x000007ec;
*((volatile unsigned int *)0x44073b0)= 0x0000004d;
*((volatile unsigned int *)0x44073b4)= 0x00000096;
*((volatile unsigned int *)0x44073b8)= 0x0000001d;
*((volatile unsigned int *)0x44073bc)= 0x000007d6;
*((volatile unsigned int *)0x44073c0)= 0x000007ac;
*((volatile unsigned int *)0x44073c4)= 0x00000080;
*((volatile unsigned int *)0x44073c8)= 0x00000080;
*((volatile unsigned int *)0x44073cc)= 0x00000796;
*((volatile unsigned int *)0x44073d0)= 0x000007ec;
*((volatile unsigned int *)0x4407270)= 0x03200500;
*((volatile unsigned int *)0x4407274)= 0x0000000d;
*((volatile unsigned int *)0x440727c)= 0x00000000;
*((volatile unsigned int *)0x4407280)= 0x80000000;
*((volatile unsigned int *)0x4407284)= 0x00000500;
*((volatile unsigned int *)0x4407288)= 0x00000000;
*((volatile unsigned int *)0x440728c)= 0x800fa000;
*((volatile unsigned int *)0x4407290)= 0x00000500;
*((volatile unsigned int *)0x440742c)= 0x00000000;
*((volatile unsigned int *)0x4407454)= 0x00000001;
*((volatile unsigned int *)0x4407474)= 0x00000003;
*((volatile unsigned int *)0x440745c)= 0x00c80040;
*((volatile unsigned int *)0x4407460)= 0x00180001;
*((volatile unsigned int *)0x4407464)= 0x00880003;
*((volatile unsigned int *)0x4407468)= 0x00000348;
*((volatile unsigned int *)0x4407268)= 0x00000001;
*((volatile unsigned int *)0x4407010)= 0x0000000d;
*((volatile unsigned int *)0x4407010)= 0x00000009;
*((volatile unsigned int *)0x4407010)= 0x00000001;
*((volatile unsigned int *)0x440726c)= 0x00000001;

    end_simulation();

    while(1)
    {
	}
}