# JVAV--

## 测试方法

使用 llvm 的后端工具链对前端进行测试

1. 在`JVAV--/Makefile`中，修改 test_case 的要测试的`.jvav`文件为你要测试的文件
2. 如果是第一次构建，执行`bash ./build.sh`
3. 如果不需要重新构建，直接`make out`即可

## TODO

* 调试完善前端
* 用 llvm 的 api 写一个简单的后端