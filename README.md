# Simple-Library-
Created this C program during the GWC Tech Bootcamp with Autodesk. The program takes in user input and allows the user to check books in and out. 

Prompt: Create an inventory management system- keep track of which books are in the
library and which have been checked out. 
--- assign a value when checked out, and assign a value when they're there
--- keep track of the number of books

Functionality: 
-- print a list of each book and its status ("on shelf" or "checked out")
-- the user can add new books to the inventory - defaulted as "on shelf"

Usability: 
-- The user interacts with the program using the command line 
-- extra credit: add extra functions 

/*
workstream:
first, I decided on using an array as my intended data structure 
then, since the size could grow I changed it to a dynamic array 
I changed scanf to fgets to read in whole lines rather than words (books w multiple words)

Then I wanted to implement the value to each book in the array, 
so I creayed a struct to give more information about the book - on shelf or checked out 
 
