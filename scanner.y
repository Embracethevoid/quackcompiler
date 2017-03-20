%{
#include <cstdio>
#include <iostream>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <memory>
//#include "expr.h"
#include "AST.h"
#include "codegen.h"
//#include "./src/expr.h"
//#include "./src/method_class.h"
//#include "./src/stmt.h"
//#include "./src/node.h"
using namespace std;
// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int yylineno;
extern char* yytext;
extern basic_class* Obj ;
void yyerror(const char *s);
program* root;
%}

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":
%union {
	int ival;
	float fval;
	char* sval;
	char* identval;
	char* qtrue;
	char* qflase;
	//struct expr_val* expval;
    program* prog;
    //std::shared_ptr<program> pro;
	//std::vector<program> v;
	basic_classes* b_classes;
	basic_class* b_class;
	class_sig* class_sign;
	extend* ex;
	statements* ss;
	methods* ms;
	class_body* cb;
	statement* stmt;
	method* mtd;
	r_expr* r_exp;
	make_ident* mk_ident;
	formal_args* f_args;
	formal_args_first* f_args_f;
	formal_args_idents* f_args_is;
	formal_args_ident* f_args_i;
	elifs*          ElIfs;
	elif*        ElIf;
	actual_args* a_args;
	r_exprs* r_exps;

}

// define the constant-string tokens:
%token EXTENDS CLASS WHILE IF ELSE ELIF RETURN DEF ENDL //QUACKTRUE QUACKFALSE
%token COLON SEMICOLON LP RP LB RB DOT COMMA
%token  GETS
%token MISS ILLEGAL //PLUS MINUS TIMES DIVIDE MORE ATMOST LESS ATLEAST EQUALS AND OR NOT
//%left PLUS MINUS TIMES DIVIDE
//%left MORE ATMOST LESS ATLEAST EQUALS
%left AND OR
%left NOT
%nonassoc   ATMOST MORE ATLEAST LESS
//%nonassoc    
%left PLUS MINUS 
%left TIMES DIVIDE
%nonassoc  EQUALS
%precedence NEG
%left DOT
//%token DOT
// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT_LIT
%token <fval> FLOAT
%token <sval> STRING_LIT
%token <identval> Ident
%token <qtrue> QUACKTRUE
%token <qflase> QUACKFALSE
//%type <expval> R_Expr;
%type <prog> Program;
%type <b_class> Class;
%type <b_classes> Classes;
%type <class_sign> Class_Signature;
%type <ex> Extends_Ident;
%type <ss> Statements Statement_Block;
%type <ms> Methods;
%type <cb> Class_Body;
%type <stmt> Statement;
%type <mtd> Method;
%type <r_exp> R_Expr;
%type <f_args> Formal_Args;
%type <f_args_f> Formal_Args_First;
%type <f_args_is> Formal_Args_Idents;
%type <f_args_i> Formal_Args_Ident;
%type <ElIf> Elif;
%type <ElIfs> Elifs;
%type <r_exp> L_Expr;
%type <a_args> Actual_Args;
%type <r_exps> R_Exprs; 
%%
// the first rule defined is the highest-level rule, which in our
// case is just the concept of a whole "program file":
Program:
	Classes  Statements {$$ = new program($1,$2);root = $$;}
	;
Classes:
	{$$ = new basic_classes();}|Classes Class {$$ = new basic_classes($1,$2);}
	;
Class:
	Class_Signature Class_Body {$$ = new basic_class($1,$2);}
	;
Class_Signature:
	CLASS Ident LP Formal_Args RP Extends_Ident {$$ = new class_sig($2,$4,$6);}|
	CLASS Ident LP Formal_Args RP {$$ = new class_sig($2,$4);}
	;


Formal_Args:
	{$$ = new formal_args();}|Formal_Args_First Formal_Args_Idents{$$ = new formal_args($1,$2);}
	;
Formal_Args_First:
	Ident COLON Ident {$$ = new formal_args_first($1,$3);}
	;

Formal_Args_Idents:
	{$$ = new formal_args_idents();}|Formal_Args_Idents Formal_Args_Ident  {$$ = new formal_args_idents($1,$2);}
	;


Formal_Args_Ident:
	COMMA Ident COLON Ident {$$ = new formal_args_ident($2,$4);}
	;

Extends_Ident:
	EXTENDS Ident {$$ = new extend($2);}
	;

Class_Body:
	LB Statements Methods RB {$$ = new class_body($2,$3);}
	;




Statements:
	{$$ = new statements();}|Statements Statement {$$ = new statements($1,$2);}
	;

Statement_Block:
	LB Statements RB {$$ = $2;}
	;
Statement:

	IF R_Expr Statement_Block Elifs ELSE Statement_Block {$$ = new ifstmt($2,$3,$4, $6);}|
	IF R_Expr Statement_Block Elifs {$$ = new ifstmt($2,$3,$4);}  |
	WHILE R_Expr Statement_Block{$$ = new whilestmt($2,$3);}  |
	L_Expr COLON Ident GETS R_Expr SEMICOLON  {$$ = new expstmt($1,$3,$5);}|
	L_Expr GETS R_Expr  SEMICOLON{$$ = new expstmt($1,$3);}|
	R_Expr SEMICOLON  {$$ = new expstmt($1);}|
	RETURN R_Expr SEMICOLON{$$ = new returnstmt($2);}|
	RETURN SEMICOLON{$$ = new returnstmt();}
	;
	
Elifs:
{$$ = new elifs();}	|Elifs Elif{$$ = new elifs($1,$2);} 
	;


Elif:
	ELIF R_Expr Statement_Block {$$ = new elif($2,$3);}
	;


Methods:
	{$$ = new methods();}|Methods Method{$$ = new methods($1,$2);} 
	;


Method:
	
	
DEF Ident LP Formal_Args RP COLON Ident Statement_Block
{$$ = new method($2,$4,$7,$8);}
|

DEF Ident LP Formal_Args RP Statement_Block

{$$ = new method($2,$4,$6);}
	;








L_Expr:
	Ident{$$ = new make_ident($1);}|
	R_Expr DOT Ident {$$ = new make_ident($1,$3);}
	;

R_Expr:
	STRING_LIT {$$  = new make_str($1);}|
	INT_LIT {$$ = new make_int($1);}|
	QUACKTRUE {$$  = new make_boolean($1);}|
	QUACKFALSE {$$  = new make_boolean($1);}|
	L_Expr {$$ = $1;}|
	R_Expr PLUS R_Expr {$$ = new bin_operator($1,"PLUS",$3);}|
	R_Expr MINUS R_Expr {$$ = new bin_operator($1,"MINUS",$3);}|
	R_Expr TIMES R_Expr{$$ = new bin_operator($1,"TIMES",$3);}|
	R_Expr DIVIDE R_Expr{$$ = new bin_operator($1,"DIVIDE",$3);}|
	MINUS R_Expr %prec NEG{$$ = new negative_operator($2);}|
	LP R_Expr RP {$$ = $2;}|
	R_Expr EQUALS R_Expr {$$ = new bin_operator($1,"EQUALS",$3);}|
	R_Expr ATMOST R_Expr {$$ = new bin_operator($1,"ATMOST",$3);}|
	R_Expr LESS R_Expr{$$ = new bin_operator($1,"LESS",$3);}|
	R_Expr ATLEAST R_Expr{$$ = new bin_operator($1,"ATLEAST",$3);}|
	R_Expr MORE R_Expr{$$ = new bin_operator($1,"MORE",$3);}|
	R_Expr AND R_Expr{$$ = new bin_operator($1,"AND",$3);}|
	R_Expr OR R_Expr {$$ = new bin_operator($1,"OR",$3);}|
	NOT R_Expr {$$ = new not_operator($2);}|
	R_Expr DOT Ident LP Actual_Args RP {$$ = new function_call($1,$3,$5);}|
	Ident LP Actual_Args RP{$$  = new function_call($1,$3);}
	;

Actual_Args:
	{$$ = new actual_args();}|R_Expr R_Exprs {$$ = new actual_args($1,$2);}
	;

R_Exprs:
	{$$ = new r_exprs();}|R_Exprs COMMA R_Expr {$$ = new r_exprs($1,$3);}
	;
	
	




	




%%



extern unordered_map<string,basic_class*> classtable;
unordered_map<string,string> classparenttable;
extern basic_class* Obj;
extern basic_class* quack_int;
extern basic_class* quack_str;
extern basic_class* quack_boolean;
extern basic_class* quack_nothing;

void init()
{
	
	initbuildinclass();
	classparenttable.insert({"Int","Obj"});
	classparenttable.insert({"Boolean","Obj"});
	classparenttable.insert({"String","Obj"});
	classparenttable.insert({"NOTHING","Obj"});
	classtable["Obj"] = Obj;
	classtable["Int"] = quack_int;
	classtable["String"] = quack_str;
	classtable["Boolean"] = quack_boolean;
	classtable["NOTHING"] = quack_nothing;

}


bool issubtype(string s1,string s2)
{
	if(s2 == "Obj")
	{
		return true;
	}
	else
	{
		while(s1 != "Obj")
		{
			if (s1 != s2)
			{
				s1 = classparenttable[s1];
			}
			else
			{
				return true;
			}
		}
		return false;
	}
}


bool validpara(vector<r_expr*> p1,vector<Para> p2) //p1 is the overwrite , and p2 is the origin
{
	if(p1.size()!= p2.size())
	{
		return false;
	}
	else
	{
		for(int i = 0;i<p1.size(); ++i)
		{
			if(!issubtype(p1[i]->m_type,p2[i].type))
			{
				return false;
			}
		}
		return true;
	}

}



string LCA(string s1,string s2)
{
	if(s1 == s2)
	{
		return s1;
	}
	else if(s1 == "Bottom")
	{
		return s2;
	}
	else if(s2 == "Bottom")
	{
		return s1;
	}
	else
	{
		auto temp1 = s1;
		auto temp2 = s2;
		while(temp1 != "Obj")
		{
			while(temp2 != "Obj")
			{
				if(temp2 == temp1)
				{
					return temp1;
				}
				temp2 = classparenttable[temp2];
			}
			temp2 = s2;
			temp1 = classparenttable[temp1];
		}
		return "Obj";
	}


}

string LCA(vector<string> v)
{
	auto temp = string("Bottom");
	for(auto e:v)
	{
		if (e == "no return ")
		{
			return e;
		}
		else
		{
			temp = LCA(temp,e);
		}
	}
}

void getinitializedidentformethod(r_expr* e,statement* s,method* m,basic_class* c)
{

	if(e->tag == string("IDENT"))
	{
	
		if(e->identname == "this")
		{
			e->m_type = c->name();
		}
		else if(m->m_variables.find(e->identname) == m->m_variables.end())
		{
			cerr<<"uninitialized ident "<< e->identname<< " in method :"<< m->name()<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = "Bottom";
		}
		// }
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//getinitializedidentformethod(e->identparent,s,m,c);
		//
		//cout<<e->identparent->identname<<endl;
		// if(e->identparent->m_type != c->name())
		// {
		// 	cerr<< "not allowed to use other class's variable "<< e->identname<<" "<<e->identparent->m_type<<" "<<e->identparent->identname<<m->name()<<endl;
		// 	exit(-1);
		// }
		// else
		// {

			if(e->identparent->identname != "this" || c->m_variables.find(e->identname) == c->m_variables.end())
			{
				cout<<e->identname<<endl;
				cerr<< "unknown variable"<<endl;
				exit(-1);
			}
			else
			{
				e->m_type = "Bottom";
			}
		//}
	}
	else if(e->tag == string("bin_oper"))
	{
		getinitializedidentformethod(e->b.l,s,m,c);
		getinitializedidentformethod(e->b.r,s,m,c);
	}
	else if(e->tag == string("single_oper"))
	{
		getinitializedidentformethod(e->s.e,s,m,c);
	}
	else if(e->tag == string("function_call"))
	{
		getinitializedidentformethod(e->f.e,s,m,c);
		for(auto i:e->f.p->m_value)
		{
			getinitializedidentformethod(i,s,m,c);
		}
		// auto temp = e->f.e->m_type;
		// if(classtable.find(e->f.e->m_type) == classtable.end())
		// {
		// 	cerr<< e->f.e->m_type<<" is unknown class "<<c->name()<<" "<<m->name()<<endl;
		// 	exit(-1);
		// }
		// else if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
		// {
		// 	cerr<<"unknown function "<<endl;
		// 	exit(-1);
		// }
		// else
		// {
		// 	for(auto j: e->f.p->m_value)
		// 	{
		// 		getinitializedidentformethod(j,s,m,c);
		// 	}
		// }
		// else if(e->f.e->tag == "IDENT" && e->f.e->identname == "this")
		// {
		// 	if(c.methodtable)
		// }

	}
	else if(e->tag == string("class_call"))
	{
		bool flag = 0;
		if( classtable.find(e->c.s) == classtable.end() && c->methodtable.find(e->c.s) == c->methodtable.end())
		{
			cerr<<"uninitialized class or function"<<endl;
			exit(-1);
		}
		else
		{
			// if(!validpara(e->c.p->m_value,classtable[e->c.s]->para()))
			// {
			// 	cerr<<"wrong parameters"<<endl;
			// 	exit(-1);
			// }
			// else
			// {
				for(auto j: e->c.p->m_value)
				{
					getinitializedidentformethod(j,s,m,c);
				}
			// }
		}

	}
}





void getinitializedidentforclass(r_expr* e,statement* s,basic_class* c)
{
	if(e->tag == string("IDENT"))
	{	
		if(e->identname == "this")
		{
			cerr<< "not allowd to use this individually"<<endl;
			exit(-1);
		}
		else if(c->m_variables.find(e->identname) == c->m_variables.end() &&
			c->m_variables_temp.find(e->identname) == c->m_variables_temp.end())
		{
			cerr<<"uninitialized ident "<<" "<<e->identname<< " in class :"<< c->name()<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = "Bottom";
		}
		// }
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		if (e->identparent->identname != "this")
		{
			//cerr<<e->identparent->identname<<endl;
			cerr<<"cannot use that"<<endl;
			exit(-1);
		}
		else if(c->m_variables.find(e->identname) == c->m_variables.end() &&
			c->m_variables_temp.find(e->identname) == c->m_variables_temp.end())
		{
			cerr<<"uninitialized ident "<<e->identparent->identname<<" "<< e->identname<< " in class :"<< c->name()<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = "Bottom";
		}
	}
	else if(e->tag == string("bin_oper"))
	{
		getinitializedidentforclass(e->b.l,s,c);
		getinitializedidentforclass(e->b.r,s,c);
	}
	else if(e->tag == string("single_oper"))
	{
		getinitializedidentforclass(e->s.e,s,c);
	}
	else if(e->tag == string("function_call"))
	{
		//check if there is function
		//s->m_variable[e->f.s] = "Bottom";
		//getinitializedidentformethod(e,s,m);
		// if(classtable.find(e->f.e->m_type) == classtable.end() )
		// {
		// 	cerr<<e->f.e->m_type<<e->f.s<<endl;
		// 	cerr<<e->f.e->identname<<endl;
		// 	cerr<<"Invalid class call"<<endl;
		// 	exit(-1);
		// }
		// else if(classtable[e->f.e->m_type]->methodtable.find(e->f.s) == classtable[e->f.e->m_type]->methodtable.end())
		// {
		// 	cerr<<"Invalid function call"<<endl;
		// }
		// else
		// {

		/*


		i ll do this in typebuilding

		*/



		getinitializedidentforclass(e->f.e,s,c);
		for(auto j: e->f.p->m_value)
		{
			getinitializedidentforclass(j,s,c);
		}
		// }
	}
	else if(e->tag == string("class_call"))
	{
		if(c->methodtable.find(e->c.s) == c->methodtable.end() && classtable.find(e->c.s) == classtable.end())
		{
			cerr<< "undefined function or class"<<endl;
			exit(-1);
		}
		else
		{
			for(auto j: e->c.p->m_value)
			{
				getinitializedidentforclass(j,s,c);
			}
		}
	}
}








void getinitializedidentforstmt(r_expr* e,statement* s,program* p)
{
	//cout<<e->tag<<" "<<m->name()<<endl;
	if(e->tag == string("IDENT"))
	{
	
		if(p->m_variables.find(e->identname) == p->m_variables.end())
		{
			cerr<<"uninitialized ident "<< e->identname<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = p->m_variables[e->identname];
		}
		// }
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//getinitializedidentformethod(e->identparent,s,m,c);
		//
		//cout<<e->identparent->identname<<endl;
		// if(e->identparent->m_type != c->name())
		// {
			cerr<< "not allowed to use other class's variable "<< e->identname<<" "<<e->identparent->identname<<endl;
			exit(-1);
		// }
		// else
		// {
		// 	if(c->m_variables.find(e->identname) == c->m_variables.end())
		// 	{
		// 		cerr<< "unknown variable"<<endl;
		// 		exit(-1);
		// 	}
		// }
	}
	else if(e->tag == string("bin_oper"))
	{
		getinitializedidentforstmt(e->b.l,s,p);
		getinitializedidentforstmt(e->b.r,s,p);
	}
	else if(e->tag == string("single_oper"))
	{
		getinitializedidentforstmt(e->s.e,s,p);
	}
	else if(e->tag == string("function_call"))
	{
		getinitializedidentforstmt(e->f.e,s,p);
		// the function part should be done in type check part




		// if(p->m_variables.find(e->f.e->name() == p -> m_variables.end())
		// {
		// 	cerr<< "not found "<<endl;
		// 	exit(-1);
		// }
		// else if(classtable[p->m_variables[e->f.e->name()]]->m_variables.find(e->f.s) == classtable[p->m_variables[e->f.e->name()]]->m_variables.end())
		// {
		// 	cerr<< "not found"<<endl;
		// 	exit(-1);
		// }
		// else
		// {
		// 	getinitializedidentforstmt(e->f.p,s,p);
		// }
	}
	else if(e->tag == string("class_call"))
	{
		bool flag = 0;
		if( classtable.find(e->c.s) == classtable.end())
		{
			cerr<<"uninitialized class"<<endl;
			exit(-1);
		}
		else
		{
			// if(!validpara(e->c.p->m_value,classtable[e->c.s]->para()))
			// {
			// 	cerr<<"wrong parameters"<<endl;
			// 	exit(-1);
			// }
			// else
			// {
				for(auto j: e->c.p->m_value)
				{
					getinitializedidentforstmt(j,s,p);
				}
			// }
		}

	}
}























void buildvariableformethodinstmt(statement* s,statement* s2,method* m,basic_class* c)
{
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentformethod(i.condition,s,m,c);
			for(auto j: i.execution->value())
			{
				buildvariableformethodinstmt(j,s2,m,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableformethodinstmt(j,s2,m,c);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);
		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}

	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentformethod(i.condition,s,m,c);
			for(auto j: i.execution->value())
			{
				buildvariableformethodinstmt(j,s2,m,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableformethodinstmt(i,s2,m,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		getinitializedidentformethod(s->exp,s,m,c);
	}
	else if (s->tag == string("GETVALUE"))
	{
		getinitializedidentformethod(s->g_value.right,s,m,c);
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
			s->g_value.left->m_type = "Bottom";
		}
		else if(s->g_value.left->tag == string("IDENTINMEMBER"))
		{
			s->m_variables_class[s->g_value.left->identname] = string("Bottom");
			s->g_value.left->m_type = "Bottom";
		}

		
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else
	{

	}
	
	//m->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
}


void buildvariableformethod(statement* s,method* m,basic_class* c)
{
	//cout<<s->tag<<endl;
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			unordered_map<string,string> tempc;
			getinitializedidentformethod(i.condition,s,m,c);
			for(auto j: i.execution->value())
			{
				buildvariableformethodinstmt(j,s,m,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
				tempc.insert(j->m_variables_class.begin(),j->m_variables_class.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableformethodinstmt(j,s,m,c);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);

		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f.clear();
				f.insert(tempm.begin(),tempm.end());
				
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}

	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			//unordered_map<string,string> temp1;
			getinitializedidentformethod(i.condition,s,m,c);
			for(auto j: i.execution->value())
			{
				buildvariableformethodinstmt(j,s,m,c);
			}
		// 	for(auto j: i.execution->value())
		// 	{
		// 		temp1.insert(j->m_variables.begin(),j->m_variables.end());
		// 	}
		// 	temp.push_back(temp1);
		// }
		// if(temp.size())
		// {
		// 	auto f = temp[0];
		// 	unordered_map<string,string> tempm;
		// 	for(auto j:temp)
		// 	{
		// 		for(auto v: f)
		// 		{
		// 			if(j.find(v.first)!= j.end())
		// 			{
		// 				tempm[v.first] = string("Bottom");
		// 			}
		// 		}
		// 		f = tempm;
		// 		tempm.clear();
		// 	}
		// 	s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableformethodinstmt(i,s,m,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		getinitializedidentformethod(s->exp,s,m,c);
	}
	else if (s->tag == string("GETVALUE"))
	{
		
		if(s->g_value.left->tag == string("IDENT"))
		{
			
			s->m_variables[s->g_value.left->identname] = string("Bottom");
			s->g_value.left->m_type = "Bottom";			
		}
		else if(s->g_value.left->tag == "IDENTINMEMBER" && s->g_value.left->identparent->identname == "this")
		{
			c->m_variables[s->g_value.left->identname] = string("Bottom");
			s->g_value.left->m_type = "Bottom";
		}
		getinitializedidentformethod(s->g_value.right,s,m,c);
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		//if(s->g_value_m.left->tag == )
	}			
	else
	{

	}
	if(s->tag != "IF" && s->tag != "WHILE")
	{
		m->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
	}
}



void buildvariableforstmtinstmt(statement* s,statement* s2,program* p)
{
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforstmt(i.condition,s,p);
			for(auto j: i.execution->value())
			{
				buildvariableforstmtinstmt(j,s2,p);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableforstmtinstmt(j,s2,p);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);
		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}

	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforstmt(i.condition,s,p);
			for(auto j: i.execution->value())
			{
				buildvariableforstmtinstmt(j,s2,p);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableforstmtinstmt(i,s2,p);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		getinitializedidentforstmt(s->exp,s,p);
	}
	else if (s->tag == string("GETVALUE"))
	{
		
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
		}

		getinitializedidentforstmt(s->g_value.right,s,p);
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else
	{

	}
	
	//m->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
}
















void buildvariableforstmt(statement* s,program* p)
{
	//cout<<s->tag<<endl;
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforstmt(i.condition,s,p);
			for(auto j: i.execution->value())
			{
				buildvariableforstmtinstmt(j,s,p);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableforstmtinstmt(j,s,p);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);
		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f.clear();
				f.insert(tempm.begin(),tempm.end());
				
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());

		}

	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforstmt(i.condition,s,p);
			for(auto j: i.execution->value())
			{
				buildvariableforstmtinstmt(j,s,p);
			}
			for(auto j: i.execution->value())
		 	{
		 		temp1.insert(j->m_variables.begin(),j->m_variables.end());
		 	}
		 	temp.push_back(temp1);
		 }
		 if(temp.size())
		 {
		 	auto f = temp[0];
		 	unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		unordered_map<string,string> temp;
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableforstmtinstmt(i,s,p);
			temp.insert(i->m_variables.begin(),i->m_variables.end());
		}
		s->m_variables.insert(temp.begin(),temp.end());
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		getinitializedidentforstmt(s->exp,s,p);
	}
	else if (s->tag == string("GETVALUE"))
	{
		
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
		}

		getinitializedidentforstmt(s->g_value.right,s,p);
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		//if(s->g_value_m.left->tag == )
		cerr<<"not allowd to call private member"<<endl;
		exit(-1);
	}			
	else
	{

	}
	if(s->tag != "IF" && s->tag != "WHILE")
	{
		p->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
	}
}


void class_inherit_issue()
{
	
	for(auto c: root->cs)
	{
		if(c->name() == "Obj" ||c->name() == "Int" ||c->name() == "String" ||c->name() == "NOTHING" ||c->name() == "Boolean")
		{
			cerr<<"Illegal definition"<<endl;
			exit(-1);
		}
		classparenttable[c->name()] = c->parent();
		//cout<<c.name()<<" "<<c.parent()<<endl;
	}
	for(auto c:root->cs)
	{
		auto temp = c->name();
		unordered_set<string> temptype;
		while(temp != string("Obj"))
		{
			temptype.insert(temp);
			temp = classparenttable[temp];
			if( classparenttable.find(temp) == classparenttable.end() && temp != "Obj")
			{
				cerr<<"illegal inherit from "<<temp<<endl;
				return;
			}
			if (temptype.find(temp) != temptype.end())
			{
				
				cerr<< "circle in class inherit:";
				auto mark = classparenttable[temp];
				cout<<temp<<"->";
				while (mark != temp)
				{
					cout<<mark<<"->";
					mark = classparenttable[mark];
				}
				cout<<mark<<endl;
				exit(-1);
				//return;
			}
			
			
		}
		if(c->parent() == "Obj")
		{
			c->reference  = Obj;
		}
		else if(c->parent() == "Int")
		{
			c->reference = quack_int;
		}
		else if(c->parent() == "String")
		{
			c->reference = quack_str;
		}
		else if(c->parent() == "Boolean")
		{
			c->reference = quack_boolean;
		}
		else if(c->parent() == "NOTHING")
		{
			c->reference = quack_nothing;
		}
		else
		{
			for(auto p:root->cs)
			{
				if(p->name() == c->parent())
				{
					c->reference = p;
				}
			}
		}
		classtable[c->name()] = c;

	}
	
}

unordered_set<string> inherited_class;
void buildclassinherit(basic_class* c)
{
	if(inherited_class.find(c->name()) == inherited_class.end())
	{
		if(c->name() == "Obj" ||c->name() == "Int" ||c->name() == "String" ||c->name() == "NOTHING" ||c->name() == "Boolean"  )
		{
			// for(auto m:c->m_methods)
			// {
			// 	c->methodtable[m->name()] = m;
			// }
			inherited_class.insert(c->name());
		}
		else
		{
			buildclassinherit(c->reference);
			for(auto m:c->m_methods)
			{
				if(c->reference->methodtable.find(m->name()) != c->reference->methodtable.end() )
				{
					//overwrite
					cout<< c->reference->methodtable[m->name()]->m_returntype<<" "<<m->m_returntype<<" "<<m->name()<<
					endl;
					if(issubtype( c->reference->methodtable[m->name()]->m_returntype,m->m_returntype) )
					{

						if(m->para().size() != c->reference->methodtable[m->name()]->para().size())
						{
							cerr<<"wront para"<<endl;
							exit(-1);
						}
						else
						{
							for(int i = 0; i < m->para().size();++i)
							{
								if(!issubtype(m->para()[i].type,c->reference->methodtable[m->name()]->para()[i].type))
								{
									cerr<<"wrong para"<<endl;
									exit(-1);
								}
							}
							c->methodtable[m->name()] = m;
							m->origin_class = c->name();
						}

					}
					else
					{
						cerr<< "not allowed to overwrite with wrong tyoe"<<endl;
						exit(-1);
					}
				}
				else if(c->methodtable.find(m->name()) == c->methodtable.end())
				{
					if(classtable.find(m->m_returntype) == classtable.end())
					{
						cerr<<"invalid return type of "<<m->name()<<" of type "<<m->m_returntype<<endl;
						exit(-1);
					}
					c->methodtable[m->name()] = m;
					c->methodtable[m->name()]->origin_class = c->name();
				}
				else
				{
					if(classtable.find(m->m_returntype) == classtable.end())
					{
						cerr<<"invalid return type of "<<m->name()<<endl<<m->m_returntype<<endl;
						exit(-1);
					}
					// overwrite to do;
					c->methodtable[m->name()]->origin_class = c->name();
				}
			}
			for(auto m_refer:c->reference->methodtable)
			{
				if(c->methodtable.find(m_refer.first) == c->methodtable.end())
				{
					c->methodtable[m_refer.first] = m_refer.second;
				}
			}
		}
		inherited_class.insert(c->name());
	}
	
}

void class_method_inherit()
{
	for(auto c:root->cs)
	{
		buildclassinherit(c);
	}

}







void buildvariableforclassinstmt(statement* s,statement* s2,basic_class* c)
{
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforclass(i.condition,s,c);
			for(auto j: i.execution->value())
			{
				buildvariableforclassinstmt(j,s2,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableforclassinstmt(j,s2,c);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);
		if(!temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}

	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforclass(i.condition,s,c);
			for(auto j: i.execution->value())
			{
				buildvariableforclassinstmt(j,s2,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		if(!temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableforclassinstmt(i,s2,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
 			cerr<<" not allowed return in class"<<endl;
		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		getinitializedidentforclass(s->exp,s,c);
		cerr<<" not allowed return in class"<<endl;
		exit(-1);
	}
	else if (s->tag == string("GETVALUE"))
	{
		
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
		}

		getinitializedidentforclass(s->g_value.right,s,c);
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else
	{

	}
	
	//m->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
}

void addvariableforclass(r_expr* e, basic_class* c)
{
	if(e->tag == string("IDENT"))
	{	
		if(e->identname == "this")
		{
			cerr<<"not allowed in use this in class individually"<<endl;
			exit(-1);
		}
		else
		{
			c->m_variables_temp[e->identname] = "Bottom";
			e->m_type = "Bottom";
		}
		// }
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//addvariableforclass(e->identparent,c);
		if(e->identparent->identname == "this")
		{
			c->m_variables[e->identname] = "Bottom";
			e->m_type = "Bottom";
		}
	}
}

void buildvariableforclass(statement* s,basic_class* c)
{
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforclass(i.condition,s,c);
			for(auto j: i.execution->value())
			{
				buildvariableforclassinstmt(j,s,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableforclassinstmt(j,s,c);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);
		if(!temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}


	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforclass(i.condition,s,c);
			for(auto j: i.execution->value())
			{
				buildvariableforclassinstmt(j,s,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		if(!temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableforclassinstmt(i,s,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;	cerr<<" not allowed return in class"<<endl;
		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		cerr<<" not allowed return in class"<<endl;
		exit(-1);
	}
	else if (s->tag == string("GETVALUE"))
	{
		getinitializedidentforclass(s->g_value.right,s,c);
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
		}
		else if(s->g_value.left->tag == string("IDENTINMEMBER") && s->g_value.left->identparent->identname == "this")
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
		}
		
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value_m.left->identname] = string("Bottom");
		}
		getinitializedidentforclass(s->g_value_m.right,s,c);
		//getinitializedidentforclass(s->g_value_m.right,s,c);
	}			
	else
	{
		getinitializedidentforclass(s->exp,s,c);
	}
	if(s->tag != "IF" && s->tag != "WHILE")
	{		
		c->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
	}
	
}


// getinitializedidentforpgm(r_expr* e,statement* s,program* r)
// {
// 	if(e->tag == string("IDENT"))
// 	{
	
// 		if(p->m_variables.find(e->identname) == p->m_variables.end())
// 		{
// 			cerr<<"uninitialized ident "<< e->identname<<endl;
// 			exit(-1);
// 		}
// 		else
// 		{
// 			e->m_type = p->m_variables[e->identname];
// 		}
// 	}
// 	else if (e->tag == string("IDENTINMEMBER"))
// 	{
// 		//getinitializedidentformethod(e->identparent,s,m,c);
// 		//
// 		//cout<<e->identparent->identname<<endl;
// 		// if(e->identparent->m_type != c->name())
// 		// {
// 			cerr<< "not allowed to use private variable "<< e->identname<<" "<<e->identparent->identname<<endl;
// 			exit(-1);
// 		// }
// 		// else
// 		// {
// 		// 	if(c->m_variables.find(e->identname) == c->m_variables.end())
// 		// 	{
// 		// 		cerr<< "unknown variable"<<endl;
// 		// 		exit(-1);
// 		// 	}
// 		// }
// 	}
// 	else if(e->tag == string("bin_oper"))
// 	{
// 		getinitializedidentforpgm(e->b.l,s,p);
// 		getinitializedidentforpgm(e->b.r,s,p);
// 	}
// 	else if(e->tag == string("single_oper"))
// 	{
// 		getinitializedidentforpgm(e->s.e,s,p);
// 	}
// 	else if(e->tag == string("function_call"))
// 	{
// 		// auto temp = e->f.e->m_type;
// 		// if(classtable.find(e->f.e->m_type) == classtable.end())
// 		// {
// 		// 	cerr<< e->f.e->m_type<<" is unknown class "<<c->name()<<" "<<m->name()<<endl;
// 		// 	exit(-1);
// 		// }
// 		// else if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
// 		// {
// 		// 	cerr<<"unknown function "<<endl;
// 		// 	exit(-1);
// 		// }
// 		// else
// 		// {
// 		// 	for(auto j: e->f.p->m_value)
// 		// 	{
// 		// 		getinitializedidentformethod(j,s,m,c);
// 		// 	}
// 		// }
// 		// else if(e->f.e->tag == "IDENT" && e->f.e->identname == "this")
// 		// {
// 		// 	if(c.methodtable)
// 		// }

// 	}
// 	else if(e->tag == string("class_call"))
// 	{
// 		bool flag = 0;
// 		if( classtable.find(e->c.s) == classtable.end())
// 		{
// 			cerr<<"uninitialized class"<<endl;
// 			exit(-1);
// 		}
// 		else
// 		{
// 			// if(!validpara(e->c.p->m_value,classtable[e->c.s]->para()))
// 			// {
// 			// 	cerr<<"wrong parameters"<<endl;
// 			// 	exit(-1);
// 			// }
// 			// else
// 			// {
// 				for(auto j: e->c.p->m_value)
// 				{
// 					getinitializedidentforstmt(j,s,p);
// 				}
// 			// }
// 		}

// 	}
// }


























































void classsvariable(basic_class* c)
{
	//unordered_map<string,string> temp;
	for(auto i:c->m_para)
	{
		c->m_variables_temp[i.name] = i.type;
	}

}





string checkmethodreturntype(vector<statement*> s)
{
	string res = "no return";
	for(auto i:s)
	{
		if(i->tag == "IFELSE")
		{	
			
		}
		else if(i->tag == "IF")
		{
			
		}
		else if(i->tag == "WHILE")
		{

		}
		else if(i->tag == "RETURNNULL")
		{
			return string("NULL");
		}
		else if (i->tag == "RETURN")
		{
			return i->returntype;
		}
	}
	return res;
}


void methodstmt(method* m,basic_class* c)
{
	for(auto p : m->para())
	{
		m->m_variables[p.name] = p.type;
	}
	for(auto s : m->methodstatements)
	{
		buildvariableformethod(s,m,c);
	}
}



/*
build type for class

*/


void buildtypeforexprinclass(r_expr* e,basic_class* c)
{
	cout<<e->tag<<" "<<c->name()<<endl;
	if(e->tag == string("IDENT"))
	{
		if(e->identname != "this")
		{
			e->m_type = LCA(e->m_type,c->m_variables_temp[e->identname]);
			c->m_variables_temp[e->identname] = e->m_type;
		}
		else
		{
			cerr<<"not allowed to use this individually"<<endl;
			exit(-1);
		}
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//e->m_type = c->m_variables[e->identname];
		if(e->identparent->identname  == "this")
		{
			e->m_type = LCA(e->m_type,c->m_variables[e->identname]);
			c->m_variables[e->identname] = e->m_type;
		}
		else
		{
			cerr<< "not allowed to use it"<<endl;
			exit(-1);
		}
	}
	else if(e->tag == string("bin_oper"))
	{
		buildtypeforexprinclass(e->b.l,c);
		buildtypeforexprinclass(e->b.r,c);
		auto oper = e->b.s;
		if(classtable[e->b.l->m_type]->methodtable.find(oper) == classtable[e->b.l->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			auto p = classtable[e->b.l->m_type]->methodtable[oper]->para()[0].type;
			if(!issubtype(e->b.r->m_type,p))
			{
				cerr<< "wrong type got"<<endl;
				exit(-1);
			}
			else
			{
				e->m_type = classtable[e->b.l->m_type]->methodtable[oper]->m_returntype;
			}
		}
	}
	else if(e->tag == string("single_oper"))
	{
		buildtypeforexprinclass(e->s.e,c);
		auto oper = e->s.s;
		if(classtable[e->s.e->m_type]->methodtable.find(oper) == classtable[e->s.e->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[e->s.e->m_type]->methodtable[oper]->m_returntype;
		}
	}
	else if(e->tag == string("function_call"))
	{
		//check if there is function
		//s->m_variable[e->f.s] = "Bottom";
		//getinitializedidentformethod(e,s,m);
		buildtypeforexprinclass(e->f.e,c);
		auto temp = e->f.e->m_type;
		cout<<temp<<endl;
		if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
		{
			cerr<< temp<<endl;
			cerr<<"unknown function "<<e->f.s<<endl;
			exit(-1);
		}
		e->m_type = classtable[temp]->methodtable[e->f.s]->m_returntype;
		cout<<e->m_type<<" "<<e->f.e->identname<<" "<<c->name()<<endl;
	}
	else if(e->tag == string("class_call"))
	{
		if(classtable.find(e->c.s) != classtable.end())
		{
			e->m_type = classtable[e->c.s]->name();
			for(int i = 0;i<e->c.p->m_value.size();++i)
			{
				auto p = e->c.p->m_value[i];
				buildtypeforexprinclass(p,c);
				if(!issubtype(p->m_type,classtable[e->c.s]->para()[i].type))
				{
					cerr<<"wrong para type"<<endl;
					exit(-1);
				}
			}
		}
		else if(c->methodtable.find(e->c.s) != c->methodtable.end())
		{
			e->m_type = c->methodtable[e->c.s]->m_returntype;
			for(int i = 0;i<e->c.p->m_value.size();++i)
			{
				auto p = e->c.p->m_value[i];
				buildtypeforexprinclass(p,c);
				if(!issubtype(p->m_type,c->methodtable[e->f.s]->para()[i].type))
				{
					cerr<<"wrong para type"<<endl;
					exit(-1);
				}
			}
		}
		else
		{
			cerr<<"unknown function or class call"<<endl;
			exit(-1);
		}
	}
}





void buildtypeforstmtinclass(statement* s,basic_class* c)
{
	cout<<s->tag<<endl;
	if(s->tag == string("IFELSE"))         // there is no problem about the not initialed
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinclass(i.condition,c);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinclass(j,c);
			}
		}
		for(auto j: s->elsestatements->value())
		{
			buildtypeforstmtinclass(j,c);
		}

	

	}
	else if(s->tag == string("IF"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinclass(i.condition,c);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinclass(j,c);
			}		
		}
	}
	else if(s->tag == string("WHILE"))
	{
		buildtypeforexprinclass(s->whilestatement.condition,c);
		if(!issubtype(s->whilestatement.condition->m_type,"Boolean"))
		{
			cerr<< "Invalid condition expression"<<endl;
			exit(-1);
		}
		for(auto i: s->whilestatement.execution->value())
		{
			buildtypeforstmtinclass(i,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
 		cerr<<" can not return in construction func"<<endl;
 		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		cerr<<" can not return in construction func"<<endl;
 		exit(-1);
	}
	else if (s->tag == string("GETVALUE"))
	{
		if(s->g_value.left->tag == string("IDENT"))
		{
			c->m_variables_temp[s->g_value.left->identname] = LCA(c->m_variables_temp[s->g_value.left->identname],s->g_value.right->m_type);
			s->g_value.left->m_type = c->m_variables_temp[s->g_value.left->identname];
		}
		else if (s->g_value.left->tag == string("IDENTINMEMBER"))
		{
			//cout<< s->g_value.right->m_type<<endl<<s->g_value.right->identname<<endl;
			buildtypeforexprinclass(s->g_value.right,c);
			auto tag = s->g_value.right->tag;
			// if(tag == "IDENT")
			// {
			// 	c->m_variables[s->g_value.left->identname] = LCA(s->g_value.left->m_type,c->m_variables_temp[s->g_value.right->identname]);
			// 	s->g_value.left->m_type = c->m_variables[s->g_value.left->identname];
			// }
			// else if (tag == "IDENTINMEMBER")
			// {
			// 	c->m_variables[s->g_value.left->identname] = LCA(s->g_value.left->m_type,c->m_variables[s->g_value.right->identname]);
			// 	s->g_value.left->m_type = c->m_variables[s->g_value.left->identname];
			// }
			// else
			// {
			c->m_variables[s->g_value.left->identname] = LCA(c->m_variables[s->g_value.left->identname],s->g_value.right->m_type);
			s->g_value.left->m_type = c->m_variables[s->g_value.left->identname];
			//}
		}
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else if(s->tag == "EXP")
	{
		buildtypeforexprinclass(s->exp,c);
	}
}
/*

build type for method

*/

void buildtypeforexprinmethod(r_expr* e, method* m, basic_class* c)
{
	if(e->tag == string("IDENT"))
	{
		if(e->identname != "this")
		{
			e->m_type = m->m_variables[e->identname];
		}
		else
		{
			cerr<< "this must come with class variable definition"<<endl;
			exit(-1);
		}
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		if(e->identparent->identname  == "this")
		{
			e->m_type = c->m_variables[e->identname];

		}
		else
		{
			cerr<< "not allowed to use it"<<endl;
			exit(-1);
		}
	}
	else if(e->tag == string("bin_oper"))
	{
		buildtypeforexprinmethod(e->b.l,m,c);
		buildtypeforexprinmethod(e->b.r,m,c);
		auto oper = e->b.s;
		if(classtable[e->b.l->m_type]->methodtable.find(oper) == classtable[e->b.l->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			auto p = classtable[e->b.l->m_type]->methodtable[oper]->para()[0].type;
			if(!issubtype(e->b.r->m_type,p))
			{
				cerr<< "wrong type got"<<endl;
				exit(-1);
			}
			else
			{
				e->m_type = classtable[e->b.l->m_type]->methodtable[oper]->m_returntype;
			}
		}
	}
	else if(e->tag == string("single_oper"))
	{
		buildtypeforexprinmethod(e->s.e,m,c);
		auto oper = e->s.s;
		if(classtable[e->s.e->m_type]->methodtable.find(oper) == classtable[e->s.e->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[e->s.e->m_type]->methodtable[oper]->m_returntype;
		}
	}
	else if(e->tag == string("function_call"))
	{

		buildtypeforexprinmethod(e->f.e,m,c);
		auto temp = e->f.e->m_type;
		if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
		{
			cerr<< temp<<endl;
			cerr<<"unknown function "<<e->f.s<<endl;
			exit(-1);
		}
		else
		{
			for(int i = 0;i < e->f.p->m_value.size();++i)
			{
				cout<<i<<endl;
				if(!issubtype(e->f.p->m_value[i]->m_type,classtable[temp]->methodtable[e->f.s]->para()[i].type))
				{
					cerr<<"invalid para"<<endl;
					exit(-1);
				}
			}
			e->m_type = classtable[temp]->methodtable[e->f.s]->m_returntype;
		}
	}
	else if(e->tag == string("class_call"))
	{
		if(classtable.find(e->c.s) != classtable.end())
		{
			e->m_type = classtable[e->c.s]->name();
			auto temp = e->m_type;
			for(int i = 0;i < e->c.p->m_value.size();++i)
			{
				buildtypeforexprinmethod(e->c.p->m_value[i],m,c);
				cout<<e->c.p->m_value[i]->m_type<<" "<<classtable[temp]->para()[i].type<<endl;
				if(!issubtype(e->c.p->m_value[i]->m_type,classtable[temp]->para()[i].type))
				{
					cerr<<"invalid para"<<endl;
					exit(-1);
				}
			}
		}
		else if(c->methodtable.find(e->c.s) != c->methodtable.end())
		{
			e->m_type = c->methodtable[e->c.s]->m_returntype;
			auto temp = e->m_type;
			for(int i = 0;i < e->c.p->m_value.size();++i)
			{
				if(!issubtype(e->c.p->m_value[i]->m_type,classtable[temp]->methodtable[e->c.s]->para()[i].type))
				{
					cerr<<"invalid para in "<< e->c.s<<endl;
					exit(-1);
				}
			}
		}
		else
		{
			cerr<<"unknown function or class call"<<endl;
			exit(-1);
		}
	}
	else
	{
		cout<< e->m_type<<"laalala"<<endl;
	}

}

void buildtypeforstmtinmethod(statement* s,method* m,basic_class* c)
{
	if(s->tag == string("IFELSE"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinmethod(i.condition,m,c);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinmethod(j,m,c);
			}
		}
		for(auto j: s->elsestatements->value())
		{
			buildtypeforstmtinmethod(j,m,c);
		}

	}
	else if(s->tag == string("IF"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinmethod(i.condition,m,c);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinmethod(j,m,c);
			}		
		}
	}
	else if(s->tag == string("WHILE"))
	{
		buildtypeforexprinmethod(s->whilestatement.condition,m,c);
		if(!issubtype(s->whilestatement.condition->m_type,"Boolean"))
		{
			cerr<< "Invalid condition expression"<<endl;
			exit(-1);
		}
		for(auto i: s->whilestatement.execution->value())
		{
			buildtypeforstmtinmethod(i,m,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
	}
	else if (s->tag == string("RETURN"))
	{
		buildtypeforexprinmethod(s->exp,m,c);
		if(!issubtype(s->exp->m_type,m->m_returntype))
		{
			cerr<<"Wrong return type"<<endl;
			exit(-1);
		}
		cout<<"Finished return building in "<<m->name()<<endl;
		//getinitializedidentformethod(s->exp,s,m);
	}
	else if (s->tag == string("GETVALUE"))
	{
		buildtypeforexprinmethod(s->g_value.right,m,c);
		if(s->g_value.left->tag == string("IDENT"))
		{
			m->m_variables[s->g_value.left->identname] = LCA(s->g_value.left->m_type,s->g_value.right->m_type);
			s->g_value.left->m_type = m->m_variables[s->g_value.left->identname];
		}
		else if(s->g_value.left->tag == "IDENTINMEMBER")
		{
			c->m_variables[s->g_value.left->identname] = LCA(s->g_value.left->m_type,s->g_value.right->m_type);
			s->g_value.left->m_type = c->m_variables[s->g_value.left->identname];
		}
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else if(s->tag == "EXP")
	{
		buildtypeforexprinmethod(s->exp,m,c);
	}
	
	//m->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
}




/*
build type for expr in program stmt
*/

// void buildtypeforparainclass(basic_class* c)
// {
// 	for(auto p:c->para())
// 	{
// 		c->m_variables_temp[c.name] = c.type;
// 	}
// }

void buildtypeforexprinstmt(r_expr* e,statement* s,program* r)
{
	cout<<e->tag<<endl;
if(e->tag == string("IDENT"))
	{
		if(e->identname != "this")
		{
			if(r->m_variables.find(e->identname) != r->m_variables.end())
			{e->m_type =r->m_variables[e->identname];
			}
			else
			{
				e->m_type = s->m_variables[e->identname];
			}
		}
		else
		{
			cerr<<"illegal calling this"<<endl;
			exit(-1);
		}
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//e->m_type = c->m_variables[e->identname];
		cerr<<"not allowed to call private member"<<endl;
		exit(-1);
	}
	else if(e->tag == string("bin_oper"))
	{
		buildtypeforexprinstmt(e->b.l,s,r);
		buildtypeforexprinstmt(e->b.r,s,r);
		auto oper = e->b.s;
		if(classtable[e->b.l->m_type]->methodtable.find(oper) == classtable[e->b.l->m_type]->methodtable.end())
		{
			cout<<oper<<endl;
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			auto p = classtable[e->b.l->m_type]->methodtable[oper]->para()[0].type;
			if(!issubtype(e->b.r->m_type,p))
			{
				cerr<< "wrong type got"<<endl;
				exit(-1);
			}
			else
			{
				e->m_type = classtable[e->b.l->m_type]->methodtable[oper]->m_returntype;
			}
		}
	}
	else if(e->tag == string("single_oper"))
	{
		buildtypeforexprinstmt(e->s.e,s,r);
		auto oper = e->s.s;
		if(classtable[e->s.e->m_type]->methodtable.find(oper) == classtable[e->s.e->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[e->s.e->m_type]->methodtable[oper]->m_returntype;
		}
	}
	else if(e->tag == string("function_call"))
	{
		//check if there is function
		//s->m_variable[e->f.s] = "Bottom";
		//getinitializedidentformethod(e,s,m);
		buildtypeforexprinstmt(e->f.e,s,r);
		auto temp = e->f.e->m_type;
		cout<<temp<<endl;
		if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
		{
			cerr<<"unknown function "<< e->f.s<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[temp]->methodtable[e->f.s]->m_returntype;
			for(auto i: e->f.p->m_value)
			{
				buildtypeforexprinstmt(i,s,r);
			}
		}
	}
	else if(e->tag == string("class_call"))
	{
		if(classtable.find(e->c.s) != classtable.end())
		{
			e->m_type = classtable[e->c.s]->name();
			for(auto i : e->c.p->m_value)
			{
				buildtypeforexprinstmt(i,s,r);
			}
		}
		else
		{
			cerr<<"unknown function or class call"<<endl;
			exit(-1);
		}
	}
	else
	{
		cout<<" other expr"<<endl;
	}


}



void buildtypeforexprinstmt(r_expr* e,program* r)
{
if(e->tag == string("IDENT"))
	{
		if(e->identname != "this")
		{
			e->m_type =r->m_variables[e->identname];
		}
		else
		{
			cerr<<"illegal calling this"<<endl;
			exit(-1);
		}
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//e->m_type = c->m_variables[e->identname];
		cerr<<"not allowed to call private member"<<endl;
		exit(-1);
	}
	else if(e->tag == string("bin_oper"))
	{
		buildtypeforexprinstmt(e->b.l,r);
		buildtypeforexprinstmt(e->b.r,r);
		auto oper = e->b.s;
		if(classtable[e->b.l->m_type]->methodtable.find(oper) == classtable[e->b.l->m_type]->methodtable.end())
		{
			cout<<oper<<endl;
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			auto p = classtable[e->b.l->m_type]->methodtable[oper]->para()[0].type;
			if(!issubtype(e->b.r->m_type,p))
			{
				cerr<< "wrong type got"<<endl;
				exit(-1);
			}
			else
			{
				e->m_type = classtable[e->b.l->m_type]->methodtable[oper]->m_returntype;
			}
		}
	}
	else if(e->tag == string("single_oper"))
	{
		buildtypeforexprinstmt(e->s.e,r);
		auto oper = e->s.s;
		if(classtable[e->s.e->m_type]->methodtable.find(oper) == classtable[e->s.e->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[e->s.e->m_type]->methodtable[oper]->m_returntype;
		}
	}
	else if(e->tag == string("function_call"))
	{
		//check if there is function
		//s->m_variable[e->f.s] = "Bottom";
		//getinitializedidentformethod(e,s,m);
		buildtypeforexprinstmt(e->f.e,r);
		auto temp = e->f.e->m_type;
		cout<<temp<<endl;
		if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
		{
			cerr<<"unknown function "<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[temp]->methodtable[e->f.s]->m_returntype;
			for(auto i: e->f.p->m_value)
			{
				buildtypeforexprinstmt(i,r);
			}
		}
	}
	else if(e->tag == string("class_call"))
	{
		if(classtable.find(e->c.s) != classtable.end())
		{
			e->m_type = classtable[e->c.s]->name();
			for(auto i : e->c.p->m_value)
			{
				buildtypeforexprinstmt(i,r);
			}
		}
		else
		{
			cerr<<"unknown function or class call"<<endl;
			exit(-1);
		}
	}
	else
	{
	}
}





void buildtypeforstmtinstmt(statement* s, statement* s2, program* r)
{
	if(s->tag == string("IFELSE"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinstmt(j,s2,r);
			}
		}
		for(auto j: s->elsestatements->value())
		{
			buildtypeforstmtinstmt(j,s2,r);
		}

	}
	else if(s->tag == string("IF"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinstmt(j,s2,r);
			}		
		}
	}
	else if(s->tag == string("WHILE"))
	{
		buildtypeforexprinstmt(s->whilestatement.condition,r);
		if(!issubtype(s->whilestatement.condition->m_type,"Boolean"))
		{
			cerr<< "Invalid condition expression"<<endl;
			exit(-1);
		}
		for(auto i: s->whilestatement.execution->value())
		{
			buildtypeforstmtinstmt(i,s2,r);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		// if(!issubtype(s->exp->m_type,m->m_returntype))
		// {
		// 	cerr<<"Wrong return type"<<endl;
		// 	exit(-1);
		// }
		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
		//getinitializedidentformethod(s->exp,s,m);
	}
	else if (s->tag == string("GETVALUE"))
	{
		buildtypeforexprinstmt(s->g_value.right,r);
		if(s->g_value.left->tag == string("IDENT"))
		{
			s2->m_variables[s->g_value.left->identname] = LCA(s->g_value.left->m_type,s->g_value.right->m_type);
			s->g_value.left->m_type = r->m_variables[s->g_value.left->identname];
		}
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		cerr<<"not allowd here"<<endl;
		exit(-1);
	}			
	else
	{

	}
}



void buildtypeforstmt(statement* s,statement* s2,program* r)
{
	cout<<s->tag<<endl;
	if(s->tag == string("IFELSE"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,s2,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmt(j,s2,r);
			}
		}
		for(auto j: s->elsestatements->value())
		{
			buildtypeforstmt(j,s2,r);
		}

	}
	else if(s->tag == string("IF"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,s2,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmt(j,s2,r);
			}		
		}
	}
	else if(s->tag == string("WHILE"))
	{
		buildtypeforexprinstmt(s->whilestatement.condition,s2,r);
		if(!issubtype(s->whilestatement.condition->m_type,"Boolean"))
		{
			cerr<< "Invalid condition expression"<<endl;
			exit(-1);
		}
		for(auto i: s->whilestatement.execution->value())
		{
			buildtypeforstmt(i,s2,r);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		// if(!issubtype(s->exp->m_type,m->m_returntype))
		// {
		// 	cerr<<"Wrong return type"<<endl;
		// 	exit(-1);
		// }
		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
		//getinitializedidentformethod(s->exp,s,m);
	}
	else if (s->tag == string("GETVALUE"))
	{
		buildtypeforexprinstmt(s->g_value.right,s2,r);
		if(s->g_value.left->tag == string("IDENT"))
		{
			auto name = s->g_value.left->identname;
			if(r->m_variables.find(name) != r->m_variables.end())
			{
				cout<<1<<endl;
				r->m_variables[s->g_value.left->identname] = LCA(r->m_variables[s->g_value.left->identname],s->g_value.right->m_type);
				s->g_value.left->m_type = r->m_variables[s->g_value.left->identname];
			}
			else
			{
				cout<<2<<endl;
				cout<<s2->m_variables[s->g_value.left->identname]<<" "<<s->g_value.right->m_type<<endl;
				s2->m_variables[s->g_value.left->identname] = LCA(s2->m_variables[s->g_value.left->identname],s->g_value.right->m_type);
				s->g_value.left->m_type = s2->m_variables[s->g_value.left->identname];
			}
			
		}
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		cerr<<"not allowd here"<<endl;
		exit(-1);
	}			
	else if(s->tag == "EXP")
	{
		buildtypeforexprinstmt(s->exp,s2,r);
	}
}



void buildtypeforstmt(statement* s,program* r)
{
	cout<<s->tag<<endl;
	if(s->tag == string("IFELSE"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmt(j,r);
			}
		}
		for(auto j: s->elsestatements->value())
		{
			buildtypeforstmt(j,r);
		}

	}
	else if(s->tag == string("IF"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmt(j,s,r);
			}		
		}
	}
	else if(s->tag == string("WHILE"))
	{
		buildtypeforexprinstmt(s->whilestatement.condition,r);
		if(!issubtype(s->whilestatement.condition->m_type,"Boolean"))
		{
			cerr<< "Invalid condition expression"<<endl;
			exit(-1);
		}
		for(auto i: s->whilestatement.execution->value())
		{
			buildtypeforstmt(i,s,r);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		// if(!issubtype(s->exp->m_type,m->m_returntype))
		// {
		// 	cerr<<"Wrong return type"<<endl;
		// 	exit(-1);
		// }
		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
		//getinitializedidentformethod(s->exp,s,m);
	}
	else if (s->tag == string("GETVALUE"))
	{
		buildtypeforexprinstmt(s->g_value.right,r);
		if(s->g_value.left->tag == string("IDENT"))
		{
			r->m_variables[s->g_value.left->identname] = LCA(r->m_variables[s->g_value.left->identname],s->g_value.right->m_type);
			s->g_value.left->m_type = r->m_variables[s->g_value.left->identname];
		}
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		cerr<<"not allowd here"<<endl;
		exit(-1);
	}			
	else if(s->tag == "EXP")
	{
		buildtypeforexprinstmt(s->exp,r);
	}
}

















































int main(int argv, char** argc) {
	// open a file handle to a particular file:
	FILE *myfile = fopen(argc[1], "r");
	// make sure it's valid:
	if (!myfile) {
		cout << "I can't open the input file!" << endl;
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	cout<<"Being parsing"<<endl;
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	cout<<"Finished parsing with 0 errors"<<endl;
	//cout<<root<<endl;
	init();
	class_inherit_issue();
	class_method_inherit();
	auto c = classtable["Int"];
	for(auto i: c->methodtable)
	{
		cout<<i.first<<" "<<i.second->origin_class<<endl;
	}
	



	for(auto i: root->cs)
	{	
		for(auto j:i->para())
		{
			i->m_variables_temp[j.name] = j.type;
		}
		for(auto j:i->m_statements)
		{
			buildvariableforclass(j,i);
		}
		for(auto j: i->m_methods)
		{	
			methodstmt(j,i);
		}

	}
	for (auto i:root->ss)
	{
		buildvariableforstmt(i,root);
	}
	cout<<"Finished build variables"<<endl;
	for(auto c:root->cs)
	{
		for(auto s:c->m_statements)
		{
			buildtypeforstmtinclass(s,c);
		}
		cout<<"Finished build types for in class for "<<c->name()<<endl;
		for(auto m:c->methodtable)
		{
			cout<<"Begin build types for method "<<m.first<<" in "<<c->name()<<endl;
			for(auto s:m.second->methodstatements)
			{
				buildtypeforstmtinmethod(s,m.second,c);
			}
			cout<<"Finished build types for in method for "<<m.first<<" in "<<c->name()<<endl;
		}

	}
	for(auto i:root->ss)
	{
		buildtypeforstmt(i,root);
	}
	cout<<"Finished build type"<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"******************************************************************************"<<endl;
	codegenpgm(root);
	cout<<"********************************************************************************"<<endl;
}




void yyerror(const char *s) {
	
	cout << yylineno << ": " << s <<"(at '"<<yytext<<"')"<< endl;
	// might as well halt now:
	exit(-1);
}


