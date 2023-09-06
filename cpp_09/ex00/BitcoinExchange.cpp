#include "BitcoinExchange.hpp"
#include <iomanip>

void    BitcoinExchange::save_data(std::map<std::string, double> &mp)
{
    std::ifstream ifs("./data.csv");
    if (!ifs.is_open())
        throw std::runtime_error("Error: could not open file.");
    std::string s;
    getline(ifs, s);
    while (getline(ifs, s))
    {
        size_t f = s.find(',');
        std::string tmp = s.substr(0, f);
        mp[tmp] = atof(s.substr(f+1).c_str());
    }
}

bool    BitcoinExchange::is_value_good(std::string &s)
{
    bool dot = 0;
    for (int i = 0; s[i]; ++i)
    {
        if (!i && !isdigit(s[i]))
            return 0;
        if (s[i] == '.')
        {
            if (dot) return 0;
            dot = 1;
        }
        else if (!isdigit(s[i]))
            return 0;
    }
    return 1;
}

bool BitcoinExchange::isstr_digit(std::string &s, bool f, bool month)
{
    int i = 0;
    while (s[i])
    {
        if (!isdigit(s[i++])) return 0;
    }
    if (f && i != 2)
        return 0;
    if (f && month && !(s >= "01" && s <= "12"))
        return 0;
    else if (f && !month && !(s >= "01" && s <= "31"))
        return 0;
    return 1;
}

bool    BitcoinExchange::parse(std::string &s, std::list<std::string>& lst, std::map<std::string, double> &mp)
{
    if (lst.size() != 7)
    {
        std::cout << "Error : bad input => " << s << "\n";
        return 0;
    }
    std::list<std::string>::iterator it = lst.begin();
    size_t i = 0;
    for (;it != lst.end(); ++it, ++i)
    {
        switch (i)
        {
            case 0:
                if (!isstr_digit(*it, 0,0))
                    return 1;
            break;
            case 1:
                if (*it != "-")
                    return 1;
            break;
            case 2:
                if (!isstr_digit(*it, 1,1))
                    return 1;
            break;
            case 3:
                if (*it != "-")
                    return 1;
            break;
            case 4:
                if (!isstr_digit(*it, 1,0))
                    return 1;
            break;
            case 5:
                if (*it != " | ")
                    return 1;
            break;
            case 6:
                if (!is_value_good(*it))
                {
                    std::cout << "Error: not a positive number.\n";
                    return 0;
                }
            break;
        }
    }
    double dbl = atof((--lst.end())->c_str());
    if (dbl > 1000)   
    {
        std::cout << "Error: too large number\n";
        return 0;
    }
    
    it = lst.begin();    
    i = 0;
    while (i < it->size() && (*it)[i] == '0')
        ++i;
    std::string date = it->substr(i);
    size_t pos = mp.begin()->first.find('-');
    std::map<std::string, double>::iterator itm = mp.begin();
    if (date.length() < itm->first.substr(0, pos).length())
    {
        std::cout << s.substr(0, s.find(' ')) << " => " << *(--lst.end()) << " = " << "not found\n";
        return 0;
    }
    itm = --mp.end();
    pos = itm->first.find('-');
    if (date.length() > itm->first.substr(0, pos).length())
    {
        std::cout << s.substr(0, s.find(' ')) << " => " << *(--lst.end()) << " = "  << dbl * itm->second << "\n";
        return 0;
    }
    date = s.substr(i,s.find(' '));
    itm = mp.upper_bound(date);
    if (itm != mp.begin())
        itm--;
    std::cout << s.substr(0, s.find(' ')) << " => " << *(--lst.end()) << " = "  << dbl * itm->second << "\n";
    return 0;
}

void    BitcoinExchange::save_in_list(std::string &s, std::list<std::string> &answer, int l, bool flag)
{
    if (!s[l])
        return ;
    int i = l;
    if (flag)
    {
        i += s[i] == '-';
        while (isdigit(s[i]))
            i++;
        answer.push_back(s.substr(l, i - l));
    }
    else
    {
        while (!isdigit(s[i]) && (i-l) < 3)
            i++;
        answer.push_back(s.substr(l, i - l));
    }
    if (answer.size() == 6)
    {
        answer.push_back(s.substr(i));
        return ;
    }
    save_in_list(s, answer, i, flag ? 0 : 1);
}

void    BitcoinExchange::exec(std::string s)
{
    std::cout << std::fixed << std::setprecision(2);
    std::map<std::string, double> mp;
    save_data(mp);
    std::ifstream ifs(s.c_str());
    if (!ifs.is_open())
        throw std::runtime_error("Error: could not open file.");
    getline(ifs, s);
    if (s != "date | value")
        throw std::runtime_error("File must use the following format: date | value.");
    while (getline(ifs, s))
    {
		if (s.empty())
		{
			std::cout << "Error: bad input \n";
			continue;
		}
		
        std::list<std::string> lst;
        save_in_list(s, lst, 0, 1);
        if (parse(s, lst, mp))
             std::cout << "Error: bad input => " << s << "\n";
    }
}


BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& n){(void)n;}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange&n){(void)n; return *this;}
