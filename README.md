# Compiler Lab Programs

This repository contains a collection of essential programs and tools implemented as part of a compiler design lab. The programs here cover various stages and components of a compiler, from lexical analysis to intermediate code generation, along with tools like Lex and Yacc for parsing and expression evaluation.

## Table of Contents
1. [Lexical Analyzer](./Lexical-Analyzer)
2. [Recursive Descent Parser](./Recursive-Descent-Parser)
3. [Shift-Reduce Parser](./Shift-Reduce-Parser)
4. [First and Follow Computation](./First-and-Follow)
5. [Operator Precedence Parser](./Operator-Precedence-Parser)
6. [Intermediate Code Generator](./Intermediate-Code-Generator)
7. [Backend Implementation of a Compiler](./Backend-Compiler)
8. [Lex and Yacc Programs](./lex-and-yacc-programs)



### 1. Lexical Analyzer
A lexical analyzer (or lexer) processes an input source code string to identify tokens like keywords, operators, identifiers, and literals. This program helps convert the source code into tokens for further stages of compilation.

### 2. Recursive Descent Parser
This program implements a recursive descent parser for a simple grammar. It uses recursive functions to parse input according to predefined grammar rules, validating the syntax of the expressions.

### 3. Shift-Reduce Parser
A shift-reduce parser is implemented here to parse expressions and reduce them according to specified grammar rules. This type of bottom-up parser uses a stack to handle shifts (moving input onto the stack) and reduces (applying grammar rules to reduce items on the stack).

### 4. First and Follow Computation
This program computes the First and Follow sets for non-terminals in a given grammar. These sets are crucial for constructing parse tables in predictive parsing, helping to determine which production rules to apply.

### 5. Operator Precedence Parser
An operator precedence parser is used to parse expressions based on operator precedence and associativity. This program builds a precedence table to guide the parsing process.

### 6. Intermediate Code Generator
The intermediate code generator converts high-level source code into an intermediate representation. This intermediate code is often platform-independent and serves as a bridge to generate optimized machine code.

### 7. Backend Implementation of a Compiler
This module represents the backend of a compiler, including tasks like code optimization, register allocation, and final code generation. It uses the intermediate code to produce optimized machine or assembly code for the target platform.

### 8. Lex and Yacc Programs
This section includes several programs demonstrating the use of **Lex** and **Yacc** tools for lexical and syntax analysis:

   - **[Lexical Analyzer using Lex Tool](./Lexical-lex)**: Implements a lexical analyzer using Lex to tokenize the input.
   
   - **[Arithmetic Expression Recognition](./Arithmetic-lex)**: Uses Lex and Yacc to identify and evaluate arithmetic expressions.
   
   - **[Identifier Validation](./identifier-lex-yacc)**: Checks for valid identifiers in the source code using Lex and Yacc.
   
   - **[Calculator using Lex and Yacc](./Calculator)**: Implements a basic calculator that can evaluate arithmetic expressions, demonstrating the use of Lex for tokenizing and Yacc for parsing and evaluating expressions.



Getting Started
Each program in this repository is located in a separate folder with source code and any necessary input files. To execute each program, follow the instructions in its respective directory.
Prerequisites
    1. C/C++ Compiler
    2. Lex and Yacc tools installed
