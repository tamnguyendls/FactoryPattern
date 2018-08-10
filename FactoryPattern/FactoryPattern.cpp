// FactoryPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

class Pizza
{
public:
    Pizza()
    {
        printf("Pizza class\n");
    }

    bool prepare() 
    { 
        printf(" do prepare");
        return true;
    }

    bool bake() 
    {
        printf(" do bake");
        return true; 
    }

    bool cut()
    {
        printf(" do cut");
        return true;
    }

    bool box()
    {
        printf(" do box");
        return true;
    }
};

class CheesePizza : public Pizza
{
public:
    CheesePizza()
    {
        printf("CheesePizza class\n");
    }
};

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza()
    {
        printf("PepperoniPizza class\n");
    }
};

class VeggiePizza : public Pizza
{
public:
    VeggiePizza()
    {
        printf("VeggiePizza class\n");
    }
};

class SimplePizzaFactory
{
public:
    Pizza * CreatePizza(char * type)
    {
        Pizza * pizza = NULL;

        if (type == "cheese")
        {
            pizza = new CheesePizza();
        }
        else if (type == "pepperoni")
        {
            pizza = new PepperoniPizza();
        }
        else if (type == "veggie")
        {
            pizza = new VeggiePizza();
        }

        return pizza;
    }
};

class PizzaStore
{
private:
    SimplePizzaFactory factory;
public:
    Pizza * OrderPizza(char * type)
    {
        Pizza *pizza;

        pizza = factory.CreatePizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }
};

int main()
{
    return 0;
}

