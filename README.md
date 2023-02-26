# The Spectre Programming Language

This is the main repository for Spectre. It contains documentations, plans and logs.

The name comes from the first sentence of `Manifesto of the Communist Party`: `A spectre is haunting Europe – the spectre of communism`.

We're planing all the details of Sunrise. Some results are as follows:

## Features

### Null safety

`Type?`, a nullable type, can be pointed to `null`. 

```spectre
val int: Int? = null
```

A program can not be compiled successfully as such:

```spectre
val int: Int = null
// Compilation error: int is a non-null reference, can not be pointed to `null`
```

### Zero safety

In order to prevent from dividing by zero, spectre makes `Type$` as a type of values can be set to `0`.

```spectre
val int = 0
// int is `Int$`
```

Or you can use `condition`. `Type{condition}` is a type of values match the condition. 

```spectre
val int: Int{!=0} = 0
// Compilation error: int is `Int{!=0}`, but initial value is `0`
```

Which is equality to the previous example.

Spectre will check if the divide number is zero. Codes can not be compiled successfully as such:

```spectre
val i0 = 1
// i0 is Int{=1}

val i1 = i0 - 1
// i1 is Int{=0}

val i2 = 5 / i1
// Compilation error: i1 is Int{=0}
```

### Reflection

`T.type` is an object `Type<T>` represents itself. 

```spectre
println(Int.type.name)
// prints `spectre.lang.Int`
```

In addition, `obj.type` is an object represents the actual type of `obj`.

```spectre
val i = 6
// i is Int{=6}

val type = i.type
// type is `Type<Int>`

if (type is Data<Int>) {
    // type is Data<Int> because of smart cast
    type.set(8)
}
```