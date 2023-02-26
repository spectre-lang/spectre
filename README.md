# The Sunrise Programming Language

This is the main repository for Sunrise. It contains documentations, plans and logs.

The name comes from the first sentence of `Manifesto of the Communist Party`: `A spectre is haunting Europe – the spectre of communism`.

We're planing all the details of Sunrise. Some results are as follows:

## Features

### Null safety

`Type?`, a nullable type, can be pointed to `null`. 

```spectre
var int: Int? = null
```

A program can not be compiled successfully as such:

```spectre
var int: Int = null
// Compilation error: int is a non-null reference, can not be pointed to `null`
```

### Zero safety

In order to prevent from dividing by zero, spectre makes `Type$` as a type of values can be set to `0`.

```spectre
var int = 0
// int is `Int$`
```

Or you can use `condition`. `Type{condition}` is a type of values match the condition. 

```spectre
var int: Int{!=0} = 0
```

which is equality to the previous example.

Spectre will check if the divide number is zero. Codes can not be compiled successfully as such:

```spectre
var i0 = 1
// i0 is Int{=1}
var i1 = i0 - 1
// i1 is Int{=0}
var i2 = 5 / i1
// Compilation error: i1 is Int{=0}
```