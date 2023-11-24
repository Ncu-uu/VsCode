starting_salary = 30000
max_years = 35
years_worked = int(input("请输入教师的工作年限:"))
if years_worked > max_years:
    years_worked = max_years
    print("工作年限超过35年,按35年计算\n")
print("该教师工资如下(保留两位小数):")
for year in range(1, years_worked + 1):
    if year <= 10:
        salary = starting_salary * (1.02 ** (year - 1))
    elif year <= 20:
        salary = starting_salary * (1.02 ** 9 ) * (1.025 ** (year - 10))
    elif year <= 30:
        salary = starting_salary * (1.02 ** 9 ) * (1.025 ** 10) * (1.03 ** (year - 20))
    else:
        salary = starting_salary * (1.02 ** 9 ) * (1.025 ** 10) * (1.03 ** 10) * (1.04 ** (year - 30))
    print("第{}年的工资为: {:.2f}".format(year, salary))
