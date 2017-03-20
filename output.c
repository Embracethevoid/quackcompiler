#include "output.h"
#include<stdio.h>
int main()
{
obj_Int temp22 = int_literal(3);
obj_Int temp23 = int_literal(3);
obj_Pt temp21 = Pt_literal(temp22 , temp23);
obj_Int temp24 = int_literal(5);
obj_Square a_square;
obj_Square temp20 = Square_literal(temp21 , temp24);
a_square = temp20;

a_square->clazz->PRINT(a_square);
return 0;
}
