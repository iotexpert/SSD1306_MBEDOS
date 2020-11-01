
#include "mbed.h"
#include "GUI.h"
#include "i2c_portapi.h"
extern const unsigned char _acBW94x64[898UL + 1];

int main()
{
    /* Initialize emWin GUI */
    GUI_Init();

#if 1
    char verticalExample[]= {
            0xAE,
            0x20, /// address mode
            0x01, //  vertical
            0xA4,
            0xAF,
            0x22, //Set page address range
            0,
            7,
            0x21, // column start and end address
            0,
            127,
    };

    I2C_WriteCmdStream(verticalExample, sizeof(verticalExample));
    // Write twelve bytes onto screen with 0b10101010
    for(int i=0;i<12;i++)
        I2C_WriteData(0xAA); 

    char readSetup[] = {
            0x22, //Set page address range
            0,
            7,
            0x21, // column start and end address
            0,
            127,
    };
   I2C_WriteCmdStream(readSetup, sizeof(readSetup));
   char buffer[12];
   printf("Calling read\n");
   I2C_ReadM01((unsigned char *)buffer,sizeof(buffer));
   
#endif

#if 0
    char horizontalExample[]= {
            0xAE,
            0x20, /// address mode
            0x00, // Horizontal
            0xA4,
            0xAF,
            0x22, //Set page address range
            0,
            7,
            0x21, // column start and end address
            0,
            127,
    };

    I2C_WriteCmdStream(horizontalExample, sizeof(horizontalExample));
    // Write twelve bytes onto screen with 0b10101010
    for(int i=0;i<12;i++)
        I2C_WriteData(0xAA); 

#endif


#if 0
    char pageExample[]= {
            0xAE,
            0x20, // address mode
            0x02, // Page mode
            0xA4, // Resume from ram
            0xAF, // Screen on
            0xB0, // Start from page 0
            // Start from column 0x78 aka 120
            0x08, // Column lower nibble address
            0x17  // Column upper nibble address
    };

    I2C_WriteCmdStream(pageExample, sizeof(pageExample));

    // Write twelve bytes onto screen with 0b10101010
    for(int i=0;i<12;i++)
        I2C_WriteData(0xAA); 

#endif
 
    GUI_BMP_Draw(_acBW94x64, 17,0); // the bitmap is 94 wide so (128-94)/2

    while(1);

}
