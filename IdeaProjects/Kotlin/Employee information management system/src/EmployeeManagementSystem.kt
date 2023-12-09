import java.io.*
import java.util.*

class EmployeeManagementSystem  // 员工管理系统构造函数
{
    private var employees: MutableList<Employee> = ArrayList() // 员工列表
    var scanner = Scanner(System.`in`)

    // run方法，用于运行员工管理系统
    fun run() {
        // 循环处理用户的操作选择
        var isRunning = true
        while (isRunning) {
            println("请选择操作：")
            println(" 1 ：录入职工信息")
            println(" 2 ：显示所有职工信息")
            println(" 3 ：查询职工信息")
            println(" 4 ：删除职工信息")
            println(" 5 ：修改职工信息")
            println(" 6 ：保存数据到文件")
            println(" 7 ：从文件打开数据")
            println(" 0 ：退出系统")
            println("请输入你的操作：")
            val choice = scanner.nextInt()
            scanner.nextLine() // 清除输入缓冲区的换行符
            when (choice) {
                0 -> isRunning = false
                1 -> addEmployee()
                2 -> displayAllEmployees()
                3 -> searchEmployee()
                4 -> deleteEmployee()
                5 -> updateEmployee()
                6 -> saveToFile()
                7 -> openFromFile()
                else -> println("无效的选择！")
            }
        }
    }

    // 添加员工
    fun addEmployee() {
        println("开始录入职工信息")
        println("请输入职工号：")
        val id = scanner.nextLine()
        for (employee in employees) {
            if (employee.id == id) {
                println("职工号已存在！")
                return
            }
        }
        println("请输入姓名：")
        val name = scanner.nextLine()
        println("请输入性别：")
        val gender = scanner.nextLine()
        println("请输入出生年月：")
        val birthDate = scanner.nextLine()
        println("请输入学历：")
        val education = scanner.nextLine()
        println("请输入职务：")
        val position = scanner.nextLine()
        println("请输入工资：")
        val salary = scanner.nextDouble()
        scanner.nextLine() // 清除输入缓冲区的换行符
        println("请输入住址：")
        val address = scanner.nextLine()
        println("请输入电话：")
        val phoneNumber = scanner.nextLine()
        val employee = Employee(id, name, gender, birthDate, education, position, salary, address, phoneNumber)
        employees.add(employee)
        println("职工信息录入成功！")
        println()
    }

    // 显示所有员工信息
    fun displayAllEmployees() {
        println("所有职工信息如下：")
        for (employee in employees) {
            employee.displayInfo()
            println()
        }
        println()
    }

    // 搜索员工
    fun searchEmployee() {
        println("请输入要查询的职工号：")
        val id = scanner.nextLine()
        for (employee in employees) {
            if (employee.id == id) {
                employee.displayInfo()
                println()
                return
            }
        }
        println("未找到该职工")
        println()
    }

    // 删除员工
    fun deleteEmployee() {
        println("请输入要删除的职工号：")
        val id = scanner.nextLine()
        for (employee in employees) {
            if (employee.id == id) {
                employees.remove(employee)
                println("职工删除成功")
                println()
                return
            }
        }
        println("未找到该职工")
        println()
    }

    // 更新员工信息
    fun updateEmployee() {
        println("请输入要修改的职工号：")
        val id = scanner.nextLine()
        for (employee in employees) {
            if (employee.id == id) {
                println("请选择要修改的信息：")
                println("1.职工号")
                println("2.姓名")
                println("3.性别")
                println("4.出生年月")
                println("5.学历")
                println("6.职务")
                println("7.工资")
                println("8，住址")
                println("9.电话")
                val choice = scanner.nextInt()
                scanner.nextLine() // 清除输入缓冲区的换行符
                when (choice) {
                    1 -> {
                        println("请输入职工号：")
                        val newId = scanner.nextLine()
                        employee.id = newId
                        println("信息修改成功！")
                        println()
                        return
                    }

                    2 -> {
                        println("请输入姓名：")
                        val newName = scanner.nextLine()
                        employee.name = newName
                        println("信息修改成功！")
                        println()
                        return
                    }

                    3 -> {
                        println("请输入性别：")
                        val newGender = scanner.nextLine()
                        employee.gender = newGender
                        println("信息修改成功！")
                        println()
                        return
                    }

                    4 -> {
                        println("请输入出生年月：")
                        val newBirthDate = scanner.nextLine()
                        employee.birthDate = newBirthDate
                        println("信息修改成功！")
                        println()
                        return
                    }

                    5 -> {
                        println("请输入学历：")
                        val newEducation = scanner.nextLine()
                        employee.education = newEducation
                        println("信息修改成功！")
                        println()
                        return
                    }

                    6 -> {
                        println("请输入职务：")
                        val newPosition = scanner.nextLine()
                        employee.position = newPosition
                        println("信息修改成功！")
                        println()
                        return
                    }

                    7 -> {
                        println("请输入工资：")
                        val newSalary = scanner.nextDouble()
                        scanner.nextLine() // 清除输入缓冲区的换行符
                        employee.salary = newSalary
                        println("信息修改成功！")
                        println()
                        return
                    }

                    8 -> {
                        println("请输入住址：")
                        val newAddress = scanner.nextLine()
                        employee.address = newAddress
                        println("信息修改成功！")
                        println()
                        return
                    }

                    9 -> {
                        println("请输入电话：")
                        val newPhoneNumber = scanner.nextLine()
                        employee.phoneNumber = newPhoneNumber
                        println("信息修改成功！")
                        println()
                        return
                    }
                }
            }
        }
        println("未找到该职工")
    }

    // 将员工信息保存到文件
    fun saveToFile() {
        try {
            println("请输入保存的文件名：")
            val fileName = scanner.nextLine()
            val fileOutputStream = FileOutputStream(fileName)
            val objectOutputStream = ObjectOutputStream(fileOutputStream)
            objectOutputStream.writeObject(employees)
            objectOutputStream.close()
            fileOutputStream.close()
            println("数据保存成功！")
            println()
        } catch (e: IOException) {
            println("保存失败：" + e.message)
            println()
        }
    }

    // 从文件读取员工信息
    fun openFromFile() {
        try {
            println("请输入打开的文件名：")
            val fileName = scanner.nextLine()
            val fileInputStream = FileInputStream(fileName)
            val objectInputStream = ObjectInputStream(fileInputStream)
            employees = objectInputStream.readObject() as MutableList<Employee>
            objectInputStream.close()
            fileInputStream.close()
            println("文件打开成功！")
            println()
        } catch (e: IOException) {
            println("打开失败：" + e.message)
            println()
        } catch (e: ClassNotFoundException) {
            println("打开失败：" + e.message)
            println()
        }
    }
}