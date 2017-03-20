#ifndef CODEGEN_H
#define CODEGEN_H
#include "AST.h"
using namespace std;
typedef struct 
{
	string s;
	string v;
}codegen;
string type2structname(string s);
codegen codegenforexpr(r_expr* e,program* r);
void codegenforstmtinstmt(statement* s,program* r);
void codegenforstmtinclass(statement* s,program* r);
void codegenforclass(basic_class* c,program* root);
void codegenpgm(program* root);


#endif