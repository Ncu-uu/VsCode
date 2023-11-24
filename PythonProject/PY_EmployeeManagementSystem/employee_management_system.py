"""定义一个职工信息管理系统类"""
from employee import Employee


class EmployeeManagementSystem:
    def __init__(self):
        self.employees = []

    # 启动系统
    def run(self):
        print("欢迎使用员工管理系统！")
        is_running = True
        while is_running:
            print("请选择要进行的操作：")
            print("1.录入员工信息")
            print("2.显示所有员工信息")
            print("3.查询员工信息")
            print("4.删除员工信息")
            print("5.修改员工信息")
            print("0.退出系统")

            choice = int(input("请输入数字："))
            if choice == 1:
                self.add_employee()
            elif choice == 2:
                self.show_employee()
            elif choice == 3:
                self.search_employee()
            elif choice == 4:
                self.delete_employee()
            elif choice == 5:
                self.update_employee()
            elif choice == 0:
                is_running = False
            else:
                print("输入错误，请重新输入！")

    # 录入员工信息
    def add_employee(self):
        _id = input("请输入员工编号：")  # 从键盘输入员工id
        for employee in self.employees:
            if employee.id == _id:
                print("该职工号已存在！\n")
                return
        name = input("请输入员工姓名：")  # 从键盘输入员工姓名
        gender = input("请输入员工性别：")  # 从键盘输入员工性别
        birth_date = input("请输入员工出生日期：")   # 从键盘输入员工出生日期
        education = input("请输入员工学历：")  # 从键盘输入员工学历
        position = input("请输入员工职位：")  # 从键盘输入员工职位
        salary = input("请输入员工薪资：")  # 从键盘输入员工薪资
        address = input("请输入员工地址：")  # 从键盘输入员工地址
        phone_number = input("请输入员工电话：")  # 从键盘输入员工电话

        # 创建一个员工对象
        employee = Employee(_id, name, gender, birth_date, education, position, salary, address, phone_number)
        # 将员工对象添加到员工列表中
        self.employees.append(employee)
        print("添加成功！\n")

    # 显示所有员工信息
    def show_employee(self):
        print("\n所有员工信息如下：")
        for employee in self.employees:
            employee.displayInfo()
        print('员工信息显示完毕！\n')

    # 查询员工信息
    def search_employee(self):
        _id = input("\n请输入要查询的员工编号：")
        for employee in self.employees:
            if employee.id == _id:
                employee.displayInfo()
                break
        else:
            print("没有找到该员工！\n")

    # 删除员工信息
    def delete_employee(self):
        _id = input("\n请输入要删除的员工编号：")
        for employee in self.employees:
            if employee.id == _id:
                self.employees.remove(employee)
                print("删除成功！\n")
                break
            else:
                print("没有找到该员工！\n")

    # 修改员工信息
    def update_employee(self):
        _id = input("\n请输入要修改的员工编号：")
        for employee in self.employees:
            if employee.id == _id:
                choice = int(input("请选择要修改的员工信息：\n1.编号\t2.姓名\t3.性别\t4.出生日期\t5.学历\t6.职位\t7.薪资\t8.地址\t9.电话\n"))
                if choice == 1:
                    _id = input("请输入新的员工编号：")
                    employee.setId(_id)
                    print("修改成功！\n")
                elif choice == 2:
                    name = input("请输入新的员工姓名：")
                    employee.setName(name)
                    print("修改成功！\n")
                elif choice == 3:
                    gender = input("请输入新的员工性别：")
                    employee.setGender(gender)
                    print("修改成功！\n")
                elif choice == 4:
                    birth_date = input("请输入新的员工出生日期：")
                    employee.setBirthDate(birth_date)
                    print("修改成功！\n")
                elif choice == 5:
                    education = input("请输入新的员工学历：")
                    employee.setEducation(education)
                    print("修改成功！\n")
                elif choice == 6:
                    position = input("请输入新的员工职位：")
                    employee.setPosition(position)
                    print("修改成功！\n")
                elif choice == 7:
                    salary = input("请输入新的员工薪资：")
                    employee.setSalary(salary)
                    print("修改成功！\n")
                elif choice == 8:
                    address = input("请输入新的员工地址：")
                    employee.setAddress(address)
                    print("修改成功！\n")
                elif choice == 9:
                    phone_number = input("请输入新的员工电话：")
                    employee.setPhonenumber(phone_number)
                    print("修改成功！\n")
            else:
                print("没有找到该员工！\n")
