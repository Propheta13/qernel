/*
 * Qernel project by Sergey Kovba (propheta13@gmail.com) 2013.
 *
 * Qernel is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Qernel is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Qernel.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "kprint.h"

#include <stdarg.h> /* For va_list and related routines */
#include "memroutines/memroutines.h"
#include "utility/vsprintf.h"

#include "cortex_a9.h"

volatile unsigned int * const UART0DR = (unsigned int *)UART0; //Make changable

static void print_uart(const char *s) {
    while(*s != '\0') { /* Loop until end of string */
        *UART0DR = (unsigned int)(*s); /* Transmit char */
        s++; /* Next char */
    }
}

unsigned long record_num = 0;

#define PRINTF_MAX_SIZE 1024

static int32_t printf_args(const char *fmt, va_list args)
{
    int8_t buf[PRINTF_MAX_SIZE] = {0};
    uint32_t uiSize = 0;

    uiSize += vsprintf(buf, fmt, args);
    print_uart((const char *)buf);

    return uiSize;
}

static int32_t printf(const char *fmt, ...)
{
    va_list args;
    int32_t uiSize = 0;

    va_start(args, fmt);
    uiSize = printf_args(fmt,args);
    va_end(args);

    return uiSize;
}

/* Print routines. */
static void print_recnum(void)
{
    record_num++;
    printf("[%6lu] ", record_num);
}

int32_t kprint(const char *format, ...)
{
    va_list args;
    uint32_t size = 0;

    print_recnum();

    va_start(args, format);
    size += printf_args(format, args);
    va_end(args);

    size += printf("\n");
    return size;
}

int32_t kblob(uint8_t *pArray, uint32_t uiSize, uint8_t uLine)
{
    uint32_t i = 0;

    print_recnum(); /* Record number */
    for(i = 0; i< uiSize; i++)
    {
        if(((i%uLine) == 0) && (i != 0))
            printf("\n[      ] ");

        printf("%02x ", pArray[i]);
    }

    printf("\n");

    return uiSize;
}
