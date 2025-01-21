**readme文档观看顺序：按时间顺序从下往上看**

## 2025.01.20 更新
1. 增加梁自定义实体功能，可以通过在屏幕上点选绘制梁实体
## 2025.01.10 更新
1. 修复直线穿过矩形的判断bug。
2. 修复Grid模块相关代码逻辑bug。
## 2025.01.09 更新
增加几何判断函数：
1. 获得自定义柱子矩形包围框。
2. 判断矩形是否在矩形内部。
3. 判断直线是否穿过矩形。
4. 判断线段是否相交，如相交则计算交点。
## 2025.01.08 更新
增加选择集相关函数，可以选择：
1. 任一database内所有实体。
2. 矩形范围内所有实体。
3. 根据指定过滤器选择实体。
4. 选择图层上所有直线实体。
## 2025.01.07 更新
增加选择集功能，可以选定固定图层上的直线进行柱子插入。
## 2025.01.06 更新
解决多重引线的箭头样式问题，可以自动读取自定义柱子的信息自动生成相应的标注。
## 2025.01.02 更新
多重引线功能已经制作完毕，未发现异常导致CAD崩溃。
## 2024.12.29 更新
圆形柱子的预览图bug也已经修改成功。
## 2024.12.28 更新
现在加入了MFC界面，可以实时预览输入的参数生成的自定义柱子是否正确，暂时完成了方柱的预览图编辑，圆形的预览图有点小问题，正在修改中。
## 2024.12.25 更新
自定义实体函数单元测试通过，暂时没有发现其他问题会导致CAD崩溃。
## 2024.12.23 更新
柱子自定义实体现在可以复制粘贴。修改了之前文件的一些小bug
## 2024.12.20 更新
目前完成了柱子的自定义实体绘制。修改了之前文件的一些小bug
### PolaPillar自定义实体说明
编译，加载，看效果的步骤同Grid。
**特殊说明：new 一个自定义实体之后如要使用务必完成函数内置的各类set函数！！哪些是必须参数可以参考checkValue()函数**
## 2024.12.16 更新
把之前的一个.arx文件分成了几个小的.dbx文件，主要更新还是Grid这个功能。
### Grid使用说明
编译整个Project后，打开CAD 务必按照"PolaTools.dbx","PolaCommon.dbx","PolaGrid.dbx","PolaTestDbx.arx"的顺序进行添加，都添加成功后 输入TESTCLASS命令就可以看到效果。
