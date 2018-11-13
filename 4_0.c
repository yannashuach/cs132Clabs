typedef volatile unsigned int ioreg;

#define	PIO_PER		(ioreg *) 0xfffff400	// PIO Enable Registe
#define	PIO_OER	  	(ioreg *) 0xfffff410	// Output Enable Register
#define	PIO_SODR  	(ioreg *) 0xfffff430	// Set Output Data Register
#define	PIO_CODR  	(ioreg *) 0xfffff434	// Clear Output Data Register

#define RED_LED		(1 << 2)
#define AMBER_LED		(1 << 3)
#define GREEN_LED		(1 << 4)
#define DELAY 		0x00800000	// Long enough to see a change in LED

void delay(int);

int main(void)
{
	*PIO_PER = RED_LED; // Enable control of I/O pin from PIO Controller
	*PIO_OER = RED_LED; // Enable output driver for pin
  *PIO_PER = AMBER_LED; // Enable control of I/O pin from PIO Controller
  *PIO_OER = AMBER_LED; // Enable output driver for pin
  *PIO_PER = GREEN_LED; // Enable control of I/O pin from PIO Controller
  *PIO_OER = GREEN_LED; // Enable output driver for pin

// NOTE: sodr is off codr is on
	while (1) {
        *PIO_CODR = RED_LED;
        *PIO_SODR = AMBER_LED;
        *PIO_SODR = GREEN_LED;
	      delay(DELAY);
	      *PIO_CODR = AMBER_LED;
	      delay(DELAY);
        *PIO_SODR = RED_LED;
        *PIO_SODR = AMBER_LED;
        *PIO_CODR = GREEN_LED;
        delay(DELAY);
        *PIO_CODR = AMBER_LED;
        *PIO_SODR = GREEN_LED;
        delay(DELAY);
	}
}

void delay(int count)
{
	register int i;
	for (i=count;i>0;i--)
       		;
}
