/* Created by vinicius on 9/23/24. */

#ifndef ERRORS_H
#define ERRORS_H

#include <stdbool.h>
#include <stdio.h>

enum Error
{
    ERROR_INVALID_CHARACTER = -100,
    ERROR_UNCLOSED_COMMENT = -200,
    ERROR_UNCLOSED_STRING = -300,
    ERROR_MULTILINE_STRING = -400
};

typedef enum Error error_t;

void handle_error(error_t error, char* text, int line);

bool is_error(int token);

#endif /* ERRORS_H */
