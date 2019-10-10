#include "../GPIO_CONFIG.h"
 
 int main (void)
 {
	 /****** Initialize GPIO Ports Here ******/
	 MY_MTS_GPIO_init();
	 
	 /****** Test Your GPIO Configuration Here ******/
	 while(1){
		PTC->PDOR = (PTD->PDIR << 8) 			//Shift SW inputs to the LT outputs
		| (0x1 << 4)							//Select EngineB
		| (0x3 <<16)							//Set Turnouts to inner loop
		| (0xF);								// Set sp to 7 and dir to forward
	 }
	 
	 
	 return 0;
 }
 