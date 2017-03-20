
scanner.tab.c scanner.tab.h: scanner.y
	bison -d scanner.y

lex.yy.c: scanner.l scanner.tab.h
	flex scanner.l

quack: lex.yy.c scanner.tab.c scanner.tab.h
	clang++ -std=c++11 -w scanner.tab.c lex.yy.c AST.cpp Buildin.cpp codegen.cpp -lfl -o quack

