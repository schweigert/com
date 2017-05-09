delim	[ \t\n\r]
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
{id} {return T_ID;}
{literal} {return T_LITERAL;}
\0	{return T_FIM;}
{num}	{yylval=atof(yytext); return T_NUM;} 
