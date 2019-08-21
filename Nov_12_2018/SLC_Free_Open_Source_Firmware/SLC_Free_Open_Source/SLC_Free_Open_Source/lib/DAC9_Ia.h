//*****************************************************************************
//*****************************************************************************
//  FILENAME: DAC9_Ia.h
//   Version: 2.2, Updated on 2015/3/4 at 22:25:15
//  Generated by PSoC Designer 5.4.3191
//
//  DESCRIPTION: DAC9 User Module C Language interface file.
//
//-----------------------------------------------------------------------------
//      Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef DAC9_Ia_INCLUDE
#define DAC9_Ia_INCLUDE

#include <m8c.h>

//-------------------------------------------------
// Defines for DAC9_Ia API's.
//-------------------------------------------------
// Power Setting Defines
#define DAC9_Ia_OFF                 0
#define DAC9_Ia_LOWPOWER            1
#define DAC9_Ia_MEDPOWER            2
#define DAC9_Ia_HIGHPOWER           3
#define DAC9_Ia_FULLPOWER           3

// Define constants for declaring function prototypes based on DataFormat parameter
#define DAC9_Ia_OffsetBinary            0x04
#define DAC9_Ia_TwosComplement          0x02
#define DAC9_Ia_SignAndMagnitude        0x01
#define DAC9_Ia_RawRegister             0x00
#define DAC9_Ia_DATAFORMAT          0x7
#define DAC9_Ia_OFFSETBINARY        DAC9_Ia_DATAFORMAT & DAC9_Ia_OffsetBinary
#define DAC9_Ia_TWOSCOMPLEMENT      DAC9_Ia_DATAFORMAT & DAC9_Ia_TwosComplement
#define DAC9_Ia_SIGNANDMAGNITUDE    DAC9_Ia_DATAFORMAT & DAC9_Ia_SignAndMagnitude

// Declare function fastcall16 pragmas
#pragma fastcall16 DAC9_Ia_Start
#pragma fastcall16 DAC9_Ia_SetPower
#pragma fastcall16 DAC9_Ia_Stop

//-------------------------------------------------
// Prototypes of the DAC9_Ia API.
//-------------------------------------------------
extern void  DAC9_Ia_Start(BYTE bPowerSetting);
extern void  DAC9_Ia_SetPower(BYTE bPowerSetting);
extern void  DAC9_Ia_Stop(void);

// Declare overloaded functions based on DataForamt parameter selected
#if DAC9_Ia_OFFSETBINARY
   #pragma fastcall16 DAC9_Ia_WriteBlind
   #pragma fastcall16 DAC9_Ia_WriteStall
   extern void  DAC9_Ia_WriteBlind(WORD wOutputValue);
   extern void  DAC9_Ia_WriteStall(WORD wOutputValue);
#else
   #if DAC9_Ia_TWOSCOMPLEMENT
      #pragma fastcall16 DAC9_Ia_WriteBlind
      #pragma fastcall16 DAC9_Ia_WriteStall
      extern void  DAC9_Ia_WriteBlind(INT iOutputValue);
      extern void  DAC9_Ia_WriteStall(INT iOutputValue);
   #else    //DAC9_Ia_SIGNANDMAGNITUDE
      #pragma fastcall16 DAC9_Ia_WriteBlind2B
      #pragma fastcall16 DAC9_Ia_WriteStall2B
      extern void  DAC9_Ia_WriteBlind2B(BYTE bLSB, BYTE bMSB);
      extern void  DAC9_Ia_WriteStall2B(BYTE bLSB, BYTE bMSB);
   #endif
#endif

//-------------------------------------------------
// Hardware Addresses for DAC9_Ia
//-------------------------------------------------

#pragma ioport  DAC9_Ia_LSB_CR0:    0x090                  // LSB Analog control register 0
BYTE            DAC9_Ia_LSB_CR0;
#pragma ioport  DAC9_Ia_LSB_CR1:    0x091                  // LSB Analog control register 1
BYTE            DAC9_Ia_LSB_CR1;
#pragma ioport  DAC9_Ia_LSB_CR2:    0x092                  // LSB Analog control register 2
BYTE            DAC9_Ia_LSB_CR2;
#pragma ioport  DAC9_Ia_LSB_CR3:    0x093                  // LSB Analog control register 3
BYTE            DAC9_Ia_LSB_CR3;

#pragma ioport  DAC9_Ia_MSB_CR0:    0x094                  // MSB Analog control register 0
BYTE            DAC9_Ia_MSB_CR0;
#pragma ioport  DAC9_Ia_MSB_CR1:    0x095                  // MSB Analog control register 1
BYTE            DAC9_Ia_MSB_CR1;
#pragma ioport  DAC9_Ia_MSB_CR2:    0x096                  // MSB Analog control register 2
BYTE            DAC9_Ia_MSB_CR2;
#pragma ioport  DAC9_Ia_MSB_CR3:    0x097                  // MSB Analog control register 3
BYTE            DAC9_Ia_MSB_CR3;

#endif
// end of file DAC9_Ia.h
