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
        printf("=>do prepare\n");
        return true;
    }

    bool bake() 
    {
        printf("=>do bake\n");
        return true; 
    }

    bool cut()
    {
        printf("=>do cut\n");
        return true;
    }

    bool box()
    {
        printf("=>do box\n");
        return true;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class CheesePizza : public Pizza
{
public:
    CheesePizza()
    {
        printf("CheesePizza class\n");
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza()
    {
        printf("PepperoniPizza class\n");
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class VeggiePizza : public Pizza
{
public:
    VeggiePizza()
    {
        printf("VeggiePizza class\n");
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////

class APizzaStore
{
private:
    //SimplePizzaFactory factory;
public:
    Pizza * OrderPizza(char * type)
    {
        Pizza *pizza;

        pizza = CreatePizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

protected:
    virtual Pizza * CreatePizza(char * type) = 0; // abstract method (pure virtual function), the sub classes must implement this one.
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class NYStylePizzaStore : public APizzaStore
{
public:
    NYStylePizzaStore()
    {
        printf("This is NYStylePizzaStore\n");
    }

    Pizza * CreatePizza(char * type)
    {
        Pizza * pizza = NULL;
        printf("NYStylePizza is created\n");
        //if (type == "cheese")
        //{
        //    pizza = new NYStyleCheesePizza();
        //}
        //else if (type == "pepperoni")
        //{
        //    pizza = new NYStylePepperoniPizza();
        //}
        //else if (type == "clam")
        //{
        //    pizza = new NYStyleStyleClamPizza();
        //}
        //else if (type == "veggie")
        //{
        //    pizza = new NYStyleVeggiePizza();
        //}

        return pizza;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class ChicagoStylePizzaStore : public APizzaStore
{
public:
    ChicagoStylePizzaStore()
    {
        printf("This is ChicagoStylePizzaStore\n");
    }

    Pizza * CreatePizza(char * type)
    {
        Pizza * pizza = NULL;
        printf("ChicagoStylePizza is created\n");

        //if (type == "cheese")
        //{
        //    pizza = new ChicagoStyleCheesePizza();
        //}
        //else if (type == "pepperoni")
        //{
        //    pizza = new ChicagoStylePepperoniPizza();
        //}
        //else if (type == "clam")
        //{
        //    pizza = new ChicagoStyleClamPizza();
        //}
        //else if (type == "veggie")
        //{
        //    pizza = new ChicagoStyleVeggiePizza();
        //}

        return pizza;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    ChicagoStylePizzaStore * pChicagoStypePizza = new ChicagoStylePizzaStore();
    NYStylePizzaStore * pNYStylePizza = new NYStylePizzaStore();

    pChicagoStypePizza->OrderPizza("cheese");
    pNYStylePizza->OrderPizza("cheese");

    return 0;
}

