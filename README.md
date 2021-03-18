# Wise
一款尚处在设想中的编程语言。

<b>如果你喜欢这款语言或对此有所期望，欢迎提交 `issue` 讨论 (๑•̀ㅂ•́)و✧`</b>

## 特性
1. <b>状态迁移</b><br>
所有的对象都有各种「状态」，例如 `Student`（学生）的作业属性有「已完成」和「未完成」两种状态。若有一个指定的方法可以将该对象作业由未完成迁移至已完成，则完全可以通过类似 `student.homework => FINISHED` 之类的语句让系统自动调用对应的方法链。

## 语法
`wise` 语言尚没有构思好整体的代码风格。但是比较确定的内容有：

1. 对象的状态。例如学生的作业可以有 `UNFINISHED` 和 `FINISHED` 两种状态。
1. 函数的影响。例如 `Student` 类内可有一函数 `finishHomework()` 让学生完成作业，则该函数的`影响`就是可以将作业的状态由 `UNFINISHED` 转换为 `FINISHED`。
1. 状态转移语句：`object.propertyName => STATE`。<br>
例如 `student.homework => FINISHED`，表示通过一系列的函数，将对象 `student` 的属性 `homework` 的状态转移为 `FINISHED`。<br>
这条语句相当于直接调用 `student.finishHomework()`。

## Demo
1. `Hello World`
```wise
package wiki.chuanwise;

public class HelloWorld {
    public static void main(String... args) {
        "Hello World!" => SHOWED;
    }
}
```