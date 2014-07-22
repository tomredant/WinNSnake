#include <fstream>
#include "Ncurses.hpp" // intToString()
#include "BoardParser.hpp"

BoardParser::BoardParser()
{
    this->clear();
}
BoardParser::~BoardParser()
{ }
bool BoardParser::load(std::string filename)
{
    this->clear();

    this->filename = filename;

    std::ifstream file(this->filename.c_str());
    if (!(file.is_open()))
        return false;

//    if (!(file.good())) what does it do?

    std::string line(""); // current line we are parsing
    bool levelStarted(false); // tells if we're not parsing metadata
    unsigned int levelWidth(0);

    // Parsing each line of the file
    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        if ((line[0] == '#') && (!levelStarted))
            continue; // ignoring comments

        // Getting the level metadata.
        // Finding it's title and getting the string right after
        // it until the end of line.

        std::size_t pos = line.find("name=");
        if (pos != std::string::npos)
            this->name = line.substr(pos + 5, std::string::npos);

        pos = line.find("author=");
        if (pos != std::string::npos)
            this->author = line.substr(pos + 7, std::string::npos);

        pos = line.find("date=");
        if (pos != std::string::npos)
            this->date = line.substr(pos + 5, std::string::npos);

        pos = line.find("comment=");
        if (pos != std::string::npos)
            this->comment = line.substr(pos + 8, std::string::npos);

        // actual level parsing
        if (line == "start")
        {
            levelStarted = true;
            continue;
        }
        if (line == "end")
        {
            levelStarted = false;
            continue;
        }

        if (levelStarted)
        {
            this->rawBoardParser.push_back(line);

            if (line.length() > levelWidth) // maximum width
                levelWidth = line.length();

            // char-by-char level parsing
            std::vector<Tile::TileContents> levelLine;
            levelLine.clear();

            for (unsigned int i = 0; i < (line.size()); i++)
            {
                char c = line[i];

                switch (c)
                {
                    // multiple ways of defining borders
                case '+':
                case '-':
                case '|':
                    levelLine.push_back(Tile::BORDER);
                    break;

                case ' ':
                    levelLine.push_back(Tile::NOTHING);
                    break;

                case '#':
                    levelLine.push_back(Tile::WALL);
                    break;

                case '1':
                    // get snake starting position
                    this->startingPosition[0].x = i;

                    // Y of the current line is the rawBoardParser size
                    // minus 1 because we'll pretty soon add it to
                    // rawBoardParser and it's size will increase by 1.
                    this->startingPosition[0].y = (this->rawBoardParser.size() - 1);

                    levelLine.push_back(Tile::NOTHING);

                    // This map supports a player!
                    this->players++;
                    break;

                    // And now we repeat this for all the 4 supported players
                case '2':
                    this->startingPosition[1].x = i;
                    this->startingPosition[1].y = (this->rawBoardParser.size() - 1);
                    levelLine.push_back(Tile::NOTHING);
                    this->players++;
                    break;

                case '3':
                    this->startingPosition[2].x = i;
                    this->startingPosition[2].y = (this->rawBoardParser.size() - 1);
                    levelLine.push_back(Tile::NOTHING);
                    this->players++;
                    break;

                case '4':
                    this->startingPosition[3].x = i;
                    this->startingPosition[3].y = (this->rawBoardParser.size() - 1);
                    levelLine.push_back(Tile::NOTHING);
                    this->players++;
                    break;

                default:
                    // ignoring strange things, good for future
                    // versions.
                    levelLine.push_back(Tile::NOTHING);
                    break;
                }
            }

            // Adding the parsed line to the parsed level container
            this->level.push_back(levelLine);

        } // if (levelStarted)
    } // while (std::getline(file, line))

    if (!(file.eof())) // Finished reading due to some error
        return false;

    if ((this->players > MAX_NUMBER_OF_PLAYERS) ||
        (this->players < 1))
        return false;

    this->width  = levelWidth;
    this->height = this->rawBoardParser.size();

    // And now we fill the whole level until all the lines
    // have this->width.
    for (int i = 0; i < (this->height); i++)
        for (int j = 0; j < (this->width); j++)
            if (j > (this->level[i].size()))
                this->level[i].push_back(Tile::NOTHING);

    return true;
}
void BoardParser::clear()
{
    this->filename.clear();

    for (unsigned int i = 0; i < (this->rawBoardParser.size()); i++)
        this->rawBoardParser[i].clear();

    this->rawBoardParser.clear();

    for (unsigned int i = 0; i < (this->level.size()); i++)
        this->level[i].clear();

    this->level.clear();

    this->width  = 0;
    this->height = 0;

    this->players = 0;

    for (int i = 0; i < MAX_NUMBER_OF_PLAYERS; i++)
        this->startingPosition[i] = Point(1, 1); // by default starting the players at
                                                 // position (1, 1) on the level

    this->name.clear();
    this->author.clear();
    this->date.clear();
    this->comment.clear();
}
int BoardParser::getWidth()
{
    return (this->width);
}
int BoardParser::getHeight()
{
    return (this->height);
}
Tile::TileContents& BoardParser::at(int x, int y)
{
    if ((x < 0) || (x >= this->width) ||
        (y < 0) || (y >= this->height))
    {
        throw "BoardParser::at() Access to invalid index " +
            Ncurses::intToString(x) +
            ", " +
            Ncurses::intToString(y);
    }

    // we need to switch them because when we built the
    // level matrix we made it on reverse:
    // this->level[] is y
    // and
    // this->level[][] is x

    return (this->level[y][x]);
}
int BoardParser::getStartingX(int player)
{
    if (player >= MAX_NUMBER_OF_PLAYERS)
        return 0;

    return (this->startingPosition[player].x);
}
int BoardParser::getStartingY(int player)
{
    if (player >= MAX_NUMBER_OF_PLAYERS)
        return 0;

    return (this->startingPosition[player].y);
}
int BoardParser::getPlayers()
{
    return (this->players);
}
std::string BoardParser::getName()
{
    return (this->name);
}
