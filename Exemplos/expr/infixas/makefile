all:
	flex expr.l
	bison --verbose expr.y
	gcc expr.c expr.tab.c -O3
