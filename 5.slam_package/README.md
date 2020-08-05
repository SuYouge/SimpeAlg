# 3. SLAM相关库测试

## 3.1 Opencv


## 3.2 Eigen


## 3.3 Sophus


## 3.4 g2o

[VS CODE下配置《视觉SLAM十四讲》工程](https://suyouge.github.io/2020/01/18/package-vslam-3/)  

这篇博客里写得比较详细，主要是在配置opencv和pangolin两个库的时候遇到了问题  

实际上可以直接参考我的**配置文件**  

[tasks.json](../../.vscode/tasks.json)  
[launch.json](../../.vscode/launch.json)  
[c_cpp_properties.json](../../.vscode/c_cpp_properties.json)  

**坑点提炼如下：**

友情提示： cmake是个好工具 / cmake-gui更好

在报错提示缺少`libxxxx.so`时可以直接按照`tasks.json`的格式插入`"-l", "GL"`试试。

实际动态库文件不同版本命名为`libxxxx.so.1`这种形式，但这样改变了后缀所以可以使用软连接将后缀改回`.so`
```
sudo ln libxxxx.so.1 libxxxx.so
```

Linux运行时动态库搜索：运行时提示找不到`.so`文件可以编辑配置文件`/etc/ld.so.conf`来指定动态库搜索路径

安装g2o可以参考这篇文章：
[g2o cmake-gui 安装排坑](https://blog.csdn.net/YuYunTan/article/details/85293078#cmakeguig2o_129)