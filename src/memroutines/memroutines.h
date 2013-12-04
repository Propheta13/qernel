#ifndef _MEMROUTINES_H_
#define _MEMROUTINES_H_

/**
 * @fn    int memcmp(const void *ptr1, const void *ptr2, unsigned int num)
 * @brief Compares the first num bytes of the block of memory pointed by ptr1 to the first num bytes pointed by ptr2
 * @param [in] ptr1 Pointer to block of memory
 * @param [in] ptr2 Pointer to block of memory
 * @param [in] num Number of bytes to compare
 * @return Returns an integral value indicating the relationship between the content of the memory blocks
 *          0 if blocks are equal
 */
extern int memcmp(const void *ptr1, const void *ptr2, unsigned int num);

/**
 * @fn    void* memset ( void *ptr, int value, unsigned int num )
 * @brief Sets the first num bytes of the block of memory pointed by ptr to the specified value
 * @param [in] ptr Pointer to the block of memory to fill
 * @param [in] value Value to be set
 * @param [in] num Number of bytes to be set to the value
 * @return ptr is returned
 */
extern void *memset ( void *ptr, int value, unsigned int num );

/**
 * @fn    void* memcpy(void *destination, const void *source, unsigned int num)
 * @brief Copies the values of num bytes from the location pointed by source directly to the memory block pointed by destination
 * @param [in] destination Pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*
 * @param [in] source Pointer to the source of data to be copied, type-casted to a pointer of type void*
 * @param [in] num Number of bytes to copy
 * @return destination is returned
 */
extern void *memcpy(void *destination, const void *source, unsigned int num);

/**
 * @fn    int strcmp(const char * str1, const char * str2)
 * @brief Compares the C string str1 to the C string str2
 * @param [in] str1 C string to be compared
 * @param [in] str2 C string to be compared
 * @return Returns an integral value indicating the relationship between the strings
 */
extern int strcmp(const char *str1, const char *str2);

/**
 * @fn    char* strcpy(char * destination, const char * source)
 * @brief Copies the C string pointed by source into the array pointed by destination, including the terminating null character
 * @param [in] destination Pointer to the destination array where the content is to be copied
 * @param [in] source C string to be copied
 * @return destination is returned
 */
extern char* strcpy(char *destination, const char *source);

#endif /* _MEMROUTINES_H_ */
