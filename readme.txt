需求分析：
	1、可以自定义桌面背景
	2、可以自定义系统任务栏：具体应实现
	3、特定风格的皮肤拥有自己的工具窗口
	4、支持多种语言
	5、支持增加窗口部件

面向使用者：
	1、普通用户
	2、具有一定编程能力的用户

初始软件架构：
	规则系统、面向对象系统

设计：
	1、软件提供平台，用于显示脚本解释的内容
	2、定义一种配置文件（规则）用于组件风格自定义
	3、让所有组件都继承自同一基类，每一个组件都是一个容器，可以容纳其他组件

详细设计：
	一、组件设计：系统组件、用户自定义组件
		系统组件：时钟、网速检测、内存/CPU使用情况、欢迎、任务栏组件、桌面组件、文件搜集组件(就是把桌面上的图标整理到一个组件中)
		用户自定义组件：支持用户自己设计所需的组件
		
		详细需求：(1)每一个组件都应该具有两组位置：绝对位置（也就是相对于屏幕左上角）和相对位置（相对于
与其最近的父组件），位置关系应该具有如下规则：1、如果该组件是最顶层组件，那么相对位置无效；2、如果一个组件是子组件，那么相对位置优先级高于绝对位置优先级。
			(2)每个组件都应该能在其本身展示图片或者添加按钮、文本框或者显示文字
			(3)每个组件都应该可以设置透明度，设置字体，设置可穿透，设置边缘吸附，设置可拖动，ps:边缘吸附只对于顶层组件有效，透明度、字体、可穿透等设置可继承。
			(4)子组件应该可旋转。

	二、配置文件设计
		1、给出一些具体的属性(以键-值对的形式)，管理程序通过读取配置文件的内容显示用户更改。属性的设置需要基于组件具有的属性
		2、配置文件中可以存在注释，注释内容以“;(英文)”开始，注释区域为一行