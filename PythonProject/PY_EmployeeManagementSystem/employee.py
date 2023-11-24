"""定义一个职工类"""
class Employee:
    def __init__(self, id, name, gender, birthDate, education, position, salary, address, phonenumber):
        self.id = id
        self.name = name
        self.gender = gender
        self.birthDate = birthDate
        self.education = education
        self.position = position
        self.salary = salary
        self.address = address
        self.phonenumber = phonenumber

    # 变量的get和set方法
    def getId(self):
        return self.id
    def setId(self, id):
        self.id = id

    def getName(self):
        return self.name
    def setName(self, name):
        self.name = name

    def getGender(self):
        return self.gender
    def setGender(self, gender):
        self.gender = gender

    def getBirthDate(self):
        return self.birthDate
    def setBirthDate(self, birthDate):
        self.birthDate = birthDate

    def getEducation(self):
        return self.education
    def setEducation(self, education):
        self.education = education

    def getPosition(self):
        return self.position
    def setPosition(self, position):
        self.position = position

    def getSalary(self):
        return self.salary
    def setSalary(self, salary):
        self.salary = salary

    def getAddress(self):
        return self.address
    def setAddress(self, address):
        self.address = address

    def getPhonenumber(self):
        return self.phonenumber
    def setPhonenumber(self, phonenumber):
        self.phonenumber = phonenumber

    # 显示员工所有信息
    def displayInfo(self):
        print("员工编号：", self.getId())
        print("员工姓名：", self.getName())
        print("员工性别：", self.getGender())
        print("员工出生日期：", self.getBirthDate())
        print("员工学历：", self.getEducation())
        print("员工职位：", self.getPosition())
        print("员工薪水：", self.getSalary())
        print("员工地址：", self.getAddress())
        print("员工电话：", self.getPhonenumber(),'\n')



