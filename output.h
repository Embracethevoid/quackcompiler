#ifndef OUTPUT_H
#define OUTPUT_H
#include "Builtins.h"
struct class_Pt_struct;
typedef struct class_Pt_struct* class_Pt;

typedef struct
{
class_Pt clazz;
obj_Int m_y;
obj_Int m_x;
}* obj_Pt;
struct class_Pt_struct
{
obj_Pt (*constructor) ();
obj_String (*STRING) (obj_Pt);
obj_Nothing (*PRINT) (obj_Pt);
obj_String (*STR) (obj_Pt);
obj_Int (*_x) (obj_Pt);
obj_Int (*_y) (obj_Pt);
obj_Pt (*PLUS) (obj_Pt, obj_Pt);
};
class_Pt the_class_Pt;
obj_Pt new_Pt()
{
obj_Pt new_thing = malloc(sizeof(struct class_Pt_struct));
new_thing->clazz = the_class_Pt;
return new_thing;
}
obj_String Pt_method_STR(obj_Pt this
)
{

obj_String temp1 = str_literal("(");
obj_String temp2 = this->m_x->clazz->STRING(this->m_x);
obj_String temp3 = temp1->clazz->PLUS(temp1,temp2);
obj_String temp4 = str_literal(",");

obj_String temp5 = temp3->clazz->PLUS(temp3,temp4);
obj_String temp6 = this->m_y->clazz->STRING(this->m_y);
obj_String temp7 = temp5->clazz->PLUS(temp5,temp6);
obj_String temp8 = str_literal(")");
obj_String temp9 = temp7->clazz->PLUS(temp7,temp8);
return temp9
;};
obj_Int Pt_method__x(obj_Pt this
)
{

return this->m_x
;};
obj_Int Pt_method__y(obj_Pt this
)
{

return this->m_y
;};
obj_Pt Pt_method_PLUS(obj_Pt this
 , obj_Pt other)
{


obj_Int temp11 = other->clazz->_x(other);
obj_Int temp12 = this->m_x->clazz->PLUS(this->m_x,temp11);


obj_Int temp13 = other->clazz->_y(other);
obj_Int temp14 = this->m_y->clazz->PLUS(this->m_y,temp13);
obj_Pt temp10 = Pt_literal(temp12 , temp14);
return temp10
;};
struct class_Pt_struct the_class_Pt_struct = 
{
new_Pt,
Obj_method_STRING,
Obj_method_PRINT,
Pt_method_STR,
Pt_method__x,
Pt_method__y,
Pt_method_PLUS,
}
obj_Pt Pt_literal(obj_Int x , obj_Int y)
{
obj_Pt new_thing = the_class_Pt->constructor();


new_thing->m_x = x;


new_thing->m_y = y;
return new_thing;
}
struct class_Square_struct;
typedef struct class_Square_struct* class_Square;

typedef struct
{
class_Square clazz;
obj_Pt m_ur;
obj_Pt m_ll;
}* obj_Square;
struct class_Square_struct
{
obj_Square (*constructor) ();
obj_Nothing (*PRINT) (obj_Square);
obj_String (*STRING) (obj_Square);
};
class_Square the_class_Square;
obj_Square new_Square()
{
obj_Square new_thing = malloc(sizeof(struct class_Square_struct));
new_thing->clazz = the_class_Square;
return new_thing;
}
struct class_Square_struct the_class_Square_struct = 
{
new_Square,
Obj_method_PRINT,
Obj_method_STRING,
}
obj_Square Square_literal(obj_Pt ll , obj_Int side)
{
obj_Square new_thing = the_class_Square->constructor();


new_thing->m_ll = ll;

obj_Int temp16 = new_thing->m_ll->clazz->_x(obj_Square this);

obj_Int temp17 = temp16->clazz->PLUS(temp16,side);

obj_Int temp18 = new_thing->m_ll->clazz->_y(obj_Square this);

obj_Int temp19 = temp18->clazz->PLUS(temp18,side);

obj_Pt temp15 = Pt_literal(temp17 , temp19);
new_thing->m_ur = temp15;
return new_thing;
}
#endif
