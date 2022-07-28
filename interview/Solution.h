#pragma once

using namespace std; 


class Solution {
public:
	int StringLength(string args);		 //计算字符串最后一个单词的长度，单词以空格隔开。  输入描述：一行字符串，非空，长度小于5000。
										/// 输出描述: 整数N，最后一个单词的长度。
	int SameCharNum(string args, char s);      //接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。

	void RandomSingleSort(int n);       //隨機生成n 組數據, 進行排序並刪除重複

	void RandomSet(int n);				//隨機生成n 組數據, 進行排序並刪除重複, 但刪除元素10.

	vector<int> TwoSum(vector<int>& numbers, int target); //給一個陣列和一個常數, 找出陣列中兩個數之和等於這個常數, 輸出兩個數的位址

	vector<int> PrimeFactor();			//輸入一個數並找出他的質因數

	vector<int> Reverse(vector<int>& input);	//输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数

	vector<char> ReverseSentence(string sen);	    // 将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
													// 所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
	int majorityElement(vector<int>& nums);			//The majority element is the element that appears more than ⌊n / 2⌋ times. 

	void Password();								//密码验证合格程序

	void ReadTxtFile1();							//Given a text file file.txt, print just the n'th line of the file.
													// using char[]

	void ReadTxtFile2();							//Given a text file file.txt, print just the n'th line of the file.
													// using string

	bool SubString(const char* input1, const char* input2);		//輸入兩個字串指針, 如果input1為input2 的子串則返回true
	


private:
	void BubbleSort(vector<int>& input, int n);

	void removeSortedDuplicates(vector<int>& nums);

	vector<string> split(const string& s, const string& seperator);
};