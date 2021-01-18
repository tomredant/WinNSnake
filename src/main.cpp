#include <Engine/Flow/StateManager.hpp>
#include <Engine/Graphics/Ncurses.hpp>
#include <Engine/Helpers/Utils.hpp>
#include <Engine/EngineGlobals.hpp>
#include <Config/Globals.hpp>
#include <Config/Arguments.hpp>
#include <States/GameStateMainMenu.hpp>
#include <QTranslator>
#include <QApplication>
#include "showlicense.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QTranslator *translator = new QTranslator();
    QString language = "nl";
    QString translatorFile =(":/winnsnake_" + language + ".qm");
    translator->load(translatorFile);
    a.installTranslator(translator);

    std::vector<std::string> libs;
    libs.push_back("WinNSnake#" + QObject::tr("Original Game made by Alexandre Dantas,\n"
                                                                                         "contact him at <eu@alexdantas.net>\n"
                                                                                         "Dutch translation and Windows version by Tom Redant\n"
                                                                                         "\n"
                                                                                         "Source Code:\n"
                                                                                         " https://github.com/tomredant/WinNSnake/").toStdString() + "#gpl-3.0");
    libs.push_back("PDCurses##PDCurses");
    libs.push_back("Qt5.15.3#Source files can be obtained from http://www.qt.io.#lgpl-3.0");
    libs.push_back("MinGW-W64-builds-4.3.5##MinGW-w64");
    libs.push_back("libstdc++-6##gpl-3.0_runtime_exception");
    showLicenseDialog(libs);
    if(!waitLicenseDialogAccepted())
        return 0;

    try {
		// Settings
		EngineGlobals::init();
		Globals::init();
		Globals::loadFile();
		Arguments::parse(argc, argv);

		// Misc Initializations
		Utils::Random::seed();
		Ncurses::init();
		Colors::init();

		// Actually running the game
		StateManager states;
		states.run(new GameStateMainMenu());

		// Finishing things
		Globals::saveFile();
		Ncurses::exit();
		Globals::warnErrors();
	}
	catch (...)
	{
		// I dont really have a nice exception-handling scheme right
		// now. I must learn how to properly deal with them.
		Ncurses::exit();
		return 666;
	}

    return 0;
}

