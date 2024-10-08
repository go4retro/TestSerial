// autoconf.h generated from config at Mon Aug 26 20:41:09 CDT 2024
#ifndef AUTOCONF_H
#define AUTOCONF_H
// This may not look like it, but it's a -*- makefile -*-
//
// GROMmet - TI GROM Replacement
// Copyright (C) 2024  Jim Brain <brain@jbrain.com>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; version 2 of the License only.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// config: User-configurable options to simplify hardware changes and/or
//         reduce the code/ram requirements of the code.
//
//
// This file is included in the main Makefile and also parsed
// into autoconf.h.
// This system based on sd2iec Makefile by Ingo Korb


// MCU to compile for
#define CONFIG_MCU atmega328p

// Use the -relax parameter when linking?
// Passing -O9 and -relax to the linker saves ~650 bytes of flash,
// but the option is broken in certain binutils versions.
// (known troublemakers: binutils 2.17, 2.18 seems fine)
#define CONFIG_LINKER_RELAX

// MCU frequency in Hz
#define CONFIG_MCU_FREQ 16000000

// Debug to serial
// CONFIG_UART_DEBUG=n
// CONFIG_UART_DEBUG_SW=n
#define CONFIG_UART_DEBUG_RATE 115200
#define CONFIG_UART_DEBUG_FLUSH

// Initial Baud rate of the UART
#define CONFIG_UART_BAUDRATE 300
#define CONFIG_UART_BUF_SHIFT 8

// Select which hardware to compile for
// Valid values:
//   1 - v1 board
#define CONFIG_HARDWARE_VARIANT 1
#define CONFIG_AVRDUDE_PROGRAMMER arduino
#define CONFIG_AVRDUDE_PORT COM3


// Track the stack size
// Warning: This option increases the code size a lot.
// CONFIG_STACK_TRACKING=n

#define CONFIG_EFUSE 0xf9
#define CONFIG_HFUSE 0xdf
#define CONFIG_LFUSE 0xff

#define CONFIG_HARDWARE_NAME TestSerial
#endif
