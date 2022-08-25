# Minishell
erdogancayir/Minishell 🐚

Clone the repo git clone

Install Readline library make install

Compile Minishell make

Run ./minishell

Enjoy!

Displays a prompt where you can enter new commands.
Just like bash, it can find and run the correct executable (using the PATH variable, relative or absolute path).
I implemented the following built-in functions to make it work like bash:
echo with option '-n'
cd using only relative and absolute paths
pwd without option
Export without options
set without option
no env option and no arguments
no option exit
Inside the door, as in Bash; You can separate commands.
The 'I' is implemented to behave like Bash except for multi-line commands.
Redirect < > ">>" works like Bash except that file descriptors are collected.
pipe | It works like bash.
Environment variables (occurs after $) behave like Bash.
$? It works like bash.
'Ctrl-C, ctrl-D, ctrl -' gives the same result as Bash.
About
Minishell is the second project of the Unix branch at 42. It's a minimum viable version of a real shell. The main goal is to have a good understanding of process creation and synchronisation using the C programmming language.

<img width="629" alt="Ekran Resmi 2022-08-10 ÖÖ 10 52 22" src="https://user-images.githubusercontent.com/94300378/183847185-b07d3894-e4c0-4cf6-b81a-abc5f1369c89.png">
<img width="725" alt="Ekran Resmi 2022-08-10 ÖÖ 10 58 25" src="https://user-images.githubusercontent.com/94300378/183847457-c2eb9cff-3ab9-4d4a-a4f4-8a58594fb520.png">
