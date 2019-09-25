
# railhubz
#### Build for Oprating Systems Course total rebuild in dev.
### Uses Message disspatcher, and enitity framwork, communcating Signalling to an operator gainign information from an indpendent hubsystem 
#### program uses, sfml lib for graphics.



## |_|Folderz|_|
### -[etcz]-
extra code and file bits on deisgn, and other conceptes and notes.
bunch of math stuff and some future concepts...

### -[sorce_railhubz]-

Contains updated sorcecode
complie for compleates (does nothing esle)
g++ -std=c++17  -Wall -Wextra -pedantic  main_test_01.cpp  trainz.cpp R_linez.cpp Base_TSym_entity.cpp railhubz.cpp   `sdl2-config --cflags --libs` -lSDL2_image -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -lGLU -lGL -lm -lglut

### -[OLDfilez]-
all the wold working files, tests
includez:

#### |{-dossairz-}|

#### base_class_and_functions_railHuhbz_v0.2
#### cmd_agent_sorce 	
#### odlervs 
#### sorce_workfiles_outdateddec5
#### test

last working example...
###### sorce_railhubz/test/newMain_testbuild_nov14.cpp
gcc Base_TSym_entity.cpp Cmd_agent_operator.cpp Defined_train_path.cpp R_linez.cpp Sym_Map.cpp
railhubz.cpp msg_dispatcher.cpp main_test_nov_5am.cpp
-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -lGLU -lGL -lm -lglut -L/usr/lib64 -lstdc++ -o outputfilenae

cmd_agent uses a que to scan hubs for avalable trains
the lines and trains communcate via a msg_dispatcher to calculate avalablity
train paths are hardcoded.(not that i ddi not try to get a*star working,...
the Cmd_agent_oprator. should create the nessary entties. and such.
currntly i'm having some segmetation fualt which appeared.. and seemly is proventing any progress

anywayz 
the program should complie.. in test.. however, for current  build is not yet finsh
as of sept 12th. 




