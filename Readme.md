##**Technical Document**
##**TW Taxi Maintenance Service** 

##**出租车保养服务程序技术文档**

******
**Author**  梁植源 ( Wyman )
**Version** V1.0
**Date**    2017.10.15


###**目录**
[TOC]

###**用途**
- ThoughtWorks homework
	
###**命名规则**
- 函数名用小写首字母的驼峰命名法，如aaBbCc();
- 变量名用大写首字母的驼峰命名法，如AaBbCc;
- 宏定义用由下划线隔开的大写单词拼接A.

###**程序编写环境**
- 使用 C ，通过 VS2015 IDE 编写  

###**程序测试方法**
- 使用VS运行（`Ctrl + F5`），输入以下测试范例，回车两次获得测试结果

- Test1
```
SubmitDate: 2030/09/01
CAR0001|2025/04/05|Porsche|10000|F
CAR0002|2029/10/14|Porsche|9000|F
CAR0003|2026/08/17|Porsche|13000|F
CAR0004|2027/11/01|BYD|23000|T
CAR0005|2027/01/11|BYD|19500|F
CAR0006|2029/07/01|Audi|10001|T
CAR0007|2028/04/19|Ford|9800|F
CAR0008|2027/07/10|Ford|15000|T
CAR0009|2024/10/22|Ford|90300|F
```
- Test2
```
SubmitDate: 2050/05/01
CAR0001|2044/05/01|Volkswagen|65535|F
CAR0002|2044/05/03|BMW|100001|F
CAR0003|2047/05/02|Mercedes-Benz|37789|T
CAR0004|2047/05/03|Honda|59908|T
CAR0005|2049/12/10|Peugeot|49999|F
CAR0006|2046/11/15|Jeep|2000|F
CAR0007|2046/11/16|Jeep|5000|F
```

###**测试结果对比**
![测试结果1](http://img.blog.csdn.net/20171015191859856?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzI2NjY1NTU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

![测试结果2](http://img.blog.csdn.net/20171015191924483?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzI2NjY1NTU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

-------------------
###修改历史

2017.10.15------ V1.0  ------      Wyman  
####**添加文件**

#####h文件
 - DataInput.h
 - DataOutput.h
 - DataAnalyse.h
 - Sort.h

#####c文件
 - DataInput.c
 - DataOutput.c
 - DataAnalyse.c
 - Sort.c
 - main.c