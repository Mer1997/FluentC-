# FluentC++

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Instructions](#instructions)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## Instructions

每个文件夹对应 **Jonathan Boccara** 的 [FluentC++](https://www.fluentcpp.com/posts/) 中的一章内容，`main.cc` 文件中是对文章代码部分的总结，实现可能与文中有些许不同，对于任一文件夹可以通过执行以下命令编译程序以查看效果：
```shell
cmake -S . -B build #创建 build 文件夹同时执行 cmake
cmake --build build #编译项目
```
如果提示编译失败, 提示 `static_assert(false)` 说明该节源码中包含不完全的实现，理解文章所要表达的概念即可
