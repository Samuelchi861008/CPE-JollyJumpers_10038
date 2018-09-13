/* **************************************************************************

    * File Name : JollyJumpers.cpp

    * Creation Date : 2018-09-06 16:07:40

    * Last Modified : 2018-09-13 10:12:20

    * Created By : Samuel Chi <Yu-Ning Chi>

************************************************************************** */

#include <iostream>
#include <cmath> //abs()
using namespace std;

int main()
{
    int numOfInput; //輸入的個數
    int inputAry[3000]; //輸入值儲存之陣列
    int checkIsJollyAry[3000]; //判斷是否存在
    int totalIsJolly; //判斷全部是否符合Jolly

    while(cin >> numOfInput)
    {
        for(int h = 0; h < 3000; h++)
            inputAry[h] = checkIsJollyAry[h] = 0; //初始化兩陣列
        for(int i = 0; i < numOfInput; i++)
            cin >> inputAry[i]; //輸入
        for(int j = 0; j < numOfInput; j++)
        {
            int diff = abs(inputAry[j] - inputAry[j + 1]); 
            //前後兩數相減取絕對值
            checkIsJollyAry[diff - 1] = 1;
            //並表示確認存在該數
        }
        if(numOfInput == 1)
    		totalIsJolly = 1; //若只輸入一個數，必定是Jolly
        for(int k = 0; k < numOfInput - 1; k++)
            if(checkIsJollyAry[k] == 0) //若只要有其中一數不存在，則不為Jolly
            {
                totalIsJolly = 0;
                break;
            }
            else
                totalIsJolly = 1;
        if(totalIsJolly == 1)
            cout << "Jolly" << endl; //若全部確定為Jolly，則輸出Jolly
        else
            cout << "Not jolly" << endl; //否則輸出Not Jolly
    }
    return 0;
}
