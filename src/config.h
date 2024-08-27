/*
    HEXTIr-SD - Texas Instruments HEX-BUS SD Mass Storage Device
    Copyright Jim Brain and RETRO Innovations, 2017

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License only.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    config.h: User-configurable options to simplify hardware changes and/or
              reduce the code/ram requirements of the code.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "version.h"

/* Boolean type */
typedef enum { FALSE = 0, TRUE } BOOL;

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#ifdef VER_PATCH
#ifdef VER_FIX
  #define VER_TEXT           TOSTRING(VER_MAJOR) "." TOSTRING(VER_MINOR) "." TOSTRING(VER_PATCH) "." TOSTRING(VER_FIX)
#else
  #define VER_TEXT           TOSTRING(VER_MAJOR) "." TOSTRING(VER_MINOR) "." TOSTRING(VER_PATCH)
#endif
#else
  #define VER_TEXT           TOSTRING(VER_MAJOR) "." TOSTRING(VER_MINOR)
#endif
#ifdef VER_PRERELEASE
  #define VERSION "" VER_TEXT TOSTRING(VER_PRERELEASE) ""
#else
  #define VERSION "" VER_TEXT ""
#endif

#define FLASH_MEM_DATA  1

#include <avr/io.h>

#include "autoconf.h"

/* ----- Common definitions for all AVR hardware variants ------ */

#define UART_DOUBLE_SPEED


#if CONFIG_HARDWARE_VARIANT == 1
/* ---------- Hardware configuration: HEXTIr v1 ---------- */

static inline void board_init(void) {
}


#else
#  error "CONFIG_HARDWARE_VARIANT is unset or set to an unknown value."
#endif

/* ---------------- End of user-configurable options ---------------- */

#ifdef CONFIG_UART_DEBUG
#  define UART0_ENABLE
#  define DYNAMIC_UART
#  define UART0_BAUDRATE CONFIG_UART_DEBUG_RATE
#elif defined CONFIG_UART_BAUDRATE
#  define UART0_ENABLE
#  define UART0_BAUDRATE CONFIG_UART_BAUDRATE
#else
#  define UART0_ENABLE
#  define UART0_BAUDRATE 57600
#endif

#ifdef CONFIG_UART_BUF_SHIFT
 #define UART0_TX_BUFFER_SHIFT CONFIG_UART_BUF_SHIFT
 #define UART0_RX_BUFFER_SHIFT CONFIG_UART_BUF_SHIFT
#endif

#ifdef FLASH_MEM_DATA
#define MEM_CLASS PROGMEM
#define mem_read_byte(x) pgm_read_byte(&(x))
#define mem_read_word(x) pgm_read_word(&(x))
#else
#define MEM_CLASS
#define mem_read_byte(x) (x)
#define mem_read_word(x) (x)
#endif

#endif /*CONFIG_H*/
