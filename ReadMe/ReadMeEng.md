# Documentation:
#### All language versions:
[Тык](https://github.com/YaroslavlPe1/archive)

## Modes
Default is normal code handling and execution.
```cpp
controller(myText, true, false);
```
true — values for working in the Default\mode. 
If you write like this:
```cpp
controller(myText);
```
Then the default mode is Default\mode.

Debug is code-deferred processing and output of tokens and processes.
```cpp
controller(myText, false, true);
```
true — values for working in Debug\mode. 



### This is a list of token names:
` \ ``
### For example:

#### Code:
1 + 2 * 3 - 4

#### You can output tokens when you enable Debug mode.
```cpp
Token(Type: 0, Value: "1")
Token(Type: 1, Value: "+")
Token(Type: 0, Value: "2")
Token(Type: 3, Value: "*")
Token(Type: 0, Value: "3")
Token(Type: 2, Value: "-")
Token(Type: 0, Value: "4")
Token(Type: 7, Value: "")
```



\ # \ # Operation priority:
`` \ ``

### data types:
`` \ `cpp

int - integer.
```

```cpp

double -A double-precision floating-point number. More accurate than float.
```

```cpp

float - A floating-point number.
```

```cpp

char - a data type designed to store a single\character.
```

```cpp

string - a data type whose values are an arbitrary sequence of\ (string) characters of the alphabet. 
```

```cpp

bool - Boolean value. It can only take one of two values: true or false. 
```

```cpp

long - A long integer.
```

```cpp

short - A short integer.
```

```cpp

struct name_structure {
components_structure
}

public Everyone has access to.

protected Only the class itself, derived classes, and friends have access to.

private Only the class itself and friends have access to.
```

### Program a+b
```cpp
Import match
Import gl

void main (int a,b)
{
   a = 100;
   b = 468;
   
   g = d + a;
   coat(g);
}

```

### Keywords and language constructs
```cpp
Embedded in the Rl language

cout \ is the output to the console of text or variables, arrays, and so on.
cout" ";

return - returns the value of.  

if \ - regular if construction:
if 1 != 4 {
// code block if true
}elif 2 = 2\ {
//code block if true elif
}esle\ {
//code block if false
}
// at the end of work in the bottom
switch \ - switch block from c++
case \ - elif
default operator \ - if more than one case is not true 

import \ - command to import the finished code.

input - sending data to users.

variable a = user input message " Enter text:";

Cycles:

for(int a, 10 < a, i++){ // for loop
/ / block code
}
// while
int n = 1;
while n < 6{
cout 'Loop completed', n;
    n = n+1;
}
// do while
int n = 1;
do {
    cout"hello";
    ++ n;
} while (n <= 10);

OOP:
class \ - class declarations for OOP
struct \ - structure
class name {

 name(){
variables
} // constructor

}

```

```cpp

Preprocessor:
#undef \ - cancel the macro, but it is not necessary because there is a dynamic preprocessor controller.
 
 #define - macro declarations or replacing the function word, and SO on.

#define print = cout;
this means that the preprocessor changes the words to something else.

feature of \ #define in RVM

create a file with . gr
and write 

file content:
```
## how to write in a file:
old \ _word = new_word or a whole
block of code.
```cpp

#define{

class = class,
cout = output,
int = integer,
float = number with a plushpoint

}

"in the main assembly file, write "
" preprocessor - (file name);"
"which is located near the file build.txt"
```

\ # \ # perfect RVM language code

```cpp

import os

int main() {
    for int a, 15 < a, i++ {
        cout "hello";
    }          

}
```
