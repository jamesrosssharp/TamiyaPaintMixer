#ifndef COLORLIST_H
#define COLORLIST_H

#include <vector>
#include <map>

#include <QColor>
#include <QString>

struct ColorDat {
    ColorDat(std::string _name, QColor _col)
    {
        name = QString(_name.c_str());
        col = _col;
    }

    QColor col;
    QString name;
};


class ColorList
{
public:
    ColorList();

    const std::vector<ColorDat>& colourTable() { return m_cols; }
    QColor colourOf(QString name) { return m_colMap.at(name.toStdString()); }

private:
    std::vector<ColorDat> m_cols;
    std::map<std::string, QColor> m_colMap;

    std::vector<std::string> m_stock;

};

#endif // COLORLIST_H
