# GitHub修改host

## 前言

中国访问 GitHub 的速度不忍直视，那就叫一个慢！


>Q:为什么访问速度会很慢？
>A: GitHub 在国内访问速度慢的问题原因有很多，但最直接和最主要的原因是 GitHub 的分发加速网络的域名遭到 dns 污染。



>Q:如何解决 DNS 污染？
>A: 通过修改 hosts 解决污染问题


## 1.查询ip地址，输入需要访问的网站，查询ip

[▷ GitHub.com : GitHub: Where the world builds software · GitHub (ipaddress.com)](https://websites.ipaddress.com/github.com)

如果IP Address显示为4*IPV4，则有四个ip地址，拉到下方查看

需要查询的域名有`github.com`,`assets-cdn.github.com`,`github.global.ssl.fastly.net`，也可以根据自己常用的域名添加其他GitHub域名

## 2.复制IP地址到host文件

**host文件路径**：`C:\Windows\System32\drivers\etc\hosts`

**第一步：**修改hosts文件属性：右击hosts文件，选择属性，将下方的只读属性的对勾去掉，然后点击应用、确定。

![网络图片](https://img-blog.csdnimg.cn/20200523181739843.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MTE4NzAw,size_16,color_FFFFFF,t_70 "备注")

安全里面的权限不用改！百度好多方法都是点进安全改角色权限。这种方法没有作用

**第三步**

以**管理员**进入控制台

任务栏右下角搜索cmd或者命令提示符，右击以管理员身份运行(右击电脑左下角开始，点击windows powershell(管理员))

或者`win+R`输入`cmd`按`Ctrl+Shift`+`Enter`也是管理员启动

再或者电脑管家之类，火绒的安全工具里面有一个修改Host文件，可以快速启动Host

在cmd中输入`notepad C:\Windows\System32\drivers\etc\hosts`，回车

**第四步**

修改host文件，格式，输入地址 空格后的网站地址可以不输入，只是做标记使用

```
# GitHub Start
140.82.111.4 github.com
185.199.118.153 assets-cdn.github.com
185.199.119.153 assets-cdn.github.com
185.199.111.153 assets-cdn.github.com
185.199.111.153 assets-cdn.github.com
2606:50c0:8000::152 assets-cdn.github.com
2606:50c0:8001::152 assets-cdn.github.com
2606:50c0:8002::152 assets-cdn.github.com
2606:50c0:8003::152 assets-cdn.github.com
199.232.69.192 github.global.ssl.fastly.net
# GitHub End
```

**第五步**

启用新的hosts

windows下打开命令行界面，输入`ipconfig /flushdns`,刷新本地dns数据即可。
linux下需执行`sudo /etc/init.d/networking restart`重启网络。

**第六步**，测试一下！



<h1>modifyhost.bat就是用上述方法写的，需要右击属性设置默认以管理员运行</h1>

