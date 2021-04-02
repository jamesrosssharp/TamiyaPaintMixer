#include "colorlist.h"

#include <iostream>
#include <fstream>

ColorList::ColorList()
{
    std::string line;

    // Load stock list

    std::ifstream stock("../stock.txt");

    if (!stock.is_open())
        throw std::runtime_error("Could not open stock list");

    while (getline(stock, line))
    {
        m_stock.push_back(line);
    }

    std::ifstream from("../cols.txt");

    if (!from.is_open())
        throw std::runtime_error("Could not open colors database");

    while(getline(from, line))
    {
        //std::cout << line << std::endl;

        std::string name = line.substr(0, line.find(":"));
        std::cout << name << std::endl;
        std::string col = line.substr(line.find(":")+1, -1);
        col.erase(0, col.find_last_of(" \t") + 1);
        col.erase(col.find_last_not_of(" \t") + 1);
        std::cout << col << std::endl;

        QColor shade = QColor(QString(col.c_str()));

        bool inStock = false;
        for (const std::string& s: m_stock)
        {
            std::string subs = name.substr(0, name.find_first_of(" \t"));
            printf("%s ==? %s\n", subs.c_str(), s.c_str());
            fflush(0);
            if (subs == s)
            {
                inStock = true;
                break;
            }
        }

        if (inStock)
            name = name + " * ";

        m_cols.emplace_back(name, shade);
        m_colMap.emplace(name, shade);
    }

    from.close();
}
