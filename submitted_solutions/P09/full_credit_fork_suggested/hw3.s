.global sumS32                 // int32_t sumS32(const int32_t x[], int32_t count)
.global sumU32_64              // uint64_t sumU32_64(const uint32_t x[], uint32_t count)
.global countNegative          // uint32_t countNegative(const int32_t x[], uint32_t count)
.global leftStringFull         // void leftStringFull(char strOut[], const char strIn[], uint32_t length)
.global leftStringTrunc        // void leftStringTrunc(char strOut[], const char strIn[], uint32_t length)
.global countMatches           // uint32_t countMatches(const char strIn[], const char strMatch[])
.global find2ndMatch           // int32_t find2ndMatch(const char strIn[], const char strMatch[])
.global sortDecendingInPlace   // void sortDecendingInPlace (int32_t x[], uint32_t count)
.global decimalStringToInt8    // int8_t decimalStringToInt8(const char str[])
.global hexStringToUint32      // uint32_t hexStringToUint32(const char str[])
.global uint8ToBinaryString    // void uint8ToBinaryString (char str[], uint8_t x)
.global findStreet             // int32_t findStreet (char street[], const BUSINESS3 business[], uint32_t count)


// int32_t sumS32(const int32_t x[], int32_t count)
// R0 = return, R0 = int32_t x[], R1 = int32_t count
// returns sum of the values in the array (x) containing count entries, modulo 2^32.
// in other words, only the 32-bits of the sum are preserved, so the carry out is lost

sumS32:

// uint64_t sumU32_64(const uint32_t x[], uint32_t count)
// R0 = return, R0 = const uint32_t x[], R1 = uint32_t count
// returns the 64-bit sum of the values in the array (x) containing count entries

sumU32_64:

// uint32_t countNegative(const int32_t x[], uint32_t count)
// R0 = return, R0 = const int32_t x[], R1 = uint32_t count
// returns number of negative values in the array (x) containing count entries

countNegative:

// void leftStringFull(char strOut[], const char strIn[], uint32_t length)
// R0 = return, R0 = char strOut[], R1 = const char strIn[], R2 = uint32_t length
// input: array (strIn) containing the input string, and the number of characters to extract (length)
// output: array (strOut) containing length number of strIn characters from the start of the array or a null string if the length is too large

leftStringFull:

// void leftStringTrunc(char strOut[], const char strIn[], uint32_t length)
// R0 = return, R0 = char strOut[], R1 = const char strIn[], R2 = uint32_t length
// input: array (strIn) containing the input string, and the number of characters to extract (length)
// output: array (strOut) containing up to, but not exceeding length number of strIn characters from the start of the array

leftStringTrunc:

// uint32_t countMatches(const char strIn[], const char strMatch[])
// R0 = return, R0 = const char strIn[], R1 = const char strMatch[]
// input: array (strMatch) containing the string to match in the array (strIn)

// output: returns the number of occurences of strMatch in strIn
countMatches:

// int32_t find2ndMatch(const char strIn[], const char strMatch[])
// R0 = return, R0 = const char strIn[], R1 = const char strMatch[]
// input: array (strMatch) containing the string to find in the array (strIn)
// output: returns the offset within str of the 2nd occurrence of strMatch or -1 if not found

find2ndMatch:

// void sortDecendingInPlace (int32_t x[], uint32_t count)
// R0 = return, R0 = int32_t x[], R1 = uint32_t count
// input: array (x) containing count entries
// output: array (x), with the values sorted in descending order

sortDecendingInPlace:

// int8_t decimalStringToInt8(const char str[])
// R0 = return, R0 = const char str[]
// convert the null-terminated string (str) to a signed 8-bit integer
// treat the string as representing a decimal number
// if a character other than 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, or – is present, return 0

decimalStringToInt8:

// uint32_t hexStringToUint32(const char str[])
// R0 = return, R0 = const char str[]
// convert the null-terminated string (str) to an unsigned 32-bit integer
// treat the string as representing a hexadecimal number
// if a character other than 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, or F is present, return 0

hexStringToUint32:

// void uint8ToBinaryString (char str[], uint8_t x)
// R0 = return, R0 = char str[], R1 = uint8_t x
// convert the unsigned integer (x) to a null-terminated string (str) representing a binary number

uint8ToBinaryString:

// int32_t findStreet (char street[], const BUSINESS3 business[], uint32_t count)
// R0 = return, R0 = char street[], R1 = const BUSINESS3 business[], R2 = uint32_t count
// returns the index of the first entry in the array (business) containing count entries which matches the requested street. 
// If the name is not found, return avalue of -1.

findStreet: