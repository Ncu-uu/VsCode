import java.io.Serializable

// 员工类
class Employee // 构造函数
(// 设置员工ID
        // 获取员工ID
        @JvmField var id // 员工ID
        : String, // 设置员工姓名
        // 获取员工姓名
        @JvmField var name // 员工姓名
        : String, // 设置员工性别
        // 获取员工性别
        @JvmField var gender // 员工性别
        : String, // 设置员工出生日期
        // 获取员工出生日期
        @JvmField var birthDate // 员工出生日期
        : String, // 设置员工学历
        // 获取员工学历
        @JvmField var education // 员工学历
        : String, // 设置员工职位
        // 获取员工职位
        @JvmField var position // 员工职位
        : String, // 设置员工薪资
        // 获取员工薪资
        @JvmField var salary // 员工薪资
        : Double, // 设置员工地址
        // 获取员工地址
        @JvmField var address // 员工地址
        : String, // 设置员工电话号码
        // 获取员工电话号码
        @JvmField var phoneNumber // 员工电话号码
        : String) : Serializable {

    // 显示员工信息
    fun displayInfo() {
        println("职工号: $id")
        println("姓名: $name")
        println("性别: $gender")
        println("出生年月: $birthDate")
        println("学历: $education")
        println("职务: $position")
        println("工资: $salary")
        println("住址: $address")
        println("电话: $phoneNumber")
    }
}
