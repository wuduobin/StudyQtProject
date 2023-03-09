# sys info
- 跨平台代码，支持Windows、Mac OS、Linux。使用了单例模式和策略模式
- 继承结构中，子类快捷键插入父类的虚函数,先鼠标选择声明的子类：1）Mac：[option] + [Enter] 2）Windows/Linux: [Alt] + [Enter]

## qBound()
- template <typename T> const T &qBound(const T &min, const T &val, const T &max)
- Returns val bounded by min and max. 
## 判断平台
```C++
#ifdef Q_OS_WIN
    static SysinfoWindowsImpl singleton;
#elif defined(Q_OS_MAC)
    static SysInfoMacImpl singleton;
#elif defined(Q_OS_LINUX)
    static SysInfoLinuxImpl singleton;
#endif
```

## 显示系统的CPU和内存
![](bin/1.png)