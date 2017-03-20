#include "AST.h"
using namespace std;
// for the build in int class
extern basic_class* Obj = new basic_class();

extern basic_class* quack_int = new basic_class();

extern basic_class* quack_str = new basic_class();

extern basic_class* quack_boolean = new basic_class();

extern basic_class* quack_nothing = new basic_class();
void initbuildinclass()
{
/*
 the quack obj class build in methods
*/
	Obj->m_name = "Obj";
	auto s_obj = new statements();
	auto fs_obj = new formal_args();
	auto obj_print = new method("PRINT",fs_obj,s_obj);
	obj_print->origin_class = "Obj";
	auto obj_STR = new method("STR",fs_obj,"String",s_obj);
	obj_STR->origin_class = "Obj";
    	Obj->methodtable["PRINT"] = obj_print;
	Obj->m_methods.push_back(obj_print);
	Obj->methodtable["STR"] = obj_STR;
	Obj->m_methods.push_back(obj_STR);
    

/*
the quack nothing class build in methods
*/
	quack_nothing->m_name = "NOTHING";
	quack_nothing->m_parent = "Obj";
	quack_nothing->reference = Obj;
	quack_nothing->methodtable["PRINT"] = obj_print;
	quack_nothing->m_methods.push_back(obj_print);

/*
the quack boolean class build in methods
*/
	quack_boolean->m_name = "Boolean";
	quack_boolean->m_parent = "Obj";
	quack_boolean->reference = Obj;
	auto s_boolean = new statements();
	auto fs_boolean = new formal_args();
	fs_boolean->m_value.push_back({"x","Boolean"});
	auto boolean_and = new method("AND",fs_boolean,s_boolean);
	boolean_and->origin_class = "Boolean";
    quack_boolean->methodtable["AND"] = boolean_and;
	quack_boolean->m_methods.push_back(boolean_and);

	auto boolean_or = new method("OR",fs_boolean,s_boolean);
	boolean_or->origin_class = "Boolean";
    quack_boolean->methodtable["OR"] = boolean_or;
	quack_boolean->m_methods.push_back(boolean_or);
	fs_boolean->m_value.clear();
	auto boolean_not = new method("NOT",fs_boolean,s_boolean);
	boolean_not->origin_class = "Boolean";
    quack_boolean->methodtable["NOT"] = boolean_not;
	quack_boolean->m_methods.push_back(boolean_not);
quack_boolean->methodtable["PRINT"] = obj_print;
	quack_boolean->m_methods.push_back(obj_print);



/*
the quack str class build in methods
*/
	quack_str->m_name = "String";
	quack_str->m_parent = "Obj";
	quack_str->reference = Obj;
	auto s_str = new statements();
	auto fs_str = new formal_args();
	fs_str->m_value.push_back({"x","String"});
	
	auto str_plus = new method("PLUS",fs_str,"String",s_str);
	str_plus->origin_class = "String";
	quack_str->methodtable["PLUS"] = str_plus;
	quack_str->m_methods.push_back(str_plus);

	auto str_equals = new method("EQUALS",fs_str,"Boolean",s_str);
	str_equals->origin_class = "String";
    	quack_str->methodtable["EQUALS"] = str_equals;
	quack_str->m_methods.push_back(str_equals);
quack_str->methodtable["PRINT"] = obj_print;
	quack_str->m_methods.push_back(obj_print);
    
    

/*
 the quack int class build in methods
*/
	quack_int->m_name = "Int";
	quack_int->m_parent = "Obj";
	quack_int->reference = Obj;
	auto s_int = new statements();
	auto fs_int = new formal_args();
	fs_int->m_value.push_back({"x","Int"});


	auto int_STR = new method("STR",fs_int,"String",s_int);
	int_STR->origin_class = "Int";
	quack_int->methodtable["STR"] = int_STR;
	quack_int->m_methods.push_back(int_STR);	

	auto int_plus = new method("PLUS",fs_int,"Int",s_int);
	int_plus->origin_class = "Int";
	quack_int->methodtable["PLUS"] = int_plus;
	quack_int->m_methods.push_back(int_plus);

	auto int_minus = new method("MINUS",fs_int,"Int",s_int);
	int_minus->origin_class = "Int";
	quack_int->methodtable["MINUS"] = int_minus;
	quack_int->m_methods.push_back(int_minus);

	auto int_times = new method("TIMES",fs_int,"Int",s_int);
	int_times->origin_class = "Int";
	quack_int->methodtable["TIMES"] = int_times;
	quack_int->m_methods.push_back(int_times);

	auto int_divide = new method("DIVIDE",fs_int,"Int",s_int);
	int_divide->origin_class = "Int";
	quack_int->methodtable["DIVIDE"] = int_divide;
	quack_int->m_methods.push_back(int_divide);

	auto int_equals = new method("EQUALS",fs_int,"Boolean",s_int);
	int_equals->origin_class = "Int";
	quack_int->methodtable["EQUALS"] = int_equals;
    quack_int->m_methods.push_back(int_equals);

    auto int_less = new method("LESS",fs_int,"Boolean",s_int);
    int_less->origin_class = "Int";
	quack_int->methodtable["LESS"] = int_less;
    quack_int->m_methods.push_back(int_less);

    auto int_more = new method("MORE",fs_int,"Boolean",s_int);
    int_more->origin_class = "Int";
	quack_int->methodtable["MORE"] = int_more;
    quack_int->m_methods.push_back(int_more);

    auto int_atmost = new method("ATMOST",fs_int,"Boolean",s_int);
    int_atmost->origin_class = "Int";
	quack_int->methodtable["ATMOST"] = int_atmost;
    quack_int->m_methods.push_back(int_atmost);

    auto int_atleast = new method("ATLEAST",fs_int,"Boolean",s_int);
    int_atleast->origin_class = "Int";
	quack_int->methodtable["ATLEAST"] = int_atleast;
    quack_int->m_methods.push_back(int_atleast);

quack_int->methodtable["PRINT"] = obj_print;
	quack_int->m_methods.push_back(obj_print);

    





}
