/*
    BigInt
    ------
    Arbitrary-sized integer class for C++.

    Author: Sandeep sepat
    
*/

#ifndef BIGINT_CLASS
#define BIGINT_CLASS

#include <iostream>

class bigint
{
private:
    std::string bigNumber;
    char sign;

public:
    bigint();
    bigint(const bigint &);
    bigint(const long long &);
    bigint(const std::string &);
    bigint(const char *);

    // Assignment Operators:

    bigint &operator=(const std::string &);
    bigint &operator=(const bigint &);
    bigint &operator=(const long long int &);
    bigint &operator=(const char *);

    // Binary arithmetic operators + :

    bigint operator+(const std::string &) const;
    bigint operator+(const char *) const;
    bigint operator+(const bigint &) const;
    bigint operator+(const long long &) const;

    // Binary arithmetic operators - :

    bigint operator-(const std::string &) const;
    bigint operator-(const char *) const;
    bigint operator-(const bigint &) const;
    bigint operator-(const long long &) const;

    // Binary arithmetic operators * :

    bigint operator*(const std::string &) const;
    bigint operator*(const char *) const;
    bigint operator*(const bigint &) const;
    bigint operator*(const long long &) const;

    // Binary arithmetic operators / :

    bigint operator/(const std::string &) const;
    bigint operator/(const char *) const;
    bigint operator/(const bigint &) const;
    bigint operator/(const long long &) const;

    // Binary arithmetic operators % :

    bigint operator%(const std::string &) const;
    bigint operator%(const char *) const;
    bigint operator%(const bigint &) const;
    bigint operator%(const long long &) const;

    // Unary arithmetic operators:

    bigint operator+() const; // unary +
    bigint operator-() const; // unary -

    //  Arithmetic-assignment operator +=:

    bigint &operator+=(const std::string &);
    bigint &operator+=(const char *);
    bigint &operator+=(const bigint &);
    bigint &operator+=(const long long &);

    //  Arithmetic-assignment operator -=:

    bigint &operator-=(const std::string &);
    bigint &operator-=(const char *);
    bigint &operator-=(const bigint &);
    bigint &operator-=(const long long &);

    //  Arithmetic-assignment operator *=:

    bigint &operator*=(const std::string &);
    bigint &operator*=(const char *);
    bigint &operator*=(const bigint &);
    bigint &operator*=(const long long &);

    //  Arithmetic-assignment operator /=:

    bigint &operator/=(const std::string &);
    bigint &operator/=(const char *);
    bigint &operator/=(const bigint &);
    bigint &operator/=(const long long &);

    //  Arithmetic-assignment operator %=:

    bigint &operator%=(const std::string &);
    bigint &operator%=(const char *);
    bigint &operator%=(const bigint &);
    bigint &operator%=(const long long &);

    // Relational operators:

    // Relational operator for BigInt

    bool operator<(const bigint &) const;
    bool operator>(const bigint &) const;
    bool operator<=(const bigint &) const;
    bool operator>=(const bigint &) const;
    bool operator==(const bigint &) const;
    bool operator!=(const bigint &) const;

    // Relational operator for long long

    bool operator<(const long long &) const;
    bool operator>(const long long &) const;
    bool operator<=(const long long &) const;
    bool operator>=(const long long &) const;
    bool operator==(const long long &) const;
    bool operator!=(const long long &) const;

    // Relational operator for string

    bool operator<(const std::string &) const;
    bool operator>(const std::string &) const;
    bool operator<=(const std::string &) const;
    bool operator>=(const std::string &) const;
    bool operator==(const std::string &) const;
    bool operator!=(const std::string &) const;

    // Relational operator for string(char*)

    bool operator<(const char *) const;
    bool operator>(const char *) const;
    bool operator<=(const char *) const;
    bool operator>=(const char *) const;
    bool operator==(const char *) const;
    bool operator!=(const char *) const;

    // Increment and decrement operators:
    bigint &operator++();   // pre-increment
    bigint &operator--();   // pre-decrement
    bigint operator++(int); // post-increment
    bigint operator--(int); // post-decrement

    // I/O stream operators:
    friend std::istream &operator>>(std::istream &, bigint &);
    friend std::ostream &operator<<(std::ostream &, const bigint &);

    // Conversion functions:
    std::string to_string() const;
    int to_int() const;
    long long int to_long_long() const;

    // Random number generating functions:
    friend bigint big_random(size_t);

    // Factorial of Bigint

    friend bigint big_factorial(size_t);
};

#endif // BIGINT_CLASS

/*
    ====================================================================================
                Valid_Number_String
                Reference -Leetcode/65
    ====================================================================================
    This class check for whether string is valid or not
 */

#include <algorithm>

class Valid_Number_String
{
    int count_dot(std::string s)
    {
        int c = 0;
        for (char i : s)
        {
            if (i == '.')
            {
                c++;
            }
        }
        return c;
    }
    bool check_alpha(std::string s)
    {
        for (char i : s)
        {
            if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
            {
                if (i == 'e' || i == 'E')
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    int count_e(std::string s)
    {
        int c = 0;
        for (char i : s)
        {
            if (i == 'e' || i == 'E')
            {
                c++;
            }
        }
        return c;
    }
    int count_sign(std::string s)
    {
        int c = 0;
        for (char i : s)
        {
            if (i == '+' || i == '-')
            {
                c++;
            }
        }
        return c;
    }
    bool good_sign(std::string s)
    {
        bool b1 = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '+' || s[i] == '-')
            {
                if (i + 1 == s.length())
                {
                    return false;
                }
                else if (i - 1 >= 0)
                {
                    if (s[i - 1] >= '0' && s[i - 1] <= '9')
                    {
                        return false;
                    }
                    else if ((s[i - 1] == 'e' || s[i - 1] == 'E') && s[i + 1] == '.')
                    {
                        return false;
                    }
                }
                else if (s[i + 1] >= '0' && s[i + 1] <= '9')
                {
                    b1 = true;
                }
                else if (s[i + 1] == '.')
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return b1;
    }
    bool good_e(std::string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'e' || s[i] == 'E')
            {
                bool b1 = false;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (s[j] >= '0' && s[j] <= '9')
                    {
                        b1 = true;
                        break;
                    }
                }
                if (b1 == false)
                {
                    return false;
                }
                for (int j = i + 1; j < s.length(); j++)
                {
                    if (s[j] == '.')
                    {
                        return false;
                    }
                }
                if (i - 1 == -1)
                {
                    return false;
                }
                if (i + 1 == s.length())
                {
                    return false;
                }
                else if (s[i - 1] == '.')
                {
                    if (i - 2 == -1)
                    {
                        return false;
                    }
                    else if (s[i - 2] == '0')
                    {
                        return false;
                    }
                    return true;
                }
                if (i + 1 == s.length())
                {
                    return false;
                }
                else if (s[i + 1] == '+' || s[i + 1] == '-')
                {
                    if (i + 2 == s.length())
                    {
                        return false;
                    }
                    else if (s[i + 2] >= '1' && s[i + 2] <= '9')
                    {
                        return true;
                    }
                }
                else if (s[i + 1] >= '1' && s[i + 1] <= '9')
                {
                    return true;
                }
                break;
            }
        }
        return true;
    }
    bool good_dot(std::string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '.')
            {

                if (i - 1 == -1 && i + 1 == s.length())
                {
                    return false;
                }
                if (i + 1 == s.length())
                {
                    if (i - 1 != -1 && s[i - 1] >= '0' && s[i - 1] <= '9')
                    {
                        return true;
                    }
                    return false;
                }
                if ((s[i + 1] >= '0' && s[i + 1] <= '9') || (s[i + 1] == 'e' || s[i + 1] == 'E'))
                {
                    return true;
                }
                if (s[i + 1] == '-' || s[i + 1] == '+')
                {
                    return false;
                }
                else
                {
                    return true;
                }
                break;
            }
        }
        return true;
    }

public:
    bool isNumber(std::string s)
    {
        bool a0 = check_alpha(s);
        if (a0 == false)
        {
            return false;
        }
        int ae = count_e(s);
        if (ae > 1)
        {
            return false;
        }
        int sign = count_sign(s);
        if (sign > 2)
        {
            return false;
        }
        bool b11 = good_sign(s);
        if (b11 == false)
        {
            return false;
        }
        bool b22 = good_e(s);
        if (b22 == false)
        {
            return false;
        }
        int a1 = count_dot(s);
        if (a1 > 1)
        {
            return false;
        }
        bool d2 = good_dot(s);
        if (d2 == false)
        {
            return d2;
        }
        return true;
    }

    void removeTrailingWhiteSpaces(std::string &num)
    {
        while (num.back() == ' ')
        {
            num.pop_back();
        }
    }
    void removeLeadingWhiteSpaces(std::string &num)
    {
        reverse(num.begin(), num.end());
        while (num.back() == ' ')
        {
            num.pop_back();
        }
        reverse(num.begin(), num.end());
    }
    void findDot(std::string &num)
    {
        bool b1 = false;
        for (char i : num)
        {
            if (i == '.')
            {
                b1 = true;
            }
        }
        if (b1 == true)
        {
            bool E = false;
            for (char i : num)
            {
                if (i == 'E' || i == 'e')
                {
                    E = true;
                    break;
                }
            }
            if (E == true)
            {
                std::string e = "";
                while (!(num.back() == 'E' || num.back() == 'e'))
                {
                    e.push_back(num.back());
                    num.pop_back();
                }
                num.pop_back();

                if (e.back() == '-')
                {
                    e.pop_back();
                    while (num.back() != '.')
                    {
                        num.pop_back();
                    }
                    num.pop_back();
                    while (e.back() == '0')
                    {
                        e.pop_back();
                    }

                    if (e.length() > 8)
                    {
                        num = "0";
                        return;
                    }
                    if (e.length() == 0)
                    {
                        return;
                    }
                    reverse(e.begin(), e.end());
                    long long it = std::stoll(e);
                    while (it-- && num.length() > 0)
                    {
                        num.pop_back();
                    }
                }
                else if (e.back() == '+')
                {
                    e.pop_back();
                    std::string store = "";
                    while (num.back() != '.')
                    {
                        store.push_back(num.back());
                        num.pop_back();
                    }
                    num.pop_back();
                    while (e.back() == '0')
                    {
                        e.pop_back();
                    }
                    reverse(e.begin(), e.end());

                    if (e.length() > 4)
                    {
                        throw std::out_of_range("Length exceed 9999.");
                    }
                    else
                    {
                        long long l1 = std::stoll(e);
                        while (l1-- && store.length() > 0)
                        {
                            num.push_back(store.back());
                            store.pop_back();
                        }
                        while (l1--)
                        {
                            num.push_back('0');
                        }
                    }
                }
                else
                {

                    std::string store = "";
                    while (num.back() != '.')
                    {
                        store.push_back(num.back());
                        num.pop_back();
                    }
                    num.pop_back();
                    while (e.back() == '0')
                    {
                        e.pop_back();
                    }
                    reverse(e.begin(), e.end());
                    if (e.length() > 4)
                    {
                        throw std::out_of_range("Length exceed 9999.");
                    }
                    else
                    {
                        long long l1 = std::stoll(e);

                        while (l1--)
                        {
                            if (store.length() > 0)
                            {
                                num.push_back(store.back());
                                store.pop_back();
                            }
                            else
                            {
                                num.push_back('0');
                            }
                        }
                    }
                }
            }
            else
            {
                while (num[num.length() - 1] != '.')
                {
                    num.pop_back();
                }
                num.pop_back();
            }
        }
    }
    bool findE(std::string &num)
    {
        bool b1 = false;
        for (char i : num)
        {
            if (i == 'e' || i == 'E')
            {
                b1 = true;
            }
        }
        return b1;
    }
    void Handle(std::string &num)
    {
        std::string temp;
        for (int i = num.length() - 1; !(num[i] == 'E' || num[i] == 'e'); i--)
        {
            temp.push_back(num[i]);
            num.pop_back();
        }
        num.pop_back();

        if (temp[temp.length() - 1] == '-' || temp[temp.length() - 1] == '+')
        {
            if (temp[temp.length() - 1] == '-')
            {
                temp.pop_back();
                while (temp[temp.length() - 1] == '0')
                {
                    temp.pop_back();
                }
                if (temp.length() > 5)
                {
                    num = "0";
                }
                int p = stoi(temp);
                while (num.length() > 0 && p--)
                {
                    num.pop_back();
                }
            }
            else if (temp[temp.length() - 1] == '+')
            {
                temp.pop_back();
                while (temp[temp.length() - 1] == '0')
                {
                    temp.pop_back();
                }
                if (temp.length() > 4)
                {
                    throw std::out_of_range("Length exceed 9999.");
                }
                std::reverse(temp.begin(), temp.end());
                int k = stoi(temp);
                while (k--)
                {
                    num.push_back('0');
                }
            }
        }
        else
        {
            while (temp[temp.length() - 1] == '0')
            {
                temp.pop_back();
            }
            if (temp.length() > 4)
            {
                throw std::out_of_range("Length exceed 9999.");
            }
            std::reverse(temp.begin(), temp.end());
            int k = stoi(temp);
            while (k--)
            {
                num.push_back('0');
            }
        }
    }
    std::pair<std::string, char> helper(std::string num)
    {
        removeLeadingWhiteSpaces(num);
        removeTrailingWhiteSpaces(num);
        for (auto it : num)
        {
            if (it == ' ')
            {
                throw std::invalid_argument("Expected an integer, got \'" + num + "\'");
            }
        }

        char sign;
        if (num[0] == '-')
        {
            sign = '-';
        }
        else
        {
            sign = '+';
        }
        findDot(num);
        bool b1 = findE(num);
        if (b1 == true)
        {
            Handle(num);
            if (num == "0")
            {
                sign = '+';
                return {num, sign};
            }
        }

        if (num[0] == '-')
        {
            if (num.length() == 1)
            {
                num = "0";
                sign = '+';
                return {num, sign};
            }
            int s = 1;
            while (num[s] == '0')
            {
                s++;
            }
            if (num.length() == s)
            {
                num = "0";
                sign = '+';
                return {num, sign};
            }
            std::string s1;
            for (int i = s; i < num.length(); i++)
            {
                s1.push_back(num[i]);
            }

            return {s1, sign};
        }
        else if (num[0] == '+')
        {
            if (num.length() == 1)
            {
                num = "0";
                sign = '+';
                return {num, sign};
            }
            int s = 1;
            while (num[s] == '0')
            {
                s++;
            }
            if (num.length() == s)
            {
                num = "0";
                sign = '+';
                return {num, sign};
            }
            std::string s1;
            for (int i = s; i < num.length(); i++)
            {
                s1.push_back(num[i]);
            }
            return {s1, sign};
        }
        else
        {
            if (num.length() == 0)
            {
                num = "0";
                sign = '+';
                return {num, sign};
            }
            int s = 0;
            while (num[s] == '0')
            {
                s++;
            }
            if (num.length() == s)
            {
                num = "0";
                sign = '+';
                return {num, sign};
            }
            std::string s1;
            for (int i = s; i < num.length(); i++)
            {
                s1.push_back(num[i]);
            }
            return {s1, sign};
        }
    }
    std::pair<std::string, char> convert_to_number(const std::string &num)
    {
        return helper(num);
    }
};

/*
    BIG INTEGER
    ========================================================================================
                                Definations of Methods
    ========================================================================================
*/

#ifndef BIGINT_UTILITIES
#define BIGINT_UTILITIES

#include <tuple>

/*
    is_valid_number
    ---------------
    Check whether the given integer string is valid.
*/

bool is_valid_number(const std::string &number)
{
    Valid_Number_String obj;
    return obj.isNumber(number);
}

/*
    remove_leading_zeroes
    ---------------------
    remove the leading zeroes from a number string.
*/

void remove_leading_zeroes(std::string &num)
{
    size_t i = 0;
    for (; i < num.length(); i++)
    {
        if (num[i] != '0')
            break;
    }
    if (i == num.length())
    {
        num = "0";
    }
    else
    {
        num = num.substr(i);
    }
}

/*
    add_leading_zeroes
    ------------------
    add leading zeroes to number string.
*/

void add_leading_zeroes(std::string &num, size_t num_zeroes)
{
    num = std::string(num_zeroes, '0') + num;
}

/*
    add_trailing_zeroes
    -------------------
    add trailing zeroes to number string.
*/

void add_trailing_zeroes(std::string &num, size_t num_zeroes)
{
    num += std::string(num_zeroes, '0');
}

/*
    get_larger_and_smaller_number
    -----------------------------
    Recognize the given string-represented integers as `larger` and `smaller`,
    padding the smaller number with leading zeroes to make it equal in length to
    the larger number.
*/

std::tuple<std::string, std::string> get_larger_and_smaller(const std::string &num1, const std::string &num2)
{
    size_t len1 = num1.length(), len2 = num2.length();
    std::string larger, smaller;
    if (len1 > len2)
    {
        larger = num1;
        smaller = num2;
    }
    else
    {
        larger = num2;
        smaller = num1;
    }
    add_leading_zeroes(smaller, larger.length() - smaller.length());
    return std::make_tuple(larger, smaller);
}

/*
    is_power_of_10
    ----------------------
    Checks whether a string-represented integer is a power of 10.
*/

bool is_power_of_10(const std::string &num)
{
    if (num[0] != '1')
    {
        return false;
    }
    size_t i = 1;
    for (; i < num.length(); i++)
    {
        if (num[i] != '0')
        {
            return false;
        }
    }
    return true; // one's place is 1 and the following positions are all 0
}

#endif // BIGINT_UTILITIES

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
           Method for Random Number generation for bigint
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef RANDOM_NUMBER_GENERATOR
#define RANDOM_NUMBER_GENERATOR

#include <random>
#include <climits>
#include <time.h>

/*
    When the number of digitin random number is not specified it will automatically take a constant value of length of number
*/

const size_t MAX_RANDOM_LENGTH = 500;

/*
    big_random(length)
    ------------------
    return a bigint with specific number of digit
*/

bigint big_random(size_t length = 0)
{
    std::random_device random_number_generator;

    if (length == 0) // the number of digit not specified
        // uses random to get the length of random number
        length = 1 + random_number_generator() % MAX_RANDOM_LENGTH;

    srand(time(0));
    bigint big_rand;
    big_rand.bigNumber = "";                              // initialized to append digits
    big_rand.bigNumber += std::to_string(1 + rand() % 9); // intialize its first digit to non-zero digit

    while (big_rand.bigNumber.length() < length)
    {
        big_rand.bigNumber += std::to_string(rand());
    }
    if (big_rand.bigNumber.length() > length) // erase extra digits from random number
    {
        big_rand.bigNumber.erase(length);
    }
    return big_rand;
}

#endif // RANDOM_NUMBER_GENERATOR

#ifndef BIG_INT_CONSTRUCTOR
#define BIG_INT_CONSTRUCTOR

/*
    Default Constructor
    -------------------
*/

bigint::bigint()
{
    this->sign = '+';
    this->bigNumber = "0";
}

/*
    Copy constructor
    ----------------
*/

bigint::bigint(const bigint &num)
{
    this->bigNumber = num.bigNumber;
    this->sign = num.sign;
}

/*
    Integer to Bigint
    -----------------
*/

bigint::bigint(const long long &num)
{
    long long num2 = num;
    if (num < 0)
    {
        this->sign = '-';
        num2 *= -1;
    }
    else
    {
        this->sign = '+';
    }
    this->bigNumber = std::to_string(num2);
}

/*
    Char* to bigint
    ----------------
*/

bigint::bigint(const char *num)
{
    std::string tempStr = num;
    bool is_string_valid = is_valid_number(tempStr);
    if (is_string_valid == 0)
    {
        throw std::invalid_argument("Expected an integer, got \'" + tempStr + "\'");
    }
    else
    {

        Valid_Number_String Extract_num;
        std::pair<std::string, char> getNum = Extract_num.convert_to_number(tempStr);
        this->bigNumber = getNum.first;
        this->sign = getNum.second;
    }
}

/*
    String to bigint
    ----------------
*/

bigint::bigint(const std::string &num)
{
    bool is_string_valid = is_valid_number(num);
    if (is_string_valid == 0)
    {
        throw std::invalid_argument("Expected an integer, got \'" + num + "\'");
    }
    else
    {

        Valid_Number_String Extract_num;
        std::pair<std::string, char> getNum = Extract_num.convert_to_number(num);
        this->bigNumber = getNum.first;
        this->sign = getNum.second;
    }
}

#endif // BIG_INT_CONSTRUCTOR

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Conversion functions for BigInt
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef BIG_INT_CONVERSION_FUNCTION
#define BIG_INT_CONVERSION_FUNCTION

/*
    to_string
    ---------
    converts bigint to a string
*/

std::string bigint::to_string() const
{
    // add - if number < 0
    return this->sign == '-' ? '-' + this->bigNumber : this->bigNumber;
}

/*
    to_int
    ------
    Converts a bigint to an int.
    NOTE: If the bigint is out of range of an int, stoi() will throw an
    out_of_range exception.
*/

int bigint::to_int() const
{
    return std::stoi(this->to_string());
}

/*
    to_long
    ------
    Converts a bigint to an long long int.
    NOTE: If the bigint is out of range of an int, stol() will throw an
    out_of_range exception.
*/

long long int bigint::to_long_long() const
{
    return std::stol(this->to_string());
};

#endif // BIG_INT_CONVERSION_FUNCTION

#ifndef BIGINT_ASSIGNMENT_OPERATOR
#define BIGINT_ASSIGNMENT_OPERATOR

/*
    bigint = bigint
    ---------------
*/

bigint &bigint::operator=(const bigint &num)
{
    this->bigNumber = num.bigNumber;
    this->sign = num.sign;
    return *this;
}

/*
    bigint = Integer
    ----------------
*/

bigint & ::bigint::operator=(const long long int &num)
{
    bigint temp = (num);
    this->bigNumber = temp.bigNumber;
    this->sign = temp.sign;
    return *this;
}

/*
    BigInt = char*
    ---------------
*/

bigint &bigint::operator=(const char *tempstr)
{
    std::string num = tempstr;
    bigint temp(num);
    this->bigNumber = temp.bigNumber;
    sign = temp.sign;

    return *this;
}

/*
    bigint = String
    ---------------
*/

bigint &bigint::operator=(const std::string &num)
{
    bigint temp(num);
    this->bigNumber = temp.bigNumber;
    this->sign = temp.sign;
    return *this;
}

#endif // BIGINT_ASSIGNMENT_OPERATOR

/*
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Unary arithmetic operators
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef BIGINT_UNARY_ARITHMETIC_OPERATORS
#define BIGINT_UNARY_ARITHMETIC_OPERATORS

/*
    +bigint
    -------
    Returns the value of a bigint.
    NOTE: This function does not return the absolute value. To get the absolute
    value of a BigInt, use the `abs` function.
*/

bigint bigint::operator+() const
{
    return *this;
}

/*
    -bigint
    -------
    Returns the negative of a bigint.
*/

bigint bigint::operator-() const
{
    bigint num;
    num.bigNumber = this->bigNumber;
    if (this->bigNumber != "0")
    {
        if (this->sign == '+')
        {
            num.sign = '-';
        }
        else
        {
            num.sign = '+';
        }
    }
    return num;
}

#endif // BIGINT_UNARY_ARITHMETIC_OPERATORS

/*
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Relational operators
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    All operators depend on '<' ,'< and '=' operator(s).
*/

#ifndef BIGINT_RELATIONAL_OPERATORS
#define BIGINT_RELATIONAL_OPERATORS

/*
    bigint == bigint
    ----------------
*/

bool bigint::operator==(const bigint &num) const
{
    return this->bigNumber == num.bigNumber and this->sign == num.sign;
}

/*
    bigint != bigint
    ----------------
*/

bool bigint::operator!=(const bigint &num) const
{
    return !(*this == num);
}

/*
    bigint < bigint
    ---------------
*/

bool bigint::operator<(const bigint &num) const
{
    if (this->sign == num.sign)
    {
        if (sign == '+')
        {
            if (this->bigNumber.length() == num.bigNumber.length())
                return this->bigNumber < num.bigNumber;
            else
                return this->bigNumber.length() < num.bigNumber.length();
        }
        else
            return -(*this) > -num;
    }
    else
        return sign == '-';
}

/*
    bigint > bigint
    ---------------
*/

bool bigint::operator>(const bigint &num) const
{
    return !((*this < num) or (*this == num));
}
/*
    bigint <= bigint
    ----------------
*/

bool bigint::operator<=(const bigint &num) const
{
    return (*this < num) or (*this == num);
}

/*
    bigint >= bigint
    ----------------
*/

bool bigint::operator>=(const bigint &num) const
{
    return !(*this < num);
}

/*
    bigint == Integer
    -----------------
*/

bool bigint::operator==(const long long &num) const
{
    return *this == bigint(num);
}

/*
    Integer == bigint
    -----------------
*/

bool operator==(const long long &lhs, const bigint &rhs)
{
    return bigint(lhs) == rhs;
}

/*
    bigint != Integer
    -----------------
*/

bool bigint::operator!=(const long long &num) const
{
    return !(*this == bigint(num));
}

/*
    Integer != bigint
    -----------------
*/

bool operator!=(const long long &lhs, const bigint &rhs)
{
    return bigint(lhs) != rhs;
}

/*
    BigInt < Integer
    ----------------
*/

bool bigint::operator<(const long long &num) const
{
    return *this < bigint(num);
}

/*
    Integer < bigint
    ----------------
*/

bool operator<(const long long &lhs, const bigint &rhs)
{
    return bigint(lhs) < rhs;
}

/*
    bigint > Integer
    ----------------
*/

bool bigint::operator>(const long long &num) const
{
    return *this > bigint(num);
}

/*
    Integer > bigint
    ----------------
*/

bool operator>(const long long &lhs, const bigint &rhs)
{
    return bigint(lhs) > rhs;
}

/*
    bigint <= Integer
    -----------------
*/

bool bigint::operator<=(const long long &num) const
{
    return !(*this > bigint(num));
}

/*
    Integer <= bigint
    -----------------
*/

bool operator<=(const long long &lhs, const bigint &rhs)
{
    return bigint(lhs) <= rhs;
}

/*
    bigint >= Integer
    -----------------
*/

bool bigint::operator>=(const long long &num) const
{
    return !(*this < bigint(num));
}

/*
    Integer >= bigint
    -----------------
*/

bool operator>=(const long long &lhs, const bigint &rhs)
{
    return bigint(lhs) >= rhs;
}

/*
    bigint == String
    ----------------
*/

bool bigint::operator==(const std::string &num) const
{
    return *this == bigint(num);
}

/*
    bigint == String(char*)
    -----------------------
*/

bool bigint::operator==(const char *num) const
{
    return *this == bigint(num);
}

/*
    String == bigint
    ----------------
*/

bool operator==(const std::string &lhs, const bigint &rhs)
{
    return bigint(lhs) == rhs;
}

/*
    bigint != String
    ----------------
*/

bool bigint::operator!=(const std::string &num) const
{
    return !(*this == bigint(num));
}

/*
    bigint != String(char*)
    -----------------------
*/

bool bigint::operator!=(const char *num) const
{
    return !(*this == bigint(num));
}

/*
    String != bigint
    ----------------
*/

bool operator!=(const std::string &lhs, const bigint &rhs)
{
    return bigint(lhs) != rhs;
}

/*
    bigint < String
    ---------------
*/

bool bigint::operator<(const std::string &num) const
{
    return *this < bigint(num);
}

/*
    bigint < String(char*)
    ---------------
*/

bool bigint::operator<(const char *num) const
{
    return *this < bigint(num);
}

/*
    String < bigint
    ---------------
*/

bool operator<(const std::string &lhs, const bigint &rhs)
{
    return bigint(lhs) < rhs;
}

/*
    bigint > String
    ---------------
*/

bool bigint::operator>(const std::string &num) const
{
    return *this > bigint(num);
}

/*
    bigint > String(char*)
    ----------------------
*/

bool bigint::operator>(const char *num) const
{
    return *this > bigint(num);
}

/*
    String > bigint
    ---------------
*/

bool operator>(const std::string &lhs, const bigint &rhs)
{
    return bigint(lhs) > rhs;
}

/*
    bigint <= String
    ----------------
*/

bool bigint::operator<=(const std::string &num) const
{
    return !(*this > bigint(num));
}

/*
    bigint <= String(char*)
    ----------------
*/

bool bigint::operator<=(const char *num) const
{
    return !(*this > bigint(num));
}

/*
    String <= bigint
    ----------------
*/

bool operator<=(const std::string &lhs, const bigint &rhs)
{
    return bigint(lhs) <= rhs;
}

/*
    bigint >= String
    ----------------
*/

bool bigint::operator>=(const std::string &num) const
{
    return !(*this < bigint(num));
}

/*
    bigint >= String(char*)
    ----------------------
*/

bool bigint::operator>=(const char *num) const
{
    return !(*this < bigint(num));
}

/*
    String >= bigint
    ----------------
*/

bool operator>=(const std::string &lhs, const bigint &rhs)
{
    return bigint(lhs) >= rhs;
}

#endif // BIGINT_RELATIONAL_OPERATORS

/*
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Mathematical functions for bigint
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef MATHEMATICAL_FUNCTIONS
#define MATHEMATICAL_FUNCTIONS

#include <string>

/*
    abs
    ---
    Returns the absolute value of a bigint
*/

bigint abs(const bigint &num)
{
    return num < "0" ? -num : num;
}

/*
    big_pow10
    ---------
    Returns a bigint equal to 10^exp.
    NOTE: exponent should be non negative
*/

bigint big_pow10(size_t exp)
{
    return bigint("1" + std::string(exp, '0'));
}

/*
    pow (bigint)
    ------------
    Returns a bigint equal to base^exp.
*/

bigint pow(const bigint &base, size_t exp)
{
    if (exp == 0)
    {
        if (base == "0")
        {
            throw std::logic_error("Zero cannot be raised to zero");
        }
        return 1;
    }
    bigint result = base, result_odd = 1;
    while (exp > 1)
    {
        if (exp % 2)
        {
            result_odd *= result;
        }
        result_odd *= result;
        exp /= 2;
    }

    return result * result_odd;
}

/*
    pow (Integer)
    -------------
    Returns a bigint equal to base^exp.
*/

bigint pow(const long long &base, int exp)
{
    return pow(bigint(base), exp);
}

/*
    sqrt
    ----
    Returns the positive integer square root of a bigint using Newton's method.
    NOTE: the input must be non-negative.
*/

bigint sqrt(const bigint &num)
{
    if (num < "0")
        throw std::invalid_argument("Cannot compute square root of a negative integer");

    // Optimisations for small inputs:
    if (num == "0")
        return "0";
    else if (num < 4)
        return 1;
    else if (num < 9)
        return 2;
    else if (num < 16)
        return 3;

    bigint sqrt_prev = -1;
    // The value for `sqrt_current` is chosen close to that of the actual
    // square root.
    // Since a number's square root has at least one less than half as many
    // digits as the number,
    //     sqrt_current = 10^(half_the_digits_in_num - 1)
    bigint sqrt_current = big_pow10(num.to_string().size() / 2 - 1);

    while (abs(sqrt_current - sqrt_prev) > 1)
    {
        sqrt_prev = sqrt_current;
        sqrt_current = (num / sqrt_prev + sqrt_prev) / 2;
    }

    return sqrt_current;
}

/*
    gcd(bigint, bigint)
    -------------------
    Returns the greatest common divisor (GCD, a.k.a. HCF) of two bigints using
    Euclid's algorithm.
*/

bigint gcd(const bigint &num1, const bigint &num2)
{
    bigint abs_num1 = abs(num1);
    bigint abs_num2 = abs(num2);

    // base cases:
    if (abs_num2 == "0")
        return abs_num1; // gcd(a, 0) = |a|
    if (abs_num1 == "0")
        return abs_num2; // gcd(0, a) = |a|

    bigint remainder = abs_num2;
    while (remainder != "0")
    {
        remainder = abs_num1 % abs_num2;
        abs_num1 = abs_num2;  // previous remainder
        abs_num2 = remainder; // current remainder
    }

    return abs_num1;
}

/*
    gcd(bigint, Integer)
    --------------------
*/

bigint gcd(const bigint &num1, const long long &num2)
{
    return gcd(num1, bigint(num2));
}

/*
    gcd(bigint, String)
    -------------------
*/

bigint gcd(const bigint &num1, const std::string &num2)
{
    return gcd(num1, bigint(num2));
}

/*
    gcd(Integer, bigint)
    --------------------
*/

bigint gcd(const long long &num1, const bigint &num2)
{
    return gcd(bigint(num1), num2);
}

/*
    lcm(bigint, bigint)
    -------------------
    Returns the least common multiple (LCM) of two bigints.
*/

bigint lcm(const bigint &num1, const bigint &num2)
{
    if (num1 == "0" or num2 == "0")
        return "0";

    return abs(num1 * num2) / gcd(num1, num2);
}

/*
    lcm(bigint, Integer)
    --------------------
*/

bigint lcm(const bigint &num1, const long long &num2)
{
    return lcm(num1, bigint(num2));
}

/*
    lcm(bigint, String)
    -------------------
*/

bigint lcm(const bigint &num1, const std::string &num2)
{
    return lcm(num1, bigint(num2));
}

/*
    lcm(Integer, bigint)
    --------------------
*/

bigint lcm(const long long &num1, const bigint &num2)
{
    return lcm(bigint(num1), num2);
}

/*
    lcm(String, bigint)
    -------------------
*/

bigint lcm(const std::string &num1, const bigint &num2)
{
    return lcm(bigint(num1), num2);
}

#endif // MATHEMATICAL_FUNCTIONS

/*
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bigint arithmetic function
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef BIGINT_BINARY_ARITHEMARIC_FUNCTION
#define BIGINT_BINARY_ARITHEMARIC_FUNCTION

#include <climits>
#include <cmath>
#include <string>

const long long FLOOR_SQRT_LL_MAX = 3037000499;

bigint bigint::operator+(const bigint &num) const
{
    // if the operands are of opposite signs, perform subtraction
    if (this->sign == '+' and num.sign == '-')
    {
        bigint rhs = num;
        rhs.sign = '+';
        return *this - rhs;
    }
    else if (this->sign == '-' and num.sign == '+')
    {
        bigint lhs = *this;
        lhs.sign = '+';
        return -(lhs - num);
    }

    // identify the numbers as `larger` and `smaller`
    std::string larger, smaller;
    std::tie(larger, smaller) = get_larger_and_smaller(this->bigNumber, num.bigNumber);

    bigint result;         // the resultant sum
    result.bigNumber = ""; // the value is cleared as the digits will be appended
    short carry = 0, sum;
    // add the two values
    for (long i = larger.size() - 1; i >= 0; i--)
    {
        sum = larger[i] - '0' + smaller[i] - '0' + carry;
        result.bigNumber = std::to_string(sum % 10) + result.bigNumber;
        carry = sum / (short)10;
    }
    if (carry)
        result.bigNumber = std::to_string(carry) + result.bigNumber;

    // if the operands are negative, the result is negative
    if (this->sign == '-' and result.bigNumber != "0")
        result.sign = '-';

    return result;
}

/*
    bigint - bigint
    ---------------
    The operand on the RHS of the subtraction is `num`.
*/

bigint bigint::operator-(const bigint &num) const
{
    // if the operands are of opposite signs, perform addition
    if (this->sign == '+' and num.sign == '-')
    {
        bigint rhs = num;
        rhs.sign = '+';
        return *this + rhs;
    }
    else if (this->sign == '-' and num.sign == '+')
    {
        bigint lhs = *this;
        lhs.sign = '+';
        return -(lhs + num);
    }

    bigint result; // the resultant difference
    // identify the numbers as `larger` and `smaller`
    std::string larger, smaller;
    if (abs(*this) > abs(num))
    {
        larger = this->bigNumber;
        smaller = num.bigNumber;

        if (this->sign == '-') // -larger - -smaller = -result
        {
            result.sign = '-';
        }
    }
    else
    {
        larger = num.bigNumber;
        smaller = this->bigNumber;

        if (num.sign == '+') // smaller - larger = -result
        {
            result.sign = '-';
        }
    }
    // pad the smaller number with zeroes
    add_leading_zeroes(smaller, larger.size() - smaller.size());

    result.bigNumber = ""; // the value is cleared as the digits will be appended
    short difference;
    long i, j;
    // subtract the two values
    for (i = larger.size() - 1; i >= 0; i--)
    {
        difference = larger[i] - smaller[i];
        if (difference < 0)
        {
            for (j = i - 1; j >= 0; j--)
            {
                if (larger[j] != '0')
                {
                    larger[j]--; // borrow from the j-th digit
                    break;
                }
            }
            j++;
            while (j != i)
            {
                larger[j] = '9'; // add the borrow and take away 1
                j++;
            }
            difference += 10; // add the borrow
        }
        result.bigNumber = std::to_string(difference) + result.bigNumber;
    }
    remove_leading_zeroes(result.bigNumber);

    // if the result is 0, set its sign as +
    if (result.bigNumber == "0")
        result.sign = '+';

    return result;
}

/*
    bigint * bigint
    ---------------
    Computes the product of two BigInts using Karatsuba's algorithm.
    The operand on the RHS of the product is `num`.
*/

bigint bigint::operator*(const bigint &num) const
{
    if (*this == "0" or num == "0")
        return bigint("0");
    if (*this == 1)
        return num;
    if (num == 1)
        return *this;

    bigint product;
    if (abs(*this) <= FLOOR_SQRT_LL_MAX and abs(num) <= FLOOR_SQRT_LL_MAX)
        product = std::stoll(this->bigNumber) * std::stoll(num.bigNumber);
    else if (is_power_of_10(this->bigNumber))
    { // if LHS is a power of 10 do optimised operation
        product.bigNumber = num.bigNumber;
        product.bigNumber.append(this->bigNumber.begin() + 1, this->bigNumber.end());
    }
    else if (is_power_of_10(num.bigNumber))
    { // if RHS is a power of 10 do optimised operation
        product.bigNumber = this->bigNumber;
        product.bigNumber.append(num.bigNumber.begin() + 1, num.bigNumber.end());
    }
    else
    {
        // identify the numbers as `larger` and `smaller`
        std::string larger, smaller;
        std::tie(larger, smaller) = get_larger_and_smaller(this->bigNumber, num.bigNumber);

        size_t half_length = larger.size() / 2;
        auto half_length_ceil = (size_t)ceil(larger.size() / 2.0);

        bigint num1_high, num1_low;
        num1_high = larger.substr(0, half_length);
        num1_low = larger.substr(half_length);

        bigint num2_high, num2_low;
        num2_high = smaller.substr(0, half_length);
        num2_low = smaller.substr(half_length);

        remove_leading_zeroes(num1_high.bigNumber);
        remove_leading_zeroes(num1_low.bigNumber);
        remove_leading_zeroes(num2_high.bigNumber);
        remove_leading_zeroes(num2_low.bigNumber);

        bigint prod_high, prod_mid, prod_low;
        prod_high = num1_high * num2_high;
        prod_low = num1_low * num2_low;
        prod_mid = (num1_high + num1_low) * (num2_high + num2_low) - prod_high - prod_low;

        add_trailing_zeroes(prod_high.bigNumber, 2 * half_length_ceil);
        add_trailing_zeroes(prod_mid.bigNumber, half_length_ceil);

        remove_leading_zeroes(prod_high.bigNumber);
        remove_leading_zeroes(prod_mid.bigNumber);
        remove_leading_zeroes(prod_low.bigNumber);

        product = prod_high + prod_mid + prod_low;
    }
    remove_leading_zeroes(product.bigNumber);

    if (this->sign == num.sign)
        product.sign = '+';
    else
        product.sign = '-';

    return product;
}

/*
    divide
    ------
    Helper function that returns the quotient and remainder on dividing the
    dividend by the divisor, when the divisor is 1 to 10 times the dividend.
*/

std::tuple<bigint, bigint> divide(const bigint &dividend, const bigint &divisor)
{
    bigint quotient, remainder, temp;

    temp = divisor;
    quotient = 1;
    while (temp < dividend)
    {
        quotient++;
        temp += divisor;
    }
    if (temp > dividend)
    {
        quotient--;
        remainder = dividend - (temp - divisor);
    }

    return std::make_tuple(quotient, remainder);
}

/*
    bigint / bigint
    ---------------
    Computes the quotient of two bigints using the long-division method.
    The operand on the RHS of the division (the divisor) is `num`.
*/

bigint bigint::operator/(const bigint &num) const
{
    bigint abs_dividend = abs(*this);
    bigint abs_divisor = abs(num);

    if (num == "0")
        throw std::logic_error("Attempted division by zero");
    if (abs_dividend < abs_divisor)
        return bigint("0");
    if (num == 1)
        return *this;
    if (num == -1)
        return -(*this);

    bigint quotient;
    if (abs_dividend <= LLONG_MAX and abs_divisor <= LLONG_MAX)
        quotient = std::stoll(abs_dividend.bigNumber) / std::stoll(abs_divisor.bigNumber);
    else if (abs_dividend == abs_divisor)
        quotient = 1;
    else if (is_power_of_10(abs_divisor.bigNumber))
    { // if divisor is a power of 10 do optimised calculation
        size_t digits_in_quotient = abs_dividend.bigNumber.size() - abs_divisor.bigNumber.size() + 1;
        quotient.bigNumber = abs_dividend.bigNumber.substr(0, digits_in_quotient);
    }
    else
    {
        quotient.bigNumber = ""; // the value is cleared as digits will be appended
        bigint chunk, chunk_quotient, chunk_remainder;
        size_t chunk_index = 0;
        chunk_remainder.bigNumber = abs_dividend.bigNumber.substr(chunk_index, abs_divisor.bigNumber.size() - 1);
        chunk_index = abs_divisor.bigNumber.size() - 1;
        while (chunk_index < abs_dividend.bigNumber.size())
        {
            chunk.bigNumber = chunk_remainder.bigNumber.append(1, abs_dividend.bigNumber[chunk_index]);
            chunk_index++;
            while (chunk < abs_divisor)
            {
                quotient.bigNumber += "0";
                if (chunk_index < abs_dividend.bigNumber.size())
                {
                    chunk.bigNumber.append(1, abs_dividend.bigNumber[chunk_index]);
                    chunk_index++;
                }
                else
                    break;
            }
            if (chunk == abs_divisor)
            {
                quotient.bigNumber += "1";
                chunk_remainder = "0";
            }
            else if (chunk > abs_divisor)
            {
                remove_leading_zeroes(chunk.bigNumber);
                std::tie(chunk_quotient, chunk_remainder) = divide(chunk, abs_divisor);
                quotient.bigNumber += chunk_quotient.bigNumber;
            }
        }
    }
    remove_leading_zeroes(quotient.bigNumber);

    if (this->sign == num.sign)
        quotient.sign = '+';
    else
        quotient.sign = '-';

    return quotient;
}

/*
    bigint % bigint
    ---------------
    Computes the modulo (remainder on division) of two bigints.
    The operand on the RHS of the modulo (the divisor) is `num`.
*/

bigint bigint::operator%(const bigint &num) const
{
    bigint abs_dividend = abs(*this);
    bigint abs_divisor = abs(num);

    if (abs_divisor == "0")
        throw std::logic_error("Attempted division by zero");
    if (abs_divisor == 1 or abs_divisor == abs_dividend)
        return bigint("0");

    bigint remainder;
    if (abs_dividend <= LLONG_MAX and abs_divisor <= LLONG_MAX)
        remainder = std::stoll(abs_dividend.bigNumber) % std::stoll(abs_divisor.bigNumber);
    else if (abs_dividend < abs_divisor)
        remainder = abs_dividend;
    else if (is_power_of_10(num.bigNumber))
    { // if num is a power of 10 use optimised calculation
        size_t no_of_zeroes = num.bigNumber.size() - 1;
        remainder.bigNumber = abs_dividend.bigNumber.substr(abs_dividend.bigNumber.size() - no_of_zeroes);
    }
    else
    {
        bigint quotient = abs_dividend / abs_divisor;
        remainder = abs_dividend - quotient * abs_divisor;
    }
    remove_leading_zeroes(remainder.bigNumber);

    // remainder has the same sign as that of the dividend
    remainder.sign = this->sign;
    if (remainder.bigNumber == "0") // except if its zero
        remainder.sign = '+';

    return remainder;
}

/*
    bigint + Integer
    ----------------
*/

bigint bigint::operator+(const long long &num) const
{
    return *this + bigint(num);
}

/*
    Integer + bigint
    ----------------
*/

bigint operator+(const long long &lhs, const bigint &rhs)
{
    return bigint(lhs) + rhs;
}

/*
    bigint - Integer
    ----------------
*/

bigint bigint::operator-(const long long &num) const
{
    return *this - bigint(num);
}

/*
    Integer - bigint
    ----------------
*/

bigint operator-(const long long &lhs, const bigint &rhs)
{
    return bigint(lhs) - rhs;
}

/*
    bigint * Integer
    ----------------
*/

bigint bigint::operator*(const long long &num) const
{
    return *this * bigint(num);
}

/*
    Integer * bigint
    ----------------
*/

bigint operator*(const long long &lhs, const bigint &rhs)
{
    return bigint(lhs) * rhs;
}

/*
    bigint / Integer
    ----------------
*/

bigint bigint::operator/(const long long &num) const
{
    return *this / bigint(num);
}

/*
    Integer / bigint
    ----------------
*/

bigint operator/(const long long &lhs, const bigint &rhs)
{
    return bigint(lhs) / rhs;
}

/*
    bigint % Integer
    ----------------
*/

bigint bigint::operator%(const long long &num) const
{
    return *this % bigint(num);
}

/*
    Integer % bigint
    ----------------
*/

bigint operator%(const long long &lhs, const bigint &rhs)
{
    return bigint(lhs) % rhs;
}

/*
    bigint + String
    ---------------
*/

bigint bigint::operator+(const std::string &num) const
{
    return *this + bigint(num);
}

/*
    bigint + String(char*)
    ----------------------
*/

bigint bigint::operator+(const char *num) const
{
    return *this + bigint(num);
}

/*
    String + bigint
    ---------------
*/

bigint operator+(const std::string &lhs, const bigint &rhs)
{
    return bigint(lhs) + rhs;
}

/*
    bigint - String
    ---------------
*/

bigint bigint::operator-(const std::string &num) const
{
    return *this - bigint(num);
}

/*
    bigint - String(char*)
    ----------------------
*/

bigint bigint::operator-(const char *num) const
{
    return *this - bigint(num);
}

/*
    String - bigint
    ---------------
*/

bigint operator-(const std::string &lhs, const bigint &rhs)
{
    return bigint(lhs) - rhs;
}

/*
    bigint * String
    ---------------
*/

bigint bigint::operator*(const std::string &num) const
{
    return *this * bigint(num);
}

/*
    bigint * String(char*)
    ----------------------
*/

bigint bigint::operator*(const char *num) const
{
    return *this * bigint(num);
}

/*
    String * bigint
    ---------------
*/

bigint operator*(const std::string &lhs, const bigint &rhs)
{
    return bigint(lhs) * rhs;
}

/*
    BigInt / String
    ---------------
*/

bigint bigint::operator/(const std::string &num) const
{
    return *this / bigint(num);
}

/*
    BigInt / String(char*)
    ----------------------
*/

bigint bigint::operator/(const char *num) const
{
    return *this / bigint(num);
}

/*
    String / bigint
    ---------------
*/

bigint operator/(const std::string &lhs, const bigint &rhs)
{
    return bigint(lhs) / rhs;
}

/*
    bigint % String
    ---------------
*/

bigint bigint::operator%(const std::string &num) const
{
    return *this % bigint(num);
}

/*
    bigint % String(char*)
    ----------------------
*/

bigint bigint::operator%(const char *num) const
{
    return *this % bigint(num);
}

/*
    String % bigint
    ---------------
*/

bigint operator%(const std::string &lhs, const bigint &rhs)
{
    return bigint(lhs) % rhs;
}

#endif // BIGINT_BINARY_ARITHEMARIC_FUNCTION

/*
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Arithmetic-assignment operators
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef BIGINT_ARITHEMATIC_OPERATORS
#define BIGINT_ARITHEMATIC_OPERATORS

/*
    bigint += bigint
    ----------------
*/

bigint &bigint::operator+=(const bigint &num)
{
    *this = *this + num;
    return *this;
}

/*
    bigint -= bigint
    ----------------
*/

bigint &bigint::operator-=(const bigint &num)
{
    *this = *this - num;
    return *this;
}

/*
    bigint *= bigint
    ----------------
*/

bigint &bigint::operator*=(const bigint &num)
{
    *this = *this * num;
    return *this;
}

/*
    bigint /= bigint
    ----------------
*/

bigint &bigint::operator/=(const bigint &num)
{
    *this = *this / num;
    return *this;
}

/*
    bigint %= bigint
    ----------------
*/

bigint &bigint::operator%=(const bigint &num)
{
    *this = *this % num;
    return *this;
}

/*
    bigint += Integer
    -----------------
*/

bigint &bigint::operator+=(const long long &num)
{
    *this = *this + bigint(num);
    return *this;
}

/*
    bigint -= Integer
    -----------------
*/

bigint &bigint::operator-=(const long long &num)
{
    *this = *this - bigint(num);
    return *this;
}

/*
    bigint *= Integer
    -----------------
*/

bigint &bigint::operator*=(const long long &num)
{
    *this = *this * bigint(num);
    return *this;
}

/*
    bigint /= Integer
    -----------------
*/

bigint &bigint::operator/=(const long long &num)
{
    *this = *this / bigint(num);
    return *this;
}

/*
    bigint %= Integer
    -----------------
*/

bigint &bigint::operator%=(const long long &num)
{
    *this = *this % bigint(num);
    return *this;
}

/*
    bigint += String
    ----------------
*/

bigint &bigint::operator+=(const std::string &num)
{
    *this = *this + bigint(num);
    return *this;
}

/*
    bigint += String(char*)
    -----------------------
*/

bigint &bigint::operator+=(const char *num)
{
    *this = *this + bigint(num);
    return *this;
}

/*
    bigint -= String
    ----------------
*/

bigint &bigint::operator-=(const std::string &num)
{
    *this = *this - bigint(num);
    return *this;
}

/*
    bigint -= String(char*)
    -----------------------
*/

bigint &bigint::operator-=(const char *num)
{
    *this = *this - bigint(num);
    return *this;
}

/*
    bigint *= String
    ----------------
*/

bigint &bigint::operator*=(const std::string &num)
{
    *this = *this * bigint(num);
    return *this;
}

/*
    bigint *= String(char*)
    -----------------------
*/

bigint &bigint::operator*=(const char *num)
{
    *this = *this * bigint(num);
    return *this;
}

/*
    bigint /= String
    ----------------
*/

bigint &bigint::operator/=(const std::string &num)
{
    *this = *this / bigint(num);
    return *this;
}

/*
    bigint /= String(char*)
    -----------------------
*/

bigint &bigint::operator/=(const char *num)
{
    *this = *this / bigint(num);
    return *this;
}

/*
    bigint %= String
    ----------------
*/

bigint &bigint::operator%=(const std::string &num)
{
    *this = *this % bigint(num);
    return *this;
}

/*
    bigint %= String(char*)
    -----------------------
*/

bigint &bigint::operator%=(const char *num)
{
    *this = *this % bigint(num);
    return *this;
}

#endif // BIGINT_ARITHEMATIC_OPERATORS

/*
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Increment and decrement operators
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef BIGINT_INCREMENT_DECREMENT_OPERATOR
#define BIGINT_INCREMENT_DECREMENT_OPERATOR

/*
    Pre-increment
    -------------
    ++bigint
*/

bigint &bigint::operator++()
{
    *this += 1;
    return *this;
}

/*
    Pre-decrement
    -------------
    --bigint
*/

bigint &bigint::operator--()
{
    *this -= 1;
    return *this;
}

/*
    Post-increment
    --------------
    bigint++
*/

bigint bigint::operator++(int)
{
    bigint temp = *this;
    *this += 1;
    return temp;
}

/*
    Post-decrement
    --------------
    bigint--
*/

bigint bigint::operator--(int)
{
    bigint temp = *this;
    *this -= 1;
    return temp;
}

#endif // BIGINT_INCREMENT_DECREMENT_OPERATOR

/*
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    I/O stream operators
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef BIGINT_IO_STREAM_OPERATORS
#define BIGINT_IO_STREAM_OPERATORS

/*
    bigint from input stream
    ------------------------
*/

std::istream &operator>>(std::istream &in, bigint &num)
{
    std::string input;
    in >> input;
    num = bigint(input); // remove sign from value and set sign, if exists
    return in;
}

/*
    bigint to output stream
    -----------------------
*/

std::ostream &operator<<(std::ostream &out, const bigint &num)
{
    if (num.sign == '-')
        out << num.sign;
    out << num.bigNumber;

    return out;
}

#endif // BIGINT_IO_STREAM_OPERATORS