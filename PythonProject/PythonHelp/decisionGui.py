import tkinter as tk

# 定义投资方案数据
investments = {
    'A': {'investment': 65000, 'cash_flow': 13000},
    'B': {'investment': 20000, 'cash_flow': 2710},
    'C': {'investment': 40000, 'cash_flow': 6870},
    'D': {'investment': 10000, 'cash_flow': 1770}
}

# 计算净现值
def calculate_npv(investment, cash_flow, rate):
    npv = -investment
    for year in range(1, 11):
        npv += cash_flow / (1 + rate) ** year
    return npv

# 计算内部收益率
def calculate_irr(investment, cash_flow):
    rate = 0.0
    while True:
        npv = calculate_npv(investment, cash_flow, rate)
        if npv > 0:
            break
        rate += 0.001
    return rate

# 选择最优方案
def select_optimal_investment(investments):
    optimal_investment = None
    max_npv = float('-inf')
    for investment, data in investments.items():
        npv = calculate_npv(data['investment'], data['cash_flow'], 0.1)
        if npv > max_npv:
            max_npv = npv
            optimal_investment = investment
    return optimal_investment

# 获取用户输入的参数
def get_input():
    investment = float(entry_investment.get())
    cash_flow = float(entry_cash_flow.get())
    return investment, cash_flow

# 显示计算结果
def show_result(optimal_investment):
    result_window = tk.Toplevel(root)
    result_window.title("计算结果")
    result_window.geometry("200x100+{}+{}".format(root.winfo_x() + (root.winfo_width() - 200) // 2, root.winfo_y() + (root.winfo_height() - 100) // 2 + 120))
    label_result = tk.Label(result_window, text="最优方案是：方案 " + optimal_investment)
    label_result.pack()

# 处理按钮点击事件
def handle_button_click():
    investment, cash_flow = get_input()
    investments['E'] = {'investment': investment, 'cash_flow': cash_flow}
    optimal_investment = select_optimal_investment(investments)
    show_result(optimal_investment)

# 创建主窗口
root = tk.Tk()
root.title("投资决策")

# 设置窗口大小
window_width = 300
window_height = 200
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
x = (screen_width - window_width) // 2
y = (screen_height - window_height) // 2
root.geometry(f"{window_width}x{window_height}+{x}+{y}")

# 添加标签和文本框
# 显示提示信息
label_investment = tk.Label(root, text="设新投资方案为方案E，请输入方案E的参数")
label_investment.pack()
entry_investment = tk.Entry(root)
entry_investment.pack()

label_cash_flow = tk.Label(root, text="年净现金流量（万元）：")
label_cash_flow.pack()
entry_cash_flow = tk.Entry(root)
entry_cash_flow.pack()

# 添加按钮
button_calculate = tk.Button(root, text="计算最优方案", command=handle_button_click)
button_calculate.pack()

# 运行主程序
root.mainloop()
