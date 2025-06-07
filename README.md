# JVAV--

模仿 java 语法的简单编译器，基于 antlr 和 llvm

## 环境搭建

### riscv64-unknown-linux-gnu

```bash
$ git clone --recursive https://github.com/riscv/riscv-gnu-toolchain
$ cd riscv-gnu-toolchain
$ mkdir build
$ cd build
$ ../configure --prefix=/opt/riscv64-linux --with-arch=rv64imafdc --with-abi=lp64 -enable-linux
$ make linux -j8
$ echo 'export PATH=$PATH:/opt/riscv64-linux/bin' >> ~/.bashrc
```

## 构建和测试方法

```bash
$ ./build.sh build
$ ./build.sh test
$ ./build.sh clean
```

获取脚本帮助

```bash
$ ./build.sh help
```