void buildvariableforstmt(stmt* s)
{
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branch)
		{
			unordered_map<string,string> temp1;
			getinitializedident(i->condition,s);
			for(auto j: i->execution->value())
			{
				buildvariableforstmt(j);
			}
			for(auto j: i->execution->value())
			{
				temp1.insert(j->m_variable.begin(),j->m_variable.end())
			}
			temp.push_back(temp1);
		}
		buildvariableforstmt(s->elsestatements);
		unordered_map<string,string> temp1;
		for(auto j: elsestatements->value())
		{
			temp1.insert(j->m_variable.begin(),j->m_variable.end())
		}
		temp.push_back(temp1);
		if(!temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:tempm)
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
			s->m_variable.insert(f.begin(),f.end());
		}

	}
	else if(s->tag == string("IF"))
	{
		
	}
	else if(s->tag == string("WHILE"))
	{
		buildvariableforstmt(s->whilestatement.execution->value());
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
	}
	else if (s->tag == string("RETURN"))
	{
		getinitializedident(s->exp,s);
	}
	else if (s->tag == string("GETVALUE"))
	{
		
		if(s->g_value.l->tag == string("IDENT"))
		{
			m_variable[s->g_value.l->name()] = string("Bottom");
		}

		getinitializedident(s->g_value.r,s);
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else
	{

	}
}




domethod(method* m)
{
	//we have arguments in the table
	for(auto i:m->methodstatements)
	{

	}
}

void getinitializedident(r_expr* e,statement* s)
{
	if(e->tag == string("IDENT"))
	{
		// if(e->isleft)
		// {
			//s->m_variable[e->name()] == "Bottom";
			//s->m_type = string("Bottom");
		// }
		// else
		// {
		if(s->m_variable.find(e->name()) == s->m->variable.end())
		{
			cerr<<"uninitialized ident"<<endl;
			exit(-1);
		}
		// }
	}
	else if(e->tag == string("bin_oper"))
	{
		getinitializedident(l,s,p);
		getinitializedident(r,s,p);
	}
	else if(e->tag == string("single_oper"))
	{
		getinitializedident(e,s,p);
	}
	else if(e->tag == string("function_call"))
	{
		//check if there is function
		s->m_variable[e->f.s] = "Bottom";
		getinitializedident(e,s,p);
	}
	else if(e->tag == string("class_call"))
	{
		// bool flag = 0;
		// if( classtable.find(e->c.s) == classtalbe.end())
		// {
		// 	cerr<<"uninitialized class"<<endl;
		// 	exit(-1);
		// }

	}
}
