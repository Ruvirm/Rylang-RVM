# Привет, это список ошибок языка Rl🧩

### Код ошибки номер 1

Ошибка: нельзя использовать несколько режимов!

Значит, что при работе с компилятором активирована несколько режимов. 

```cpp
int main() {
std::string myText = "cout('привет');";

    controller(myText,true,false);
return 0;
}
```
```cpp
controller(myText,false,false);
```

myText — это переменная, которая хранит код на Rl, можно и так:

```cpp
controller("cout('привет');",true,false);
```

### Код ошибки номер 2
Ошибка: не выбран режим работы!

```cpp
controller(myText,false,false);
```
