# 学生信息管理系统设计介绍
## 基本功能
首先定义了一个Student结构体来表示学生的数据。然后定义了一个StudentManager类来管理学生数据，包括添加学生记录、查询学生、排序学生数据、删除学生记录、修改学生记录、班级成绩分析和输出学生信息表等功能。
### 代码内容
在main函数中，首先创建一个StudentManager对象，并使用addStudent方法添加几个学生记录。然后使用findStudentById方法和findStudentsByName方法分别按学号和姓名查询学生记录。接着使用sortByAverageScore方法和sortByComputerScore方法对学生数据进行排序。然后使用deleteStudent方法删除一个学生记录，并使用updateStudent方法修改一个学生记录。最后使用analyzeClassScores方法进行班级成绩分析，并使用printStudentInfoTable方法输出学生信息表。
C6031  在VS中打开属性栏>属性配置>C/C++>所有选项，将SDL检查改为否，保存即可，不影响代码的运行