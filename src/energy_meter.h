/*
 * -------------------------------------------------------------------
 * EmonESP Serial to Emoncms gateway
 * -------------------------------------------------------------------
 * Modified to use with the CircuitSetup.us energy meters by jdeglavina
 * All adaptation GNU General Public License as below.
 *
 * -------------------------------------------------------------------
 *
 * This file is part of OpenEnergyMonitor.org project.
 * EmonESP is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * EmonESP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with EmonESP; see the file COPYING.  If not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef _ENERGY_METER
#define _ENERGY_METER

// for ATM90E32 energy meter
#include <SPI.h>
#include <ATM90E32.h>

//#define ENABLE_OLED_DISPLAY

#ifdef ENABLE_OLED_DISPLAY
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_DC     0
#define OLED_CS     16
#define OLED_RESET  17
#endif

/*
    Uncomment if using the solar meter adapter board
*/
//#define SOLAR_METER

/*
    Uncomment to send metering values to EmonCMS, like Fundamental, Harmonic, Reactive, Apparent Power, and Phase Angle
*/
//#define EXPORT_METERING_VALS

/*******************************************************************************
   The following calibration values can be set here or in the EmonESP interface
   EmonESP values take priority if they are set
********************************************************************************/

/*
   4485 for 60 Hz (North America)
   389 for 50 hz (rest of the world)
*/
#define LINE_FREQ 4485

/*
 * 0 for 1x (CTs up to 60mA/720mV)
 * 21 for 2x (CTs up to 30mA/360mV)
 * 42 for 4x (CTs up to 15mA/180mV)
*/
#define PGA_GAIN 0

/*
   For meter <= v1.3:
      42080 - 9v AC Transformer - Jameco 112336
      32428 - 12v AC Transformer - Jameco 167151
   For meter = v1.4:
      37106 - 9v AC Transformer - Jameco 157041
      38302 - 9v AC Transformer - Jameco 112336
      29462 - 12v AC Transformer - Jameco 167151
   For Meters >= v1.4 rev.3
      3920 - 9v AC Transformer - Jameco 157041 - default
*/
#define VOLTAGE_GAIN 3920

/*
   10170 - SCT-006 20A/25mA
   39571 - SCT-010 80A/26.6mA
   25498 - SCT-013-000 100A/50mA
   39473 - SCT-016 120A/40mA - default
   46539 - Magnalab 100A
   26315 - SCT-024 200A/100mA 
*/
#define CURRENT_GAIN_CT1 39473
#define CURRENT_GAIN_CT2 39473

#ifdef SOLAR_METER
#define VOLTAGE_GAIN_SOLAR 3920
#define SOLAR_GAIN_CT1 39473
#define SOLAR_GAIN_CT2 39473
#endif

extern void energy_meter_setup();
extern void energy_meter_loop();

#endif
