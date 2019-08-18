/* MEMORY command : Define allowed memory regions */
/* This part define various memory regions that the */
/* linker is allowed to put data into. This is an */
/* optional feature, but useful because the linker can */
/* warn you when your program is too big to fit. */


MEMORY
{
	/* ROM is a readable (r), executable region (x)  */
	rom (rx) : ORIGIN = 0, LENGTH = 256K
	
	/* RAM is a readable (r), writable (w) and executable region (x) */
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 32K
}

/* SECTION command : Define mapping of input sections into output sections. */
SECTIONS
{
	. = 0x0; /* From 0x00000000 */
	.text : {
		*(.vectors) /* Vector table */
		*(.text) /* Program code */
		*(.rodata) /* Read only data */
		. = ALIGN(4);
		
	} > rom

	. = 0x20000000; /* From 0x20000000 */
	.data : {
		INIT_DATA_VALUES = LOADADDR(.data);
		INIT_DATA_START = .;
		*(.data) /* Data memory */
		INIT_DATA_END = .;
	}
	BSS_START = .;
	.bss : {
		*(.bss) /* Zero-fi lled run time allocate data memory */
	} > ram
	BSS_END = .;
}
