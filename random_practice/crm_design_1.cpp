/*
Problem;
Object Oriented Design - Design a coffee maker machine class 

There is a coffee maker with a screen. 
We need to add three ingredients into the machine: coffee beans, water and milk.
There are three types of drinks we can make, below are the default recipes:

Espresso: cost 3 coffee beans and 1 water

Americano: cost 2 coffee beans and 3 water

Latte: cost 2 coffee beans, 2 milk and 2 water

When a user comes, on the screen we show available drinks. 
After the user chooses a drink, the user will be able to customize the amount of ingredients. 
(For example, after choosing Espresso, the user can change from default to 4 coffee beans and 1 water)

The admin is able to refill the ingredients. 
The admin and the users interact with the machine via the screen. 
In the future, we might can support more drink types.

Please design a class with public APIs to represent the coffee maker, 
which will be called by the screen.
*/

/*
Thoughts:

We have the coffee maker machine
We have a screen to interact with users

Screen cannot exist without the coffee maker machine 

In the coffee maker machine, we have 3+ ingredients and 3+ recipes 
(the "+" means for future extention). 
The admin type of user is able to refill the ingredient amounts.
The general user tyoe of user is able to customize the amount of ingredients.

For ingredients, the company in the future might add more ingredients
For recipies, 

*/