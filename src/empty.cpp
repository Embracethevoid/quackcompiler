#include "Builtins.h"
#include <iostream>
using namespace std;
int main()
{
	obj_Int a1 = int_literal(7);	
	obj_Int a2 = int_literal(3);
	cout<< a1->clazz->PLUS(a1,a2)->value<<endl;
	cin.get();	
	return 0;
}
