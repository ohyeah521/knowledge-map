# 作用域

Python创建、改变或查找变量名都是在所谓的命名空间（一个保存变量名的地方）中进行的，一个变
量在被赋值的地点被绑定给特定的命名空间。因此，Python中变量被赋值的地方决定了它的命名空间，
也即是它的可见范围，或者说作用域。

## 作用域法则

- 函数定义了本地作用域，模块定义了全局作用域。
- 全局作用域的作用范围仅限于单个文件。
- 赋值的变量名除非声明为全局变量或非全局变量，否则均为本地变量。
  - 如果要给一个函数内部却位于模块文件顶层的变量名赋值，需要在函数内部通过global语句生明。
  - 如果需要给一个嵌套的def中的名称赋值，从Python3.0开始可以通过nonlocal语句生明。

*注：原处改变对象并不会把变量划分为本地变量，只有对变量名赋值才可以。*  

## 变量名解析规则：LEGB规则

当引用一个变量时，Python按如下顺序查找：从本地变量中，在任意上层函数的作用域，在全局作用
域，最后在内置作用域中查找。变量在代码中被赋值的位置通常决定了它的作用域。

- L，本地作用域
- E，上一层结构中def或lambda的本地作用域
- G，全局作用域
- B，内置作用域

如上的L作用域通常是在函数体内的局部作用域，而E作用域则常出现在函数嵌套的过程中。

## global语句与nonlocal语句

global使得作用域查找从嵌套的模块的作用域开始，并且允许对那里的名称赋值。但是，对全局名称
的赋值总是在模块的作用域中创建或修改他们。

nonlocal限制作用域查找只是嵌套的def，要求名称已经存在于那里，并且允许对它们赋值。作用域
查找不会继续到全局或内置作用域。

比如如下的代码在嵌套的nested()函数中修改status的值会修改其作用域，从而出现
“nboundLocalError: local variable 'status' referenced before assignment”的错误，
可以通过添加nonlocal关键字解决。

```
def test_scope(start):
    status = start
    def nested():
        #nonlocal status
        print(status)
        status += 1
    return nested
```
