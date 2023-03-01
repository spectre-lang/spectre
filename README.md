# Spectre 编程语言

这是 `Spectre` 编程语言得主仓库，主要包含编译器、文档和开发计划。

`Spectre` **幽灵**是这款编程语言的暂定名，来源于《共产党宣言》的第一句话：「一个**幽灵**，共产主义的**幽灵**，在欧洲游荡」。

这款语言应该具备以下特性：

* 编译型语言。
* 代码跨平台。
* 支持面向对象的程序设计。
* 支持反射。
* 具备异常。
* 空安全。
* 所有权和生命周期。

## 走马观花

下面**可能**是用 `Spectre` 编写的 Hello World 程序：

```spectre
fun main(args: Array<String>) = println("Hello World!")
```

## 特性

我们正在设计 `Spectre` 语言的草案，下面是一些以往编程语言中令人着迷的特性，我们正在考虑将哪些特性添加进 `Spectre` 中。

### 空安全

`Type?` 是一个可以指向 `null` 的指针，而 `Type` 是不允许指向 `null` 的指针。

```spectre
// 下面的语句定义一个可以为 `null` 的整型数字
val i1: Int? = null

// 下面的代码将会编译错误，因为使用 `null` 初始化不可为 `null` 的类型
val i2: Int = null
```

### 类型条件

运用 `Type{condition}` 可以声明一个满足某条件的类型。例如，`Int{? != 0}` 是一个取值非 `0` 的整型数字。

如果不加 `{condition}`，则默认是所有可能的取值。例如，`Int` 等价于 `Int{Int.MIN <= ? <= Int.MAX}`

```spectre
// 下面的代码将会编译错误，因为 `int` 不能为 `0`
val int: Int{? != 0} = 0
```

这些条件未必是编译期能验证的条件。例如，`spectre.lang.List` 中有一个方法 `get`：

```spectre
operator fun get(index: Int{0 <= ? < length}) = data[index]
```

`size` 属性不一定是编译时能确定的，但依旧可以写入类型条件。编译器如果不确定，将会在合适的时候插入断言。

类型条件可以实现零安全，以避免除零错误：

```spectre
// zero 的类型是 Int{? = 0}
val zero = 0

// 下面的语句将编译错误，因为 zero 的取值为 0
val res1 = 5 / zero

// random 的类型是 Int，即 Int{Int.MIN <= ? <= Int.MAX}
// res2 的语句将编译错误，因为 zero 的可能取值为 0
// res3 的语句将编译成功，编译器将会在此之前插入断言
val random = Random().nextInt()
val res2 = 5 / random
val res3 = 5 / random!!
```

满足条件的类型是可以协变的。例如，`Int{? != 0}` 的引用可以接受 `Int{? > 0}` 的值：

```spectre
val int: Int{? != 0} = (Int{? > 0}) 3
```

类型条件中使用 `?` 指代当前值，该值非空的，因此 `? == null` 不可能成立，也不会编译通过：

```spectre
// 编译错误：? 是 Int 类型，不可能为 null
val int: Int{? == null || ? != null} = null
```

### 只读和读写引用

`Type&` 是一个读写引用，例如：

```spectre
// 下面的代码定义了一个读写引用
val m1: Map<String, String>& = HashMap<>()
m1["key"] = "value"

// 下面的代码定义了一个只读引用，immutable 只能用于读取对象
// 因此下面的代码会编译错误
val i1 = HashMap<String, String>()
i1["key"] = "value"
```

可变引用可以绑定在不可变引用上。例如：

```spectre
val m2: List<String>& = ArrayList<String>()
val i2: List<String> = m2
```

引用可以借用和出让。

#### 借用

使用 `&obj` 可以借用一个对象。例如：

```spectre
val s1 = "Hello HirakiLan"
val b1: String* = &s1
```

例如下面的代码：

```spectre
fun longer(s1: String*, s2: String*) = if (s1.length > s2.length) {
    s1
} else {
    s2
}
```