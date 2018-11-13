typedef volatile unsigned int ioreg;

#define	PIO_PER		(ioreg *) 0xfffff400	// PIO Enable Registe
#define	PIO_OER	  	(ioreg *) 0xfffff410	// Output Enable Register
#define	PIO_SODR  	(ioreg *) 0xfffff430	// Set Output Data Register
#define	PIO_CODR  	(ioreg *) 0xfffff434	// Clear Output Data Register
#define STEPPER_MOTOR_MOVE		(1 << 0)
#define DELAY 		0x00010000	// Long enough to see a change in LED

void delay(int);

int main(void)
{
	*PIO_PER = STEPPER_MOTOR_MOVE; // Enable control of I/O pin from PIO Controller
	*PIO_OER = STEPPER_MOTOR_MOVE; // Enable output driver for pin

// NOTE: sodr is off codr is on
// 96 ticks is one rotation
  int i;
	for(i = 0; i <= 96 ; i++){
    *PIO_CODR = STEPPER_MOTOR_MOVE;
    delay(DELAY);
    *PIO_SODR = STEPPER_MOTOR_MOVE;
    delay(DELAY);
	}
}

void delay(int count)
{
	register int i;
	for (i=count;i>0;i--)
       		;
}
