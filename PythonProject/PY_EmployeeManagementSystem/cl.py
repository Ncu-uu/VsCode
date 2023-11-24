import csv

# 职工类
class Staff:
    def __init__(self, id, name, gender, birth, education, job, salary, address, phone):
        self.id = id
        self.name = name
        self.gender = gender
        self.birth = birth
        self.education = education
        self.job = job
        self.salary = salary
        self.address = address
        self.phone = phone

# 职工管理类
class StaffManager:
    def __init__(self):
        self.staffs = []

    # 录入职工信息
    def input_staff(self):
        id = input('Enter staff id: ')
        name = input('Enter name: ')
        gender = input('Enter gender: ')
        birth = input('Enter birth: ')
        education = input('Enter education: ')
        job = input('Enter job: ')
        salary = input('Enter salary: ')
        address = input('Enter address: ')
        phone = input('Enter phone: ')

        staff = Staff(id, name, gender, birth, education, job, salary, address, phone)
        self.staffs.append(staff)
        print('Staff added successfully!')

    # 输出所有职工信息
    def output_staffs(self):
        for staff in self.staffs:
            print(staff.id, staff.name, staff.gender, staff.birth, staff.education,
                  staff.job, staff.salary, staff.address, staff.phone)

    # 根据职工号查询职工
    def search_staff(self, id):
        for staff in self.staffs:
            if staff.id == id:
                return staff
        return None

    # 删除职工
    def delete_staff(self, id):
        staff = self.search_staff(id)
        if staff:
            self.staffs.remove(staff)
            print('Staff deleted successfully!')
        else:
            print('Staff not found!')

    # 修改职工信息
    def update_staff(self, id):
        staff = self.search_staff(id)
        if staff:
            # 修改逻辑
            print('Staff updated successfully!')
        else:
            print('Staff not found!')

    # 数据保存到文件
    def save_data(self):
        with open('staffs.csv', 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(['id', 'name', 'gender', 'birth', 'education', 'job', 'salary', 'address', 'phone'])
            for staff in self.staffs:
                writer.writerow([staff.id, staff.name, staff.gender, staff.birth, staff.education,
                                 staff.job, staff.salary, staff.address, staff.phone])
        print('Data saved successfully!')

    # 从文件加载数据
    def load_data(self):
        self.staffs.clear()
        with open('staffs.csv', 'r') as f:
            reader = csv.reader(f)
            next(reader)
            for row in reader:
                id, name, gender, birth, education, job, salary, address, phone = row
                staff = Staff(id, name, gender, birth, education, job, salary, address, phone)
                self.staffs.append(staff)
        print('Data loaded successfully!')

manager = StaffManager()

# 主循环
while True:
    print('''
    1. Input Staff
    2. Output Staffs
    3. Search Staff
    4. Delete Staff
    5. Update Staff
    6. Save Data
    7. Load Data
    0. Exit
    ''')

    choice = int(input('Enter your choice: '))
    if choice == 1:
        manager.input_staff()
    elif choice == 2:
        manager.output_staffs()
    elif choice == 3:
        id = input('Enter staff id: ')
        staff = manager.search_staff(id)
        if staff:
            print(staff.id, staff.name, staff.gender, staff.birth, staff.education,
                  staff.job, staff.salary, staff.address, staff.phone)
        else:
            print('Staff not found!')
    elif choice == 4:
        id = input('Enter staff id: ')
        manager.delete_staff(id)
    elif choice == 5:
        id = input('Enter staff id: ')
        manager.update_staff(id)
    elif choice == 6:
        manager.save_data()
    elif choice == 7:
        manager.load_data()
    elif choice == 0:
        break
    else:
        print('Invalid option!')

print('System exited.')