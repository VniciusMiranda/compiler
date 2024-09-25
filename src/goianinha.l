
%{
    #include "keywords.h"
    #include "errors.h"
    #include "types.h"
    #include "operations.h"
%}

DIGIT           [0-9]
WHITESPACE      [\t\n\r' ']

%%

"programa"                          { return KEYWORD_PROGRAMA; }
"car"                               { return KEYWORD_CAR; }
"int"                               { return KEYWORD_INT; }
"retorne"                           { return KEYWORD_RETORNE; }
"leia"                              { return KEYWORD_LEIA; }
"escreva"                           { return KEYWORD_ESCREVA; }
"novalinha"                         { return KEYWORD_NOVALINHA; }
"se"                                { return KEYWORD_SE; }
"entao"                             { return KEYWORD_ENTAO; }
"senao"                             { return KEYWORD_SENAO; }
"enquanto"                          { return KEYWORD_ENQUANTO; }
"execute"                           { return KEYWORD_EXECUTE; }

"ou"    { return OR; }
"e"     { return AND; }

"+"     { return ADDITION; }
"-"     { return SUBTRACTION; }
"*"     { return MULTIPLICATION; }
"/"     { return DIVISION; }
"=="    { return EQUALITY; }
"!="    { return DIFFERENCE; }
">="    { return GREATER_THAN_EQUALITY; }
"<="    { return LESS_THAN_EQUALITY; }
">"     { return GREATER_THAN; }
"<"     { return LESS_THAN; }

"="     { return ATTRIBUTION; }

","     { return VIRGULA; }
"{"     { return ABRE_CHAVES; }
"}"     { return FECHA_CHAVES; }
";"     { return PONTO_VIRGULA; }
"("     { return ABRE_PARENTESES; }
")"     { return FECHA_PARENTESES; }



{WHITESPACE}+                       { /* clear whitespaces */ }

[a-zA-Z_][0-9a-zA-Z_]*              { return IDENTIFIER; }

[+-]?{DIGIT}+                       { return TYPE_INT; }

\"([^"\\\n]|\\.)*\"                 { return TYPE_STRING; }
\"([^"]|\\.)*\"                     { return ERROR_MULTILINE_STRING; }
\"                                  { return ERROR_UNCLOSED_STRING; }

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] { /* ignore valid comment */ }
"\/\*"                              { return ERROR_UNCLOSED_COMMENT; }
"\*\/"                              { return ERROR_UNCLOSED_COMMENT; }



. { return ERROR_INVALID_CHARACTER; }

%%

int yywrap() {
    return 1;
}