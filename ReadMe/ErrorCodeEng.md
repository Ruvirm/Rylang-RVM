# Rl Language Errors 🧩

## Error 1: Cannot use multiple modes!
> [!CAUTION]
> **Error:** Multiple modes cannot be activated simultaneously!

This error occurs when more than one mode is enabled while working with the compiler. Only one mode can be active at a time.

### Example:
```cpp
int main() {
    std::string myText = "cout('hello');";

    controller(myText, true, false); // Default mode
    return 0;
}
```
But if you add another call with a different mode:
```cpp
controller(myText, false, false); // Error! Cannot use multiple modes at the same time
```

### How to fix:
`myText` is a variable that stores Rl code. You can also pass the code directly:
```cpp
controller("cout('hello');", true, false); // Correct usage
```

---

## Error 2: No mode selected!
> [!CAUTION]
> **Error:** No mode selected!

A working mode must be selected. Without selecting a mode, the program doesn't know how to process the code.

### Example:
```cpp
controller(myText, false, false); // Error! No mode selected
```

### How to fix:
Set the working mode: **Default** or **Debug**.

```cpp
controller(myText, true, false);  // Correct usage (Default mode)
```

---

## Error 3: Unknown token in the code!
> [!CAUTION]
> **Error:** An unknown token was encountered in the code!

This error occurs when the compiler encounters a token that it doesn't recognize.

### Example:
```cpp
controller("print(hello);", true, false); // Error! Unknown token "print"
```

### How to fix:
Check the code for correct syntax and use valid language constructs.
