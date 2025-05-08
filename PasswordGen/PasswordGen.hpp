#include <iostream>
#include <windows.h>
#include <random>
#include <vector>
#include <ctime>

class password_gen
{
public:

    std::vector<std::string> logs;

    std::vector<std::string> generate_multiple_passwords(int amount, std::string prefix = "", int length = 12, bool upper = true, bool lower = true, bool num = true, bool special = true)
    {
        std::vector<std::string> buffer;

        for (int i = 0; i < amount; i++)
            buffer.push_back(generate_password(prefix, length, upper, lower, num, special));

        return buffer;
    }

    std::string generate_password(std::string prefix = "", int length = 12, bool upper = true, bool lower = true, bool num = true, bool special = true)
    {
        return gen_str(prefix, length, upper, lower, num, special);
    }

    int password_strength(std::string password)
    {
        int buffer = 0;

        for (char c : upper_char_map)
        {
            if (password.find(c))
            {
                logs.push_back("[good] contains upper chars.");
                buffer++;
                break;
            }
        }

        for (char c : lower_char_map)
        {
            if (password.find(c))
            {
                logs.push_back("[good] contains lower chars.");
                buffer++;
                break;
            }
        }

        for (char c : num_char_map)
        {
            if (password.find(c))
            {
                logs.push_back("[good] contains numerical chars.");
                buffer++;
                break;
            }
        }


        for (char c : special_char_map)
        {
            if (password.find(c))
            {
                logs.push_back("[good] contains special chars.");
                buffer++;
                break;
            }
        }

        if (buffer == 4)
            logs.push_back("[pass] password has 4 or more flags therefore it's secure.");

        return buffer;

    }

private:

    std::string upper_char_map = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lower_char_map = "abcdefghijklmnopqrstuvwxyz";
    std::string num_char_map = "0123456789";
    std::string special_char_map = "!£$%^&*(){}:@><,.~#¬`[]';";

    std::string gen_str(std::string prefix, int length, bool upper, bool lower, bool num, bool special)
    {

        std::string buffer;
        std::string output;

        if (!prefix.empty())
            output += prefix + "_";

        if (upper)
            buffer += upper_char_map;

        if (lower)
            buffer += lower_char_map;

        if (num)
            buffer += num_char_map;

        if (special)
            buffer += special_char_map;

        if (buffer.empty())
            return "";

        for (int i = 0; i < length; i++)
            output += buffer[rand() % buffer.length()];

        return output;
    }
};

password_gen* pass_gen = new password_gen();

