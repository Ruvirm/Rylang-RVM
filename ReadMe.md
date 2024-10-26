![иконка](/icon/icon128.png)

## Documentation: RVM Language

#### All language versions:
[Click here](https://github.com/YaroslavlPe1/archive)

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

##### Token output (with Debug mode enabled):
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

## Operator Precedence:
```cpp
1. ()  - Parentheses
2. ""  - Strings
3. ''  - Characters
4. * / - Multiplication and division
5. + - - Addition and subtraction
6. ID  - Identifiers
```

## Data Types:
- `int` — Integer.
- `double` — Double-precision floating-point number, more accurate than `float`.
- `float` — Floating-point number.
- `char` — Data type for storing a single character.
- `string` — Data type for storing a string of characters.
- `bool` — Boolean value, can be either `true` or `false`.
- `long` — Long integer.
- `short` — Short integer.

### Structures:
```cpp
struct structure_name {
    structure_components;
};
```

Access Modifiers:
- `public` — Accessible to everyone.
- `protected` — Accessible only within the class, derived classes, and friends.
- `private` — Accessible only within the class and its friends.

## Example program a+b:
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

## Keywords and Constructs:
- `cout` — Outputs text, variables, arrays, etc., to the console.
  ```cpp
  cout " ";
  ```

- `return` — Returns a value.

- `if` — Conditional construct:
  ```cpp
  if (1 != 4) {
      // code if true
  } elif (2 == 2) {
      // code for elif
  } else {
      // code if false
  }
  ```

- `switch`, `case`, `default` — Switch block:
  ```cpp
  switch (x) {
      case 1:
          // code
          break;
      default:
          // code
  }
  ```

- `import` — Command to import code.

- `input` — User data input.
  ```cpp
  variable a = input("Enter text:");
  ```

## Loops:
- **For Loop**:
  ```cpp
  for (int a = 0; a < 10; a++) {
      // loop code
  }
  ```

- **While Loop**:
  ```cpp
  int n = 1;
  while (n < 6) {
      cout 'Loop executed', n;
      n++;
  }
  ```

- **Do-While Loop**:
  ```cpp
  int n = 1;
  do {
      cout "Hello";
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
- `#undef` — Cancels a macro, though typically unnecessary due to the dynamic control of the preprocessor.
- `#define` — Declares a macro or replacement for a word/function.
  ```cpp
  #define print cout
  ```

### Preprocessor Feature in RVM:
Create a file with the `.gr` extension and define replacements:
```cpp
class = class,
cout = output,
int = integer,
float = floating-point number
```

In the main build file:
```cpp
preprocessor - file_name;
```

## Ideal Code in RVM Language:
```cpp
import os;

int main() {
    for (int a = 0; a < 15; a++) {
        cout "Hello";
    }
}
```
