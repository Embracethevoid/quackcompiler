#include "AST.h"
#include "codegen.h"
#include <fstream>
using namespace std;

int temp = 0;
ofstream file_h;
ofstream file_c;


unordered_set<string> variabletale;



unordered_map<string,basic_class*> classtable;


string type2structname(string s)
{
	if(s == "INT")
	{
		return "obj_Int";
	}
	else if(s == "Obj")
	{
		return "obj_Obj";
	}
	else if(s == "String" || s == "STR")
	{
		return "obj_String";
	}
	else if(s == "Boolean")
	{
		return "obj_Boolean";
	}
	else if (s == "NOTHING")
	{
		return "obj_Nothing";
	}
	else if(s == string("Bottom"))
	{
		return "Bottom";
	}
	else
	{
		return "obj_"+s;
	}
}




codegen codegenforexpr(r_expr* e,statement* s,program* root)
{
	cout<<e->tag<<endl;
	if(e->tag == string("IDENT"))
	{
		if(variabletale.find(e->identname) == variabletale.end())
		{
			variabletale.insert(e->identname);
			if(root->m_variables.find(e->identname) != root->m_variables.end())
			{
				return codegen{type2structname(root->m_variables[e->identname])+" "+e->identname+";",e->identname};
			}
			else
			{
				return codegen{type2structname(s->m_variables[e->identname])+" "+e->identname+";",e->identname};
			}
		}
		else
		{
			return codegen{"",e->identname};
		}
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		
	}
	else if(e->tag == string("bin_oper"))
	{
			auto l = codegenforexpr(e->b.l,s,root);
			auto r = codegenforexpr(e->b.r,s,root);
			file_h<< l.s<<endl<<r.s<<endl;
			++temp;
			return codegen{type2structname(e->m_type)+" temp"+to_string(temp)+ " = " +l.v+"->clazz->"+e->b.s+"("+l.v+","+r.v+");","temp"+to_string(temp)};
	}
	else if(e->tag == string("single_oper"))
	{
		auto expr = codegenforexpr(e->s.e,s,root);
		file_h<<expr.s<<endl;
		return codegen{expr.v+"->clazz->"+e->s.s+"("+expr.v+")","temp"+to_string(temp)};
	}
	else if(e->tag == string("function_call"))
	{
		++temp;
		int t = temp;
		auto c = codegenforexpr(e->f.e,s,root);
		file_h<<c.s<<endl;
		string res = type2structname(e->m_type)+" temp"+to_string(temp)+" = "+ c.v + "->clazz->"+ e->f.s+"(";
		int flag = 0;
			if(e->f.e->tag == "IDENT")
		{
				res += c.v;
			
		}
		else if(e->f.e->tag == "IDENTINMEMBER")
		{

				res += c.v;
			
			
		}
		for(int i = 0; i< e->f.p->m_value.size();++i)
		{
			auto t = codegenforexpr(e->f.p->m_value[i],s,root);
			file_h<< t.s<<endl;
			
				res += " , "+t.v;
		}
		res+=");";
		return{res,"temp"+to_string(t)};
	}
	else if(e->tag == string("class_call"))
	{
		++temp;
		int t = temp;
		auto res = type2structname(e->m_type) + " temp"+to_string(t)+" = "+e->m_type+"_literal(";
		for(int i = 0; i< e->c.p->m_value.size();++i)
		{
			auto c  = codegenforexpr(e->c.p->m_value[i],s,root);
			file_h<<c.s<<endl;
			if(i == 0)
			{
				res += c.v;
			}
			else
			{
				res+= " , "+c.v;
			}
		}
		res +=");";
		return codegen{res,"temp"+to_string(t)};
	}
	else if(e->tag == string("Int"))
	{
		++temp;
		//file_h<< "obj_Int temp"+to_string(temp)+ " = int_literal("+ e->m_value+");"<<endl;
		return codegen{"obj_Int temp"+to_string(temp)+ " = int_literal("+ e->m_value+");","temp"+to_string(temp)};

	}
	else if(e->tag == string("String"))
	{
		++temp;
		return codegen{"obj_String temp"+to_string(temp)+ " = str_literal("+ e->m_value+");","temp"+to_string(temp)};

	}
}





















codegen codegenforexpr(r_expr* e,program* root)
{
	if(e->tag == string("IDENT"))
	{
		if(variabletale.find(e->identname) == variabletale.end())
		{
			variabletale.insert(e->identname);
			return codegen{type2structname(root->m_variables[e->identname])+" "+e->identname+";",e->identname};
		}
		else
		{
			return codegen{"",e->identname};
		}
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		
	}
	else if(e->tag == string("bin_oper"))
	{
			auto l = codegenforexpr(e->b.l,root);
			auto r = codegenforexpr(e->b.r,root);
			file_c<< l.s<<endl<<r.s<<endl;
			++temp;
			return codegen{type2structname(e->m_type)+" temp"+to_string(temp)+ " = " +l.v+"->clazz->"+e->b.s+"("+l.v+","+r.v+");","temp"+to_string(temp)};
	}
	else if(e->tag == string("single_oper"))
	{
		auto expr = codegenforexpr(e->s.e,root);
		file_c<<expr.s<<endl;
		return codegen{expr.v+"->clazz->"+e->s.s+"("+expr.v+")","temp"+to_string(temp)};
	}
	else if(e->tag == string("function_call"))
	{
		++temp;
		int t = temp;
		auto c = codegenforexpr(e->f.e,root);
		file_c<<c.s<<endl;
		string res = type2structname(e->m_type) +" temp"+to_string(temp) +" = "+ c.v + "->clazz->"+ e->f.s+"(";
		int flag = 0;
		if(e->f.e->tag == "IDENT")
		{
				res += c.v;
			
		}
		else if(e->f.e->tag == "IDENTINMEMBER")
		{

				res += c.v;
			
			
		}
		for(int i = 0; i< e->f.p->m_value.size();++i)
		{
			auto t = codegenforexpr(e->f.p->m_value[i],root);
			file_c<< t.s<<endl;
			res += " , "+t.v;
		}
		res+=");";
		return{res,"temp"+to_string(t)};
	}
	else if(e->tag == string("class_call"))
	{
		++temp;
		int t = temp;
		auto res = type2structname(e->m_type) + " temp"+to_string(t)+" = "+e->m_type+"_literal(";
		for(int i = 0; i< e->c.p->m_value.size();++i)
		{
			auto c  = codegenforexpr(e->c.p->m_value[i],root);
			file_c<<c.s<<endl;
			if(i == 0)
			{
				res += c.v;
			}
			else
			{
				res+= " , "+c.v;
			}
		}
		res +=");";
		return codegen{res,"temp"+to_string(t)};
	}
	else if(e->tag == string("Int"))
	{
		++temp;
		//file_h<< "obj_Int temp"+to_string(temp)+ " = int_literal("+ e->m_value+");"<<endl;
		return codegen{"obj_Int temp"+to_string(temp)+ " = int_literal("+ e->m_value+");","temp"+to_string(temp)};

	}
	else if(e->tag == string("String"))
	{
		++temp;
		return codegen{"obj_String temp"+to_string(temp)+ " = str_literal("+ e->m_value+");","temp"+to_string(temp)};

	}
}



// unordered_set<string> variabletale_class;
// codegen codegenforexprinclass(r_expr* e,statement* s,program* root)
// {
// 	if(e->tag == string("IDENT"))
// 	{
// 		// if(variabletale.find(e->identname) == variabletale.end())
// 		// {
// 		// 	variabletale.insert(e->identname);
// 		// 	return codegen{type2structname(root->m_variables[e->identname])+" "+e->identname+";",e->identname};
// 		// }
// 		// else
// 		// {
// 			return codegen{"",e->identname};
// 		// }
// 	}
// 	else if (e->tag == string("IDENTINMEMBER"))
// 	{
// 		return codegen{"","m_"+e->identname};
// 	}
// 	else if(e->tag == string("bin_oper"))
// 	{
// 			auto l = codegenforexprinclass(e->b.l,s,root);
// 			auto r = codegenforexprinclass(e->b.r,s,root);
// 			file_h<< l.s<<endl<<r.s<<endl;
// 			++temp;
// 			return codegen{type2structname(e->m_type)+" temp"+to_string(temp)+ " = " +l.v+"->clazz->"+e->b.s+"("+l.v+","+r.v+");","temp"+to_string(temp)};
// 	}
// 	else if(e->tag == string("single_oper"))
// 	{
// 		// if(e->s.s == "NEG")
// 		// {
// 		// 	return "- "+codegenforexpr(e->s.e);
// 		// }
// 		// else if(e->s.s == "NOT")
// 		// {
// 		// 	return "not "+codegenforexpr(e->s.e);
// 		// }
// 		auto expr = codegenforexprinclass(e->s.e,root);
// 		file_h<<expr.s<<endl;
// 		return codegen{expr.v+"->clazz->"+e->s.s+"("+expr.v+")","temp"+to_string(temp)};
// 	}
// 	else if(e->tag == string("function_call"))
// 	{
// 		++temp;
// 		int t = temp;
// 		//auto res = type2structname(e->m_type) + " temp"+to_string(t)+" = new_"+e->m_type+"(";
// 		auto c = codegenforexprinclass(e->f.e,root);
// 		file_h<<c.s<<endl;
// 		string res = type2structname(e->m_type) + " temp"+to_string(t)+" = new_"+c.v + "->clazz->"+ e->f.s+"(";
// 		for(int i = 0; i< e->f.p->m_value.size();++i)
// 		{
// 			auto t = codegenforexprinclass(e->f.p->m_value[i],root);
// 			file_h<< t.s<<endl;
// 			if(i == 0)
// 			{
// 				res += t.v;
// 			}
// 			else
// 			{
// 				res += " , "+t.v;
// 			}
// 		}
// 		res+=");";
// 		return{res,"temp"+to_string(t)};
// 	}
// 	else if(e->tag == string("class_call"))
// 	{
// 		++temp;
// 		int t = temp;
// 		auto res = type2structname(e->m_type) + " temp"+to_string(t)+" = new_"+e->m_type+"(";
// 		for(int i = 0; i< e->c.p->m_value.size();++i)
// 		{
// 			auto c  = codegenforexprinclass(e->c.p->m_value[i],root);
// 			file_h<<c.s<<endl;
// 			if(i == 0)
// 			{
// 				res += c.v;
// 			}
// 			else
// 			{
// 				res+= " , "+c.v;
// 			}
// 		}
// 		res +=");";
// 		return codegen{res,"temp"+to_string(t)};
// 	}
// 	else if(e->tag == string("Int"))
// 	{
// 		++temp;
// 		//file_h<< "obj_Int temp"+to_string(temp)+ " = int_literal("+ e->m_value+");"<<endl;
// 		return codegen{"obj_Int temp"+to_string(temp)+ " = int_literal("+ e->m_value+");","temp"+to_string(temp)};

// 	}
// 	else if(e->tag == string("String"))
// 	{
// 		++temp;
// 		return codegen{"obj_str temp"+to_string(temp)+ " = str_literal("+ e->m_value+");","temp"+to_string(temp)};

// 	}
// 	else
// 	{
// 		//return codegen(e->exp);
// 	}
// }



unordered_set<string> variabletale_class;
codegen codegenforexprinclass(r_expr* e,basic_class* c,program* root)
{
	if(e->tag == string("IDENT"))
	{
		if(variabletale_class.find(e->identname) == variabletale_class.end())
		{
			variabletale_class.insert(e->identname);
			return codegen{type2structname(c->m_variables_temp[e->identname])+" "+e->identname+";",e->identname};
		}
		else
		{
			return codegen{"",e->identname};
		
		}
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		return codegen{"","new_thing->m_"+e->identname};
	}
	else if(e->tag == string("bin_oper"))
	{
			auto l = codegenforexprinclass(e->b.l,c,root);
			auto r = codegenforexprinclass(e->b.r,c,root);
			file_h<< l.s<<endl<<r.s<<endl;
			++temp;
			// cout<<e->b.l->tag<<" "<<e->b.l->m_type<<endl;
			// if(e->b.l->tag == "IDENT")
			// {
			// 	e->b.l->m_type = c->m_variables_temp[e->b.l->identname];
			// }
			// else if(e->b.l->tag == "IDENTINMEMBER")
			// {
			// 	e->b.l->m_type = c->m_variables[e->b.l->identname];
			// }
			// string type = classtable[e->b.l->m_type]->methodtable[e->b.l->identname]->m_returntype;
			// cout<<type<<endl;
			cout<<e->m_type<<" "<<c->name()<<endl;
			return codegen{type2structname(e->m_type)+" temp"+to_string(temp)+ " = " +l.v+"->clazz->"+e->b.s+"("+l.v+","+r.v+");","temp"+to_string(temp)};
	}
	else if(e->tag == string("single_oper"))
	{
		// if(e->s.s == "NEG")
		// {
		// 	return "- "+codegenforexpr(e->s.e);
		// }
		// else if(e->s.s == "NOT")
		// {
		// 	return "not "+codegenforexpr(e->s.e);
		// }
		auto expr = codegenforexprinclass(e->s.e,c,root);
		file_h<<expr.s<<endl;
		return codegen{expr.v+"->clazz->"+e->s.s+"("+expr.v+")","temp"+to_string(temp)};
	}
	else if(e->tag == string("function_call"))
	{
		++temp;
		int t = temp;
		//auto res = type2structname(e->m_type) + " temp"+to_string(t)+" = new_"+e->m_type+"(";
		auto con = codegenforexprinclass(e->f.e,c,root);
		file_h<<con.s<<endl;
		// if(e->f.e->tag == "IDENT")
		// {
		// 	e->f.e->m_type = c->m_variables_temp[e->f.e->identname];
		// }
		// else if(e->f.e->tag == "IDENTINMEMBER")
		// {
		// 	e->f.e->m_type = c->m_variables[e->f.e->identname];
		// }
		cout<<e->m_type<<endl;
		//string type = classtable[e->f.e->m_type]->methodtable[e->f.s]->m_returntype;
		string res = type2structname(e->m_type) + " temp"+to_string(t)+" = "+con.v + "->clazz->"+ e->f.s+"(";
		res += codegenforexprinclass(e->f.e,c,root).v;
		
		for(int i = 0; i< e->f.p->m_value.size();++i)
		{
			auto t = codegenforexprinclass(e->f.p->m_value[i],c,root);
			file_h<< t.s<<endl;
			
				res += " , "+t.v;
		}
		res+=");";
		return{res,"temp"+to_string(t)};
	}
	else if(e->tag == string("class_call"))
	{
		++temp;
		int t = temp;
		auto res = type2structname(e->m_type) + " temp"+to_string(t)+" = "+e->m_type+"_literal(";
		for(int i = 0; i< e->c.p->m_value.size();++i)
		{
			auto con  = codegenforexprinclass(e->c.p->m_value[i],c,root);
			file_h<<con.s<<endl;
			if(i == 0)
			{
				res += con.v;
			}
			else
			{
				res+= " , "+con.v;
			}
		}
		res +=");";
		return codegen{res,"temp"+to_string(t)};
	}
	else if(e->tag == string("Int"))
	{
		++temp;
		//file_h<< "obj_Int temp"+to_string(temp)+ " = int_literal("+ e->m_value+");"<<endl;
		return codegen{"obj_Int temp"+to_string(temp)+ " = int_literal("+ e->m_value+");","temp"+to_string(temp)};

	}
	else if(e->tag == string("String"))
	{
		++temp;
		return codegen{"obj_str temp"+to_string(temp)+ " = str_literal("+ e->m_value+");","temp"+to_string(temp)};

	}
	else
	{
		//return codegen(e->exp);
	}
}


unordered_set<string> variabletale_method;
codegen codegenforexprinmethod(r_expr* e,method* m,basic_class* c,program* root)
{
	if(e->tag == string("IDENT"))
	{
		// if(variabletale.find(e->identname) == variabletale.end())
		// {
		// 	variabletale.insert(e->identname);
		// 	return codegen{type2structname(root->m_variables[e->identname])+" "+e->identname+";",e->identname};
		// }
		// else
		// 
		if(variabletale_method.find(e->identname) == variabletale_method.end())
		{
			int flag = 1;
			for(auto i:m->para())
			{
				if(e->identname == i.name)
				{
					flag = 0;
				}
			}
			if(flag)
			{
				auto type = m->m_variables[e->identname];
				variabletale_method.insert(e->identname);
				return codegen{type2structname(type)+" "+e->identname+";",e->identname};
			}
			else
			{
				return codegen{"",e->identname};
			}
		}
		else
		{
			return codegen{"",e->identname};
		}
		// }
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		return codegen{"",e->identparent->identname+"->m_"+e->identname};
	}
	else if(e->tag == string("bin_oper"))
	{
			auto l = codegenforexprinmethod(e->b.l,m,c,root);
			auto r = codegenforexprinmethod(e->b.r,m,c,root);
			file_h<< l.s<<endl<<r.s<<endl;
			++temp;
			return codegen{type2structname(e->m_type)+" temp"+to_string(temp)+ " = " +l.v+"->clazz->"+e->b.s+"("+l.v+","+r.v+");","temp"+to_string(temp)};
	}
	else if(e->tag == string("single_oper"))
	{
		// if(e->s.s == "NEG")
		// {
		// 	return "- "+codegenforexpr(e->s.e);
		// }
		// else if(e->s.s == "NOT")
		// {
		// 	return "not "+codegenforexpr(e->s.e);
		// }
		auto expr = codegenforexprinmethod(e->s.e,m,c,root);
		file_h<<expr.s<<endl;
		return codegen{expr.v+"->clazz->"+e->s.s+"("+expr.v+")","temp"+to_string(temp)};
	}
	else if(e->tag == string("function_call"))
	{
		++temp;
		int t = temp;
		//auto res = type2structname(e->m_type) + " temp"+to_string(t)+" = new_"+e->m_type+"(";
		auto con = codegenforexprinmethod(e->f.e,m,c,root);
		file_h<<con.s<<endl;
		string type = classtable[e->f.e->m_type]->methodtable[e->f.s]->m_returntype;
		string res = type2structname(e->m_type) + " temp"+to_string(t)+" = "+con.v + "->clazz->"+ e->f.s+"(";
			if(e->f.e->tag == "IDENT")
		{
				res += con.v;
			
		}
		else if(e->f.e->tag == "IDENTINMEMBER")
		{

				res += con.v;
			
			
		}
		for(int i = 0; i< e->f.p->m_value.size();++i)
		{
			auto t = codegenforexprinmethod(e->f.p->m_value[i],m,c,root);
			file_h<< t.s<<endl;
		
				res += " , "+t.v;
		}
		res+=");";
		return{res,"temp"+to_string(t)};
	}
	else if(e->tag == string("class_call"))
	{
		++temp;
		int t = temp;
		auto res = type2structname(e->m_type) + " temp"+to_string(t)+" = "+e->m_type+"_literal(";
		for(int i = 0; i< e->c.p->m_value.size();++i)
		{
			auto con  = codegenforexprinmethod(e->c.p->m_value[i],m,c,root);
			file_h<<con.s<<endl;
			if(i == 0)
			{
				res += con.v;
			}
			else
			{
				res+= " , "+con.v;
			}
		}
		res +=");";
		return codegen{res,"temp"+to_string(t)};
	}
	else if(e->tag == string("Int"))
	{
		++temp;
		//file_h<< "obj_Int temp"+to_string(temp)+ " = int_literal("+ e->m_value+");"<<endl;
		return codegen{"obj_Int temp"+to_string(temp)+ " = int_literal("+ e->m_value+");","temp"+to_string(temp)};

	}
	else if(e->tag == string("String"))
	{
		++temp;
		return codegen{"obj_String temp"+to_string(temp)+ " = str_literal("+ e->m_value+");","temp"+to_string(temp)};

	}
	else
	{
		//return codegen(e->exp);
	}
}























void codegenforstmtinstmt(statement* s,statement* s2,program* root)
{
	if(s->tag == string("IFELSE"))
	{
		auto first = s->branches[0];
		auto con = codegenforexpr(first.condition,s2,root);
		file_c<<con.s<<endl;
		file_c<<"if("<<con.v<<")"<<endl<<"{"<<endl;
		for(auto j:first.execution->value())
		{
			codegenforstmtinstmt(j,root);
		}
		file_c<<"}"<<endl;
		for(int i = 1; i<s->branches.size();++i)
		{
			auto con = codegenforexpr(s->branches[i].condition,s2,root);
			file_c<<"else if("<<con.s<<")"<<endl<<"{"<<endl;
			for(auto j:s->branches[i].execution->value())
			{
				codegenforstmtinstmt(j,root);
			}
			file_c<<"}"<<endl;
		}
		auto last = s->elsestatements->value();
		file_c<<"else"<<endl<<"{"<<endl;
		for(auto j:last)
		{
			codegenforstmtinstmt(j,root);
		}
		file_c<<"}"<<endl;
	}
	else if(s->tag == string("IF"))
	{
		auto first = s->branches[0];
		auto con = codegenforexpr(first.condition,s2,root);
		file_c<<"if("<<con.s<<")"<<endl<<"{"<<endl;
		for(auto j:first.execution->value())
		{
			codegenforstmtinstmt(j,s,root);
		}
		file_c<<"}"<<endl;
		for(int i = 1; i<s->branches.size();++i)
		{
			auto con = codegenforexpr(s->branches[i].condition,s2,root);
			file_c<<"else if("<<con.s<<")"<<endl<<"{"<<endl;
			for(auto j:s->branches[i].execution->value())
			{
				codegenforstmtinstmt(j,s,root);
			}
			file_c<<"}"<<endl;
		}
	}
	else if(s->tag == string("WHILE"))
	{
		auto con = codegenforexpr(s->whilestatement.condition,root);
		file_c<<con.s<<endl;
		file_c<<"while("<<con.v<<")"<<endl<<"{"<<endl;
		for(auto j:s->whilestatement.execution->value())
		{
			codegenforstmtinstmt(j,s,root);
		}
		file_c<<"}"<<endl;
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
 		cerr<<"wrong stmt"<<endl;
 		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		cerr<<"wrong stmt"<<endl;
 		exit(-1);
	}
	else if (s->tag == string("GETVALUE"))
	{
		auto l = codegenforexpr(s->g_value.left,s2,root);
		auto r = codegenforexpr(s->g_value.right,s2,root);
		file_c<<l.s<<endl;
		file_c<<r.s<<endl;
		if(root->m_variables.find(s->g_value.left->identname) == root->m_variables.end())
		{
			if(root->m_variables[s->g_value.left->identname]!= s->g_value.right->m_type)
			{
				file_c<<l.v<<" = ("<<type2structname(root->m_variables[s->g_value.left->identname])<<")"
				<<r.v<<";"<<endl;
			}
			else
			{
				file_c<<l.v<<" = "
				<<r.v<<";"<<endl;
			}
		}
		else
		{
			if(s2->m_variables[s->g_value.left->identname]!= s->g_value.right->m_type)
			{
				file_c<<l.v<<" = ("<<type2structname(s2->m_variables[s->g_value.left->identname])<<")"
				<<r.v<<";"<<endl;
			}
			else
			{
				file_c<<l.v<<" = "
				<<r.v<<";"<<endl;
			}
		}
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else 
	{
		auto c =  codegenforexpr(s->exp,s2,root);
		file_c<<c.v<<endl;
	}
}































void codegenforstmtinstmt(statement* s,program* root)
{
	cout<<s->tag<<endl;
	if(s->tag == string("IFELSE"))
	{
		auto first = s->branches[0];
		auto con = codegenforexpr(first.condition,root);
		for(auto i:s->m_variables)
		{
			file_c<<type2structname(root->m_variables[i.first])<<" "<<i.first<<";"<<endl;
			variabletale.insert(i.first);
		}
		file_c<<con.s<<endl;
		file_c<<"if("<<con.v<<"->value)"<<endl<<"{"<<endl;
		for(auto j:first.execution->value())
		{
			codegenforstmtinstmt(j,root);
		}
		file_c<<"}"<<endl;
		for(int i = 1; i<s->branches.size();++i)
		{
			auto con = codegenforexpr(s->branches[i].condition,root);
			file_c<<"else if("<<con.s<<")"<<endl<<"{"<<endl;
			for(auto j:s->branches[i].execution->value())
			{
				codegenforstmtinstmt(j,root);
			}
			file_c<<"}"<<endl;
		}
		auto last = s->elsestatements->value();
		file_c<<"else"<<endl<<"{"<<endl;
		for(auto j:last)
		{
			codegenforstmtinstmt(j,root);
		}
		file_c<<"}"<<endl;
	}
	else if(s->tag == string("IF"))
	{
		auto first = s->branches[0];
		auto con = codegenforexpr(first.condition,root);
		file_c<<"if("<<con.s<<")"<<endl<<"{"<<endl;
		for(auto j:first.execution->value())
		{
			codegenforstmtinstmt(j,s,root);
		}
		file_c<<"}"<<endl;
		for(int i = 1; i<s->branches.size();++i)
		{
			auto con = codegenforexpr(s->branches[i].condition,root);
			file_c<<"else if("<<con.s<<")"<<endl<<"{"<<endl;
			for(auto j:s->branches[i].execution->value())
			{
				codegenforstmtinstmt(j,s,root);
			}
			file_c<<"}"<<endl;
		}
	}
	else if(s->tag == string("WHILE"))
	{
		auto con = codegenforexpr(s->whilestatement.condition,root);
		file_c<<con.s<<endl;
		file_c<<"while("<<con.v<<")"<<endl<<"{"<<endl;
		for(auto j:s->whilestatement.execution->value())
		{
			codegenforstmtinstmt(j,s,root);
		}
		file_c<<"}"<<endl;
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
 		cerr<<"wrong stmt"<<endl;
 		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		cerr<<"wrong stmt"<<endl;
 		exit(-1);
	}
	else if (s->tag == string("GETVALUE"))
	{
		auto l = codegenforexpr(s->g_value.left,root);
		auto r = codegenforexpr(s->g_value.right,root);
		file_c<<l.s<<endl;
		file_c<<r.s<<endl;
		if(root->m_variables[s->g_value.left->identname]!= s->g_value.right->m_type)
		{
			file_c<<l.v<<" = ("<<type2structname(root->m_variables[s->g_value.left->identname])<<")"
			<<r.v<<";"<<endl;
		}
		else
		{
			file_c<<l.v<<" = "
			<<r.v<<";"<<endl;
		}
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else 
	{
		auto c =  codegenforexpr(s->exp,root);
		file_c<<c.s<<endl;
	}
}







// void codegenforstmtinclass(statement* s,statement* s2,program* root)
// {
// 	if(s->tag == string("IFELSE"))
// 	{
// 		auto first = s->branches[0];
// 		auto con = codegenforexprinclass(first.condition,s2,root);
// 		file_h<<"if("<<con.s<<")"<<endl<<"{"<<endl;
// 		for(auto j:first.execution->value())
// 		{
// 			codegenforstmtinclass(j,s2,root);
// 		}
// 		file_h<<"}"<<endl;
// 		for(int i = 1; i<s->branches.size();++i)
// 		{
// 			auto con = codegenforexprinclass(s->branches[i].condition,root);
// 			file_h<<"else if("<<con.s<<")"<<endl<<"{"<<endl;
// 			for(auto j:s->branches[i].execution->value())
// 			{
// 				codegenforstmtinclass(j,s2,root);
// 			}
// 			file_h<<"}"<<endl;
// 		}
// 		auto last = s->elsestatements->value();
// 		file_h<<"else"<<endl<<"{"<<endl;
// 		for(auto j:last)
// 		{
// 			codegenforstmtinclass(j,s2,root);
// 		}
// 		file_h<<"}"<<endl;
// 	}
// 	else if(s->tag == string("IF"))
// 	{
// 		auto first = s->branches[0];
// 		auto con = codegenforexprinclass(first.condition,root);
// 		file_h<<"if("<<con.s<<")"<<endl<<"{"<<endl;
// 		for(auto j:first.execution->value())
// 		{
// 			codegenforstmtinclass(j,s2,root);
// 		}
// 		file_h<<"}"<<endl;
// 		for(int i = 1; i<s->branches.size();++i)
// 		{
// 			auto con = codegenforexprinclass(s->branches[i].condition,root);
// 			file_h<<"else if("<<con.s<<")"<<endl<<"{"<<endl;
// 			for(auto j:s->branches[i].execution->value())
// 			{
// 				codegenforstmtinclass(j,s2,root);
// 			}
// 			file_h<<"}"<<endl;
// 		}
// 	}
// 	else if(s->tag == string("WHILE"))
// 	{
		
// 	}
// 	else if(s->tag == string("RETURNNULL"))
// 	{
//  		//pass;
 		
// 	}
// 	else if (s->tag == string("RETURN"))
// 	{
// 		auto c = codegenforexprinclass(s->exp,s2,root);
// 		file_h<<c.s<<endl;
// 		file_h<< "return "+c.v<<endl;
// 	}
// 	else if (s->tag == string("GETVALUE"))
// 	{
// 		auto l = codegenforexprinclass(s->g_value.left,s2,root);
// 		auto r = codegenforexprinclass(s->g_value.right,s2,root);
// 		file_h<<l.s<<endl;
// 		file_h<<r.s<<endl;
// 		if(root->m_variables[s->g_value.left->identname]!= s->g_value.right->m_type)
// 		{
// 			file_h<<l.v<<" = ("<<type2structname(root->m_variables[s->g_value.left->identname])<<")"
// 			<<r.v<<";"<<endl;
// 		}
// 		else
// 		{
// 			file_h<<l.v<<" = "
// 			<<r.v<<";"<<endl;
// 		}
		
// 	}
// 	else if(s->tag == string("GETVALUEMEMBER"))
// 	{

// 	}			
// 	else
// 	{

// 	}
// }







void codegenforstmtinmethod(statement* s,method* m,basic_class* c,program* root)
{
	if(s->tag == string("IFELSE"))
	{
		auto first = s->branches[0];
		auto con = codegenforexprinmethod(first.condition,m,c,root);
		file_h<<"if("<<con.s<<")"<<endl<<"{"<<endl;
		for(auto j:first.execution->value())
		{
			codegenforstmtinmethod(j,m,c,root);
		}
		file_h<<"}"<<endl;
		for(int i = 1; i<s->branches.size();++i)
		{
			auto con = codegenforexprinmethod(s->branches[i].condition,m,c,root);
			file_h<<"else if("<<con.s<<")"<<endl<<"{"<<endl;
			for(auto j:s->branches[i].execution->value())
			{
				codegenforstmtinmethod(j,m,c,root);
			}
			file_h<<"}"<<endl;
		}
		auto last = s->elsestatements->value();
		file_h<<"else"<<endl<<"{"<<endl;
		for(auto j:last)
		{
			codegenforstmtinmethod(j,m,c,root);
		}
		file_h<<"}"<<endl;
	}
	else if(s->tag == string("IF"))
	{
		auto first = s->branches[0];
		auto con = codegenforexprinmethod(first.condition,m,c,root);
		file_h<<"if("<<con.s<<")"<<endl<<"{"<<endl;
		for(auto j:first.execution->value())
		{
			codegenforstmtinmethod(j,m,c,root);
		}
		file_h<<"}"<<endl;
		for(int i = 1; i<s->branches.size();++i)
		{
			auto con = codegenforexprinmethod(s->branches[i].condition,m,c,root);
			file_h<<"else if("<<con.s<<")"<<endl<<"{"<<endl;
			for(auto j:s->branches[i].execution->value())
			{
				codegenforstmtinmethod(j,m,c,root);
			}
			file_h<<"}"<<endl;
		}
	}
	else if(s->tag == string("WHILE"))
	{
		
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
 		
	}
	else if (s->tag == string("RETURN"))
	{
		auto con = codegenforexprinmethod(s->exp,m,c,root);
		file_h<<con.s<<endl;
		file_h<< "return "+con.v<<endl<<";";
	}
	else if (s->tag == string("GETVALUE"))
	{
		auto l = codegenforexprinmethod(s->g_value.left,m,c,root);
		auto r = codegenforexprinmethod(s->g_value.right,m,c,root);
		file_h<<l.s<<endl;
		file_h<<r.s<<endl;
		if(s->g_value.left->tag == "IDENT")
		{
			if(m->m_variables[s->g_value.left->identname] != s->g_value.right->m_type)
			{
				file_h<<l.v<<" = ("<<type2structname(root->m_variables[s->g_value.left->identname])<<")"
				<<r.v<<";"<<endl;
			}
			else
			{
				file_h<<l.v<<" = "
				<<r.v<<";"<<endl;
			}
		}	
		else
		{
			if(root->m_variables[s->g_value.left->identname] != s->g_value.right->m_type)
			{
				file_h<<l.v<<" = ("<<type2structname(root->m_variables[s->g_value.left->identname])<<")"
				<<r.v<<";"<<endl;
			}
			else
			{
				file_h<<l.v<<" = "
				<<r.v<<";"<<endl;
			}
		}
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else
	{

	}
}














void codegenforstmtinclass(statement* s,basic_class* c,program* root)
{
	if(s->tag == string("IFELSE"))
	{
		auto first = s->branches[0];
		auto con = codegenforexprinclass(first.condition,c,root);
		file_h<<"if("<<con.s<<")"<<endl<<"{"<<endl;
		for(auto j:first.execution->value())
		{
			codegenforstmtinclass(j,c,root);
		}
		file_h<<"}"<<endl;
		for(int i = 1; i<s->branches.size();++i)
		{
			auto con = codegenforexprinclass(s->branches[i].condition,c,root);
			file_h<<"else if("<<con.s<<")"<<endl<<"{"<<endl;
			for(auto j:s->branches[i].execution->value())
			{
				codegenforstmtinclass(j,c,root);
			}
			file_h<<"}"<<endl;
		}
		auto last = s->elsestatements->value();
		file_h<<"else"<<endl<<"{"<<endl;
		for(auto j:last)
		{
			codegenforstmtinclass(j,c,root);
		}
		file_h<<"}"<<endl;
	}
	else if(s->tag == string("IF"))
	{
		auto first = s->branches[0];
		auto con = codegenforexprinclass(first.condition,c,root);
		file_h<<"if("<<con.s<<")"<<endl<<"{"<<endl;
		for(auto j:first.execution->value())
		{
			codegenforstmtinclass(j,c,root);
		}
		file_h<<"}"<<endl;
		for(int i = 1; i<s->branches.size();++i)
		{
			auto con = codegenforexprinclass(s->branches[i].condition,c,root);
			file_h<<"else if("<<con.s<<")"<<endl<<"{"<<endl;
			for(auto j:s->branches[i].execution->value())
			{
				codegenforstmtinclass(j,c,root);
			}
			file_h<<"}"<<endl;
		}
	}
	else if(s->tag == string("WHILE"))
	{
		
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
 		
	}
	else if (s->tag == string("RETURN"))
	{
		auto con = codegenforexprinclass(s->exp,c,root);
		file_h<<con.s<<endl;
		file_h<< "return "+con.v<<endl;
	}
	else if (s->tag == string("GETVALUE"))
	{
		auto l = codegenforexprinclass(s->g_value.left,c,root);
		auto r = codegenforexprinclass(s->g_value.right,c,root);
		file_h<<l.s<<endl;
		file_h<<r.s<<endl;
		if(s->g_value.left->tag == "IDENTINMEMBER")
		{
			if(c->m_variables[s->g_value.left->identname]!= s->g_value.right->m_type)
			{
				file_h<<l.v<<" = ("<<type2structname(c->m_variables[s->g_value.left->identname])<<")"
				<<r.v<<";"<<endl;
			}
			else
			{
				file_h<<l.v<<" = "
				<<r.v<<";"<<endl;
			}
		}
		else if(s->g_value.left->tag == "IDENT")
		{
			if(c->m_variables_temp[s->g_value.left->identname]!= s->g_value.right->m_type)
			{
				file_h<<l.v<<" = ("<<type2structname(c->m_variables_temp[s->g_value.left->identname])<<")"
				<<r.v<<";"<<endl;
			}
			else
			{
				file_h<<l.v<<" = "
				<<r.v<<";"<<endl;
			}
		}
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else
	{

	}
}






void codegenforclass(basic_class* c,program* root)
{
	string struct_name = "class_"+c->name()+"_struct";
	string class_struct = "class_" + c->name();
	file_h<< "struct "+struct_name+ ";\n"+ "typedef struct "+ struct_name +"* "+class_struct + ";\n" <<endl;
	file_h<<"typedef struct"<<endl<<"{"<<endl;
	file_h<<class_struct + " clazz;"<<endl;
	for(auto i: c->m_variables)
	{
		file_h<< type2structname(i.second)+" m_"+i.first<<";"<<endl;   // use m_name means the member
	}
	file_h<<"}* "+ type2structname(c->name())<<";"<<endl;
	file_h<< "struct "+struct_name<<endl<<"{"<<endl;

/* methods*/
	file_h<< type2structname(c->name())+" (*constructor) ();"<<endl;


	for(auto i:c->methodtable)
	{
		auto type = type2structname( i.second->m_returntype);
		file_h<< type +" (*" + i.second->name()+") (";
		file_h<< type2structname(i.second->origin_class);
		for(int j = 0; j< i.second->para().size();++j)
		{
			auto n = i.second->para()[j].type;
			file_h<<", "+type2structname(n);
		}
		file_h<<");"<<endl;
	}	
	

	file_h<<"};"<<endl;
	file_h<<"class_"<<c->name()<<" the_class_"<<c->name()<<";"<<endl;
	file_h<<type2structname(c->name())<<" "<<c->name()<<"_literal(";
	for(int i = 0;i<c->para().size();++i)
	{
		auto n = c->para()[i];
		if(!i)
		{
			file_h<<type2structname(n.type)<<" "<<n.name;
		}
		else
		{
			file_h<<" , "<<type2structname(n.type)<<" "<<n.name;
		}
		variabletale_class.insert(n.name);
	}
	file_h<<");"<<endl;

	vector<string> function_names;
	// function_names.push_back(c->name()+"_literal");
	// file_h<< type2structname(c->name())<<" "<<c->name()+"_literal()\n{\n";
	function_names.push_back("new_"+c->name());
	file_h<< type2structname(c->name())<<" new_"<<c->name()<<"(";
	
	file_h<<")\n{\n";
	file_h<<type2structname(c->name())+" new_thing"<<" = ("<<type2structname(c->name())<<")malloc(sizeof(struct class_"+c->name()+ "_struct));"<<endl;
	file_h<<"new_thing->clazz = the_class_"<<c->name()<<";"<<endl;
	// for(auto i:c->m_statements)
	// {
	// 	codegenforstmtinclass(i,c,root);
	// }
	file_h<<"return new_thing;"<<endl;
	file_h<<"}"<<endl;
	//variabletale_class.clear();
	for(auto i:c->methodtable)
	{
		//file_h<<i.second->origin_class<<endl<<i.second->name()<<endl;
		
		if(i.second->origin_class != c->name())
		{
			string name = i.second->origin_class+"_method_"+i.second->name();
			function_names.push_back(name);
		} 
		else
		{
			file_h<< type2structname(i.second->m_returntype) +" "+c->name()+"_method_"+i.second->name()+"(";
			string name = c->name()+"_method_"+i.second->name();
			file_h<< type2structname(c->name())<<" this"<<endl;
			for(int j = 0; j< i.second->para().size();++j)
			{
				auto n = i.second->para()[j];
				// if(j == 0)
				// {
				// 	file_h<<type2structname(n.type) +" "+n.name;
				// }
				// else
				// {
					file_h<<" , "+type2structname(n.type)+" "+n.name;
				//}
			}
			file_h<<")"<<endl<<"{"<<endl;
		
			for(auto s:i.second->methodstatements)
			{
				codegenforstmtinmethod(s,i.second,c,root);
			}
			variabletale_method.clear();
			file_h<<"};"<<endl;
			function_names.push_back(name);



		}
	
	}

	file_h<<"struct "<<struct_name<<" the_"<<struct_name<<" = \n";
	file_h<<"{"<<endl;
	for(auto i:function_names)
	{
		file_h<<i<<","<<endl;
	}
	file_h<<"};"<<endl;
	file_h<<"class_"<<c->name()<<" the_class_"<<c->name()<<" = &the_class_"<<c->name()<<"_struct;"<<endl;
	file_h<<type2structname(c->name())<<" "<<c->name()<<"_literal(";
	for(int i = 0;i<c->para().size();++i)
	{
		auto n = c->para()[i];
		if(!i)
		{
			file_h<<type2structname(n.type)<<" "<<n.name;
		}
		else
		{
			file_h<<" , "<<type2structname(n.type)<<" "<<n.name;
		}
		variabletale_class.insert(n.name);
	}
	file_h<<")"<<endl<<"{"<<endl;
	file_h<<type2structname(c->name())<<" new_thing = the_class_"<<c->name()<<"->constructor();"<<endl;
	for(auto i:c->m_statements)
	{
		codegenforstmtinclass(i,c,root);
	}
	file_h<<"return new_thing;"<<endl;
	file_h<<"}"<<endl;





	/*variables*/


	

}

void codegenpgm(program* root)
{
	file_h.open("./output/output.h");
	file_c.open("./output/output.c");
	file_h<<"#ifndef OUTPUT_H"<<endl<<"#define OUTPUT_H"<<endl<<"#include \"Builtins.h\""<<endl;
	file_c<<"#include \"output.h\""<<endl<<"#include<stdio.h>"<<endl<<"int main()\n{"<<endl;
	for(auto c:root->cs)
	{
		codegenforclass(c,root);
	}
	for(auto i: root->ss)
	{
		codegenforstmtinstmt(i,root);
	}
	file_c<<"return 0;"<<endl<<"}"<<endl;
	file_h<<"#endif"<<endl;
	file_c.close();
	file_h.close();
}
