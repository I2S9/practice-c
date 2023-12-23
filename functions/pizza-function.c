#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

//Project : pizza making - a delicious use of function pointers

void thinCrust()
{
    printf("Making thin crust\n");
}

//Sauce making functions

void tomatoSauce()
{
    printf("adding tomato sauce\n");
}

void pestoSauce()
{
    printf("adding pesto sauce\n");
}

//Cheese making functions

void mozzarellaCheese()
{
    printf("Adding mozzarella cheese\n");
}

void cheddarCheese()
{
    printf("Adding cheddar cheese\n");
}

//Create the pizza function

void createPizza(void (*makeDough)(), void (*makeSauce)(), void(*addCheese)())
{
    makeDough();
    makeSauce();
    addCheese();
}

int main()
{
    printf("Pizza 1:\n");
    createPizza(thinCrust, tomatoSauce, mozzarellaCheese);
    printf("\n========\n");
    printf("Pizzza 2\n");
    createPizza(thinCrust, pestoSauce, cheddarCheese);
}
