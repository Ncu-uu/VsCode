
///*
import java.io.*;

// Ա����
public class Employee implements Serializable {
    private String id;  // Ա��ID
    private String name;  // Ա������
    private String gender;  // Ա���Ա�
    private String birthDate;  // Ա����������
    private String education;  // Ա��ѧ��
    private String position;  // Ա��ְλ
    private double salary;  // Ա��н��
    private String address;  // Ա����ַ
    private String phoneNumber;  // Ա���绰����

    // ���캯��
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

    // ��ȡԱ��ID
    public String getId() {
        return id;
    }

    // ����Ա��ID
    public void setId(String id) {
        this.id = id;
    }

    // ��ȡԱ������
    public String getName() {
        return name;
    }

    // ����Ա������
    public void setName(String name) {
        this.name = name;
    }

    // ��ȡԱ���Ա�
    public String getGender() {
        return gender;
    }

    // ����Ա���Ա�
    public void setGender(String gender) {
        this.gender = gender;
    }

    // ��ȡԱ����������
    public String getBirthDate() {
        return birthDate;
    }

    // ����Ա����������
    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }

    // ��ȡԱ��ѧ��
    public String getEducation() {
        return education;
    }

    // ����Ա��ѧ��
    public void setEducation(String education) {
        this.education = education;
    }

    // ��ȡԱ��ְλ
    public String getPosition() {
        return position;
    }

    // ����Ա��ְλ
    public void setPosition(String position) {
        this.position = position;
    }

    // ��ȡԱ��н��
    public double getSalary() {
        return salary;
    }

    // ����Ա��н��
    public void setSalary(double salary) {
        this.salary = salary;
    }

    // ��ȡԱ����ַ
    public String getAddress() {
        return address;
    }

    // ����Ա����ַ
    public void setAddress(String address) {
        this.address = address;
    }

    // ��ȡԱ���绰����
    public String getPhoneNumber() {
        return phoneNumber;
    }

    // ����Ա���绰����
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    // ��ʾԱ����Ϣ
    public void displayInfo() {
        System.out.println("ְ����: " + id);
        System.out.println("����: " + name);
        System.out.println("�Ա�: " + gender);
        System.out.println("��������: " + birthDate);
        System.out.println("ѧ��: " + education);
        System.out.println("ְ��: " + position);
        System.out.println("����: " + salary);
        System.out.println("סַ: " + address);
        System.out.println("�绰: " + phoneNumber);
    }
}

//*/

/*

import java.io.*;
// Ա����
public class Employee implements Serializable{
    private String id;  // Ա��ID
    private String name;  // Ա������
    private String gender;  // Ա���Ա�
    private String birthDate;  // Ա����������
    private String education;  // Ա����������
    private String position;  // Ա��ְλ
    private double salary;  // Ա��н��
    private String address;  // Ա����ַ
    private String phoneNumber;  // Ա���绰����


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

    // ��ʾԱ����Ϣ
    public void displayInfo() {
        System.out.println("ְ����: " + id);
        System.out.println("����: " + name);
        System.out.println("�Ա�: " + gender);
        System.out.println("��������: " + birthDate);
        System.out.println("ѧ��: " + education);
        System.out.println("ְ��: " + position);
        System.out.println("����: " + salary);
        System.out.println("סַ: " + address);
        System.out.println("�绰: " + phoneNumber);
    }
}
 */