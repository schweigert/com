all:
	flex expr.l
	bison --verbose expr.y
	gcc expr.c expr.tab.c gen.c  -O3 -o "Compiler.o"

