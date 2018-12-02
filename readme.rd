program uses, sfml lib for graphics.
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

