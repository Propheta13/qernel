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

#ifndef TYPES
#define TYPES

#ifndef _LINUX_TYPES_H

#ifndef int8_t
typedef char int8_t;
#endif /* int8_t */

#ifndef int16_t
typedef short int int16_t;
#endif /* int16_t */

#ifndef int32_t
typedef int int32_t;
#endif /* int32_t */

#ifndef uint8_t
typedef unsigned char uint8_t;
#endif /* uint8_t */

#ifndef uint16_t
typedef unsigned short int uint16_t;
#endif /* uint16_t */

#ifndef uint32_t
typedef unsigned int uint32_t;
#endif /* uint32_t */

#ifndef uint64_t
typedef unsigned long long uint64_t;
#endif /* uint64_t */

#ifndef __STDDEF_H__
#ifndef _STDLIB_H
#ifndef size_t
typedef unsigned int size_t;
#endif /* size_t */
#endif /* _STDLIB_H */
#endif /* __STDDEF_H__ */

#endif /* _LINUX_TYPES_H */

#ifndef uint128_t
typedef struct { uint64_t hi,lo; } uint128_t;
#endif /* uint128_t */

#ifndef NULL
#define NULL (void *)0
#endif /* NULL */

#endif /* TYPES */
