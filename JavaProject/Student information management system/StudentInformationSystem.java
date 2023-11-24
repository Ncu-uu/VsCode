import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class StudentInformationSystem {
    private List<Student> list;

    Scanner scanner = new Scanner(System.in);

     public StudentInformationSystem(){
        list = new ArrayList<>();
    }


    public void run(){
         boolean isRunning = true;
         while (isRunning){
             System.out.println("请选择要进行的操作：");
             System.out.println(" 1 .学生信息录入");
             System.out.println(" 2 .学生信息浏览");
             System.out.println(" 3 .学生信息查询");
             System.out.println(" 4 .学生信息排序");
             System.out.println(" 5 .学生信息统计");
             System.out.println(" 6 .学生信息删除");
             System.out.println(" 7 .学生信息修改");
             System.out.println(" 0 . 退出系统");

             int choice = scanner.nextInt();
             scanner.nextLine();

             switch (choice){
                 case 1 : enterStudent();
                 case 2 : browseStudent();
                 case 3 : inquireStudent();
                 case 4 : sortStudent();
                 case 5 : statisticsStudent();
                 case 6 : deleteStudent();
                 case 7 : editStudent();
                 case 0 : isRunning = false;
             }
         }
    }

    private void enterStudent() {
        System.out.println("开始录入学生信息");
        System.out.println();
        System.out.println("请输入学生学号：");
        String id = scanner.nextLine();
        for (Student student : list){
            if (student.getId().equals(id)){
                System.out.println("学号已存在，请重新输入");
                System.out.println();
                return;
            }
        }
        System.out.println("请输入姓名：");
        String name = scanner.nextLine();
        System.out.println("请输入年龄：");
        String age = scanner.nextLine();
        System.out.println("请输入性别：");
        String gender = scanner.nextLine();
        System.out.println("请输入出生年月：");
        String birthDate = scanner.nextLine();
        System.out.println("请输入政治面貌：");
        String politicalStatus = scanner.nextLine();
        System.out.println("请输入籍贯：");
        String Nativeplace = scanner.nextLine();
        System.out.println("请输入家庭住址：");
        String homeAdress = scanner.nextLine();
        System.out.println("请输入电话号码：");
        String telnumber = scanner.nextLine();
        System.out.println("请输入电子邮箱：");
        String email = scanner.nextLine();
        Student student = new Student(id,name,age,gender,birthDate,politicalStatus,Nativeplace,homeAdress,telnumber,email);
        list.add(student);
        System.out.println("学生信息录入成功！");
        System.out.println();

    }

    private void browseStudent() {
         if(list.isEmpty()){
             System.out.println("系统中不存在任何学生信息。");
             return;
         }
         for(Student student : list){
             student.displayInfo();
         }
    }

    private void inquireStudent() {
         
    }

    private void sortStudent() {
    }

    private void statisticsStudent() {
    }

    private void deleteStudent() {
    }

    private void editStudent() {
    }


}
