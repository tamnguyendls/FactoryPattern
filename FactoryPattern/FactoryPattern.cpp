// FactoryPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <list>

using namespace std;

class APizza
{
public:
    APizza()
    {
        name = "";
        dough = "";
        sauce = "";
        printf("Pizza class\n");
    }

    bool prepare() 
    { 
        printf("Preparing %s\n", name);
        printf("Tossing dough...\n");
        printf("Adding sauce...\n");
        printf("Adding toppings: \n");

        for (int i = 0; i < 3; i++)
        {
            //
        }

        return true;
    }

    bool bake() 
    {
        printf("Bake for 25 mins at 350\n");
        return true; 
    }

    bool cut()
    {
        printf("Cutting the pizza into diagonal slices\n");
        return true;
    }

    bool box()
    {
        printf("Place pizza in official PizzaStote Box\n");
        return true;
    }

    char * GetName()
    {
        return name;
    }
    
protected:
    char * name;
    char * dough;
    char * sauce;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

//class CheesePizza : public APizza
//{
//public:
//    CheesePizza()
//    {
//        printf("CheesePizza class\n");
//    }
//};

////////////////////////////////////////////////////////////////////////////////////////////////////

//class PepperoniPizza : public APizza
//{
//public:
//    PepperoniPizza()
//    {
//        printf("PepperoniPizza class\n");
//    }
//};

////////////////////////////////////////////////////////////////////////////////////////////////////

//class VeggiePizza : public APizza
//{
//public:
//    VeggiePizza()
//    {
//        printf("VeggiePizza class\n");
//    }
//};

////////////////////////////////////////////////////////////////////////////////////////////////////

class SimplePizzaFactory
{
public:
    APizza * CreatePizza(char * type)
    {
        APizza * pizza = NULL;

        if (type == "cheese")
        {
            //pizza = new CheesePizza();
        }
        else if (type == "pepperoni")
        {
            //pizza = new PepperoniPizza();
        }
        else if (type == "veggie")
        {
            //pizza = new VeggiePizza();
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
    APizza * OrderPizza(char * type)
     {
        APizza *pizza;

        pizza = CreatePizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

protected:
    virtual APizza * CreatePizza(char * type) = 0; // abstract method (pure virtual function), the sub classes must implement this one.
    bool isType(char * inputType, char * myType)
    {
        bool bRet = false;

        if (strlen(inputType) == strlen(myType))
        {
            if (strcmp(inputType, myType) == 0)
                bRet = true;
        }

        return bRet;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class NYStyleCheesePizza : public APizza
{
public:
    NYStyleCheesePizza()
    {
        name = "NY Style Sauce and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class NYStylePepperoniPizza : public APizza
{
public:
    NYStylePepperoniPizza()
    {
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class NYStyleStyleClamPizza : public APizza
{
public:
    NYStyleStyleClamPizza()
    {
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class NYStyleVeggiePizza : public APizza
{
public:
    NYStyleVeggiePizza()
    {
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class NYStylePizzaStore : public APizzaStore
{
public:
    NYStylePizzaStore()
    {
        printf("This is NYStylePizzaStore\n");
    }

    APizza * CreatePizza(char * type)
    {
        APizza * pizza = NULL;
        printf("NYStylePizza is created\n");
        if (isType(type, "cheese") == true)
        {
            pizza = new NYStyleCheesePizza();
        }
        else if (isType(type, "pepperoni") == true)
        {
            pizza = new NYStylePepperoniPizza();
        }
        else if (isType(type, "clam") == true)
        {
            pizza = new NYStyleStyleClamPizza();
        }
        else if (isType(type, "veggie") == true)
        {
            pizza = new NYStyleVeggiePizza();
        }

        return pizza;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class ChicagoStyleCheesePizza : public APizza
{
public:
    ChicagoStyleCheesePizza()
    {
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class ChicagoStylePepperoniPizza : public APizza
{
public:
    ChicagoStylePepperoniPizza()
    {
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class ChicagoStyleClamPizza : public APizza
{
public:
    ChicagoStyleClamPizza()
    {
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class ChicagoStyleVeggiePizza : public APizza
{
public:
    ChicagoStyleVeggiePizza()
    {
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

    APizza * CreatePizza(char * type)
    {
        APizza * pizza = NULL;

        printf("ChicagoStylePizza is created\n");

        if (isType(type, "cheese") == true)
        {
            pizza = new ChicagoStyleCheesePizza();
        }
        else if (isType(type, "pepperoni") == true)
        {
            pizza = new ChicagoStylePepperoniPizza();
        }
        else if (isType(type, "clam") == true)
        {
            pizza = new ChicagoStyleClamPizza();
        }
        else if (isType(type, "veggie") == true)
        {
            pizza = new ChicagoStyleVeggiePizza();
        }

        return pizza;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////

bool PizzaTestDrive()
{
    APizzaStore * pNYStylePizzaStore = new NYStylePizzaStore();
    APizza * pPizza = pNYStylePizzaStore->OrderPizza("cheese");

    //APizzaStore * pChicagoStypePizza = new ChicagoStylePizzaStore();
    //pChicagoStypePizza->OrderPizza("cheese");

    return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PizzaTestDrive();

    return 0;
}

