#include "generate.h"
#include <QRandomGenerator>

NameGenerator::NameGenerator()
{
    colorsList << "Red" << "Orange" << "Yellow" << "Green" << "Blue" << "Purple" << "Pink" << "Dark" << "Mat";
    namesList << "Alpha" << "Beta" << "Gamma" << "Delta" << "Epsilon" << "Zeta" << "Eta" << "Theta" << "Penta" << "Galaxy" << "Eclipse" << "Omega" << "Lose";
    specialNamesList << "Titan" << "Dragon" << "Phoenix" << "Valkyrie" << "Wizard" << "Samurai" << "Ninja" << "Hook" << "Hud" << "GUI" << "UI" << "Nano" << "Game" << "Never";
}

QString NameGenerator::generateName(bool useSpecialNames, bool includeColor, bool includeName, bool removeGap)
{
    QString outputText;

    if (useSpecialNames) {
        if (includeColor && includeName) {
            // Generate name with both color and special name
            QString color = colorsList.at(QRandomGenerator::global()->bounded(colorsList.size()));
            QString specialName = specialNamesList.at(QRandomGenerator::global()->bounded(specialNamesList.size()));
            QString classicName = namesList.at(QRandomGenerator::global()->bounded(namesList.size()));
            outputText = QString("%1 %2 %3").arg(color, specialName, classicName);
        }
        else if (includeColor) {
            // Generate name with color and special name
            QString color = colorsList.at(QRandomGenerator::global()->bounded(colorsList.size()));
            QString specialName = specialNamesList.at(QRandomGenerator::global()->bounded(specialNamesList.size()));
            outputText = QString("%1 %2").arg(color, specialName);
        }
        else if (includeName) {
            QString name = namesList.at(QRandomGenerator::global()->bounded(namesList.size()));
            QString specialName = specialNamesList.at(QRandomGenerator::global()->bounded(specialNamesList.size()));
            outputText = QString("%1 %2").arg(specialName, name);
        }
        else {
            // Generate name with special name only
            QString specialName = specialNamesList.at(QRandomGenerator::global()->bounded(specialNamesList.size()));
            outputText = specialName;
        }
    }

    else if (includeColor && includeName) {
        // Generate name with both color and name
        QString color = colorsList.at(QRandomGenerator::global()->bounded(colorsList.size()));
        QString name = namesList.at(QRandomGenerator::global()->bounded(namesList.size()));
        outputText = QString("%1 %2").arg(color, name);
    }
    else if (includeColor) {
        // Generate name with color only
        QString color = colorsList.at(QRandomGenerator::global()->bounded(colorsList.size()));
        outputText = color;
    }
    else if (includeName) {
        QString name = namesList.at(QRandomGenerator::global()->bounded(namesList.size()));
        outputText = name;
    }
    else {
        // Generate name with name only

        outputText = "Please check a box!";
    }

    // Remove gap if requested
    if (removeGap) {
        outputText.remove(" ");
    }

    return outputText;
}

