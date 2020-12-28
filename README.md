# WinNSnake

Classic snake game on the Windows terminal; made with C++ and curses. It is based on NSnake, to which it is for more than 99.9 percent identical. Only a few modifications had to be done to make it work for Windows.

`WinNSnake` is a clone of the classic snake game that we all used to
play on our cellphones. You play this game on the terminal,
with textual interface.

Here's some features:

* Customizable gameplay, appearance and key bindings
* GUI-like interface with nice animations
* Levels - create your own [easily][level_wiki];
* Lots of possible game modes; teleport, scroll map, random walls,
  etc. Scores are saved for each setting.

## Controls

The keybindings are completely customizable on the in-game menus.
The default ones are:

| Keys              | Actions                    |
| ----------------- | -------------------------- |
| Arrow Keys        | Moves the snake            |
| q                 | Quits the game at any time |
| p                 | Pauses/Unpauses the game   |
| h                 | Show help during game      |

All user settings are located at `~/.local/share/nsnake`. (to be checked if this is still the case for WinSnake).

## Levels

nSnake looks out for level files on `~/.local/share/nsnake/levels`. By default
it installs stock levels on `/usr/share/games/nsnake/levels`, so make sure to
copy them before playing. (to be checked if this is still the case for WinSnake).

Levels have a `.nsnake` extension and are simple text files.  The file
format is very easy to edit; check out [the wiki][level_wiki] for a quick guide. (to be checked if this is still the case for WinSnake).

## Dependencies

WinNSnake only depends on `PDCurses`; it's used to show cute things on the terminal.

Make sure you have downloaded and compiled PDCurses by means with its default settings.

## Installation

You may first have to make sure all path variables are set accordingly to make sure the toolchain and qmake executable is found.  Furthermore, edit the WinNSnake.pro file (last two lines of the file), pointing to the directory in which PDCurses is installed.
Briefly, the following shell commands should configure,
and build this package:

    $ qmake
    $ make

Further reading on the version on which this is based: 

Check file `INSTALL.md` for more info.

## Contact

Here is a message from the original developer of NSnake:

Hello there, I'm Alexandre Dantas (kure)!

Thanks for downloading and playing this game, I'm very glad you had
interest on this humble project.

You can send me comments, bugs, ideas or anything else by email.
And if you have time, please visit my blog!

* My email:      <eu@alexdantas.net>
* My homepage:   http://alexdantas.net/
* Mu blog:       http://alexdantas.net/stuff

I'd appreciate any commentary - even if it's
just _"Hello, I play your game!"_.

## Links

Some interesting links if you're interested on nsnake:

* [nSnake homepage][home]
* [Up-to-date nsnake news][news] ([RSS feed][rss])

Also, it's all over the web!

* [Source on GitHub][github]
* [Source on Bitbucket][bitbucket]
* [Source on Sourceforge][sourceforge]
* [Source on Google Code][googlecode]
* [Source on Gitcafe][gitcafe]
* [Package on Debian](https://tracker.debian.org/pkg/nsnake)
* [Package on Fedora](https://apps.fedoraproject.org/packages/nsnake)
* [Package on Arch Linux (AUR)](https://aur.archlinux.org/packages/nsnake/)
* [Package on Slackware (SlackBuilds)](http://slackbuilds.org/repository/14.1/games/nSnake/)

## Credits
I want to credit Mr. Alexandre Dantas. Here is a message from him, taken from the original NSnake project.

Firstly, I'd like to thank you for playing this game.
Hope you liked it!

The game was mainly done by me, but a lot of people helped me in
many ways. There's a list of them on the `AUTHORS` file, and you
can see people's [contributions to the code here][contrib].

Throughout the nsnake development, I found very interesting sources
of ideas; small games made in C, textual games with ncurses, and
stuff like that.

I raise my hat to:

* *nInvaders*: A space invaders-like game using ncurses.
  * homepage: http://ninvaders.sourceforge.net
  * comments: "Thanks for the inspiration. If I haven't installed
               this in first place, I'd never have the idea
			   for nsnake"

* *pacman4console*: A console-based pacman game.
  * homepage:  http://doctormike.googlepages.com/pacman.html
  * comments:  "The way this package was organized
                    is incredible. Thanks for the
                    general packaging ideas"

* *vadorz*: An addicting ncurses space-invaders game.
  * homepage: http://code.google.com/p/vadorz/
  * comments: "This package is awesome, 'cause it uses ncurses
               AND pdcurses to be able to play in Windows and
			   GNU/Linux"

* *snake4*: Fruit-eating snake game
  * homepage: http://shh.thathost.com/
  * comments: "Thanks for the Makefile ideas. It's
               very well-written."

* *ASCII Generator*: A generator of awesome ASCII text arts
  * homepage:  http://www.network-science.de/ascii/

* *Text ASCII Art Generator*: Another awesome ASCII text generator
  * homepage:  http://patorjk.com/software/taag/
  * comments:  "I've used the Modular font to display
                the Game Over screen"

## License


 WinNSnake is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.
 
 nsnake, on which WinNSnake is based is also free software.
 
 nsnake - The classic snake game with ncurses.
 Copyright (C) 2011,2014  Alexandre Dantas

 nsnake is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 homepage: http://www.alexdantas.net/projects/nsnake/
 mailto:   eu@alexdantas.net

[issues]:      https://github.com/alexdantas/nSnake/issues
[github]:      https://github.com/alexdantas/nsnake
[bitbucket]:   https://bitbucket.org/alexdantas/nsnake
[sourceforge]: https://sourceforge.net/projects/nsnake/
[gitcafe]:     https://gitcafe.com/alexdantas/nsnake
[googlecode]:  http://code.google.com/p/nsnake/
[contrib]:     https://github.com/alexdantas/nSnake/graphs/contributors
[level_wiki]:  https://github.com/alexdantas/nSnake/wiki/How-to-create-your-own-levels

