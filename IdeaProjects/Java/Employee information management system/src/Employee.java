
///*
import java.io.*;

// 员工类
public class Employee implements Serializable {
    private String id;  // 员工ID
    private String name;  // 员工姓名
    private String gender;  // 员工性别
    private String birthDate;  // 员工出生日期
    private String education;  // 员工学历
    private String position;  // 员工职位
    private double salary;  // 员工薪资
    private String address;  // 员工地址
    private String phoneNumber;  // 员工电话号码

    // 构造函数
    public Employee(String id, String name, String gender, String birthDate, String education, String position, double salary, String address, String phoneNumber) {
        this.id = id;
        this.name = name;
        this.gender = gender;
        this.birthDate = birthDate;
        this.education = education;
        this.position = position;
        this.salary = salary;
        this.address = address;
        this.phoneNumber = phoneNumber;
    }

    // 获取员工ID
    public String getId() {
        return id;
    }

    // 设置员工ID
    public void setId(String id) {
        this.id = id;
    }

    // 获取员工姓名
    public String getName() {
        return name;
    }

    // 设置员工姓名
    public void setName(String name) {
        this.name = name;
    }

    // 获取员工性别
    public String getGender() {
        return gender;
    }

    // 设置员工性别
    public void setGender(String gender) {
        this.gender = gender;
    }

    // 获取员工出生日期
    public String getBirthDate() {
        return birthDate;
    }

    // 设置员工出生日期
    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }

    // 获取员工学历
    public String getEducation() {
        return education;
    }

    // 设置员工学历
    public void setEducation(String education) {
        this.education = education;
    }

    // 获取员工职位
    public String getPosition() {
        return position;
    }

    // 设置员工职位
    public void setPosition(String position) {
        this.position = position;
    }

    // 获取员工薪资
    public double getSalary() {
        return salary;
    }

    // 设置员工薪资
    public void setSalary(double salary) {
        this.salary = salary;
    }

    // 获取员工地址
    public String getAddress() {
        return address;
    }

    // 设置员工地址
    public void setAddress(String address) {
        this.address = address;
    }

    // 获取员工电话号码
    public String getPhoneNumber() {
        return phoneNumber;
    }

    // 设置员工电话号码
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    // 显示员工信息

    public void displayInfo() {
        System.out.println("职工号: " + id);
        System.out.println("姓名: " + name);
        System.out.println("性别: " + gender);
        System.out.println("出生年月: " + birthDate);
        System.out.println("学历: " + education);
        System.out.println("职务: " + position);
        System.out.println("工资: " + salary);
        System.out.println("住址: " + address);
        System.out.println("电话: " + phoneNumber);
    }
}

//*/

/*

import java.io.*;
// 员工类
public class Employee implements Serializable{
    private String id;  // 员工ID
    private String name;  // 员工姓名
    private String gender;  // 员工性别
    private String birthDate;  // 员工出生日期
    private String education;  // 员工教育背景
    private String position;  // 员工职位
    private double salary;  // 员工薪资
    private String address;  // 员工地址
    private String phoneNumber;  // 员工电话号码


    public Employee(String id, String name, String gender, String birthDate, String education, String position, double salary, String address, String phoneNumber) {
        this.id = id;
        this.name = name;
        this.gender = gender;
        this.birthDate = birthDate;
        this.education = education;
        this.position = position;
        this.salary = salary;
        this.address = address;
        this.phoneNumber = phoneNumber;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }

    public String getEducation() {
        return education;
    }

    public void setEducation(String education) {
        this.education = education;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    // 显示员工信息
    public void displayInfo() {
        System.out.println("职工号: " + id);
        System.out.println("姓名: " + name);
        System.out.println("性别: " + gender);
        System.out.println("出生年月: " + birthDate);
        System.out.println("学历: " + education);
        System.out.println("职务: " + position);
        System.out.println("工资: " + salary);
        System.out.println("住址: " + address);
        System.out.println("电话: " + phoneNumber);
    }
}
 */