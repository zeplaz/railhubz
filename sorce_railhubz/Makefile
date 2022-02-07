
.PhONY: all clean initdrectory


SOURCES = main_test_01.cpp system_org.cpp Base_TSym_entity.cpp Cmd_agent_v3Operaor.cpp drivers.cpp msg_dispatcher.cpp parser.cpp R_linez.cpp railhubz.cpp trainz.cpp

OBJECTS = $(SOURCES:.cpp=.o)
BINARY  = Rhub_debug00_01

LDFLAGS =  -lSDL2_image -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -lGLU -lGL -lm -lglut
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -pg


-include $(OBJECTS:.o=.d)
#Rhub_debug00_01: $(MAIN) $(SOURCES)
#	g++            $(MAIN) $(SOURCES) -o obj/$@


#	%.o: %.cpp
#	g++ -c $< -o $@


$(BINARY): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)


%.o: %.c
	gcc -c $(CFLAGS) $*.c -o $*.o
	gcc -MM $(CXXFLAGS) $*.cpp > $*.d $(LDFLAGS)
	@mv -f $*.d $*.d.tmp
	@sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d
	@cp -f $*.d $*.d.tmp
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmp



all: $(BINARY)

clean :
	rm -f $(BINARY) *.o *.d


initdrectory:
	rmdir obj
	mkdir obj
