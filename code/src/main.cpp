#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


void func_continuous_square_wave_signal()
{
    std::string in_str;
    std::getline(std::cin, in_str);

    std::vector<std::string> result_strs;
    
    //从零开始
    auto str_pos = in_str.find('0');
    unsigned char begin_pos = 0;
    unsigned char str_count = 0;

    while (str_pos < in_str.size() &&
        str_pos != in_str.npos)
    {
        if (str_pos + 1 >= in_str.size())
        {
            if (str_count != 0)
                result_strs.push_back(in_str.substr(begin_pos, str_count + 1));
            break;
        }
        else
        {
            auto plus = in_str[str_pos] + in_str[str_pos + 1];
            if (plus == 97)
            {
                if (str_count == 0)
                    begin_pos = str_pos;
                str_count++;
            }
            else if (plus == 96)
            {
                if (str_count != 0)
                {
                    result_strs.push_back(in_str.substr(begin_pos, str_count + 1));
                    begin_pos = 0;
                    str_count = 0;
                }
            }
            else if (plus == 98)
            {
                str_count = 0;
                str_pos += in_str.substr(str_pos).find('0');
            }
        }
        str_pos++;
    }

    sort(result_strs.begin(), result_strs.end(), [](std::string left, std::string right){
        return left.size() > right.size();
    });

    if (result_strs.empty())
        std::cout << "output:" << -1 << std::endl;
    else
        std::cout << "output:" <<result_strs[0] << std::endl;
}

int main()
{
    while (true)
    {
        std::cout << "input: ";
        func_continuous_square_wave_signal();
        std::cout << "if you want to quit, enter q, else continue..." << std::endl;
        std::string in_str;
        std::getline(std::cin, in_str);
        if (in_str == "q")
            break;
    }
    return 0;
}