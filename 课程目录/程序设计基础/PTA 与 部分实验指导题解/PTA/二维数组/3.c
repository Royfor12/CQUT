/**********************************

每次游戏玩家会拿到一张彩票，上面会有 9 个数字，分别为数字 1 到数字 9，数字各不重复，并以 3×3 的“九宫格”形式排布在彩票上。

在游戏开始时能看见一个位置上的数字，其他位置上的数字均不可见。
你可以选择三个位置的数字刮开，这样玩家就能看见四个位置上的数字了。
最后玩家再从 3 横、3 竖、2 斜共 8 个方向中挑选一个方向，方向上三个数字的和可根据下列表格进行兑奖，获得对应数额的金币。

数字合计	获得金币

    6	    10,000
    7	        36	    
    8	       720	    
    9	       360	    
    10	        80	    
    11	       252	    
    12	       108	    
    13	        72	    
    14	        54	    
    15	       180		
	16	        72
    17	       180
    18	       119
    19	        36
    20	       306
    21	     1,080
    22	       144
    23	     1,800
    24	     3,600

现在请你写出一个模拟程序，模拟玩家的游戏过程。

输入格式:
输入第一部分给出一张合法的彩票，即用 3 行 3 列给出 0 至 9 的数字。
0 表示的是这个位置上的数字初始时就能看见了，而不是彩票上的数字为 0。

第二部给出玩家刮开的三个位置，分为三行，
每行按格式 x y 给出玩家刮开的位置的行号和列号（题目中定义左上角的位置为第 1 行、第 1 列。）。
数据保证玩家不会重复刮开已刮开的数字。

最后一部分给出玩家选择的方向，即一个整数： 
1 至 3 表示选择横向的第一行、第二行、第三行，
4 至 6 表示纵向的第一列、第二列、第三列，7、8分别表示左上到右下的主对角线和右上到左下的副对角线。

输出格式:
对于每一个刮开的操作，在一行中输出玩家能看到的数字。
最后对于选择的方向，在一行中输出玩家获得的金币数量。

输入样例:
1 2 3
4 5 6
7 8 0
1 1
2 2
2 3
7

输出样例:
1
5
6
180

***********************************/

#include <stdio.h>

int reward[25] = {
    0,      // reward[0]  未使用
    0,      // reward[1]  未使用
    0,      // reward[2]  未使用
    0,      // reward[3]  未使用
    0,      // reward[4]  未使用
    0,      // reward[5]  未使用
    10000,  // reward[6]  = 1+2+3
    36,     // reward[7]  = 1+2+4
    720,    // reward[8]  = 1+2+5
    360,    // reward[9]  = 1+2+6
    80,     // reward[10] = 1+3+6
    252,    // reward[11]
    108,    // reward[12]
    72,     // reward[13]
    54,     // reward[14]
    180,    // reward[15]
    72,     // reward[16]
    180,    // reward[17]
    119,    // reward[18]
    36,     // reward[19]
    306,    // reward[20]
    1080,   // reward[21]
    144,    // reward[22]
    1800,   // reward[23]
    3600    // reward[24] = 7+8+9
};

int main() {
    int a[3][3]; // 彩票
    int x, y;
    int direction;
    int all_nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int used[9] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0) {
                // 找到未使用的数字填充
                for (int k = 0; k < 9; k++) {
                    if (used[k] == 0) {
                        a[i][j] = all_nums[k];
                        used[k] = 1;
                        break;
                    }
                }
            } else {
                used[a[i][j] - 1] = 1;
            }
        }
    }

    // 输出刮开位置的数字
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", a[x-1][y-1]);
    }

    scanf("%d", &direction);
    int sum = 0;
    switch (direction) {
        case 1: sum = a[0][0] + a[0][1] + a[0][2]; break;
        case 2: sum = a[1][0] + a[1][1] + a[1][2]; break;
        case 3: sum = a[2][0] + a[2][1] + a[2][2]; break;
        case 4: sum = a[0][0] + a[1][0] + a[2][0]; break;
        case 5: sum = a[0][1] + a[1][1] + a[2][1]; break;
        case 6: sum = a[0][2] + a[1][2] + a[2][2]; break;
        case 7: sum = a[0][0] + a[1][1] + a[2][2]; break;
        case 8: sum = a[0][2] + a[1][1] + a[2][0]; break;
    }

    printf("%d\n", reward[sum]);

    return 0;
}