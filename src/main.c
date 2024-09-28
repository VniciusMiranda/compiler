/* Created by vinicius on 9/22/24. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "errors.h"
#include "types.h"
#include "keywords.h"
#include "operations.h"

extern int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;

const char *print_only_errors_str = "--print-only-errors";
bool print_only_errors = false;

void handle_args(int argc, char *argv[]);
void process_test_file(char *filename);
const char *get_token_name(int token);


int main(int argc, char *argv[])
{
	handle_args(argc, argv);
	process_test_file(argv[1]);
	return 0;
}


void handle_args(int argc, char *argv[])
{
	if (argc < 2 || argc > 3 || strcmp(argv[1], "--help") == 0 || (
		    argc == 3 && strcmp(argv[2], print_only_errors_str) != 0)) {
		printf(
			"Uso correto: executável arquivo_de_teste(required) %s(optional)\n",
			print_only_errors_str);
		exit(1);
	}
	if (access(argv[1], F_OK) != 0) {
		printf("O arquivo \"%s\" nao existe\n", argv[1]);
		exit(1);
	}
	if (argc == 3 && strcmp(argv[2], print_only_errors_str) == 0) {
		print_only_errors = true;
	}
}


void process_test_file(char *filename)
{
	yyin = fopen(filename, "r");
	int token = yylex();
	while (token) {
		if (is_error(token)) {
			handle_error(token, yytext, yylineno);
			token = yylex();
			continue;
		}
		if (!print_only_errors) {
			printf(
				"Encontrado o lexema %s pertencente ao token de código %d nome %s linha %d\n",
				yytext, token, get_token_name(token), yylineno);
		}
		token = yylex();
	}
}


const char *get_token_name(int token)
{
	switch (token) {
	case IDENTIFIER:
		return "IDENTIFIER";

	/* KEYWORD ENUM */
	case KEYWORD_PROGRAMA:
		return "KEYWORD_PROGRAMA";
	case KEYWORD_CAR:
		return "KEYWORD_CAR";
	case KEYWORD_INT:
		return "KEYWORD_INT";
	case KEYWORD_RETORNE:
		return "KEYWORD_RETORNE";
	case KEYWORD_LEIA:
		return "KEYWORD_LEIA";
	case KEYWORD_ESCREVA:
		return "KEYWORD_ESCREVA";
	case KEYWORD_NOVALINHA:
		return "KEYWORD_NOVALINHA";
	case KEYWORD_SE:
		return "KEYWORD_SE";
	case KEYWORD_ENTAO:
		return "KEYWORD_ENTAO";
	case KEYWORD_SENAO:
		return "KEYWORD_SENAO";
	case KEYWORD_ENQUANTO:
		return "KEYWORD_ENQUANTO";
	case KEYWORD_EXECUTE:
		return "KEYWORD_EXECUTE";

	/* ERROR ENUM */
	case ERROR_INVALID_CHARACTER:
		return "ERROR_INVALID_CHARACTER";
	case ERROR_UNCLOSED_COMMENT:
		return "ERROR_UNCLOSED_COMMENT";
	case ERROR_UNCLOSED_STRING:
		return "ERROR_UNCLOSED_STRING";
	case ERROR_MULTILINE_STRING:
		return "ERROR_MULTILINE_STRING";

	/* TYPE ENUM */
	case TYPE_STRING:
		return "TYPE_STRING";
	case TYPE_INT:
		return "TYPE_INT";

	/* CHARS ENUM */
	case VIRGULA:
		return "VIRGULA";
	case ABRE_CHAVES:
		return "ABRE_CHAVES";
	case FECHA_CHAVES:
		return "FECHA_CHAVES";
	case PONTO_VIRGULA:
		return "PONTO_VIRGULA";
	case ABRE_PARENTESES:
		return "ABRE_PARENTESES";
	case FECHA_PARENTESES:
		return "FECHA_PARENTESES";

	/* OPERATIONS ENUM */
	case ADDITION:
		return "ADDITION";
	case SUBTRACTION:
		return "SUBTRACTION";
	case MULTIPLICATION:
		return "MULTIPLICATION";
	case DIVISION:
		return "DIVISION";
	case ATTRIBUTION:
		return "ATTRIBUTION";
	case GREATER_THAN:
		return "GREATER_THAN";
	case LESS_THAN:
		return "LESS_THAN";
	case EQUALITY:
		return "EQUALITY";
	case DIFFERENCE:
		return "DIFFERENCE";
	case GREATER_THAN_EQUALITY:
		return "GREATER_THAN_EQUALITY";
	case LESS_THAN_EQUALITY:
		return "LESS_THAN_EQUALITY";
	case OR:
		return "OR";
	case AND:
		return "AND";
	default:
		return "TOKEN UNKNOWN";
	}
}