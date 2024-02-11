# LL1Checker
Check if the grammar is LL1; also, accept an input string and verify if that string belongs to the language generated by the grammar.
The program reads the grammar from a file.

# Important
The project is under development, although all the functionality is ready, and the program works. I tested it with several grammars and the results are as expected. **If you encounter an incorrectly interpreted LL1 grammar, please open an issue and provide all the details**. 

# Requirements
- This program only works on Linux systems (for now). This is due to the use of `dlfcn.h` header for loading dynamic libraries.
- Flex (the fast lexical analyzer generator) needs to be installed on your system. This is necessary because the program generates a lexer file and compiles it using `flex`.
- Within the code, there is a call to the C compiler `gcc`, so, `gcc` needs to be installed.
- The Makefile provided uses `g++`, it can be changed to use other compiles such as `clangd` **(not tested)**.

# Compiling
A Makefile is provided.

# Run it
After running `make` simply execute `./parser`. The program can accept at most two arguments.
- `./parser <GRAMMAR_FILENAME>`. Checks if the provided grammar is LL1.
- `./parser <GRAMMAR_FILENAME> <INPUT_FILENAME>`. Check if the provided grammar is LL1 and verifies if the input provided conforms to the grammar.

# To consider
- The end of line character is **$**, currently it cannot be changed.
- When writing the terminals symbols, it should be noted that they will be evaluated in order_. So, if A and B are two regex with common elements, you should put the more specific one first. Example:
~~~
terminal WH while;
terminal WORD [a-zA-Z][a-zA-Z]*;
~~~
# Structure of grammar.txt
It consists of two sections: symbol definition and grammar; each section is separated by **;**.
At the moment it is necessary to designate a symbol to serve as the axiom.
## Symmbol definition
~~~
no terminal S;
no terminal A;
start with S;
~~~
You should write the last line to designate S as the axiom (this will be changed).
The terminal symbols follows the following structure: `terminal <IDENTIFIER> <REGEX>;`. The `<IDENTIFIER>` should adhere to the following regex pattern: `[a-zA-Z_\'][a-zA-Z_\'0-9]*`. This rule also applies to no terminal definition.
An example of the first section would be:
~~~
no terminal S;
no terminal A;
terminal a a;
start with S;
;
~~~
## Grammar definition
The grammar follows the following structure:
~~~
S -> A$;
A -> aaA;
A ->;
;
~~~
Note that currently, the line `S -> A$` (axiom) is required. However, this will be automated in order_ to augment the grammar with that rule. As mentioned in the "to consider" section, the EOL character currently used is **$**.
The line `A->;` represents an empty production.
So, our **grammar.txt** would be:
~~~
no terminal S;
no terminal A;
terminal a a;
start with S;
;
S -> A$;
A -> aaA;
A ->;
;
~~~
This grammar generates the following language: `L(G) = {aa, aaaa, aaaaaa, ...}`, that is, a language with an even number of 'a'.
And in **input.txt** file, you place the line you want to check (don't forget the **$**!).
