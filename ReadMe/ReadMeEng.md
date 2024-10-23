### Documentation: RVM Language

#### All language versions:
[Click here](https://github.com/YaroslavlPe1/archive)

## Modes

- **Default** — Normal code handling and execution.
  Example:
  ```cpp
  controller(myText, true, false);
  ```
  If no parameters are provided, the mode defaults to **Default**:
  ```cpp
  controller(myText);
  ```

- **Debug** — Deferred code processing with token and process output.
  Example:
  ```cpp
  controller(myText, false, true);
  ```

## List of Token Names:
```cpp
    NUMBER    -   0
    PLUS      -   1
    MINUS     -   2
    MULTIPLY  -   3
    DIVIDE    -   4
    LPAREN    -   5
    RPAREN    -   6
    END       -   7
```

#### Example:
##### Code:
```cpp
1 + 2 * 3 - 4
```

##### Output of tokens (when Debug mode is enabled):
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

## Operation Priority:
```cpp
1. ()  - Parentheses
2. ""  - Strings
3. ''  - Characters
4. * / - Multiplication and Division
5. + - - Addition and Subtraction
6. ID  - Identifiers
```

## Data Types:
- `int` — Integer.
- `double` — A double-precision floating-point number. More precise than `float`.
- `float` — A floating-point number.
- `char` — A data type designed to store a single character.
- `string` — A data type representing an arbitrary sequence (string) of characters.
- `bool` — Boolean value. Can only take two values: `true` or `false`.
- `long` — A long integer.
- `short` — A short integer.

### Structures:
```cpp
struct structure_name {
    structure_components;
};
```

Access modifiers:
- `public` — Accessible by everyone.
- `protected` — Accessible only by the class itself, derived classes, and friends.
- `private` — Accessible only by the class itself and its friends.

## Example Program a+b:
```cpp
import match;
import gl;

void main(int a, int b) {
    a = 100;
    b = 468;
    int g = d + a;
    cout(g);
}
```

## Keywords and Language Constructs:
- `cout` — Outputs text, variables, arrays, etc. to the console.
  ```cpp
  cout " ";
  ```

- `return` — Returns a value.

- `if` — Conditional construct:
  ```cpp
  if (1 != 4) {
      // code block if true
  } elif (2 == 2) {
      // code block if true for elif
  } else {
      // code block if false
  }
  ```

- `switch`, `case`, `default` — Switch block from C++:
  ```cpp
  switch (x) {
      case 1:
          // code
          break;
      default:
          // code
  }
  ```

- `import` — Command to import external code.

- `input` — User input.
  ```cpp
  variable a = input("Enter text:");
  ```

## Loops:
- **For loop**:
  ```cpp
  for (int a = 0; a < 10; a++) {
      // code block
  }
  ```

- **While loop**:
  ```cpp
  int n = 1;
  while (n < 6) {
      cout "Loop completed", n;
      n++;
  }
  ```

- **Do-while loop**:
  ```cpp
  int n = 1;
  do {
      cout "hello";
      n++;
  } while (n <= 10);
  ```

## OOP:
- **Class**:
  ```cpp
  class ClassName {
      ClassName() {
          // constructor
      }
  };
  ```

## Preprocessor:
- `#undef` — Cancels the macro, although it’s usually unnecessary due to the dynamic preprocessor controller.
- `#define` — Macro declarations or function/word replacements.
  ```cpp
  #define print cout
  ```

### Preprocessor Feature in RVM:
Create a `.gr` file and define replacements:
```cpp
class = class,
cout = output,
int = integer,
float = floating-point number
```

In the main assembly file:
```cpp
preprocessor - filename;
```

## Ideal RVM Language Code:
```cpp
import os;

int main() {
    for (int a = 0; a < 15; a++) {
        cout "hello";
    }
}
```
