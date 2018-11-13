typedef volatile unsigned int ioreg;

#define	PIO_PER		(ioreg *) 0xfffff400	// PIO Enable Registe
#define	PIO_OER	  	(ioreg *) 0xfffff410	// Output Enable Register
#define	PIO_SODR  	(ioreg *) 0xfffff430	// Set Output Data Register
#define	PIO_CODR  	(ioreg *) 0xfffff434	// Clear Output Data Register

#define RED_LED		0x00000004
#define DELAY 		0x00800000	// Long enough to see a change in LED

void delay(int);

int main(void)
{
	*PIO_PER = RED_LED; // Enable control of I/O pin from PIO Controller
	*PIO_OER = RED_LED; // Enable output driver for pin

	while (1) {
	      *PIO_SODR = RED_LED;
	      delay(DELAY);
	      *PIO_CODR = RED_LED;
	      delay(DELAY);
	}
}

void delay(int count)
{
	register int i;
	for (i=count;i>0;i--)
       		;
}
