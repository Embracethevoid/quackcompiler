#ifndef NODE_H
#define NODE_H
#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<unordered_set>
#include<stdlib.h>

typedef struct 
{
	std::string name;
	std::string type;
}
Para;
class node
{
public:
	node();
	~node();
	//std::string type;
protected:
	//std::string type;
	//virtual void print();
	//virtual void evalutate();
};

#endif
