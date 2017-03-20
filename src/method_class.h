#ifndef METHOD_CLASS_H
#define METHOD_CLASS_H
#include "node.h"
#include "stmt.h"




class extend: public node
{
public:
	extend(char* i);
	~extend();
	std::string value();
protected:
	std::string m_value;
	//void evaluate();
};
class formal_args_first : public node
{
public:
	formal_args_first(char* s1,char* s2);
	~formal_args_first();
	Para value();
private:
	Para m_value;
	
};

class formal_args_ident : public node
{
public:
	formal_args_ident(char* s1,char* s2);
	~formal_args_ident();
	Para value();
private:
	Para m_value;
};

class formal_args_idents : public node
{
public:
	formal_args_idents();
	formal_args_idents(formal_args_idents*,formal_args_ident*);
	~formal_args_idents();
	std::vector<Para> value();
	std::vector<Para> m_value;
	//std::vector<formal_args_ident> value();
};





class formal_args : public node
{
public:
	formal_args();
	//formal_args(formal_args f);
	formal_args(formal_args_first* f,formal_args_idents* i );
	~formal_args();
	std::vector<Para> value();
	std::vector<Para> m_value;
	//std::vector<std::string> value();
};
class method:public node
{
public:
	method(char* s1,formal_args* f,char* s2,statements* s);
	method(char* s1,formal_args* f,statements* s);
	~method();
	std::string name();
	std::string type();
	std::vector<Para> para();
	std::unordered_map<std::string,std::string> variables();
	std::vector<statement*> methodstatements;
private:
	std::string m_type;
	std::string m_name;
	std::vector<Para> m_para;
	std::string m_returntype;
	std::unordered_map<std::string,std::string> m_variables;
};


class methods : public node
{
public:
	methods();
	methods(methods* ms,method* m);
	~methods();
	std::vector<method*> value();
	std::vector<method*> m_value;
	//std::vector<method> former;

};


class class_body:public node
{
public:
	class_body(statements* s,methods* m);
	std::vector<statement*> class_statements();
	std::vector<method*> class_methods();
	~class_body();
private:

	std::vector<statement*> m_statements;
	std::vector<method*> m_methods;
	
};



class class_sig : public node
{
public:
	class_sig(char* s,formal_args* f );
	class_sig(char* s, formal_args* f,extend* e);
	~class_sig();
	//formal_args m_f_args;
	std::string name();
	std::string parent();
	std::vector<Para> para();
protected:
	std::string m_name;
	std::string m_parent;
	std::vector<Para> m_para;
};



class basic_class:public node
{
public:
	basic_class(class_sig* s, class_body* b);
	basic_class();
	~basic_class();
	std::string name();
	std::string parent();
	std::vector<Para> para();
	std::string m_name;
	std::string m_parent;
	std::vector<Para> m_para;
	basic_class* reference;
	std::vector<method*> m_methods;
	std::vector<method*> m_inherit_methods;
	std::vector<statement*> m_statements;
	std::unordered_map<std::string,method*> methodtable;
	std::unordered_map<std::string,std::string> m_variables; 
//protected:
	//class_sig m_sign;
	//class_body m_body;

	//std::string name;
	//std::string parent;
	//std::vector<std::string> method_names; 

};

class basic_classes : public node
{
public:
	basic_classes();
	basic_classes(basic_classes* bcs, basic_class* bc);
	~basic_classes();

	std::vector<basic_class*> value();
	std::vector<basic_class*> m_value;
};
class program : public node
{public:
	program(basic_classes* cs,statements* ss);
	~program();
	//std::map<std::string,std::string> classes;
// protected:
// private:
	std::vector<basic_class*> cs;
	std::vector<statement*> ss;
	void class_inherit_issue();
	void class_method_inherit();
};

#endif
