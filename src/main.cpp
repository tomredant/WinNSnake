#include <Engine/Flow/StateManager.hpp>
#include <Engine/Graphics/Ncurses.hpp>
#include <Engine/Helpers/Utils.hpp>
#include <Engine/EngineGlobals.hpp>
#include <Config/Globals.hpp>
#include <Config/Arguments.hpp>
#include <States/GameStateMainMenu.hpp>
#include <QTranslator>
#include <QCoreApplication>
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    QTranslator *translator = new QTranslator();
    QString language = "nl";
    QString translatorFile =(":/winnsnake_" + language + ".qm");
    translator->load(translatorFile);
    a.installTranslator(translator);
	try
	{
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


    return a.exec();
}

