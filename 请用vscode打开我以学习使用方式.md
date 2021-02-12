# 如何利用markdown进行记录笔记
## 我是二级标题
### 我是三级标题
## **我是加粗的二级标题**
## *我是倾斜的二级标题*
#### ***我是惨遭斜体加粗的四级标题***

~~我是惨遭划掉的东西~~
# 下面是花样引用的状态
>这是你爹引用的东西
>>你爹还想多引用一点
>>>好像可以无限引用
>>>>>>>>>>虽然没有卵用

真有意思那么接下来是分割线
-------
这个不行
****
厉害吧！

插入图片
![blockchain](D:\sai7e03300ec0db4902921eaef95f3eb555.jpeg)

插入超链接
[简书教程链接](https://www.jianshu.com/p/191d1e21f7ed)
# 无序列表和有序列表的格式
无序列表

* 列表内容

+ 列表内容

- 列表内容

1.我是第一个

2.那我就是第二个
    
* 我是弟中弟
* 我是弟弟
    * 弟弟的弟弟
    * 滴滴滴
        * 孙子就是我
            * 什么！子子孙孙无穷匮也。

3.嘿嘿第三个在这里    

    1.我是第三个的小弟弟
        
        * 我是小弟弟

# 我是表格的格式
姓名|技能|排行
--|:--:|--:
刘备|哭|大哥
关羽|打|二哥
张飞|骂|三弟

# 我是单行代码的格式
`printf("hello world!");`

```flow
st=>start: 开始
op=>operation: My Operation
cond=>condition: Yes or No?
e=>end
st->op->cond
cond(yes)->e
cond(no)->op
```
# 我是直接引用图片的格式
![Paste_Image.png](http://upload-images.jianshu.io/upload_images/8031371-79d13bad8d89efa9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
# 我是代码的格式
```cpp
#include<iostream>
using namespace std;
int main(){
    cout<<"hello world";
    reuturn 0;
}