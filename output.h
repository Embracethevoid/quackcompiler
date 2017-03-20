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
obj_Nothing (*PRINT) (obj_Pt);
obj_String (*STR) (obj_Pt);
obj_Int (*_x) (obj_Pt);
obj_Int (*_y) (obj_Pt);
obj_Pt (*PLUS) (obj_Pt, obj_Pt);
};
obj_Pt new_Pt(obj_Int x , obj_Int y)
{
obj_Pt new_thing = malloc(sizeof(structobj_Pt_struct));
new_thing->clazz = the_class_Pt;


new_thing->m_x = x;


new_thing->m_y = y;
return new_Pt;
}
obj_String Pt_method_STR(obj_Pt this
)
{

obj_String temp1 = str_literal("(");
obj_String temp2 = this->m_x->clazz->STR(this->m_x);
obj_String temp3 = temp1->clazz->PLUS(temp1,temp2);
obj_String temp4 = str_literal(",");

obj_String temp5 = temp3->clazz->PLUS(temp3,temp4);
obj_String temp6 = this->m_y->clazz->STR(this->m_y);
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
obj_Pt other;

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
Obj_method_PRINT,
Pt_method_STR,
Pt_method__x,
Pt_method__y,
Pt_method_PLUS,
}
struct class_Rect_struct;
typedef struct class_Rect_struct* class_Rect;

typedef struct
{
class_Rect clazz;
obj_Pt m_ur;
obj_Pt m_ll;
}* obj_Rect;
struct class_Rect_struct
{
obj_Rect (*constructor) ();
obj_Nothing (*PRINT) (obj_Rect);
obj_String (*STR) (obj_Rect);
obj_Pt (*translate) (obj_Rect, obj_Pt);
};
obj_Rect new_Rect(obj_Pt ll , obj_Pt ur)
{
obj_Rect new_thing = malloc(sizeof(structobj_Rect_struct));
new_thing->clazz = the_class_Rect;


new_thing->m_ll = ll;


new_thing->m_ur = ur;
return new_Rect;
}
obj_String Rect_method_STR(obj_Rect this
)
{

obj_Int temp16 = this->m_ur->clazz->_y(this->m_ur);

obj_Int temp17 = this->m_ll->clazz->_x(this->m_ll);
obj_Pt lr;
obj_Pt temp15 = Pt_literal(temp16 , temp17);
lr = temp15;

obj_Int temp19 = this->m_ll->clazz->_x(this->m_ll);

obj_Int temp20 = this->m_ur->clazz->_y(this->m_ur);
obj_Pt ul;
obj_Pt temp18 = Pt_literal(temp19 , temp20);
ul = temp18;

obj_String temp21 = str_literal("(");
obj_String temp22 = this->m_ll->clazz->STR(this->m_ll);
obj_String temp23 = temp21->clazz->PLUS(temp21,temp22);
obj_String temp24 = str_literal(", ");

obj_String temp25 = temp23->clazz->PLUS(temp23,temp24);
obj_String temp26 = ul->clazz->STR(ul);
obj_String temp27 = temp25->clazz->PLUS(temp25,temp26);
obj_String temp28 = str_literal(",");

obj_String temp29 = temp27->clazz->PLUS(temp27,temp28);
obj_String temp30 = this->m_ur->clazz->STR(this->m_ur);
obj_String temp31 = temp29->clazz->PLUS(temp29,temp30);
obj_String temp32 = str_literal(",");

obj_String temp33 = temp31->clazz->PLUS(temp31,temp32);
obj_String temp34 = lr->clazz->STR(lr);
obj_String temp35 = temp33->clazz->PLUS(temp33,temp34);
obj_String temp36 = str_literal(")");
obj_String temp37 = temp35->clazz->PLUS(temp35,temp36);
return temp37
;};
obj_Pt Rect_method_translate(obj_Rect this
 , obj_Pt delta)
{

obj_Pt delta;
obj_Int temp39 = this->m_ll->clazz->_x(this->m_ll);
obj_Int temp40 = delta->clazz->_x(delta);
obj_Int temp41 = temp39->clazz->PLUS(temp39,temp40);


obj_Int temp42 = this->m_ur->clazz->_y(this->m_ur);
obj_Int temp43 = delta->clazz->_y(delta);
obj_Int temp44 = temp42->clazz->PLUS(temp42,temp43);
obj_Pt temp38 = Pt_literal(temp41 , temp44);
return temp38
;};
struct class_Rect_struct the_class_Rect_struct = 
{
new_Rect,
Obj_method_PRINT,
Rect_method_STR,
Rect_method_translate,
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
obj_Pt (*translate) (obj_Square, obj_Pt);
obj_String (*STR) (obj_Square);
obj_Nothing (*PRINT) (obj_Square);
};
obj_Square new_Square(obj_Pt ll , obj_Int side)
{
obj_Square new_thing = malloc(sizeof(structobj_Square_struct));
new_thing->clazz = the_class_Square;


new_thing->m_ll = ll;

obj_Int temp46 = new_thing->m_ll->clazz->_x(obj_Square this);

