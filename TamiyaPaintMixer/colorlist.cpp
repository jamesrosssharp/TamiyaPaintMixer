#include "colorlist.h"

#include <iostream>
#include <fstream>

ColorList::ColorList()
{

    std::ifstream from("../cols.txt");
    std::string line;

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

        m_cols.emplace_back(name, shade);
        m_colMap.emplace(name, shade);
    }

}
