
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Ա������ϵͳ��
public class EmployeeManagementSystem {
    private List<Employee> employees =new ArrayList<>(); // Ա���б�
    Scanner scanner = new Scanner(System.in);

    // run��������������Ա������ϵͳ
    public void run() {
        // ѭ�������û��Ĳ���ѡ��
        boolean isRunning = true;
        while (isRunning) {
            System.out.println("��ѡ�������");
            System.out.println(" 1 ��¼��ְ����Ϣ");
            System.out.println(" 2 ����ʾ����ְ����Ϣ");
            System.out.println(" 3 ����ѯְ����Ϣ");
            System.out.println(" 4 ��ɾ��ְ����Ϣ");
            System.out.println(" 5 ���޸�ְ����Ϣ");
            System.out.println(" 6 ���������ݵ��ļ�");
            System.out.println(" 7 �����ļ�������");
            System.out.println(" 0 ���˳�ϵͳ");

            System.out.println("��������Ĳ�����");
            int choice = scanner.nextInt();
            scanner.nextLine(); // ������뻺�����Ļ��з�

            // �����û���ѡ��ִ�ж�Ӧ�Ĳ���
            switch (choice) {
                case 0 -> isRunning = false;
                case 1 -> addEmployee();
                case 2 -> displayAllEmployees();
                case 3 -> searchEmployee();
                case 4 -> deleteEmployee();
                case 5 -> updateEmployee();
                case 6 -> saveToFile();
                case 7 -> openFromFile();
                default -> System.out.println("��Ч��ѡ��");
            }
        }
    }

    // Ա������ϵͳ���캯��
    public EmployeeManagementSystem() {

    }

    // ���Ա��
    public void addEmployee() {
        System.out.println("��ʼ¼��ְ����Ϣ");
        System.out.println("������ְ���ţ�");
        String id = scanner.nextLine();

        for (Employee employee : employees) {
            if (employee.getId().equals(id)) {
                System.out.println("ְ�����Ѵ��ڣ�");
                return;
            }
        }

        System.out.println("������������");
        String name = scanner.nextLine();
        System.out.println("�������Ա�");
        String gender = scanner.nextLine();
        System.out.println("������������£�");
        String birthDate = scanner.nextLine();
        System.out.println("������ѧ����");
        String education = scanner.nextLine();
        System.out.println("������ְ��");
        String position = scanner.nextLine();
        System.out.println("�����빤�ʣ�");
        double salary = scanner.nextDouble();
        scanner.nextLine(); // ������뻺�����Ļ��з�
        System.out.println("������סַ��");
        String address = scanner.nextLine();
        System.out.println("������绰��");
        String phoneNumber = scanner.nextLine();

        Employee employee = new Employee(id, name, gender, birthDate, education, position, salary, address, phoneNumber);
        employees.add(employee);
        System.out.println("ְ����Ϣ¼��ɹ���");
        System.out.println();
    }

    // ��ʾ����Ա����Ϣ
    public void displayAllEmployees() {
        System.out.println("����ְ����Ϣ���£�");
        for (Employee employee : employees) {
            employee.displayInfo();
            System.out.println();
        }
        System.out.println();
    }

    // ����Ա��
    public void searchEmployee() {
        System.out.println("������Ҫ��ѯ��ְ���ţ�");
        String id = scanner.nextLine();
        for (Employee employee : employees) {
            if (employee.getId().equals(id)) {
                employee.displayInfo();
                System.out.println();
                return;
            }
        }
        System.out.println("δ�ҵ���ְ��");
        System.out.println();
    }

    // ɾ��Ա��
    public void deleteEmployee () {
            System.out.println("������Ҫɾ����ְ���ţ�");
            String id = scanner.nextLine();

            for (Employee employee : employees) {
                if (employee.getId().equals(id)) {
                    employees.remove(employee);
                    System.out.println("ְ��ɾ���ɹ�");
                    System.out.println();
                    return;
                }
            }
            System.out.println("δ�ҵ���ְ��");
            System.out.println();
        }

    // ����Ա����Ϣ
    public void updateEmployee (){
            System.out.println("������Ҫ�޸ĵ�ְ���ţ�");
            String id = scanner.nextLine();

            for (Employee employee : employees){
                if (employee.getId().equals(id)){
                    System.out.println("��ѡ��Ҫ�޸ĵ���Ϣ��");
                    System.out.println("1.ְ����");
                    System.out.println("2.����");
                    System.out.println("3.�Ա�");
                    System.out.println("4.��������");
                    System.out.println("5.ѧ��");
                    System.out.println("6.ְ��");
                    System.out.println("7.����");
                    System.out.println("8��סַ");
                    System.out.println("9.�绰");

                    int choice= scanner.nextInt();
                    scanner.nextLine(); // ������뻺�����Ļ��з�

                    switch (choice){
                        case 1 ->{
                            System.out.println("������ְ���ţ�");
                            String newId = scanner.nextLine();
                            employee.setId(newId);
                            System.out.println("��Ϣ�޸ĳɹ���");
                            System.out.println();
                            return;
                        }
                        case 2 ->{
                            System.out.println("������������");
                            String newName = scanner.nextLine();
                            employee.setName(newName);
                            System.out.println("��Ϣ�޸ĳɹ���");
                            System.out.println();
                            return;
                        }
                        case 3 ->{
                            System.out.println("�������Ա�");
                            String newGender = scanner.nextLine();
                            employee.setGender(newGender);
                            System.out.println("��Ϣ�޸ĳɹ���");
                            System.out.println();
                            return;
                        }
                        case 4->{
                            System.out.println("������������£�");
                            String newBirthDate = scanner.nextLine();
                            employee.setBirthDate(newBirthDate);
                            System.out.println("��Ϣ�޸ĳɹ���");
                            System.out.println();
                            return;
                        }
                        case 5->{
                            System.out.println("������ѧ����");
                            String newEducation = scanner.nextLine();
                            employee.setEducation(newEducation);
                            System.out.println("��Ϣ�޸ĳɹ���");
                            System.out.println();
                            return;
                        }
                        case 6 ->{
                            System.out.println("������ְ��");
                            String newPosition = scanner.nextLine();
                            employee.setPosition(newPosition);
                            System.out.println("��Ϣ�޸ĳɹ���");
                            System.out.println();
                            return;
                        }
                        case 7->{
                            System.out.println("�����빤�ʣ�");
                            double newSalary = scanner.nextDouble();
                            scanner.nextLine(); // ������뻺�����Ļ��з�
                            employee.setSalary(newSalary);
                            System.out.println("��Ϣ�޸ĳɹ���");
                            System.out.println();
                            return;
                        }

                        case 8->{
                            System.out.println("������סַ��");
                            String newAddress = scanner.nextLine();
                            employee.setAddress(newAddress);
                            System.out.println("��Ϣ�޸ĳɹ���");
                            System.out.println();
                            return;
                        }

                        case 9->{
                            System.out.println("������绰��");
                            String newPhoneNumber = scanner.nextLine();
                            employee.setPhoneNumber(newPhoneNumber);
                            System.out.println("��Ϣ�޸ĳɹ���");
                            System.out.println();
                            return;
                        }
                    }
                }
            }
            System.out.println("δ�ҵ���ְ��");
    }

    // ��Ա����Ϣ���浽�ļ�
    public void saveToFile (){
            try {
                System.out.println("�����뱣����ļ�����");
                String  fileName = scanner.nextLine();
                FileOutputStream fileOutputStream = new FileOutputStream(fileName);
                ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
                objectOutputStream.writeObject(employees);
                objectOutputStream.close();
                fileOutputStream.close();
                System.out.println("���ݱ���ɹ���");
                System.out.println();
            } catch (IOException e) {
                System.out.println("����ʧ�ܣ�" + e.getMessage());
                System.out.println();
            }
        }

    // ���ļ���ȡԱ����Ϣ
    public void openFromFile (){
            try {
                System.out.println("������򿪵��ļ�����");
                String fileName = scanner.nextLine();
                FileInputStream fileInputStream = new FileInputStream(fileName);
                ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
                employees = (List<Employee>) objectInputStream.readObject();
                objectInputStream.close();
                fileInputStream.close();
                System.out.println("�ļ��򿪳ɹ���");
                System.out.println();
            } catch (IOException | ClassNotFoundException e) {
                System.out.println("��ʧ�ܣ�" + e.getMessage());
                System.out.println();
            }
        }
}