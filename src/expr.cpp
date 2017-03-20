
r_expr::r_expr()
{

}

r_expr::~r_expr()
{

}


make_int::make_int(int i)
{
	// char* to integer
	m_type = "INT";
}

make_int::~make_int()
{

}

// int make_int::value()
// {
// 	return m_value;
// }


make_str::make_str(char*s)/*:m_value(std::string(s))*/
{
	m_type = "STR";
}


make_str::~make_str()
{

}

// std::string make_str::value()
// {
// 	return m_value;
// }

bin_operator::bin_operator(r_expr* e1,char *s,r_expr* e2)
{
	if(s == "PLUS")
	{
		
	}
	else if( s == "MINUS")
	{
		
	}
	else if( s == "TIMES")
	{
		
	}
	else if( s == "DIVIDE")
	{
		
	}
	else if( s == "ATMOST")
	{
		
	}
	else if( s == "ATLEAST")
	{
		
	}
	else if( s == "MORE")
	{
		
	}
	else if( s == "LESS")
	{
		
	}
	else if( s == "EQUALS")
	{
		
	}
	else if( s == "GETS")
	{
		
	}
	else if( s == "AND")
	{
		
	}
	else if( s == "OR")
	{
		
	}
	else
	{

	}
	
}

bin_operator::~bin_operator()
{

}

negative_operator::negative_operator(r_expr* e)
{
	// do the neg of the value
}

negative_operator::~negative_operator()
{

}

not_operator::not_operator(r_expr* e)
{
	// do the not operation
}

not_operator::~not_operator()
{

}




r_exprs::r_exprs()
{

}


r_exprs::r_exprs(r_exprs* es,r_expr* e)
{
	m_value = es->value();
	m_value.push_back(e);
}

vector<r_expr*> r_exprs::value()
{
	return m_value;
}

r_exprs::~r_exprs()
{

}


actual_args::actual_args()
{

}

actual_args::actual_args(r_expr* exp,r_exprs* exps)
{
	m_value = exps->m_value;
	m_value.insert(m_value.begin(),exp);
}
actual_args::~actual_args()
{

}


function_call::function_call(r_expr* e, char* s, actual_args* a)
{

	
}


function_call::function_call(char* s, actual_args* a)
{

}

// function_call::function_call(expr* e, char* s, actual_args a)
// {

// }
// function_call::function_call(char* s, actual_args a)
// {

// }


function_call::~function_call()
{

}


make_ident::make_ident(char* s)
{
	m_name = string(s);
}

make_ident::make_ident(r_expr* e,char* s2)
{
	m_name = string(s2);
}


make_ident::~make_ident()
{

}
string make_ident::name()
{
	return m_name;
}

element_call::element_call(r_expr* e,char* s)
{

}
element_call::~element_call()
{

}
