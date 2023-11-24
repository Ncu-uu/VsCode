import numpy as np
import matplotlib. pyplot as plt
import pandas as pd
import warnings

# warnings. filterwarnings（＇ignore＇）
plt.rcParams['font.sans-serif'] = ['SimHei']  #用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  #来正常显示负号
class B_1_cls:
    def __init__(self):
        self.theta_rad = None
        self.theta_deg = None
        self.r = None
        self.all_color = ['b','c','g','k','m','y','purple']
        self.color = None
        self.counter = 0  #计时器，画图用
    def __mid_k_func(self,theta_i,theta_j,theta_k_true):
        """
        此时k在中间，偏差为＋-1
        """
        theta_rad = None
        theta_deg = None
        r = None
        color = None
        if theta_j - theta_k_true < 180 and theta_k_true - theta_i < 180:
            alpha_i = (180- theta_k_true + theta_i)/ 2
            alpha_i = np.arange(alpha_i-1, alpha_i + 1, 0.1)
            alpha_j = (180 + theta_k_true - theta_j)/ 2
            alpha_j = np.arange(alpha_j-1, alpha_j + 1, 0.1)

            fenzi = np.sin(np.radians(alpha_j + theta_j)) * np.sin(np.radians(alpha_i)) + np.sin(np.radians(-alpha_i + theta_i)) * np.sin(np.radians(alpha_j))
            fenmu = np.cos(np.radians(alpha_j + theta_j)) * np.sin(np.radians(alpha_i)) + np.cos(np.radians(-alpha_i + theta_i)) * np.sin(np.radians(alpha_j))

            theta_rad = np.array(pd.Series(np.arctan(fenzi / fenmu)).map(lambda x: x if x > 0 else x + np.pi))

            # print("=========================================")
            # print(theta_deg)
            # print(r)
            # print("=========================================")
            # print(theta_deg.shape)
            # print(r.shape)
            # print("theta 为：{}".format(theta_deg))
            # print("r 为：{}".format(r))

        elif theta_j - theta_k_true > 180 and theta_k_true - theta_i < 180:
            alpha_i = (180 - theta_k_true + theta_i) / 2
            alpha_i = np.arange(alpha_i - 1, alpha_i + 1, 0.1)
            alpha_j = (-180 - theta_k_true + theta_j) / 2
            alpha_j = np.arange(alpha_j - 1, alpha_j + 1, 0.1)

            fenzi = np.sin(np.radians(-alpha_j + theta_j)) * np.sin(np.radians(alpha_i)) - np.sin(np.radians(-alpha_i + theta_i)) * np.sin(np.radians(alpha_j))
            fenmu = np.cos(np.radians(-alpha_j + theta_j)) * np.sin(np.radians(alpha_i)) - np.cos(np.radians(-alpha_i + theta_i)) * np.sin(np.radians(alpha_j))

            theta_rad = np.array(pd.Series(np.arctan(fenzi / fenmu)).map(lambda x: x if x > 0 else x + np.pi))
            theta_deg = np.rad2deg(theta_rad)

            # print("=========================================")
            # print(theta_deg)
            # print("=========================================")

            r = 100 * np.sin(np.radians(-180 - theta_deg + theta_j - alpha_j)) / np.sin(np.radians(alpha_j))

        elif theta_j - theta_k_true < 180 and theta_k_true - theta_i > 180:
            alpha_i = (-180 + theta_k_true - theta_i) / 2
            alpha_i = np.arange(alpha_i - 1, alpha_i + 1, 0.1)
            alpha_j = (180 + theta_k_true - theta_j) / 2
            alpha_j = np.arange(alpha_j - 1, alpha_j + 1, 0.1)

            fenzi = np.sin(np.radians(alpha_i + theta_i)) * np.sin(np.radians(alpha_j)) - np.sin(np.radians(alpha_j + theta_j)) * np.sin(np.radians(alpha_i))
            fenmu = np.cos(np.radians(alpha_i + theta_i)) * np.sin(np.radians(alpha_j)) - np.cos(np.radians(alpha_j + theta_j)) * np.sin(np.radians(alpha_i))

            theta_rad = np.array(pd.Series(np.arctan(fenzi / fenmu)).map(lambda x: x + np.pi if x > 0 else x + 2 * np.pi))
            theta_deg = np.rad2deg(theta_rad)
            r = 100 * np.sin(np.radians(180 + theta_deg - theta_j - alpha_j)) / np.sin(np.radians(alpha_j))

            # print(theta_deg)
            # print(r)
            # print("=========================================")

        return theta_rad, theta_deg, r

    def __right_or_left_k_func(self,theta_i,theta_j,theta_k_true):
        """
        此时k在两边，偏差为＋-1
        """

        theta_rad = None
        theta_deg = None
        r = None

        if theta_k_true - theta_j < 180 and theta_k_true - theta_i < 180:
            alpha_i = (180 - theta_k_true + theta_i)/ 2
            alpha_i = np.arange(alpha_i-1, alpha_i + 1, 0.1)
            alpha_j = (180 - theta_k_true + theta_j)/ 2
            alpha_j = np.arange(alpha_j-1, alpha_j + 1, 0.1)

            fenzi = np.sin(np.radians(alpha_j - theta_j)) * np.sin(np.radians(alpha_i)) - np.sin(np.radians(alpha_i - theta_i)) * np.sin(np.radians(alpha_j))
            fenmu = np.cos(np.radians(alpha_i - theta_i)) * np.sin(np.radians(alpha_j)) - np.cos(np.radians(alpha_j - theta_j)) * np.sin(np.radians(alpha_i))

            theta_rad = np.array(pd.Series(np.arctan(fenzi / fenmu)).map(lambda x: x if x > 0 else x + np.pi))
            theta_deg = np.rad2deg(theta_rad)

            r = 100 * np.sin(np.radians(-theta_j + theta_deg + alpha_j)) / np.sin(np.radians(alpha_j))

        elif theta_k_true - theta_j < 180 and theta_k_true - theta_i > 180:
            alpha_i = (-180 + theta_k_true - theta_i) / 2
            alpha_i = np.arange(alpha_i - 1, alpha_i + 1, 0.1)
            alpha_j = (180 - theta_k_true + theta_j) / 2
            alpha_j = np.arange(alpha_j - 1, alpha_j + 1, 0.1)
            fenzi = np.sin(np.radians(-alpha_j + theta_j)) * np.sin(np.radians(alpha_i)) + np.sin(np.radians(alpha_i + theta_i)) * np.sin(np.radians(-alpha_j))
            fenmu = np.cos(np.radians(alpha_i + theta_i)) * np.sin(np.radians(alpha_j)) + np.cos(np.radians(alpha_j - theta_j)) * np.sin(np.radians(alpha_i))

            theta_rad = np.array(pd.Series(np.arctan(fenzi / fenmu)).map(lambda x: x + np.pi if x > 0 else x + 2 * np.pi))
            theta_deg = np.rad2deg(theta_rad)
            r = 100 * np.sin(np.radians(theta_deg - theta_j + alpha_j)) / np.sin(np.radians(alpha_j))

        elif theta_k_true - theta_j > 180 and theta_k_true - theta_i > 180:
            alpha_i = (-180 + theta_k_true - theta_i) / 2
            alpha_i = np.arange(alpha_i - 1, alpha_i + 1, 0.1)
            alpha_j = (-180 + theta_k_true - theta_j) / 2
            alpha_j = np.arange(alpha_j - 1, alpha_j + 1, 0.1)
            fenzi = np.sin(np.radians(alpha_j + theta_j)) * np.sin(np.radians(alpha_i)) - np.sin(np.radians(alpha_i + theta_i)) * np.sin(np.radians(alpha_j))
            fenmu = np.cos(np.radians(alpha_j + theta_j)) * np.sin(np.radians(alpha_i)) - np.cos(np.radians(alpha_i + theta_i)) * np.sin(np.radians(alpha_j))

            theta_rad = np.array(pd.Series(np.arctan(fenzi / fenmu)).map(lambda x: x + np.pi if x > 0 else x + 2 * np.pi))
            theta_deg = np.rad2deg(theta_rad)
            r = 100 * np.sin(np.radians(-180 + theta_deg - theta_j + alpha_j)) / np.sin(np.radians(alpha_j))

            return theta_rad, theta_deg, r

    def polar_plot(self):
        Qi = 0
        Qj = np.arange(40, 360, 40)
        Qk = np.arange(40, 360, 40)

        for i,j in enumerate(Qj):
            ax = plt.subplot(2, 4, i+1, projection='polar')
            self.theta_rad = np.array([])
            self.theta_deg = np.array([])
            self.r = np.array([])
            self.color = np.array([])
            self.counter = 0

            for k in Qk:
                if k == j:
                    continue
                else:
                    if j > k:
                        theta_rad, theta_deg, temp_r = self.__mid_k_func(Qi, j, k)
                        self.theta_rad = np.hstack([self.theta_rad, theta_rad])
                        self.theta_deg = np.hstack([self.theta_deg, theta_deg])
                        self.r = np.hstack([self.r, temp_r])
                        self.color = np.hstack([self.color, np.array([self.all_color[self.counter]] for _ in range(theta_rad.shape[0]))])
                    elif j < k:
                        theta_rad, theta_deg, temp_r = self.__right_or_left_k_func(Qi, j, k)
                        self.theta_rad = np.hstack([self.theta_rad, theta_rad])
                        self.theta_deg = np.hstack([self.theta_deg, theta_deg])
                        self.r = np.hstack([self.r, temp_r])
                        self.color = np.hstack([self.color, np.array([self.all_color[self.counter]] for _ in range(theta_rad.shape[0]))])

                    self.counter += 1
            #画图
            ax.scatter(self.theta_rad, self.r, s=10, c=self.color)
            ax.set_rlim(0, 105)
            ax.scatter(Qi, 100, s=100, c='r', marker='*')
            if i == 0:
                ax.scatter(np.radians(j), 100, s=100, c='r', marker='*', label='发射信号无人机极坐标')
                ax.legend(bbox_to_anchor=(.55, 1.35))
            ax.scatter(np.radians(j), 100, s=100, c='r', marker='*')

            plt.show()
        # def b_2(j, k):
        #     return self.__mid_k_func(0, j, k) if j > k else self.__right_or_left_k_func(0, j, k)

if __name__ == '__main__':
    b_1 = B_1_cls()
    b_1.polar_plot()

