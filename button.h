/*
 * button.h
 *
 * Created: 2/10/2018 7:32:46 PM
 *  Author: Mohamed Zaghlol
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
/*
Function Name        : button_vInit
Function Returns     : void
Function Arguments   : unsigned char portname,unsigned char pinnumber
Function Description : define the given pin in the given port as input pin
*/

void button_vInit(unsigned char portname,unsigned char pinnumber);
/*
Function Name        : button_u8read
Function Returns     : unsigned char
Function Arguments   : unsigned char portname,unsigned char pinnumber
Function Description : Returns 0 or 1 depend on the status of the button(pressed or not) and the type of connection (pull up or pull down)
*/

unsigned char button_u8read(unsigned char portname,unsigned char pinnumber);
#endif /* BUTTON_H_ */