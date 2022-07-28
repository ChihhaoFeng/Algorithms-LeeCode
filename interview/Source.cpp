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

#include "DataStore.h"
#include "Tree.h"
#include "Solution.h"

using namespace std;

class Data //构造函数体赋值
{
public:
    Data(int year = 2000, int month = 4, int day = 28)  // 內建值構造函數
    {
        _year = year;
        _month = month;
        _day = day;
    }

    void InitData(int year, int month, int day)   // 初始化
    {
        _year = year;
        _month = month;
        _day = day;
    }

    void PrintData() 
    {
        cout << _year << "/" << _month << "/" << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};


int main()
{
    string input = "people4ar6es5go4ophpfp4pdp ph4fdd";
    string sen = "   observe dont you     but see You     ";

    vector<int> tree = { 3, 9, 20, 15, 7 };
    vector<int> tree2 = { 9, 7, 15, 3, 20 };
    TreeNode* root = NULL;

    vector<char> output;
    srand(time(NULL));

    Solution sol;

    //sol.StringLength(input);

    //sol.SameCharNum(input, 'p');

    //sol.RandomSingleSort(10);

    //sol.RandomSet(10);

    vector<int> nums = { 2,7,4,5,5,7,8 };
    //sol.TwoSum(nums, 10);

    //sol.Reverse(nums);

    //sol.PrimeFactor();

    //sol.ReverseSentence(sen);

    //sol.Password();

    //sol.ReadTxtFile1();             //char[]

    //sol.ReadTxtFile2();             //string
    

    /////*Tree structure problem*//////
    /*
    Tree _tree;

    root = _tree.CreateTree(tree2);

    _tree.LevelOrder(root);

    _tree.WhetherHeightBalance(root);

    _tree.preorderTraversal(root);

    _tree.postorderTraversal(root);

    _tree.FreeTree(root);



    */
    /////////////////////////////////////





    //Data d1;
    //d1.PrintData();
    //d1.InitData(1996,2,24);
    //d1.PrintData();


    /*  // DataStore 链接式数据 构造函数 & 析构函数
    DataStore ds;

    Student s;
    s.id = 24;
    strcpy_s(s.name, "Daniel");
    ds.Add(&s);

    s.id = 28;
    strcpy_s(s.name, "Geneieve");
    ds.Add(&s);

    s.id = 16;
    strcpy_s(s.name, "Eren");
    ds.Add(&s);
    
    ds.Print();
    */












    return 0;
}
