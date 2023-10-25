static void REG_W32(unsigned long addr, unsigned int val)
{
    *(volatile unsigned int *)addr = val;
}
static unsigned int REG_R32(unsigned long addr)
{
    return *((volatile unsigned int *)addr);
}
static void uart_init()
{
    //uart print
    *((volatile unsigned int *)0x04880010) = 0x0;          //MCR
    *((volatile unsigned int *)0x0488000c) |= 1 << 7;      //LCR
    *((volatile unsigned int *)0x04880000) = 0x41;         //DLL 9600
    *((volatile unsigned int *)0x04880004) = 0x0;          //DLH 9600
    *((volatile unsigned int *)0x0488000c) = 0x03;        //LCR
    *((volatile unsigned int *)0x04880008) = 0x0;          //FCR
    *((volatile unsigned int *)0x04880004) = 0x0;          //IER
}
static void uart_putc(char c)
{
    volatile int i;
    REG_W32(0x04880000, c);
    for (i = 0; i < 10; i++) {}
}
#if 0
#define CHECK_BASE 0x40000000
#define CHECK_BLK_LEN 0x10000
#define CHECK_BLK_CNT  (0x40000000 / CHECK_BLK_LEN)
static void outnum(const long n)
{
    char outbuf[8];
    const char digits[] = "0123456789ABCDEF";
    unsigned long num;
    int base = 16;
    int i;
    num = (n);
    /* Build number (backwards) in outbuf */
    for (i = 0; i < 8; i++) {
        outbuf[i] = digits[(int)(num % base)];
        num /= base;
    }
    for (i = 7; i >= 0; i--) {
        uart_putc(outbuf[i]);
    }
}

void ddr_init_check()
{
    int i, j;
    uart_putc('E');
    for (i = 0; i < CHECK_BLK_CNT; i ++) {
        for (j = 0; j < (CHECK_BLK_LEN / 4); j += 0x100) {
            if (REG_R32(CHECK_BASE + i * CHECK_BLK_LEN + j * 4) != (i * CHECK_BLK_LEN / 4 + j)) {
                uart_putc('E');
                uart_putc('R');
                uart_putc('R');
                uart_putc('O');
                uart_putc('R');
                outnum(CHECK_BASE + i * CHECK_BLK_LEN + j * 4);
                while (1);
            }
        }
        uart_putc('.');
    }
    uart_putc('F');
}
static int ddr_wr_check()
{
    int rdata, i;
    REG_W32(0x40000000, 0xaaaa);
    rdata = REG_R32(0x40000000);
    if (rdata == 0xaaaa)
        *((volatile unsigned int *)0x04880000) = 'A';  //THR
    else
        *((volatile unsigned int *)0x04880000) = 'a';  //THR
    for (i = 0; i < 1000; i++) {}

    REG_W32(0x40004000, 0xbbbb);
    rdata = REG_R32(0x40004000);
    if (rdata == 0xbbbb)
        *((volatile unsigned int *)0x04880000) = 'B';  //THR
    else
        *((volatile unsigned int *)0x04880000) = 'b';  //THR

    for (i = 0; i < 1000; i++) {}

    REG_W32(0x40008000, 0xdddd);
    rdata = REG_R32(0x40008000);
    if (rdata == 0xdddd)
        *((volatile unsigned int *)0x04880000) = 'D';  //THR
    else
        *((volatile unsigned int *)0x04880000) = 'd';  //THR
    return 0;
}
#endif
void ddr_init()
{
    int rdata, i;
    //uart print
    for (int i = 0; i < 500; i++) //wait pll ready
    {}
    //DDR_CLK3200M
    uart_putc('1');
    //plat_printf("[DV INFO:] cfg DDR_CLK3200M. \n");
    REG_W32(0x0000026505c, 0x00000000);
    REG_W32(0x00000265038, 0x01fffffe);
    REG_W32(0x00000265010, 0x0000010a);
    REG_W32(0x00000265010, 0x0000010a);
    REG_W32(0x00000265010, 0x0000010a);
    REG_W32(0x00000265010, 0x0000010a);
    REG_W32(0x00000265004, 0x02aaaaa8);
    REG_W32(0x00000265038, 0x01ffffff);
    //wait pll ready
    for (int i = 0; i < 5000; i++) {}
    REG_W32(0x0026505c, 0x00000001); //dpll_re_open

    //plat_printf("[DV INFO:] release_all_reset. \n");
    uart_putc('2');
    REG_W32(0x00002340068, 0x00000200);
    REG_W32(0x00002340068, 0x00000100);

    //plat_printf("[DV INFO:] ddr sys real clk cfg. \n");
    uart_putc('3');
    REG_W32(0x00000210004, 0x00000001);
    REG_W32(0x00000210000, 0x00060000);   //REG_W32(0x00000210000,0x00080000);
    REG_W32(0x00000210000, 0x00060002);   //REG_W32(0x00000210000,0x00080002);
    REG_W32(0x00000210000, 0x00060012);   //REG_W32(0x00000210000,0x00080012);
    REG_W32(0x00000210000, 0x00060092);   //REG_W32(0x00000210000,0x00080092);
    REG_W32(0x00000210000, 0x00060492);   //REG_W32(0x00000210000,0x00080492);
    REG_W32(0x00000210000, 0x00062492);   //REG_W32(0x00000210000,0x00082492);
    REG_W32(0x00000210000, 0x00072492);   //REG_W32(0x00000210000,0x00092492);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x00000210008, 0xffffffff);
    REG_W32(0x0000021000c, 0x0000001f);
    REG_W32(0x0000021000c, 0x0000001f);
    REG_W32(0x0000021000c, 0x0000001f);
    REG_W32(0x0000021000c, 0x0000001f);
    REG_W32(0x0000021000c, 0x0000001f);

    //plat_printf("[DV INFO:] ddr init! \n");
    uart_putc('4');
    REG_W32(0x00000100000, 0x01000202);
    REG_W32(0x00000100004, 0x00000000);
    REG_W32(0x00000100008, 0x00000000);
    REG_W32(0x00000100010, 0x01000202);
    REG_W32(0x00000100014, 0x00000000);
    REG_W32(0x00000100018, 0x00000000);
    REG_W32(0x00000100020, 0x01000202);
    REG_W32(0x00000100024, 0x00000000);
    REG_W32(0x00000100028, 0x00000000);
    REG_W32(0x00000100030, 0x01000202);
    REG_W32(0x00000100034, 0x00000000);
    REG_W32(0x00000100038, 0x00000000);
    REG_W32(0x00000100040, 0x01000202);
    REG_W32(0x00000100044, 0x00000000);
    REG_W32(0x00000100048, 0x00000000);
    REG_W32(0x00000100050, 0x01000202);
    REG_W32(0x00000100054, 0x00000000);
    REG_W32(0x00000100058, 0x00000000);
    REG_W32(0x00000100060, 0x01000202);
    REG_W32(0x00000100064, 0x00000000);
    REG_W32(0x00000100068, 0x00000000);
    REG_W32(0x00000100070, 0x01000202);
    REG_W32(0x00000100074, 0x00000000);
    REG_W32(0x00000100078, 0x00000000);
    REG_W32(0x00000100080, 0x00030000);
    REG_W32(0x00000100084, 0x00020104);
    REG_W32(0x00000100088, 0x00401452);
    REG_W32(0x0000010008c, 0x00000000);
    REG_W32(0x00000100090, 0x00000000);
    REG_W32(0x00000100094, 0x00000000);
    REG_W32(0x00000100098, 0x00000010);
    REG_W32(0x0000010009c, 0x04000000);
    REG_W32(0x000001000a0, 0x00000000);
    REG_W32(0x000001000a4, 0x00000800);
    REG_W32(0x000001000a8, 0x00000000);
    REG_W32(0x000001000ac, 0x0000c0c0);
    REG_W32(0x000001000b0, 0x00003030);
    REG_W32(0x000001000b4, 0x00000000);
    REG_W32(0x000001000b8, 0x00000000);
    REG_W32(0x000001000bc, 0x08000040);
    REG_W32(0x000001000c0, 0x00ff0000);
    REG_W32(0x000001000c4, 0xffffffff);
    REG_W32(0x000001000c8, 0xffffffff);
    REG_W32(0x000001000cc, 0x00000000);
    REG_W32(0x000001000d4, 0x00640000);
    REG_W32(0x000001000d8, 0x0000f800);
    REG_W32(0x000001000dc, 0x3c3c3c3c);
    REG_W32(0x000001000e0, 0x3c3c3c3c);
    REG_W32(0x000001000e4, 0x00000000);
    REG_W32(0x000001000e8, 0x00000000);
    REG_W32(0x000001000ec, 0x00000000);
    REG_W32(0x000001000f0, 0x00000000);
    REG_W32(0x000001000f4, 0x00030000);
    REG_W32(0x000001000f8, 0x00000000);
    REG_W32(0x000001000fc, 0x00000000);
    REG_W32(0x00000100180, 0x000f0011);
    REG_W32(0x00000100184, 0x0308190f);
    REG_W32(0x00000100188, 0x0010100e);
    REG_W32(0x0000010018c, 0x02020000);
    REG_W32(0x00000100190, 0x12120804);
    REG_W32(0x00000100194, 0x00070000);
    REG_W32(0x00000100198, 0x007000e0);
    REG_W32(0x0000010019c, 0x001000e6);
    REG_W32(0x000001001a0, 0x0c0c020c);
    REG_W32(0x000001001a4, 0x0a002022);
    REG_W32(0x000001001a8, 0x00000000);
    REG_W32(0x000001001ac, 0x07070707);
    REG_W32(0x000001001b0, 0x0000110f);
    REG_W32(0x000001001b4, 0x00000000);
    REG_W32(0x000001001b8, 0x10000000);
    REG_W32(0x000001001bc, 0x08400000);
    REG_W32(0x000001001c0, 0x00010080);
    REG_W32(0x000001001c4, 0x00001000);
    REG_W32(0x000001001c8, 0x00010000);
    REG_W32(0x000001001cc, 0x00000000);
    REG_W32(0x000001001d0, 0x00000022);
    REG_W32(0x000001001e0, 0x0124022d);
    REG_W32(0x000001001e4, 0x0b000331);
    REG_W32(0x000001001e8, 0x0124022d);
    REG_W32(0x000001001ec, 0x0b000331);
    REG_W32(0x000001001f0, 0x0124022d);
    REG_W32(0x000001001f4, 0x0b000331);
    REG_W32(0x000001001f8, 0x0124022d);
    REG_W32(0x000001001fc, 0x0b000331);
//    REG_W32(0x00000111004,0x06543210);
//    REG_W32(0x00000111008,0x76543211);
//    REG_W32(0x0000011100c,0x76543210);
//    REG_W32(0x00000111010,0xfedc1a98);
//    REG_W32(0x00000111014,0xffff0000);
//    REG_W32(0x00000121004,0x76545432);
//    REG_W32(0x00000121008,0x76543210);
//    REG_W32(0x0000012100c,0x76543210);
//    REG_W32(0x00000121010,0xfedcba98);
//    REG_W32(0x00000121014,0xffff0000);
//    REG_W32(0x00000110000,0x0020e402);
//    REG_W32(0x00000120000,0x0020e402);
//    REG_W32(0x00000110100,0x007f8405);
//    REG_W32(0x00000110104,0x00010408);
//    REG_W32(0x00000110108,0x0000007c);
//    REG_W32(0x0000011010c,0x000000fc);
//    REG_W32(0x00000110110,0x00000ffc);
//    REG_W32(0x00000110114,0x00000fff);
//    REG_W32(0x00000110118,0x140000fe);
//    REG_W32(0x0000011011c,0x04100040);
//    REG_W32(0x00000110120,0x000a0fff);
//    REG_W32(0x00000110124,0x00300233);
//    REG_W32(0x00000110128,0x00000000);
//    REG_W32(0x0000011012c,0x19751023);
//    REG_W32(0x00000110130,0x40018e20);
//    REG_W32(0x00000110134,0x04010002);
//    REG_W32(0x00000111100,0x00250213);
//    REG_W32(0x00000111104,0x00008000);
//    REG_W32(0x00000111108,0x00008000);
//    REG_W32(0x00000112100,0x00250213);
//    REG_W32(0x00000112104,0x00008230);
//    REG_W32(0x00000112108,0x00008000);
//    REG_W32(0x0000011210c,0x00008100);
//    REG_W32(0x00000112110,0x00008100);
//    REG_W32(0x00000112114,0x00008000);
//    REG_W32(0x00000112118,0x0000003c);
//    REG_W32(0x00000113100,0x00250213);
//    REG_W32(0x00000113104,0x00008230);
//    REG_W32(0x00000113108,0x00008000);
//    REG_W32(0x0000011310c,0x00008100);
//    REG_W32(0x00000113110,0x00008100);
//    REG_W32(0x00000113114,0x00008000);
//    REG_W32(0x00000113118,0x0000003c);
//    REG_W32(0x00000120100,0x007f8405);
//    REG_W32(0x00000120104,0x00010408);
//    REG_W32(0x00000120108,0x0000007c);
//    REG_W32(0x0000012010c,0x000000fc);
//    REG_W32(0x00000120110,0x00000ffc);
//    REG_W32(0x00000120114,0x00000fff);
//    REG_W32(0x00000120118,0x140000fe);
//    REG_W32(0x0000012011c,0x04100040);
//    REG_W32(0x00000120120,0x000a0fff);
//    REG_W32(0x00000120124,0x00300233);
//    REG_W32(0x00000120128,0x00000000);
//    REG_W32(0x0000012012c,0x19751023);
//    REG_W32(0x00000120130,0x40018e20);
//    REG_W32(0x00000120134,0x04010002);
//    REG_W32(0x00000121100,0x00250213);
//    REG_W32(0x00000121104,0x00008000);
//    REG_W32(0x00000121108,0x00008000);
//    REG_W32(0x00000122100,0x00250213);
//    REG_W32(0x00000122104,0x00008230);
//    REG_W32(0x00000122108,0x00008000);
//    REG_W32(0x0000012210c,0x00008100);
//    REG_W32(0x00000122110,0x00008100);
//    REG_W32(0x00000122114,0x00008000);
//    REG_W32(0x00000122118,0x0000003c);
//    REG_W32(0x00000123100,0x00250213);
//    REG_W32(0x00000123104,0x00008230);
//    REG_W32(0x00000123108,0x00008000);
//    REG_W32(0x0000012310c,0x00008100);
//    REG_W32(0x00000123110,0x00008100);
//    REG_W32(0x00000123114,0x00008000);
//    REG_W32(0x00000123118,0x0000003c);
    REG_W32(0x00000100080, 0x00330003);
    //TODO need manual change addr&value !
    //addr:100080 polling: bit8==1
    //addr:100100 polling: bit29==0
    for (int poll_num = 0; poll_num < 1000; poll_num++) {
        rdata = REG_R32(0x00100100);
        if (rdata & 0x00000100)
            break;
        //if(poll_num == 500)
        //plat_printf("ERROR: poll_num==500. D_DDRMC_CFG0_ADDR. \n");
    }
    uart_putc('5');
    REG_W32(0x00000100080, 0x00330100);
    REG_W32(0x000001000d8, 0x0000f800);
    REG_W32(0x000001000d8, 0x0020f800);
//    REG_W32(0x00000110000,0x0422e402);
//    REG_W32(0x00000120000,0x0422e402);
//    REG_W32(0x00000110000,0x0420e402);
//    REG_W32(0x00000120000,0x0420e402);
    REG_W32(0x000001000d8, 0x0020f802);
    REG_W32(0x000001000d8, 0x0030f802);
    REG_W32(0x00000100080, 0x00310100);
    REG_W32(0x00000100098, 0x00000000);
    REG_W32(0x00000100088, 0x31401552);
    REG_W32(0x000001000f8, 0x01000002);
    REG_W32(0x000001000fc, 0x0000002d);
    REG_W32(0x00000100100, 0x01000002);
    //TODO need manual change addr&value !
    //addr:100080 polling: bit8==1
    //addr:100100 polling: bit29==0
    for (int poll_num = 0; poll_num < 1000; poll_num++) {
        rdata = REG_R32(0x00100100);
        if ((rdata & 0x20000000) == 0)
            break;
        //if(poll_num == 500)
        //plat_printf("ERROR: poll_num==500. D_DDRMC_CFG0_ADDR. \n");
    }
    uart_putc('6');
    REG_W32(0x000001000f8, 0x01000001);
    REG_W32(0x000001000fc, 0x00000024);
    REG_W32(0x00000100100, 0x01000002);
    //TODO need manual change addr&value !
    //addr:100080 polling: bit8==1
    //addr:100100 polling: bit29==0
    for (int poll_num = 0; poll_num < 1000; poll_num++) {
        rdata = REG_R32(0x00100100);
        if ((rdata & 0x20000000) == 0)
            break;
        //if(poll_num == 500)
        //plat_printf("ERROR: poll_num==500. D_DDRMC_CFG0_ADDR. \n");
    }
    REG_W32(0x000001000f8, 0x01000003);
    REG_W32(0x000001000fc, 0x00000031);
    REG_W32(0x00000100100, 0x01000002);
    //TODO need manual change addr&value !
    //addr:100080 polling: bit8==1
    //addr:100100 polling: bit29==0
    for (int poll_num = 0; poll_num < 1000; poll_num++) {
        rdata = REG_R32(0x00100100);
        if ((rdata & 0x20000000) == 0)
            break;
        //if(poll_num == 500)
        //plat_printf("ERROR: poll_num==500. D_DDRMC_CFG0_ADDR. \n");
    }
    uart_putc('7');
    REG_W32(0x000001000f8, 0x0100000b);
    REG_W32(0x000001000fc, 0x00000000);
    REG_W32(0x00000100100, 0x01000002);
    //TODO need manual change addr&value !
    //addr:100080 polling: bit8==1
    //addr:100100 polling: bit29==0
    for (int poll_num = 0; poll_num < 1000; poll_num++) {
        rdata = REG_R32(0x00100100);
        if ((rdata & 0x20000000) == 0)
            break;
        //if(poll_num == 500)
        //plat_printf("ERROR: poll_num==500. D_DDRMC_CFG0_ADDR. \n");
    }
    REG_W32(0x000001000f8, 0x0100000d);
    REG_W32(0x000001000fc, 0x00000048);
    REG_W32(0x00000100100, 0x01000002);
    //TODO need manual change addr&value !
    //addr:100080 polling: bit8==1
    //addr:100100 polling: bit29==0
    for (int poll_num = 0; poll_num < 1000; poll_num++) {
        rdata = REG_R32(0x00100100);
        if ((rdata & 0x20000000) == 0)
            break;
        //if(poll_num == 500)
        //plat_printf("ERROR: poll_num==500. D_DDRMC_CFG0_ADDR. \n");
    }
    uart_putc('8');
    REG_W32(0x000001000f8, 0x0100000d);
    REG_W32(0x000001000fc, 0x00000008);
    REG_W32(0x00000100100, 0x01000002);
    //TODO need manual change addr&value !
    //addr:100080 polling: bit8==1
    //addr:100100 polling: bit29==0
    for (int poll_num = 0; poll_num < 1000; poll_num++) {
        rdata = REG_R32(0x00100100);
        if ((rdata & 0x20000000) == 0)
            break;
        //if(poll_num == 500)
        //plat_printf("ERROR: poll_num==500. D_DDRMC_CFG0_ADDR. \n");
    }
    uart_putc('9');
    REG_W32(0x000001000c0, 0x00ff0001);
    REG_W32(0x000001000a0, 0x00000000);
    for (i = 0; i < 1000; i++) {}
}

#define PMU_BASE 0x2100000
#define CPU_BASE 0X1900000
#define COMM_GLB_REG_BASE 0x2340000
static void pmu_config()
{
    REG_W32(PMU_BASE + 0x4, 0xfffffff); //wake_up
}
static void clk_config()
{
    unsigned int val;
    REG_W32(CPU_BASE, (4 << 2) | (3)); //CPU cpupll_1200m, clk_bus_flash_sel: 312M
    /*
     * aclk_cpu_top_sel npll_533m
     * aclk_isp_top_sel npll_533m
     */
    val = (5 << 24) | (5 << 27);
    REG_W32(COMM_GLB_REG_BASE, val);//clk_mux_0
    /*
     * aclk_mm_top_sel npll_533m
     * aclk_nn_top_sel npll_533m
     * aclk_ocm_top_sel npll_533m
     * aclk_vpu_top_sel npll_533m
     */
    val = (5) | (5 << 3) | (5 << 6) | (5 << 9);
    REG_W32(COMM_GLB_REG_BASE + 0xc, val);//clk_mux_1
    /*pclk_top_sel cpll_208m*/
    REG_W32(COMM_GLB_REG_BASE + 0x18, 3);//clk_mux_2
}
void syscnt_init()
{
    REG_W32(0x1B30008, 0x0);//CNTCVL
    REG_W32(0x1B3000c, 0x0);//CNTCVH
    REG_W32(0x1B30020, 0x16E3600);//24MHz
    REG_W32(0x1B30000, 1);//enable
}
void chip_init()
{
    uart_init();
    uart_putc('A');
    uart_putc('B');
    clk_config();
    uart_putc('B');
    pmu_config();
    uart_putc('C');
    ddr_init();
    syscnt_init();
    uart_putc('E');
}
