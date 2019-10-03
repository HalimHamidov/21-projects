
<h3>
Highly recommended to check official site of Debugging in Visual Studio Code
https://code.visualstudio.com/docs/editor/debugging

```diff
- => If you found helpful then please do follow and give a star 
```
:v: :raised_hands: 
</h3>

{
// Use IntelliSense to learn about possible attributes.
// Hover to view descriptions of existing attributes.
// For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
"version": "0.2.0",
"configurations": [
{
"name": "lldb",
"type": "cppdbg",
"request": "launch",
"program": "${workspaceFolder}/a.out",
"args": ["test.txt"],
"stopAtEntry": false,
"cwd": "${workspaceFolder}",
"environment": [],
"externalConsole": false,
"MIMode": "lldb",
}
]
}

# 21-School--
For better understanding pull the work and use debugger(VScode LLDB)  to see how each step works.
Any suggestion's will be highly appreciated. -_-

Don't ever forget ever to use `-g` like the example below during compiling:

gcc main.c get_next_line.c get_next_line.h libft.a -g
