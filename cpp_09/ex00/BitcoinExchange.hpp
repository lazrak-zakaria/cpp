#ifndef BTC
#define BTC

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <list>
#include <cstdlib>

class BitcoinExchange
{
    private:
        static void    save_data(std::map<std::string, double> &mp);
        static bool    parse(std::string &s, std::list<std::string>& lst, std::map<std::string, double> &mp);
        static void    save_in_list(std::string &s, std::list<std::string> &answer, int l, bool flag);
        static bool    isstr_digit(std::string &s, bool f, bool month);
        static bool    is_value_good(std::string &s);

        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange& operator=(const BitcoinExchange&);
    public:
        static void    exec(std::string s);
};
#endif