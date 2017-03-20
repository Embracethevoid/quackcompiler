#ifndef R_EXPR_H
#define R_EXPR_H
#include "node.h"
class r_expr : public node
{
public:
	r_expr();
	~r_expr();
	std::string m_type;
};

class ident : public node
{
public:
	ident(char*);
	~ident();
	std::string value();
protected:
	std::string m_value;

};

class r_exprs: public node
{
public:
	r_exprs();
	r_exprs(r_exprs* es,r_expr* e);
	~r_exprs();
	std::vector<r_expr*> value(); 
	std::vector<r_expr*> m_value; 
};

class actual_args:public node
{
public:
	actual_args(r_expr* exp , r_exprs* e);
	actual_args();
	~actual_args();
	std::vector<r_expr*> m_value;
};

class make_ident : public r_expr
{
public:
	make_ident(char*);
	make_ident(r_expr* ,char*);
	~make_ident();
	std::string name();
	std::string m_name;
	std::string tag;
};


class element_call : public r_expr
{
public:
	element_call(r_expr* ,char*);
	~element_call();
};

class function_call : public r_expr
{
public:
	function_call(r_expr* e, char* s, actual_args* a);
	function_call(char* s, actual_args* a);
	~function_call();
};


class make_int : public r_expr
{
public:
	make_int(int i);
	~make_int();
	//int value();
private:
	//int m_value;

};

class make_str:public r_expr
{public:
	make_str(char* s);
	~make_str();
//	std::string value();
private:
//	std::string m_value;

};



class bin_operator : public r_expr
{public:
	bin_operator(r_expr* e1, char*s ,r_expr* e2);
	~bin_operator();

};

class negative_operator : public r_expr
{
public:
	negative_operator(r_expr* e);
	~negative_operator();
};

class not_operator: public r_expr
{
public:
	not_operator( r_expr *e);
	~not_operator();
};





#endif
