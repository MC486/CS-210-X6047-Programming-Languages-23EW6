# Michael Crevier
# 08/20/2023
# CS-210-X6047-Programming-Languages-23EW6
# Desc: A repository used to upload a project to my portfolio for an assignment from the CS-210 class at SNHU
# Proj: Banking Software

** Summarize the project and what problem it was solving.
  
    The program took input from the user to obtain information about an investment account. It received the initial deposit, interest rate, monthly deposit amount and length in years from the user. Afterward, it calculated the compound interest based on the provided parameters and generated a table that outlined the yield schedule for the user's account.
  
** What did you do particularly well?
  
    This program was well optimized using methods to avoid a cluttered main().  It is also extensively commented with detailed, concise comments that are set out with good whitespace and is fairly easy to read.  Because of this, the program is very straightforward when it comes to understanding its function and set-up.
  
** Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
  
    This program could be enhanced with the use of class objects to handle multiple investment accounts, with class files used to remove some of the methods from the main() file in order to make it even more concisely approachable from the outside.  I also should have created a standalone method for calculating the compound interest instead of having it included in the monthlyReturnChart method, which as a result is very long and harder to follow than would be optimal. 
  
** Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  
    I found writing the code for the math used in monthly compounding interest to be the most challenging.  I was able to overcome this by studying the equations used for monthly compounding interest and consulting ZyBooks for help with the code.
    
** What skills from this project will be particularly transferable to other projects or course work?

    The ability to take input, modify that input with calculations and output those values in table format will be transferrable to many other projects, and will be the cornerstone for taking input from a file and creating output for another file.  This will be useful in many fields of work and in most of the future class that I will take.
    
** How did you make this program maintainable, readable, and adaptable?

    Using methods outside of the main() function helps with the maintainability of code by making code that will be called many times in a program and making it able to be edited in one place to affect many.  This makes simple changes easy and makes adapting this code into other projects and uses possible by making the code into concise, single purpose groups of code that can be called for other uses.  It also makes it easier to read as each method is formatted with its name and comments about its function, separated by whitespace.  This breaks up the code into easily readable segments which can be read like a book instead of a group of mangled code.
