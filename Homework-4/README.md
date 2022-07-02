## 编译说明

**注意：如果您是从github上下载的我的代码，那么将不包含图片文件和pdf文件（因为文件太大了），请务必完整执行以下三个步骤完成编译。建议您从学在浙大下载包含图片与pdf的压缩包。**

在项目根目录下打开终端，首先编译源代码（大约需要10秒）：

```bash
make
```

然后获得论文所需的图像（大约需要10分钟，如果您是从学在浙大上下载的代码，可以忽略这一步）：

```bash
make img
```

最后编译报告（大约需要5分钟）：

```bash
make report
```

使用以下命令清除编译过程产生的中间文件：

```bash
make clean
```

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


## 源文件说明

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