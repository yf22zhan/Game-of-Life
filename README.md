# Game-of-Life

This is a Conway's Game of Life clone implemented in C++ with SFML.

I coded this on my own to better understand Game's Flow of Control and how a multimedia framework functions 
so that I can better appreciate when using a game enginer later.

It also helped me code better in C++.

Some key ideas in the project are: 
  - State Driven Game Design
  - UI and Logic Separation
  - Caching Font (Heavy Resource)
  - Event Interrupts Handling
  - Inheritance
  - Being More Modular

***Visual Studio Project Dependencies Setup***

Project Properties -> C/C++ -> Additional Include Directories -> $(ProjectDir)/include

Project Properties -> Linker -> Additional Library Directories -> $(ProjectDir)/lib

Project Properties -> Linker -> Input -> Additional Dependencies -> sfml-network-d.lib;sfml-audio-d.lib;sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;kernel32.lib;user32.lib;gdi32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;%(AdditionalDependencies)
