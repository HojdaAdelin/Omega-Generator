#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <QStringList>

class NameGenerator
{
public:
    NameGenerator();

    QString generateName(bool useSpecialNames, bool includeColor, bool includeName, bool removeGap);

private:
    QStringList colorsList;
    QStringList namesList;
    QStringList specialNamesList;
};

#endif // NAMEGENERATOR_H
