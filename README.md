# CS50x_Notebook
All problem sets are located in this repository.

## Week 0 - Scratch
Load the .sb3 file into https://scratch.mit.edu to run the program.

## Week 1 to 5 - C
### Local Windows Set-Up
#### Environment Setup
1. Open PowerShell and run to install MSYS2:<br> 
winget install MSYS2.MSYS2<br> 

2. Open MSYS2 UCRT64 from Windows Start menu and run to install GCC Compiler:<br> 
pacman -S mingw-w64-ucrt-x86_64-gcc<br>

3. Add GCC to Windows PATH:<br>
    - Press Win + R, type sysdm.cpl, and press Enter
    - Go to Advanced > Environment Variables
    - Under User variables, select Path, click Edit > New, and paste: C:\msys64\ucrt64\bin
    - Click OK on all windows and restart VS Code

#### Project File Compilation
Option A: Terminal (Manual)<br>
Move the cs50.c and cs50.h files into the running sub-folder<br>
Open VS Code terminal (Ctrl + ~) to run:<br>
gcc filename.c cs50.c -o filename.exe<br>
.\filename<br>

Option B: VS Code Build & Debug (F5 Play Buttion)<br>
Create a .vscode folder in the project workspace with these two config files:<br> 
.vscode\tasks.json and .vscode\launch.json<br>

#### Other Notes
Style Guide for C: https://cs50.readthedocs.io/style/c/<br>

## Week 6 - Python
#### Project File Compilation
Open Command Prompt or VS Code terminal (Ctrl + ~), and cd directory to run:<br>
python filename.py<br>

#### Other Notes
Python Documentation: https://docs.python.org/3/builtins/index.html<br>

## Week 7 - SQL
#### Project File Compilation
Open Command Prompt or VS Code terminal (Ctrl + ~), and cd directory to run:<br>
sqlite3 db_name.db<br>
.schema -- to view tables and values datatype<br>
-- insert SQL query to retrive required info<br>

#### Other Notes
Syntax Guide for SQL: https://www.w3schools.com/sql/sql_ref_keywords.asp<br>
Style Guide for SQL: https://www.sqlstyle.guide/#indentation<br>