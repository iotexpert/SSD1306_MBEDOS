
#include "mbed.h"
#include "GUI.h"
#include "i2c_portapi.h"
extern const unsigned char _acBW94x64[898UL + 1];

int main()
{
    /* Initialize emWin GUI */
    GUI_Init();
 
    GUI_BMP_Draw(_acBW94x64, 17,0); // the bitmap is 94 wide so (128-94)/2

    while(1);

}
