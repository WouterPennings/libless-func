#include "print.h"
#include <unistd.h>

void print_i32(int input) {
    int is_neg = 0;
    if(input < 0) {
        input += input*-2; // Makes positive integer of negative integer
        is_neg = 1;
    }

    char buffer[32];
    int buffer_sz = 1;
    buffer[sizeof(buffer) - buffer_sz] = '\n'; // Places an '\n' at and if the array

    // Integer to array of chars
    // Fills 'buffer' from back to front, so you do not need to reverse the array
    do {
        buffer[sizeof(buffer) - buffer_sz - 1] = input % 10 + '0'; // Converts an integer to char
        buffer_sz++;
        input = input / 10;
    } while(input);

    // If 'input' is negative, add a '-' before the place where the elements starts
    if(is_neg) {
        buffer[sizeof(buffer) - buffer_sz - 1] = '-';\
        buffer_sz++;
    }

    // Linux syscall 
    // '&buffer[sizeof(buffer) - buffer_sz]', returns pointer of begining of chacacters in array.
    write(1, &buffer[sizeof(buffer) - buffer_sz], buffer_sz);
}

void print_f32(float input) {
    int is_neg = 0;
    if (input < 0){
        input += input*-2;
        is_neg = 1;
    }   

    int num = (int)input;
    int dec_num = (int)((input - num) * 1000000);
    while(dec_num % 10 + '0' == '0') dec_num /= 10;

    char buffer[32];
    int buffer_sz = 1;
    buffer[sizeof(buffer) - buffer_sz] = '\n'; // Places an '\n' at and if the array

    // Integer to array of chars
    // Fills 'buffer' from back to front with the decimals, so you do not need to reverse the array
    do {
        buffer[sizeof(buffer) - buffer_sz - 1] = dec_num % 10 + '0'; // Converts an integer to char
        buffer_sz++;
        dec_num = dec_num / 10;
    } while(dec_num);

    // Dot in the middle between the decimals and the 'normal' numbers
    buffer_sz++;
    buffer[sizeof(buffer) - buffer_sz] = '.';

    // Integer to array of chars
    // Fills 'buffer' from back to front, so you do not need to reverse the array
    do {
        buffer[sizeof(buffer) - buffer_sz - 1] = num % 10 + '0'; // Converts an integer to char
        buffer_sz++;
        num = num / 10;
    } while(num);

    // If 'input' is negative, add a '-' before the place where the elements starts
    if(is_neg) {
        buffer[sizeof(buffer) - buffer_sz - 1] = '-';\
        buffer_sz++;
    }

    // Linux syscall 
    // '&buffer[sizeof(buffer) - buffer_sz]', returns pointer of begining of chacacters in array.
    write(1, &buffer[sizeof(buffer) - buffer_sz], buffer_sz);
}