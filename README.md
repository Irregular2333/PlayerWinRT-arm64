此README.md为本人中文化之后的版本，查看原版README.md[请点击这里](https://github.com/YexuanXiao/PlayerWinRT/blob/master/README.md)

# PlayerWinRT

PlayerWinRT是一个面向现代Windows体验的开源本地音乐播放器

PlayerWinRT正在使用WinUI 3、C++/WinRT和C++ 23进行开发，该项目目前处于早期阶段

## 贡献

欢迎所有的贡献、建议、拉取请求以及问题反馈

如果您想贡献自己的代码，您可以简单地提交一个pull request来说明您的更改

对于更大、更复杂的贡献，如果您在提交pull request之前能够提出一个issue就更好了

## 特性

此列表仅作为本项目的计划目标

- 支持WAV、WMA、MP3、FLAC、ALAC、AC3等格式和编解码器，参考[支持的编解码器](https://learn.microsoft.com/zh-cn/windows/uwp/audio-video-camera/supported-codecs)
- 均衡器
- 定时器
- 网络存储，如SMB、FTP、WebDAV
- OneDrive
## 系统要求

- 支持的操作系统：Windows 10版本1809或更高版本以及Windows 11
- 支持的平台：x64和ARM64

## 构建

仅保证在最新的**VS2022**上编译通过，但欢迎提供向前兼容支持，以及提供与旧工具链兼容性的测试

## 开发路线

- 四月：基本UI
- 五月：播放功能
- 六月：国际化和基本网络存储
- 七月：完整的网络存储和OneDrive

## 截图

![image](https://github.com/YexuanXiao/PlayerWinRT/assets/20025591/b6eadd18-7a32-462d-8543-95bf26b282ab)
![image](https://github.com/YexuanXiao/PlayerWinRT/assets/20025591/dfda3582-fdcb-4b65-b4df-56a02327ba8b)
![image](https://github.com/YexuanXiao/PlayerWinRT/assets/20025591/f07aed58-6d8e-464a-85d2-f4fc16cc7884)
![image](https://github.com/YexuanXiao/PlayerWinRT/assets/20025591/f02a86ba-afc3-4b64-8b49-da281f2a67c6)
![image](https://github.com/YexuanXiao/PlayerWinRT/assets/20025591/b086d54c-fdb2-420a-bf3e-fba4913159ea)
![image](https://github.com/YexuanXiao/PlayerWinRT/assets/20025591/dd624693-4bc8-4bc2-81ac-33fe2b91f3d4)
![image](https://github.com/YexuanXiao/PlayerWinRT/assets/20025591/63f4d109-0645-4268-a76d-dd082b2f560d)
![image](https://github.com/YexuanXiao/PlayerWinRT/assets/20025591/2d46d20e-c36a-4cff-9204-a9dfb462259e)
![image](https://github.com/YexuanXiao/PlayerWinRT/assets/20025591/7ca063a2-c90b-4dde-98cb-7976cf3f2b47)

## 安装方式
此仓库为本人拉取之后编译的arm64版本，这里对于安装方式简单说明

在[Release](https://github.com/Irregular2333/PlayerWinRT-arm64/releases)中下载最新的编译版本后解压你可以看到如下文件：

![image](https://raw.githubusercontent.com/Irregular2333/Code-Caches/main/PlayerWinRT-arm64%20ScreenShots/1.png)

如果你可以正常安装，那么恭喜你））

![image](https://raw.githubusercontent.com/Irregular2333/Code-Caches/main/PlayerWinRT-arm64%20ScreenShots/2.png)

如果不能，请看下面的步骤

右键安装包->属性->数字签名->选中"Irregular"->详情信息

![image](https://raw.githubusercontent.com/Irregular2333/Code-Caches/main/PlayerWinRT-arm64%20ScreenShots/3.png)

在弹出来的页面中点击->查看证书，再在弹出来的页面中点击->安装证书

![image](https://raw.githubusercontent.com/Irregular2333/Code-Caches/main/PlayerWinRT-arm64%20ScreenShots/4.png)

![image](https://raw.githubusercontent.com/Irregular2333/Code-Caches/main/PlayerWinRT-arm64%20ScreenShots/5.png)

将证书安装至本地计算机->受信任的根证书颁发机构，之后点击完成

![image](https://raw.githubusercontent.com/Irregular2333/Code-Caches/main/PlayerWinRT-arm64%20ScreenShots/7.png)

![image](https://raw.githubusercontent.com/Irregular2333/Code-Caches/main/PlayerWinRT-arm64%20ScreenShots/8.png)

提示导入成功之后，再次尝试安装，如果能够正常安装即可

![image](https://raw.githubusercontent.com/Irregular2333/Code-Caches/main/PlayerWinRT-arm64%20ScreenShots/9.png)

如果此时安装提示什么依赖不行，框架不支持什么的，请安装Dependencies/arm64文件夹下面的三个安装包，安装之后再去安装软件本体，此时应该理论上不会出现什么奇奇怪怪的问题了

![image](https://raw.githubusercontent.com/Irregular2333/Code-Caches/main/PlayerWinRT-arm64%20ScreenShots/10.png)

![image](https://raw.githubusercontent.com/Irregular2333/Code-Caches/main/PlayerWinRT-arm64%20ScreenShots/2.png)