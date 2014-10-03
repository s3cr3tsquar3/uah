/***********************************************
 * General Notes for C programming on MSP430
 ***********************************************
 * 
 *	TI Experimentor Board
 *	.----._.-----.
 *	|MSP430xG461x|
 *	|            |
 *	|        RST |-->
 *	|            |
 *	|       P1.0 |-->SW1 (labeled)
 *	|       P1.1 |-->SW2 (labeled)
 *	|            |
 *	|       P2.2 |-->LED1 (GREEN)
 *	|       P2.1 |-->LED2 (YELLOW)
 *	.____.-._____.
 * 
 *	TI Launchpad
 *	.---._.-----.
 *	|MSP430G2231|
 *	|           |
 *	|       RST |-->
 *	|           |
 *	|      P1.0 |-->SW1 (labeled)
 *	|           |
 *	|      P2.2 |-->LED1 (GREEN)
 *	.___.-._____.
 * 
 * Ideas:
 *	- Create project which expoits the ~90ms brain delay
 *	- Control a servo with a potentiometer
 * 
 * 
 * C Programming Points:
 * - Make sure to encapsulate comparisons with () when using && + ||
 * - 'volatile' variables are ones which are changed outside the scope of the program.
 * 		These vars are kept in registers, and defeat a lot of optimizations.
 * - && and || are boolean operators, meaning they operate on a value (A = 1001) as a whole.
 * 	- &(AND), |(OR), ^(XOR), ~(NOT) are bitwise operators, meaning they operate on each bit of a value. (B = 1010) A & B = 1000.
 * - BIT0 - BIT7 are bit masks, with zeros everywhere except the specified location. BIT3 = 00001000.
 * - 
 * 
 * MSP Specific Things:
 * 
 * Timer_A:
 * 	- TACLK: clock input to the timer
 * 	- TA0 and TA1: either inputs or outputs
 * 	- TACTL: Timer_A Control
 * 	- 
 * 
 * 
 * IAR Bullshit (aka setup configs):
 * - Create a project, open the options window
 * - General Options:
 * 	- TARGET tab: Set device to MSP430FG4618
 * 	- OUTPUT tab: Output file set to EXECUTABLE
 * 	- LIBRARY CONFIGURATION tab: LIBRARY set to NONE (ASM) or NORMAL DLIB (C)
 * - C COMPILER:
 * 	- OPTIMIZATIONS tab: LEVEL set to NONE
 * 	- OUTPUT tab: GENERATE DEBUG INFORMATION
 * 	- LIST tab: OUTPUT LIST FILE and ASSEMBLER MNEMONICS checked
 * - Assembler:
 * 	- LIST tab: OUTPUT LIST FILE checked
 * - LINKER:
 * 	- OUTPUT tab: DEBUG INFORMATION FOR CSPY and RUNTIME CONTROL MODULES and I/O EMULATION checked
 * 	- LIST tab: GENERATE LINKER LISTING and SEGMENT MAP and MODULE MAP
 * - debugger:
 * 	- SETUP tab: DRIVER set to SIMULATION
 * 
 * Naming Conventions:
 * - MSP: Mixed Signal Processor
 * - The letter after msp430 indicates type of memory.
 * 	- F: Flash memory
 * 	- C: ROM
 * - A second letter shows the type of intended measurement:
 * 	- E: Electricity
 * 	- W: Water
 * 	- G: Signals (which require a gain stage by an op amp?)
 * - The next digit indicates family, and the final two or three detail the specific device
 * 	- MSP430x1xx: General Purpose
 * 	- MSP430F2xx: Newer, general purpose line (2005). Runs at 16Mhz, uses less power. Comes in DIP packages!
 * 	- MSP430x3xx: Original family, obsolete.
 * 	- MSP430x4xx: Can drive LCDs, has a lot of pins usually.
 * 	- MSP430X: Original architecture. A part of the F2xx and F4xx lines.
 * 
 * Lab devices (from the naming convention):
 * - MSP430FG4618: Flash memory, signal processing, can drive LCDs and has many pins.
 * - MSP430G2231: Unknown memory? Signal processing.
 * 
 * Registers (in all msp devices):
 * - R0 / Program Counter / PC: Holds address of the next instruction.
 * - R1 / Stack Pointer / SP: Holds address of top of stack.
 * - R2 / Status Register / SR: Contains status flags.
 * - R3 / Constant Generator: Provides the six most frequently used values from RAM?
 * - R4 - R15: General Purpose Registers
 * 
 * Clocks (in all msp devices):
 * - Master Clock [MCLK]
 * - Subsystem Master Clock [SMCLK}
 * - Auxiliary Clock [ACLK]
 * 
 */






























