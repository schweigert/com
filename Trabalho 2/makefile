all:
	flex expr.l
	bison --verbose expr.y
	gcc expr.c expr.tab.c eda.c  -O3 -o "Compiler.o"

