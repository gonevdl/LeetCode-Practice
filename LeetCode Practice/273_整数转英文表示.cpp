#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

/*
将非负整数 num 转换为其对应的英文表示。
示例 1：
输入：num = 123 输出："One Hundred Twenty Three"
示例 2：
输入：num = 12345 输出："Twelve Thousand Three Hundred Forty Five"
示例 3：
输入：num = 1234567 输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
示例 4：
输入：num = 1234567891
输出："One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-to-english-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//2,147,483,647
//废物解题法
class Solution {
public:
    string numberToWords(int num) {
        string sNum = to_string(num);
        string result = "";
        reverse(sNum.begin(), sNum.end());
        for (int i = sNum.size() - 1; i >= 0; i--) {
            switch (sNum[i])
            {
            case '0': 
            {
                if (i / 3 == 2) {
                    if (i % 3 == 0) {
                        if (i < (sNum.size() - 2)) {
                            if (sNum[i + 1] == '0' && sNum[i + 2] == '0') {
                                result += "";
                            }
                            else {
                                result += "Million ";
                            }
                        }
                        else {
                            result += "Million ";
                        }
                    }
                    else if (i % 3 == 1) {
                        result += "";
                    }
                    else {
                        result += "";
                    }
                }
                else if (i / 3 == 1) {
                    if (i % 3 == 0) {
                        if (i < (sNum.size() - 2)) {
                            if (sNum[i + 1] == '0' && sNum[i + 2] == '0') {
                                result += "";
                            }
                            else {
                                result += "Thousand ";
                            }
                        }
                        else {
                            result += "Thousand ";
                        }
                    }
                    else if (i % 3 == 1) {
                        result += "";
                    }
                    else {
                        result += "";
                    }
                }
                else {
                    if (i % 3 == 0) {
                        if (sNum.size() == 1) {
                            result += "Zero ";
                        }
                        else if (sNum.size() == 2) {
                            result += "";
                        }
                        else {
                            if (i < (sNum.size() - 2)) {
                                if (sNum[i + 1] == '0' && sNum[i + 2] == '0') {
                                    result += "";
                                }
                                else {
                                    result += "";
                                }
                            }
                        }
                    }
                    else if (i % 3 == 1) {
                        result += "";
                    }
                    else {
                        result += "";
                    }
                }
            }
            break;
            case '1':
            {
                if (i / 3 == 3) {
                    result += "One Billion ";
                }
                else if (i / 3 == 2) {
                    if (i % 3 == 0) {
                        result += "One Million ";
                    }
                    else if (i % 3 == 1) {
                        switch (sNum[i - 1])
                        {
                        case'0':
                        {
                            result += "Ten Million ";
                            i--;
                            break;
                        }
                        case'1':
                        {
                            result += "Eleven Million ";
                            i--;
                            break;
                        }
                        case '2':
                        {
                            result += "Twelve Million ";
                            i--;
                            break;
                        }
                        case '3':
                        {
                            result += "Thirteen Million ";
                            i--;
                            break;
                        }
                        case '4':
                        {
                            result += "Fourteen Million ";
                            i--;
                            break;
                        }
                        case '5':
                        {
                            result += "Fifteen Million ";
                            i--;
                            break;
                        }
                        case '6':
                        {
                            result += "Sixteen Million ";
                            i--;
                            break;
                        }
                        case '7':
                        {
                            result += "Seventeen Million ";
                            i--;
                            break;
                        }
                        case '8':
                        {
                            result += "Eighteen Million ";
                            i--;
                            break;
                        }
                        case '9':
                        {
                            result += "Nineteen Million ";
                            i--;
                            break;
                        }
                        default:
                            break;
                        }
                    }
                    else {
                        result += "One Hundred ";
                    }
                }
                else if (i / 3 == 1) {
                    {
                        if (i % 3 == 0) {
                            result += "One Thousand ";
                        }
                        else if (i % 3 == 1) {
                            switch (sNum[i - 1])
                            {
                            case'0':
                            {
                                result += "Ten Thousand ";
                                i--;
                                break;
                            }
                            case'1':
                            {
                                result += "Eleven Thousand ";
                                i--;
                                break;
                            }
                            case '2':
                            {
                                result += "Twelve Thousand ";
                                i--;
                                break;
                            }
                            case '3':
                            {
                                result += "Thirteen Thousand ";
                                i--;
                                break;
                            }
                            case '4':
                            {
                                result += "Fourteen Thousand ";
                                i--;
                                break;
                            }
                            case '5':
                            {
                                result += "Fifteen Thousand ";
                                i--;
                                break;
                            }
                            case '6':
                            {
                                result += "Sixteen Thousand ";
                                i--;
                                break;
                            }
                            case '7':
                            {
                                result += "Seventeen Thousand ";
                                i--;
                                break;
                            }
                            case '8':
                            {
                                result += "Eighteen Thousand ";
                                i--;
                                break;
                            }
                            case '9':
                            {
                                result += "Nineteen Thousand ";
                                i--;
                                break;
                            }
                            default:
                                break;
                            }
                        }
                        else {
                            result += "One Hundred ";
                        }
                    }
                }
                else {
                    {
                        if (i % 3 == 0) {
                            result += "One ";
                        }
                        else if (i % 3 == 1) {
                            switch (sNum[i - 1])
                            {
                            case'0':
                            {
                                result += "Ten ";
                                i--;
                                break;
                            }
                            case'1':
                            {
                                result += "Eleven ";
                                i--;
                                break;
                            }
                            case '2':
                            {
                                result += "Twelve ";
                                i--;
                                break;
                            }
                            case '3':
                            {
                                result += "Thirteen ";
                                i--;
                                break;
                            }
                            case '4':
                            {
                                result += "Fourteen ";
                                i--;
                                break;
                            }
                            case '5':
                            {
                                result += "Fifteen ";
                                i--;
                                break;
                            }
                            case '6':
                            {
                                result += "Sixteen ";
                                i--;
                                break;
                            }
                            case '7':
                            {
                                result += "Seventeen ";
                                i--;
                                break;
                            }
                            case '8':
                            {
                                result += "Eighteen ";
                                i--;
                                break;
                            }
                            case '9':
                            {
                                result += "Nineteen ";
                                i--;
                                break;
                            }
                            default:
                                break;
                            }
                        }
                        else {
                            result += "One Hundred ";
                        }
                    }
                }
            }
            break;
            case '2':
            {
                if (i / 3 == 3) {
                    if (i % 3 == 0) {
                        result += "Two Billion ";
                    }
                    else if (i % 3 == 1) {
                        result += "Twenty ";
                    }
                    else {
                        result += "Two Hundred ";
                    }
                }
                else if (i / 3 == 2) {
                    if (i % 3 == 0) {
                        result += "Two Million ";
                    }
                    else if (i % 3 == 1) {
                        result += "Twenty ";
                    }
                    else {
                        result += "Two Hundred ";
                    }
                }
                else if (i / 3 == 1) {
                    if (i % 3 == 0) {
                        result += "Two Thousand ";
                    }
                    else if (i % 3 == 1) {
                        result += "Twenty ";
                    }
                    else {
                        result += "Two Hundred ";
                    }
                }
                else {
                    if (i % 3 == 0) {
                        result += "Two ";
                    }
                    else if (i % 3 == 1) {
                        result += "Twenty ";
                    }
                    else {
                        result += "Two Hundred ";
                    }
                }
            }
            break;
            case '3':
            {
                if (i / 3 == 3) {
                    if (i % 3 == 0) {
                        result += "Three Billion ";
                    }
                    else if (i % 3 == 1) {
                        result += "Thirty ";
                    }
                    else {
                        result += "Three Hundred ";
                    }
                }
                else if (i / 3 == 2) {
                    if (i % 3 == 0) {
                        result += "Three Million ";
                    }
                    else if (i % 3 == 1) {
                        result += "Thirty ";
                    }
                    else {
                        result += "Three Hundred ";
                    }
                }
                else if (i / 3 == 1) {
                    if (i % 3 == 0) {
                        result += "Three Thousand ";
                    }
                    else if (i % 3 == 1) {
                        result += "Thirty ";
                    }
                    else {
                        result += "Three Hundred ";
                    }
                }
                else {
                    if (i % 3 == 0) {
                        result += "Three ";
                    }
                    else if (i % 3 == 1) {
                        result += "Thirty ";
                    }
                    else {
                        result += "Three Hundred ";
                    }
                }
            }
            break;
            case '4':
            {
                if (i / 3 == 3) {
                    if (i % 3 == 0) {
                        result += "Four Billion ";
                    }
                    else if (i % 3 == 1) {
                        result += "Forty ";
                    }
                    else {
                        result += "Four Hundred ";
                    }
                }
                else if (i / 3 == 2) {
                    if (i % 3 == 0) {
                        result += "Four Million ";
                    }
                    else if (i % 3 == 1) {
                        result += "Forty ";
                    }
                    else {
                        result += "Four Hundred ";
                    }
                }
                else if (i / 3 == 1) {
                    if (i % 3 == 0) {
                        result += "Four Thousand ";
                    }
                    else if (i % 3 == 1) {
                        result += "Forty ";
                    }
                    else {
                        result += "Four Hundred ";
                    }
                }
                else {
                    if (i % 3 == 0) {
                        result += "Four ";
                    }
                    else if (i % 3 == 1) {
                        result += "Forty ";
                    }
                    else {
                        result += "Four Hundred ";
                    }
                }
            }
            break;
            case '5':
            {
                if (i / 3 == 3) {
                    if (i % 3 == 0) {
                        result += "Five Billion ";
                    }
                    else if (i % 3 == 1) {
                        result += "Fifty ";
                    }
                    else {
                        result += "Five Hundred ";
                    }
                }
                else if (i / 3 == 2) {
                    if (i % 3 == 0) {
                        result += "Five Million ";
                    }
                    else if (i % 3 == 1) {
                        result += "Fifty ";
                    }
                    else {
                        result += "Five Hundred ";
                    }
                }
                else if (i / 3 == 1) {
                    if (i % 3 == 0) {
                        result += "Five Thousand ";
                    }
                    else if (i % 3 == 1) {
                        result += "Fifty ";
                    }
                    else {
                        result += "Five Hundred ";
                    }
                }
                else {
                    if (i % 3 == 0) {
                        result += "Five ";
                    }
                    else if (i % 3 == 1) {
                        result += "Fifty ";
                    }
                    else {
                        result += "Five Hundred ";
                    }
                }
            }
            break;
            case '6':
            {
                if (i / 3 == 3) {
                    if (i % 3 == 0) {
                        result += "Six Billion ";
                    }
                    else if (i % 3 == 1) {
                        result += "Sixty ";
                    }
                    else {
                        result += "Six Hundred ";
                    }
                }
                else if (i / 3 == 2) {
                    if (i % 3 == 0) {
                        result += "Six Million ";
                    }
                    else if (i % 3 == 1) {
                        result += "Sixty ";
                    }
                    else {
                        result += "Six Hundred ";
                    }
                }
                else if (i / 3 == 1) {
                    if (i % 3 == 0) {
                        result += "Six Thousand ";
                    }
                    else if (i % 3 == 1) {
                        result += "Sixty ";
                    }
                    else {
                        result += "Six Hundred ";
                    }
                }
                else {
                    if (i % 3 == 0) {
                        result += "Six ";
                    }
                    else if (i % 3 == 1) {
                        result += "Sixty ";
                    }
                    else {
                        result += "Six Hundred ";
                    }
                }
            }
            break;
            case '7':
            {
                if (i / 3 == 3) {
                    if (i % 3 == 0) {
                        result += "Seven Billion ";
                    }
                    else if (i % 3 == 1) {
                        result += "Seventy ";
                    }
                    else {
                        result += "Sevent Hundred ";
                    }
                }
                else if (i / 3 == 2) {
                    if (i % 3 == 0) {
                        result += "Seven Million ";
                    }
                    else if (i % 3 == 1) {
                        result += "Seventy ";
                    }
                    else {
                        result += "Sevent Hundred ";
                    }
                }
                else if (i / 3 == 1) {
                    if (i % 3 == 0) {
                        result += "Seven Thousand ";
                    }
                    else if (i % 3 == 1) {
                        result += "Seventy ";
                    }
                    else {
                        result += "Sevent Hundred ";
                    }
                }
                else {
                    if (i % 3 == 0) {
                        result += "Seven ";
                    }
                    else if (i % 3 == 1) {
                        result += "Seventy ";
                    }
                    else {
                        result += "Sevent Hundred ";
                    }
                }
            }
            break;
            case '8':
            {
                if (i / 3 == 3) {
                    if (i % 3 == 0) {
                        result += "Eight Billion ";
                    }
                    else if (i % 3 == 1) {
                        result += "Eighty ";
                    }
                    else {
                        result += "Eight Hundred ";
                    }
                }
                else if (i / 3 == 2) {
                    if (i % 3 == 0) {
                        result += "Eight Million ";
                    }
                    else if (i % 3 == 1) {
                        result += "Eighty ";
                    }
                    else {
                        result += "Eight Hundred ";
                    }
                }
                else if (i / 3 == 1) {
                    if (i % 3 == 0) {
                        result += "Eight Thousand ";
                    }
                    else if (i % 3 == 1) {
                        result += "Eighty ";
                    }
                    else {
                        result += "Eight Hundred ";
                    }
                }
                else {
                    if (i % 3 == 0) {
                        result += "Eight ";
                    }
                    else if (i % 3 == 1) {
                        result += "Eighty ";
                    }
                    else {
                        result += "Eight Hundred ";
                    }
                }
            }
            break;
            case '9':
            {
                if (i / 3 == 3) {
                    if (i % 3 == 0) {
                        result += "Nine Billion ";
                    }
                    else if (i % 3 == 1) {
                        result += "Ninety ";
                    }
                    else {
                        result += "Nine Hundred ";
                    }
                }
                else if (i / 3 == 2) {
                    if (i % 3 == 0) {
                        result += "Nine Million ";
                    }
                    else if (i % 3 == 1) {
                        result += "Ninety ";
                    }
                    else {
                        result += "Nine Hundred ";
                    }
                }
                else if (i / 3 == 1) {
                    if (i % 3 == 0) {
                        result += "Nine Thousand ";
                    }
                    else if (i % 3 == 1) {
                        result += "Ninety ";
                    }
                    else {
                        result += "Nine Hundred ";
                    }
                }
                else {
                    if (i % 3 == 0) {
                        result += "Nine ";
                    }
                    else if (i % 3 == 1) {
                        result += "Ninety ";
                    }
                    else {
                        result += "Nine Hundred ";
                    }
                }
            }
            break;
            default:
                break;
            }
        }
        result.erase(result.end() - 1);
        return result;
    }
};

class Solution1 {
public:
    string numberToWords(int num) {
        vector<string> singles = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten" };
        vector<string> teens = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                 "Seventeen", "Eighteen", "Nineteen" };
        vector<string> tens = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
        vector<string> thousands = { "", "Thousand", "Million", "Billion" };
        string result = "";
        int i = 9;
        int n = 0;
        do
        {
            n = num / (int)pow(10, i);
            num = num - n * (int)pow(10, i);
            if (n) {
                int hundred = n / 100;
                int ten = (n % 100) / 10;
                int single = (n % 10);
                if (hundred) {
                    result += singles[hundred] + "Hundred";
                    if (ten == 1) {
                        result += teens[single];
                    }
                    else {
                        result = result + tens[ten] + singles[single];
                    }
                }
                else {
                    result += singles[hundred];
                    if (ten == 1) {
                        result += teens[single];
                    }
                    else {
                        result = result +tens[ten] + singles[single];
                    }
                }
                result += thousands[i / 3];
            }
            i = i - 3;
        } while (i >= 0);
        //result.erase(result.begin());
        string cpy = result;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] >= 'A' && result[i] <= 'Z') {
                cpy.insert(i, 1, ' ');
            }
        }
        return cpy;
    }
};

int main() {
    Solution S;
    Solution1 S1;
    int num1 = 120;
    int num2 = 111111;
    int num3 = 111000101;
    int num4 = 10011010;
    cout << num1 << ":" << S1.numberToWords(num1) << endl;
    cout << num2 << ":" << S1.numberToWords(num2) << endl;
    cout << num3 << ":" << S1.numberToWords(num3) << endl;
    cout << num4 << ":" << S1.numberToWords(num4) << endl;
    return 0;
}