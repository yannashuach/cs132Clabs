typedef volatile unsigned int ioreg;

#define	PIO_PER		(ioreg *) 0xfffff400	// PIO Enable Registe
#define	PIO_OER	  	(ioreg *) 0xfffff410	// Output Enable Register
#define	PIO_SODR  	(ioreg *) 0xfffff430	// Set Output Data Register
#define	PIO_CODR  	(ioreg *) 0xfffff434	// Clear Output Data Register

#define RED_LED		0x00000004
#define AMBER_LED		0x00000003
#define GREEN_LED		0x00000002

void main(void) {
  *PIO_PER = RED_LED; // Enable control of I/O pin from PIO Controller
	*PIO_OER = RED_LED; // Enable output driver for pin
  *PIO_PER = AMBER_LED; // Enable control of I/O pin from PIO Controller
	*PIO_OER = AMBER_LED; // Enable output driver for pin
  *PIO_PER = GREEN_LED; // Enable control of I/O pin from PIO Controller
	*PIO_OER = GREEN_LED; // Enable output driver for pin
  while (1) {
    *PIO_CODR = RED_LED;
    *PIO_SODR = AMBER_LED;
    *PIO_SODR = GREEN_LED;
  }
}
