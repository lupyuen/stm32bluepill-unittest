#include <logger.h>

double x = 123;
double y = 456;
double r;

int main(void)
{	
	enable_log();          //  Enable logging via Arm Semihosting. Note: ST Link must be connected or this line will hang.
	debug_println("Starting..."); debug_force_flush();

	r = x * y;             //  r = 123 * 456
	debug_print_float(r);  //  Print the value of 123 * 456.

	debug_println("");
	debug_force_flush();   //  Flush the debug buffer before we halt.
	for (;;) {}            //  Loop forever.
}

//  double-precision multiplication
double __wrap___aeabi_dmul(double x, double y) { 
    return 123456; 
}
