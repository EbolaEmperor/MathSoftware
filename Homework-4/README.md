# 测试说明

**注意：由于图片与pdf文件过大，不便上传至Github，建议您从学在浙大上下载包含图片与pdf的文件。如果您是在Github上clone的我的项目，您需要在本机进行编译。**

## 编译说明

直接执行以下命令可以一步编译，当然需要一些时间，您需要等待大约20分钟。

```bash
bash compile.sh
```
当然您也可以通过如下步骤手动编译：

1. 在`source`目录下执行`make`编译源代码
2. 在`source`目录下新建目录`img/`
3. 运行`paperpicgen`获得论文中的所有图片
4. 将`source`目录下的`img/`目录拷贝至`report.tex`同目录下
5. 在`report.tex`所在目录下执行`make`编译论文

**如果您是在学在浙大上下载的文件，那么论文与图片可以不用重复生成，您可以只执行上述第一步。**

## 测试说明

编译后得到论文，同时在`source`目录下生成两个可执行文件`test`和`paperpicgen`

运行`paperpicgen`可以生成论文中的所有图片。`test`可以生成Mandelbrot集的局部图像，使用方式如下：

```bash
./test [filename] [x] [y] [d] [N]
```

上述所有参数都是可选参数，允许从后往前缺省：
- 第一个参数为文件名（缺省值：`test.png`）
- 第二、三个参数是绘图区域中心（缺省值：`0.0, 0.0`）
- 第四个参数为绘图区域直径（缺省值：`5.0`）
- 第五个参数为最大迭代次数（缺省值：`100`）


## 文件说明

- `compile.sh`：一键编译指令
- `report.tex`：论文源文件
- `reference.bib`：引用文献目录
- `Makefile`：论文编译指令
- `source`目录包含所有源代码文件
  - `main.cpp`：绘图主程序
  - `paperpicgen.cpp`：生存论文中所有图片的主程序
  - `png.h`：png编码器的头文件
  - `png.cpp`：png编码器的实现
  - `axis.h`：像素坐标-轴坐标转换器的头文件
  - `axis.cpp`：像素坐标-轴坐标转换器的实现
  - `mandelbrot.h`：Mandelbrot集迭代器的头文件
  - `mandelbrot.h`：Mandelbrot集迭代器的实现
  - `Makefile`：代码编译指令
  - `lib`：由[queensun](https://Github.com/queensun)编写的zlib开源库