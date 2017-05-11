delim	[ \t\r]
ws	{delim}+
digito	[0-9]
num	{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
id [a-zA-Z_][a-zA-Z0-9_]*
literal \".*\"

%%
{ws}	{}
"+"	{return T_ADICAO;}
"-"	{return T_SUBTRACAO;}
"*"	{return T_MULTIPLICACAO;}
"/"	{return T_DIVISAO;}
"="	{return T_IGUAL;}
"("	{return T_ABRE_PARENTESES;}
")"	{return T_FECHA_PARENTESES;}
"{"	{return T_ABRE_CHAVES;}
"}"	{return T_FECHA_CHAVES;}
"int" {return T_INT;}
"," {return T_VIRGULA;}
";" {return T_PONTO_E_VIRGULA;}
"String" {return T_STRING;}
"void" {return T_VOID;}
"if" {return T_IF;}
"while" {return T_WHILE;}
"else" {return T_ELSE;}
"print" {return T_PRINT;}
"read" {return T_READ;}
"return" {return T_RETURN;}
"!" {return T_NOT;}
"&&" {return T_AND;}
"||" {return T_OR;}
"true" {return T_TRUE;}
"false" {return T_FALSE;}
">=" {return T_MAIOR_IGUAL;}
"<=" {return T_MENOR_IGUAL;}
"!=" {return T_DIFERENTE;}
"==" {return T_IGUAL_IGUAL;}
">" {return T_MAIOR;}
"<" {return T_MENOR;}
{id} {return T_ID;}
{literal} {return T_LITERAL;}
\0	{return T_FIM;}
\n  {__linha__ ++;}
{num}	{yylval=atof(yytext); return T_NUM;} 