import java.io.Serializable;
import java.util.Scanner;

public class Student implements Serializable {

    private String id; //学号

    private String name;

    private String age;

    private String gender;

    private String birthDate;

    private String nativePlace;
    private String politicalStatus;

    private String homeAdress;

    private String telNumber;

    private String eMail;

    public Student(String id, String name, String age, String gender, String birthDate, String politicalStatus, String nativePlace, String homeAdress, String telNumber, String eMail) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.birthDate = birthDate;
        this.politicalStatus = politicalStatus;
        this.nativePlace = nativePlace;
        this.homeAdress = homeAdress;
        this.telNumber = telNumber;
        this.eMail = eMail;
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

    public String getAge() {
        return age;
    }

    public void setAge(String age) {
        this.age = age;
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

    public String getPoliticalStatus() {
        return politicalStatus;
    }

    public void setPoliticalStatus(String politicalStatus) {
        this.politicalStatus = politicalStatus;
    }

    public String getNativePlace() {
        return nativePlace;
    }

    public void setNativePlace(String nativePlace) {
        this.nativePlace = nativePlace;
    }

    public String getHomeAdress() {
        return homeAdress;
    }

    public void setHomeAdress(String homeAdress) {
        this.homeAdress = homeAdress;
    }

    public String getTelNumber() {
        return telNumber;
    }

    public void setTelNumber(String telNumber) {
        this.telNumber = telNumber;
    }

    public String geteMail() {
        return eMail;
    }

    public void seteMail(String eMail) {
        this.eMail = eMail;
    }

    public void displayInfo(){
        System.out.println("学号：" + getId());
        System.out.println("姓名：" + getName());
        System.out.println("年龄：" + getAge() );
        System.out.println("性别：" + getGender());
        System.out.println("出生年月：" + getBirthDate());
        System.out.println("政治面貌：" + getPoliticalStatus());
        System.out.println("籍贯：" + getNativePlace());
        System.out.println("家庭住址：" + getHomeAdress());
        System.out.println("电话号码：" + getTelNumber());
        System.out.println("电子邮箱：" + geteMail());
    }


}
