# ch03-gallery-core
- 像专辑那样管理图片
## gallery-core
- 是一个library动态库包括了应用逻辑的核心：1）数据类；2）持久存储SQL；3）Model使存储通过一个单一的入口点提供给UI
## gallery-desktop
- Qt widgets桌面应用
## gallery-mobile
- QML应用，用于移动平台（Android and iOS）
---
# .pro文件
- `TEMPLATE = subdirs`：表明Qt要寻找子项目来编译
- `SUBDIRS`：是一个列表，可以添加子项目