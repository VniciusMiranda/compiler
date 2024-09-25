/* Created by vinicius on 9/24/24. */

#include "errors.h"

void handle_error(error_t error, char *text, int line)
{
	switch (error) {
	case ERROR_INVALID_CHARACTER:
		printf("ERROR: CARACTERE INVÁLIDO '%s' Linha: %d\n", text,
		       line);
		break;
	case ERROR_UNCLOSED_COMMENT:
		printf("ERROR: COMENTÁRIO NÃO TERMINA Linha: %d\n", line);
		break;
	case ERROR_UNCLOSED_STRING:
		printf("ERROR: CADEIA DE CARACTERES NÃO TERMINA Linha: %d\n",
		       line);
		break;
	case ERROR_MULTILINE_STRING:
		printf(
			"ERROR: CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA Linha: %d\n",
			line);
		break;
	}
}

bool is_error(int token)
{
	return token < 0;
}