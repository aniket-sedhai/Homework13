//
//  main.cpp
//  Homework13
//
//  Created by Aniket Sedhai on 7/15/24.
//

#include <iostream>
#include "Operand.h"
#include <queue>
#include <stack>
#include <exception>

double Calculate(std::queue<Operand*>& operand_ptr_queuce);

int main()
{
    std::queue<Operand*> oper_queue;
    
    oper_queue.push(new Number(6));
    oper_queue.push(new Number(8));
    oper_queue.push(new Add());
    oper_queue.push(new Square());
    oper_queue.push(new Number(102));
    oper_queue.push(new Number(53));
    oper_queue.push(new Substract());
    oper_queue.push(new Divide());
    oper_queue.push(new Number(428));
    oper_queue.push(new Number(379));
    oper_queue.push(new Substract());
    oper_queue.push(new Number(7));
    oper_queue.push(new Divide());
    oper_queue.push(new Add());
    
    try 
    {
        std::cout << Calculate(oper_queue) << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}

double Calculate(std::queue<Operand*>& operand_ptr_queue)
{
    std::stack<double>my_stack;
        
    while (!operand_ptr_queue.empty())
    {
        Operand* operand_ptr = operand_ptr_queue.front();
        operand_ptr_queue.pop();
        
        Number* num_ptr = dynamic_cast<Number*>(operand_ptr);
        if (num_ptr != nullptr)
        {
            my_stack.push(num_ptr->my_number);
        }
        else if (dynamic_cast<Add*>(operand_ptr) != nullptr)
        {
            double a = my_stack.top();
            my_stack.pop();
            double b = my_stack.top();
            my_stack.pop();
            my_stack.push(a + b);
        }
        else if (dynamic_cast<Substract*>(operand_ptr) != nullptr)
        {
            double a = my_stack.top();
            my_stack.pop();
            double b = my_stack.top();
            my_stack.pop();
            my_stack.push(b - a);
        }
        else if (dynamic_cast<Multiply*>(operand_ptr) != nullptr)
        {
            double a = my_stack.top();
            my_stack.pop();
            double b = my_stack.top();
            my_stack.pop();
            my_stack.push(a * b);
        }
        else if (dynamic_cast<Divide*>(operand_ptr) != nullptr)
        {
            double a = my_stack.top();
            my_stack.pop();
            double b = my_stack.top();
            my_stack.pop();
            my_stack.push(b / a);
        }
        else if (dynamic_cast<Square*>(operand_ptr) != nullptr)
        {
            double a = my_stack.top();
            my_stack.pop();
            my_stack.push(a * a);
        }
    }
    
    if (my_stack.size() != 1)
        throw std::logic_error("Invalid number of items on the stack!");
    
    return my_stack.top();
}
