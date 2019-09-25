
# railhubz
#### Base was build for a Oprating Systems Course However as of 2019 total REFACTOR! in devevloment for personal growth.
### Uses Message dispatcher, facotry patterns, a simple xml Parser to dynamicly load data, a enitity framwork, to communcating Signalling to an operator gain information from an indpendent hubsystem 

#### program uses, sfml lib for graphics. not included!


## |_|Folderz|_|

### -[sorce_railhubz]-

Contains updated sorcecode
complies current with parser and baisc hub raillinez no functionaly byound.

test compilez using {you may remove unessary flags, -pg is used to profile, and wall etc to just give more info}

g++ -std=c++17  -Wall -Wextra -pedantic -pg   main_test_01.cpp  trainz.cpp R_linez.cpp Base_TSym_entity.cpp railhubz.cpp system_org.cpp  parser.cpp  drivers.cpp msg_dispatcher.cpp `sdl2-config --cflags --libs` -lSDL2_image -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -lGLU -lGL -lm -lglut

### -[etcz]-
extra code and file bits on deisgn, and other conceptes and notes.
bunch of math stuff and some future concepts...

### -[OLDfilez]-
all the wold working files, tests
includez:
#### |{-dossairz-}|

#### base_class_and_functions_railHuhbz_v0.2
#### cmd_agent_sorce 	
#### odlervs 
#### sorce_workfiles_outdateddec5
#### test

OLD "working" example...has some fun bizzar behavour!
###### sorce_railhubz/test/newMain_testbuild_nov14.cpp
gcc Base_TSym_entity.cpp Cmd_agent_operator.cpp Defined_train_path.cpp R_linez.cpp Sym_Map.cpp
railhubz.cpp msg_dispatcher.cpp main_test_nov_5am.cpp
-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -lGLU -lGL -lm -lglut -L/usr/lib64 -lstdc++ -o outputfilenae

cmd_agent uses a que to scan hubs for avalable trains
the lines and trains communcate via a msg_dispatcher to calculate avalablity
train paths are hardcoded..for time being though future may see pathfidning algrthems used.
the Cmd_agent_oprator deals with trainsz.





