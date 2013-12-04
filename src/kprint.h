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

#ifndef __KPRINT_H__
#define __KPRINT_H__

#include "types.h"

int32_t kprint(const char *format, ...);
int32_t kblob(uint8_t *pArray, uint32_t uiSize, uint8_t uLine);
void print_uart(const char *s);

#endif /* __KPRINT_H__ */
