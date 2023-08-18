#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int studentId;
    string name;
    string className;
    double mathScore;
    double englishScore;
    double computerScore;
    double averageScore;
};

// 学生数据管理类
class StudentManager {
private:
    vector<Student> students;

public:
    // 添加学生记录
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // 查询学生（按学号）
    Student* findStudentById(int studentId) {
        for (auto& student : students) {
            if (student.studentId == studentId) {
                return &student;
            }
        }
        return nullptr;
    }

    // 查询学生（按姓名）
    vector<Student*> findStudentsByName(const string& name) {
        vector<Student*> result;
        for (auto& student : students) {
            if (student.name == name) {
                result.push_back(&student);
            }
        }
        return result;
    }

    // 对学生数据排序（按平均成绩降序）
    void sortByAverageScore() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.averageScore > b.averageScore;
            });
    }

    // 对学生数据排序（按计算机成绩降序）
    void sortByComputerScore() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.computerScore > b.computerScore;
            });
    }

    // 删除学生记录
    void deleteStudent(int studentId) {
        students.erase(remove_if(students.begin(), students.end(), [studentId](const Student& student) {
            return student.studentId == studentId;
            }), students.end());
    }

    // 修改学生记录
    void updateStudent(const Student& updatedStudent) {
        for (auto& student : students) {
            if (student.studentId == updatedStudent.studentId) {
                student = updatedStudent;
                break;
            }
        }
    }

    // 班级成绩分析
    void analyzeClassScores() {
        double mathSum = 0.0;
        double englishSum = 0.0;
        double computerSum = 0.0;
        double highestScore = 0.0;
        double lowestScore = 100.0;
        int passCount = 0;

        for (auto& student : students) {
            mathSum += student.mathScore;
            englishSum += student.englishScore;
            computerSum += student.computerScore;

            if (student.computerScore > highestScore) {
                highestScore = student.computerScore;
            }

            if (student.computerScore < lowestScore) {
                lowestScore = student.computerScore;
            }

            if (student.computerScore >= 60.0) {
                passCount++;
            }
        }

        double mathAverage = mathSum / students.size();
        double englishAverage = englishSum / students.size();
        double computerAverage = computerSum / students.size();
        double passRate = (static_cast<double>(passCount) / students.size()) * 100.0;

        cout << "班级成绩分析：" << endl;
        cout << "数学平均分：" << mathAverage << endl;
        cout << "英语平均分：" << englishAverage << endl;
        cout << "计算机平均分：" << computerAverage << endl;
        cout << "最高分：" << highestScore << endl;
        cout << "最低分：" << lowestScore << endl;
        cout << "及格率：" << passRate << "%" << endl;
    }

    // 输出学生信息表
    void printStudentInfoTable() {
        cout << "学号\t姓名\t班级\t数学\t英语\t计算机\t平均成绩" << endl;
        for (auto& student : students) {
            cout << student.studentId << "\t" << student.name << "\t" << student.className << "\t"
                << student.mathScore << "\t" << student.englishScore << "\t" << student.computerScore << "\t"
                << student.averageScore << endl;
        }
    }
};

int main() {
    StudentManager studentManager;

    // 添加学生记录
    Student student1 = { 1, "Alice", "Class A", 80.0, 85.0, 90.0, 0.0 };
    student1.averageScore = (student1.mathScore + student1.englishScore + student1.computerScore) / 3;
    studentManager.addStudent(student1);

    Student student2 = { 2, "Bob", "Class A", 75.0, 70.0, 80.0, 0.0 };
    student2.averageScore = (student2.mathScore + student2.englishScore + student2.computerScore) / 3;
    studentManager.addStudent(student2);

    Student student3 = { 3, "Charlie", "Class B", 90.0, 95.0, 85.0, 0.0 };
    student3.averageScore = (student3.mathScore + student3.englishScore + student3.computerScore) / 3;
    studentManager.addStudent(student3);

    // 查询学生（按学号）
    Student* foundStudent = studentManager.findStudentById(2);
    if (foundStudent != nullptr) {
        cout << "学号为2的学生姓名：" << foundStudent->name << endl;
    }
    else {
        cout << "未找到学号为2的学生" << endl;
    }

    // 查询学生（按姓名）
    vector<Student*> foundStudents = studentManager.findStudentsByName("Alice");
    if (!foundStudents.empty()) {
        cout << "姓名为Alice的学生个数：" << foundStudents.size() << endl;
    }
    else {
        cout << "未找到姓名为Alice的学生" << endl;
    }

    // 对学生数据排序（按平均成绩降序）
    studentManager.sortByAverageScore();

    // 对学生数据排序（按计算机成绩降序）
    studentManager.sortByComputerScore();

    // 删除学生记录
    studentManager.deleteStudent(3);

    // 修改学生记录
    Student updatedStudent = { 2, "Bob Smith", "Class B", 85.0, 80.0, 90.0, 0.0 };
    updatedStudent.averageScore = (updatedStudent.mathScore + updatedStudent.englishScore + updatedStudent.computerScore) / 3;
    studentManager.updateStudent(updatedStudent);

    // 班级成绩分析
    studentManager.analyzeClassScores();

    // 输出学生信息表
    studentManager.printStudentInfoTable();

    return 0;
}