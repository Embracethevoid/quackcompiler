#include "output.h"
#include<stdio.h>
int main()
{
obj_Int temp52 = int_literal(3);
obj_Int temp53 = int_literal(3);
obj_Pt temp51 = Pt_literal(temp52 , temp53);
obj_Int temp54 = int_literal(5);
obj_Obj a_square;
obj_Square temp50 = Square_literal(temp51 , temp54);
a_square = (obj_Obj)temp50;

obj_Int temp57 = int_literal(2);
obj_Int temp58 = int_literal(2);
obj_Pt temp56 = Pt_literal(temp57 , temp58);

a_square->clazz->translate(a_square , temp56);
a_square = (obj_Obj)temp55;

a_square->clazz->PRINT(a_square);
return 0;
}
