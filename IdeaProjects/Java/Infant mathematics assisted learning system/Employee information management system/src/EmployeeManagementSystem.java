
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// 员工管理系统类
public class EmployeeManagementSystem {
    private List<Employee> employees =new ArrayList<>(); // 员工列表
    Scanner scanner = new Scanner(System.in);

    // run方法，用于运行员工管理系统
    public void run() {
        // 循环处理用户的操作选择
        boolean isRunning = true;
        while (isRunning) {
            System.out.println("请选择操作：");
            System.out.println(" 1 ：录入职工信息");
            System.out.println(" 2 ：显示所有职工信息");
            System.out.println(" 3 ：查询职工信息");
            System.out.println(" 4 ：删除职工信息");
            System.out.println(" 5 ：修改职工信息");
            System.out.println(" 6 ：保存数据到文件");
            System.out.println(" 7 ：从文件打开数据");
            System.out.println(" 0 ：退出系统");

            System.out.println("请输入你的操作：");
            int choice = scanner.nextInt();
            scanner.nextLine(); // 清除输入缓冲区的换行符

            // 根据用户的选择，执行对应的操作
            switch (choice) {
                case 0 -> isRunning = false;
                case 1 -> addEmployee();
                case 2 -> displayAllEmployees();
                case 3 -> searchEmployee();
                case 4 -> deleteEmployee();
                case 5 -> updateEmployee();
                case 6 -> saveToFile();
                case 7 -> openFromFile();
                default -> System.out.println("无效的选择！");
            }
        }
    }

    // 员工管理系统构造函数
    public EmployeeManagementSystem() {

    }

    // 添加员工
    public void addEmployee() {
        System.out.println("开始录入职工信息");
        System.out.println("请输入职工号：");
        String id = scanner.nextLine();

        for (Employee employee : employees) {
            if (employee.getId().equals(id)) {
                System.out.println("职工号已存在！");
                return;
            }
        }

        System.out.println("请输入姓名：");
        String name = scanner.nextLine();
        System.out.println("请输入性别：");
        String gender = scanner.nextLine();
        System.out.println("请输入出生年月：");
        String birthDate = scanner.nextLine();
        System.out.println("请输入学历：");
        String education = scanner.nextLine();
        System.out.println("请输入职务：");
        String position = scanner.nextLine();
        System.out.println("请输入工资：");
        double salary = scanner.nextDouble();
        scanner.nextLine(); // 清除输入缓冲区的换行符
        System.out.println("请输入住址：");
        String address = scanner.nextLine();
        System.out.println("请输入电话：");
        String phoneNumber = scanner.nextLine();

        Employee employee = new Employee(id, name, gender, birthDate, education, position, salary, address, phoneNumber);
        employees.add(employee);
        System.out.println("职工信息录入成功！");
        System.out.println();
    }

    // 显示所有员工信息
    public void displayAllEmployees() {
        System.out.println("所有职工信息如下：");
        for (Employee employee : employees) {
            employee.displayInfo();
            System.out.println();
        }
        System.out.println();
    }

    // 搜索员工
    public void searchEmployee() {
        System.out.println("请输入要查询的职工号：");
        String id = scanner.nextLine();

        for (Employee employee : employees) {
            if (employee.getId().equals(id)) {
                employee.displayInfo();
                System.out.println();
                return;
            }
        }
        System.out.println("未找到该职工");
        System.out.println();
    }

    // 删除员工
    public void deleteEmployee () {
            System.out.println("请输入要删除的职工号：");
            String id = scanner.nextLine();

            for (Employee employee : employees) {
                if (employee.getId().equals(id)) {
                    employees.remove(employee);
                    System.out.println("职工删除成功");
                    System.out.println();
                    return;
                }
            }
            System.out.println("未找到该职工");
            System.out.println();
        }

    // 更新员工信息
    public void updateEmployee (){
            System.out.println("请输入要修改的职工号：");
            String id = scanner.nextLine();

            for (Employee employee : employees){
                if (employee.getId().equals(id)){
                    System.out.println("请选择要修改的信息：");
                    System.out.println("1.职工号");
                    System.out.println("2.姓名");
                    System.out.println("3.性别");
                    System.out.println("4.出生年月");
                    System.out.println("5.学历");
                    System.out.println("6.职务");
                    System.out.println("7.工资");
                    System.out.println("8，住址");
                    System.out.println("9.电话");

                    int choice= scanner.nextInt();
                    scanner.nextLine(); // 清除输入缓冲区的换行符

                    switch (choice){
                        case 1 ->{
                            System.out.println("请输入职工号：");
                            String newId = scanner.nextLine();
                            employee.setId(newId);
                            System.out.println("信息修改成功！");
                            System.out.println();
                            return;
                        }
                        case 2 ->{
                            System.out.println("请输入姓名：");
                            String newName = scanner.nextLine();
                            employee.setName(newName);
                            System.out.println("信息修改成功！");
                            System.out.println();
                            return;
                        }
                        case 3 ->{
                            System.out.println("请输入性别：");
                            String newGender = scanner.nextLine();
                            employee.setGender(newGender);
                            System.out.println("信息修改成功！");
                            System.out.println();
                            return;
                        }
                        case 4->{
                            System.out.println("请输入出生年月：");
                            String newBirthDate = scanner.nextLine();
                            employee.setBirthDate(newBirthDate);
                            System.out.println("信息修改成功！");
                            System.out.println();
                            return;
                        }
                        case 5->{
                            System.out.println("请输入学历：");
                            String newEducation = scanner.nextLine();
                            employee.setEducation(newEducation);
                            System.out.println("信息修改成功！");
                            System.out.println();
                            return;
                        }
                        case 6 ->{
                            System.out.println("请输入职务：");
                            String newPosition = scanner.nextLine();
                            employee.setPosition(newPosition);
                            System.out.println("信息修改成功！");
                            System.out.println();
                            return;
                        }
                        case 7->{
                            System.out.println("请输入工资：");
                            double newSalary = scanner.nextDouble();
                            scanner.nextLine(); // 清除输入缓冲区的换行符
                            employee.setSalary(newSalary);
                            System.out.println("信息修改成功！");
                            System.out.println();
                            return;
                        }

                        case 8->{
                            System.out.println("请输入住址：");
                            String newAddress = scanner.nextLine();
                            employee.setAddress(newAddress);
                            System.out.println("信息修改成功！");
                            System.out.println();
                            return;
                        }

                        case 9->{
                            System.out.println("请输入电话：");
                            String newPhoneNumber = scanner.nextLine();
                            employee.setPhoneNumber(newPhoneNumber);
                            System.out.println("信息修改成功！");
                            System.out.println();
                            return;
                        }
                    }
                }
            }
            System.out.println("未找到该职工");
    }

    // 将员工信息保存到文件
    public void saveToFile (){
            try {
                System.out.println("请输入保存的文件名：");
                String  fileName = scanner.nextLine();
                FileOutputStream fileOutputStream = new FileOutputStream(fileName);
                ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
                objectOutputStream.writeObject(employees);
                objectOutputStream.close();
                fileOutputStream.close();
                System.out.println("数据保存成功！");
                System.out.println();
            } catch (IOException e) {
                System.out.println("保存失败：" + e.getMessage());
                System.out.println();
            }
        }

    // 从文件读取员工信息
    public void openFromFile (){
            try {
                System.out.println("请输入打开的文件名：");
                String fileName = scanner.nextLine();
                FileInputStream fileInputStream = new FileInputStream(fileName);
                ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
                employees = (List<Employee>) objectInputStream.readObject();
                objectInputStream.close();
                fileInputStream.close();
                System.out.println("文件打开成功！");
                System.out.println();
            } catch (IOException | ClassNotFoundException e) {
                System.out.println("打开失败：" + e.getMessage());
                System.out.println();
            }
        }
}