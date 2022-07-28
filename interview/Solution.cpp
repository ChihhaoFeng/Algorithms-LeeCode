#include<iostream>
#include<vector>
#include<string>
#include <set>
#include <unordered_map>
#include <queue>

#include <cstdlib> // 亂數相關函數
#include <ctime>   // 時間相關函數
#include <fstream> // 讀file 相關函數
#include <sstream> // file string

#include "Solution.h" 
using namespace std;




int Solution::StringLength(string args) {
    /// <summary>
    /// 计算字符串最后一个单词的长度，单词以空格隔开。  输入描述：一行字符串，非空，长度小于5000。
    /// 输出描述: 整数N，最后一个单词的长度。
    /// </summary>

    int max = 0;
    int cun = 0;
    int pointer = 0;

    for (char c : args)
    {

        if (c == NULL)
        {
            break;
        }

        cun++;

        if (c == ' ')
        {
            cun = 0;
        }
    }

    cout << cun << endl;

    return cun;
}

int Solution::SameCharNum(string args, char s)
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

void Solution::RandomSingleSort(int n)
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

void Solution::RandomSet(int n)
{

    /// <summary>
    /// 隨機生成n 組數據, 進行排序並刪除重複, 但刪除元素10.
    /// </summary>
    /// <param name="n"></param>

    set<int> input;

    int max = 20;
    int min = 1;

    for (int i = 0; i < n; i++)
    {
        int x = rand() % (max - min + 1) + min;

        cout << x << ",";

        input.insert(x);
    }

    cout << endl;
    cout << "-----------------------------------" << endl;

    input.insert(10);

    for (set<int>::iterator it = input.begin(); it != input.end(); it++)
    {
        cout << *it << ",";
    }

    cout << endl;

    input.erase(input.find(10));     // 搜尋元素10,並刪除

    cout << "-----------------------------------" << endl;

    for (set<int>::iterator it = input.begin(); it != input.end(); it++)
    {
        cout << *it << ",";
    }

    cout << endl;

}

vector<int> Solution::TwoSum(vector<int>& numbers, int target)
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

vector<int> Solution::PrimeFactor()
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

            cout << index << " ";

        }
        else
        {
            index++;
        }

    }

    return result;
}

vector<int> Solution::Reverse(vector<int>& input)
{
    ///<summary>
    ///输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
    ///<summary>

    unordered_map<int, int> hash;
    vector<int> output;

    for (int i = input.size() - 1; i >= 0; i--)
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

vector<char> Solution::ReverseSentence(string sen)
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

            for (int i = 0; i < count + 1; i++)
            {
                output.push_back(sen[tmp + i]);
                cout << sen[tmp + i];
            }
        }

    }



    return output;

}

int Solution::majorityElement(vector<int>& nums) {


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

void Solution::Password()
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
            cout << "pass" << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }



}

void Solution::ReadTxtFile1()
{
    ///<summary>
    /// Given a text file file.txt, print just the n'th line of the file.
    /// using char[]
    ///<summary>

    fstream newfile;

    char buffer[256] = { 0 };
    int n;
    cout << "the line's: ";
    cin >> n;

    newfile.open("file.txt");

    if (!newfile.is_open())
    {
        cout << "Failed to open file.\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            newfile.getline(buffer, sizeof(buffer));
        }

        cout << buffer << "\n";
        newfile.close();
    }


}

void Solution::ReadTxtFile2()
{
    ///<summary>
    /// Given a text file file.txt, print just the n'th line of the file.
    /// using string
    ///<summary>

    fstream newfile;
    string str;
    stringstream ss;

    vector<string> output;

    newfile.open("file.txt");

    int n;
    cout << "the line's: ";
    cin >> n;

    if (!newfile.is_open()) {
        cout << "Failed to open file.\n";
    }
    else {

        ss << newfile.rdbuf();  // newfile.rdbuf() 串流到 stringstream ss

        string str(ss.str());

        output = split(str, "\n");

        cout << output[n - 1] << endl;

        newfile.close();
    }

}

bool Solution::SubString(const char* input1, const char* input2)
{
    // 輸入兩個字串指針, 如果input1為input2 的子串則返回true

    bool test;

    for (int i = 0; i < sizeof(input1); i++)
    {

        if (input1[i] == input2[0])
        {
            for (int j = 0; j < sizeof(input2); j++)
            {
                int cun = i;
                if (input1[cun] != input2[j])
                {
                    return false;
                }
                cun++;
            }
            return true;
        }
    }
    return false;

}



/// <summary>
/// private
/// </summary>

void Solution::BubbleSort(vector<int>& input, int n)
{

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (input[j] > input[j + 1])
                swap(input[j], input[j + 1]);
}

void Solution::removeSortedDuplicates(vector<int>& nums)
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

vector<string> Solution::split(const string& s, const string& seperator) {

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