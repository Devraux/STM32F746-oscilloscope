#ifndef _DISPLAY_LIB_
#define _DISPLAY_LIB_


//*** This library is part of oscilloscope application based on stm32f746 embedded in STM32 Discovery board ***//
//*** These functions implement graphical features necessary to basic oscilloscope features ***//
//*** This library is dedicated to 272px x 480px display ***//

//*** Display Layout***//
/// _____________________________
///|          Top Bar            |
///|-----------------------------|
///|                     |       |
///|         Chart       |Buttons|
///|                     |       |
///|-----------------------------|
///|          Bottom Bar         |
///|_____________________________|


#include "main.h"
#include "lvgl.h"

///  Widget description: Plot current and past input signal sample's measured by ADC3.
///
///  Displayed features:
/// 					- Chart
///			  			- Grid
void display_chartWindow(void);


///  Widget description: right side buttons which allows to choose oscilloscope options
///
///  Displayed features:
/// 					- "Stop/Run"                Button
///						- "Place X/Y Cursor 1 | 2"  button
/// 					- "DC/AC Coupling"          button
/// 					- "Math functions"          button
///						- "More options"            button
void display_buttonsWindow(void);


///  Widget description: bottom bar measure
///
///  Displayed features:
/// 					- "VOLTS/DIV"                 label
///						- "TIME/DIV"                  label
/// 					- "X_Coordinate Cursor_1 | 2" label
/// 					- "Y_Coordinate Cursor_1 | 2" label
void display_bottomWindow(void);


///  Widget description: top bar additional informations
///
///  Displayed features:
/// 					- Time     label
///						- "Status" label
void display_topWindow(void);

#endif
