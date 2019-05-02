
# railhubz
### Build for Oprating Systems Course

#### program uses, sfml lib for graphics.

## |_|Folderz|_|

### -[etcz]-
extra code and file bits on deisgn, and other conceptes and notes.

### -[sorce_railhubz]-

Contains all sorcecode and other older builds and work related to program.

###### most recent Main:
###### sorce_railhubz/test/newMain_testbuild_nov14.cpp

### |{-dossairz-}|

#### base_class_and_functions_railHuhbz_v0.2
#### cmd_agent_sorce 	
#### odlervs 
#### railhubz_0.07.2
#### test



cmd_agent uses a que to scan hubs for avalable trains
the lines and trains communcate via a msg_dispatcher to calculate avalablity
train paths are hardcoded.(not that i ddi not try to get a*star working,...
the Cmd_agent_oprator. should create the nessary entties. and such.
currntly i'm having some segmetation fualt which appeared.. and seemly is proventing any progress

anywayz 
the program should complie.. 
gcc Base_TSym_entity.cpp Cmd_agent_operator.cpp Defined_train_path.cpp R_linez.cpp Sym_Map.cpp
railhubz.cpp msg_dispatcher.cpp main_test_nov_5am.cpp
-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -lGLU -lGL -lm -lglut -L/usr/lib64 -lstdc++ -o outputfilenae

