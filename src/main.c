
/*
    TesteSerial
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

    main.c: Main application
*/

#include <stddef.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "config.h"
#include "debug.h"
#include "uart.h"

void init(void) {
  board_init();
  debug_init();
  uart_init();

  sei();

}


int main(void) __attribute__((OS_main));
//int  __attribute__ ((noreturn)) main(void);
int main(void) {
  uint16_t len;

  init();

  uart_puts_P(PSTR("\r\n" TOSTRING(CONFIG_HARDWARE_NAME) " Version: " VERSION));
  uart_putcrlf();

  while (TRUE) {
    len = uart_data_available();
    if(len) {
      uart_putc('|');
      uart_puthex((len & 0xff00) >> 8);
      uart_puthex(len & 0xff);
      uart_putc('|');
    }
    for(uint8_t i = 0; i < len; i++) {
      uart_putc(uart_getc());
    }

  }
}
