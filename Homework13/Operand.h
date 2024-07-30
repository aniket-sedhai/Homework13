//
//  Operand.h
//  Homework13
//
//  Created by Aniket Sedhai on 7/15/24.
//

#ifndef Operand_h
#define Operand_h

class Operand
{
public:
    virtual ~Operand();
};

class Number: public Operand
{
public:
    Number(double num);
    double my_number;
};

class Operator: public Operand
{
    
};

class Add: public Operator
{
    
};

class Substract: public Operator
{
    
};

class Multiply: public Operator
{
    
};

class Divide: public Operator
{
    
};

class Square: public Operator
{
    
};






#endif /* Operand_h */
