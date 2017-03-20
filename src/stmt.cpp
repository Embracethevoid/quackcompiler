stmt::stmt()
{

}

stmt::~stmt()
{

}


elif::elif(r_expr* e, statements* s)
{
	m_value = branch{e,s};
}

branch elif::value()
{
	return m_value;
}

elif::~elif()
{

}



elifs::elifs()
{

}

elifs::elifs(elifs* es,elif* e)
{
	m_value = es->value();
	m_value.push_back(e);
	delete es;
}

vector<elif*> elifs::value()
{
	return m_value;
}
elifs::~elifs()
{

}
ifstmt::ifstmt(r_expr* exp,statements* s1,elifs* elfs,statements* s2) //with else
{
	tag = "IFELSE";
	branches.push_back({exp,s1});
	//branches.insert(elfs->value().begin(),elfs->value().end(),branches.begin());
	for(auto e : elfs->value())
	{
		branches.push_back(e->value());
	}
	elsestatements = s2;
}

ifstmt::ifstmt(r_expr* exp,statements* s,elifs* elfs) //without else
{
	tag = "IF";
	branches.push_back({exp,s});
	//branches.insert(elfs->value().begin(),elfs->value().end(),branches.begin());
	for(auto e : elfs->value())
	{
		branches.push_back(e->value());
	}
}

ifstmt::~ifstmt()
{

}
whilestmt::whilestmt(r_expr* exp,statements* s)
{
	tag = "WHILE";
	whilestatement = branch{exp,s};
}

whilestmt::~whilestmt()
{

}

expstmt::expstmt(r_expr* l, r_expr* r)
{

}

expstmt::expstmt(r_expr* l ,char* s,r_expr* r)
{

}

expstmt::expstmt( r_expr* r)
{

}
expstmt::~expstmt()
{

}

returnstmt::returnstmt()
{
	tag = "RETURNNULL";
}

returnstmt::returnstmt(r_expr* e)
{
	tag = "RETURN";
	returntype = e->m_type;
}

returnstmt::~returnstmt()
{

}
