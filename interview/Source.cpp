#include<iostream>
#include<vector>
#include<string>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include <unordered_map>
using namespace std;


class Solution {
public: 
    static int StringLength( string args ){
        /// <summary>
        /// 计算字符串最后一个单词的长度，单词以空格隔开。  输入描述：一行字符串，非空，长度小于5000。
        /// 输出描述: 整数N，最后一个单词的长度。
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
        /// 接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
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

        removeSortedDuplicates(list);

        cout << endl;
        for (int n : list)
        {
            cout << n << " ";
        }



    }

    static vector<int> TwoSum(vector<int>& numbers, int target)
    {
        /// <summary>
        /// 給一個陣列和一個常數, 找出陣列中兩個數之和等於這個常數, 輸出兩個數的位址
        /// </summary>
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                //+1 because indices are NOT zero based
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                cout << hash[numberToFind] << "and" << i << endl;
                return result;
            }

            //number was not found. Put it in the map.
            hash[numbers[i]] = i;
        }
        return result;
    }

    static vector<int> PrimeFactor() 
    {
        /// <summary>
        /// 輸入一個數並找出他的質因數
        /// </summary>
        
        long int input;
        vector <int> result;

        cin >> input;


        if (input < 2) 
        {
            cout << "NULL" << endl;
            return result;
        }


        int index = 2;
        cout << "PrimeFactors:";

        while (input >= index) 
        {
            if (input % index == 0)
            {
                input /= index;

                result.push_back(index);

                cout << index <<" ";

            }
            else
            {
                index++;
            }

        }

        return result;
    }

    static vector<int> Reverse(vector<int>& input)
    {
        ///<summary>
        ///输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
        ///<summary>

        unordered_map<int, int> hash;
        vector<int> output;

        for (int i = input.size()-1 ; i >= 0; i--)
        {
            if (hash.find(input[i]) != hash.end())
            {
                continue;
            }

            hash[input[i]] = i;
            output.push_back(input[i]);
            cout << input[i] << " ";
        }

        return output;

    }

    static vector<char> ReverseSentence(string sen) 
    {
        ///<summary>
        /// 将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
        /// 所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
        ///<summary>
        
        vector<char> output;

        bool blank = false;
        int count = 0;
        int pointer = sen.size() - 1;
        int tmp;


        while (pointer >= 0) 
        {
            if (sen[pointer] == ' ' && blank == false)
            {
                pointer--;
            }
            else if (sen[pointer] == ' ' && blank == true) 
            {
                output.push_back(' ');
                cout << ' ';
                blank = false;
            }
            else if (sen[pointer] != ' ')
            {   
                count = 0;
                blank = true;
                while (sen[pointer] != ' ')   // 抓到單字,回傳單字長度
                {
                    count++;
                    pointer--;
                }
                tmp = pointer;

                for (int i = 0; i < count+1; i++) 
                {
                    output.push_back(sen[tmp+i]);
                    cout << sen[tmp + i];
                }
            }
            
        }



        return output;

    }

    static int majorityElement(vector<int>& nums) {


        /// <summary>
        /// The majority element is the element that appears more than ⌊n / 2⌋ times. 
        /// You may assume that the majority element always exists in the array.
        /// ex:
        /// Input: nums = [2,2,1,1,1,2,2]
        /// Output: 2
        /// </summary>

        int major = nums[0];

        int count = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (major == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }

            if (count < 0)
            {
                major = nums[i];
                count = 0;
            }

        }

        return major;

    }
    
    static void Password()
    {
        /// <summary>
        /// 密码验证合格程序
        /// </summary>    
        
        
        string password = "Danielfeng";

        string input;
        bool pass = false;

        while (!pass) 
        {
            pass = true;

            cout << "Please input your password: ";
            cin >> input;

            for (int i = 0; i < password.size(); i++)
            {
                if (password[i] != input[i])
                {
                    pass = false;
                    break;
                }
            }

            if (pass)
            {
                cout << "pass" <<endl;
            }
            else
            {
                cout << "error"<< endl;
            }
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

    static void removeSortedDuplicates(vector<int>& nums) 
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

    static vector<string> split(const string& s, const string& seperator) {
        
        vector<string> result;
        typedef string::size_type string_size;
        string_size i = 0;

        while (i != s.size()) {
            //找到字符串中首个不等于分隔符的字母；
            int flag = 0;
            while (i != s.size() && flag == 0) {
                flag = 1;
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[i] == seperator[x]) {
                        ++i;
                        flag = 0;
                        break;
                    }
            }

            //找到又一个分隔符，将两个分隔符之间的字符串取出；
            flag = 0;
            string_size j = i;
            while (j != s.size() && flag == 0) {
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[j] == seperator[x]) {
                        flag = 1;
                        break;
                    }
                if (flag == 0)
                    ++j;
            }
            if (i != j) {
                result.push_back(s.substr(i, j - i));
                i = j;
            }
        }
        return result;
    }
};


int main()
{
    string input = "people4ar6es5go4ophpfp4pdpph4fdd";
    string sen = "   observe dont you     but see You     ";

   
    vector<char> output;
    srand(time(NULL));

    //Solution::StringLength(input);
    
    //Solution::SameCharNum(input, 'p');

    //Solution::RandomSingleSort(10);

    vector<int> nums = { 2,7,4,5,5,7,8 };
    //Solution::TwoSum(nums, 10);


    //Solution::Reverse(nums);
    
    //Solution::PrimeFactor();

    //Solution::ReverseSentence(sen);

    //Solution::Password();

    return 0;
}
