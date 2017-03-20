#ifndef STMT_H
#define STMT_H
#include "node.h"
#include "expr.h"
#include "method_class.h"

class statements;
class statement; 
class ifstmt; 
class expstmt;
class returnstmt;

typedef struct 
{
	r_expr* condition;
	statements* execution;
}branch;






class stmt:public node
{
public:
	stmt();
	~stmt();
	std::unordered_map<std::string,std::string> m_variables;
	std::string tag;
};






class statement : public stmt
{
public:
	statement();
	~statement();
	std::vector<branch> branches;
	statements* elsestatements;
	branch whilestatement;
	std::string returntype;
};

class statements : public stmt
{
public:
	statements();
	statements(statements* ss,statement* s);
	~statements();
	std::vector<statement*> value();
	std::vector<statement*> m_value;

};

class elif:public node
{
public:
	elif(r_expr* e,statements* s);
	~elif();
	branch value();
	branch m_value;
};

class elifs:public node
{
public:
	elifs();
	elifs(elifs* es,elif* e);
	~elifs();
	std::vector<elif*> value();
private:
	std::vector<elif*> m_value;
};



class ifstmt:public statement
{
public:
	ifstmt(r_expr* exp,statements* s1,elifs* elfs,statements* s2);
	ifstmt(r_expr* exp,statements* s,elifs* elfs);
	~ifstmt();

};

class whilestmt : public statement
{
public:
	whilestmt(r_expr* exp,statements* s);
	~whilestmt();
};

class expstmt: public statement
{
public:
	expstmt(r_expr* r);
	expstmt(r_expr* l ,r_expr* r);
	expstmt(r_expr* l ,char* s,r_expr* r);
	~expstmt();
};

class returnstmt : public statement
{
public:
	returnstmt();
	returnstmt(r_expr* e);
	~returnstmt();
};






#endif
