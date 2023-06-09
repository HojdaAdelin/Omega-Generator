#include <QApplication>
#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include "Generator/generate.h"
#include <iostream>
#include "Generator/password.h"
#include <QLineEdit>
#include <QRandomGenerator>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Omega Generator");
    window.setFixedSize(400, 300); // make the window a little bigger
    window.setWindowFlag(Qt::MSWindowsFixedSizeDialogHint, true); // make window non-resizable

    // create the layout
    QGridLayout *layout = new QGridLayout(&window);
    QLabel *titleLabel = new QLabel("Omega Generator");
    QLabel *colorLabel = new QLabel("Include color");
    QLabel *nameLabel = new QLabel("Include name");
    QLabel *removeGapLabel = new QLabel("Remove gap");
    QLabel *specialNamesLabel = new QLabel("Special names");
    QCheckBox *colorCheckbox = new QCheckBox();
    QCheckBox *nameCheckbox = new QCheckBox();
    nameCheckbox->setChecked(true); // make the name checkbox checked by default
    QCheckBox *removeGapCheckbox = new QCheckBox();
    QCheckBox *specialNamesCheckbox = new QCheckBox();
    QPushButton *github = new QPushButton("Open GitHub");
    QPushButton *version = new QPushButton("Version");
    QPushButton *generateButton = new QPushButton("Generate");
    QPushButton *log = new QPushButton("Change log");
    QPushButton *passGenerator = new QPushButton("Password Generator");
    QTextEdit *outputText = new QTextEdit();
    // add the widgets to the layout
    layout->addWidget(titleLabel, 0, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(colorLabel, 1, 0);
    layout->addWidget(colorCheckbox, 1, 0, Qt::AlignCenter);
    layout->addWidget(nameLabel, 2, 0);
    layout->addWidget(nameCheckbox, 2, 0, Qt::AlignCenter);
    layout->addWidget(removeGapLabel, 3, 0);
    layout->addWidget(removeGapCheckbox, 3, 0, Qt::AlignCenter);
    layout->addWidget(specialNamesLabel, 4, 0);
    layout->addWidget(specialNamesCheckbox, 4, 0, Qt::AlignCenter);
    layout->addWidget(github, 1, 0, 1, 2, Qt::AlignRight);
    layout->addWidget(generateButton, 6, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(version, 2, 0, 1, 2, Qt::AlignRight);
    layout->addWidget(log, 3, 0, 1, 2, Qt::AlignRight);
    layout->addWidget(passGenerator, 4, 0, 1, 2, Qt::AlignRight);
    layout->addWidget(outputText, 7, 0, 1, 2);

    // connect the generate button to a slot function
    QObject::connect(generateButton, &QPushButton::clicked, [&]() {
        bool includeColor = colorCheckbox->isChecked();
        bool includeName = nameCheckbox->isChecked();
        bool removeGap = removeGapCheckbox->isChecked();
        bool includeSpecialNames = specialNamesCheckbox->isChecked();

        NameGenerator nameGenerator; // create an instance of the NameGenerator class
        QString projectName = nameGenerator.generateName(includeSpecialNames, includeColor, includeName, removeGap);

        outputText->setText(projectName);
    });

    QObject::connect(github, &QPushButton::clicked, [&](){
        string git = "https://github.com/HojdaAdelin/Name-Generator";
        system(string("start " + git).c_str());
    } );

    QObject::connect(version, &QPushButton::clicked, [&]() {
        QString n_version = "Version: BETA 1.0";
        outputText->setText(n_version);
    });

    QObject::connect(log, &QPushButton::clicked, [&]() {
        QString logs = "-Interface\n-Functions";
        outputText->setText(logs);
    });

    QObject::connect(passGenerator, &QPushButton::clicked, [&]() {

        outputText->setText(generate_random_string(16));
    });


    window.show();
    return app.exec();
}
