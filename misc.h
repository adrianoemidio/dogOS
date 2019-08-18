#ifndef MISC_H
#define MISC_H

//Bit mask

#define	b0	0x1
#define	b1	0x2
#define	b2	0x4
#define	b3	0x8
#define	b4	0x10
#define	b5	0x20
#define	b6	0x40
#define	b7	0x80
#define	b8	0x100
#define	b9	0x200
#define	b10	0x400
#define	b11	0x800
#define	b12	0x1000
#define	b13	0x2000
#define	b14	0x4000
#define	b15	0x8000
#define	b16	0x10000
#define	b17	0x20000
#define	b18	0x40000
#define	b19	0x80000
#define	b20	0x100000
#define	b21	0x200000
#define	b22	0x400000
#define	b23	0x800000
#define	b24	0x1000000
#define	b25	0x2000000
#define	b26	0x4000000
#define	b27	0x8000000
#define	b28	0x10000000
#define	b29	0x20000000
#define	b30	0x40000000
#define	b31	0x80000000


//Set bit in Register
#define bit_set(reg,mask) (reg |= mask )	

//Clear bit in Register
#define bit_clr(reg,mask) (reg &= (~mask))


#endif
