#include<iostream>
#include<vector>
#include<string>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
using namespace std;


class Solution {
public: 
    static int StringLength( string args ){
        /// <summary>
        /// 最後一個單詞的長度
        /// </summary>

        int max = 0;
        int cun = 0 ;
        int pointer = 0;
        
        for (char c: args)
        {
            
            if(c == NULL)
            {
                break;
            }

            cun++;

            if (c ==' ') 
            {
                cun = 0;
            }
        }

        cout << cun << endl;

        return cun;
    }

    static int SameCharNum(string args, char s) 
    {
        /// <summary>
        /// string中,指定字母的數量
        /// </summary>

        int num = 0;

        for (char c : args) 
        {
            if (c == s) 
            {
                num++;
            }
        }

        cout << num << endl;
        return num;
    
    }
    
    
    static void RandomSingleSort(int n) 
    {   
        /// <summary>
        /// 隨機生成n 組數據, 進行排序並刪除重複
        /// </summary>
        /// <param name="n"></param>

        vector<int> list;
        int max = 20;
        int min = 1;
        
        for (int i = 0; i < n; i++) 
        {
            int x = rand() % (max - min + 1) + min;
            
            cout << x << " ";

            list.push_back(x);
        }
        
        BubbleSort(list, n);

        cout << endl;
        for (int n : list) 
        {
            cout << n << " ";
        }

        removeDuplicates(list);

        cout << endl;
        for (int n : list)
        {
            cout << n << " ";
        }



    }





private:
    static void BubbleSort(vector<int>& input, int n)
    {

        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (input[j] > input[j + 1])
                    swap(input[j], input[j + 1]);
    }

    static void removeDuplicates(vector<int>& nums) 
    {
        int j = 1;
        if (nums.size() == 0 || nums.size() == 1)
        {
            return;
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[j])
            {
                nums.erase(nums.begin() + i);
                i--;
                j--;
            }
            j++;

        }
        return;
    }






};


int main()
{
    string input = "people4ar6es5go4ophpfp4pdpph4fdd";

    srand(time(NULL));

    //Solution::StringLength(input);

    //Solution::SameCharNum(input, 'p');

    //Solution::RandomSingleSort(10);



    return 0;
}
