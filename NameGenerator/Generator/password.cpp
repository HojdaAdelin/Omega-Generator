#include "password.h"
#include <QString>
#include <QRandomGenerator>

QString generate_random_string(int length) {
    QString random_string;
    for (int i = 0; i < length; ++i) {
        int random_ascii = QRandomGenerator::global()->bounded(48, 123); // ASCII values for 0-9, a-z
        if (random_ascii >= 58 && random_ascii <= 96) {
            --i; // re-generate if the character is not a digit or lowercase letter
        }
        else {
            random_string.append(QChar(random_ascii));
        }
    }
    return random_string;
}
