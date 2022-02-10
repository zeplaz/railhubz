
.PhONY: all clean cleaner initdrectory check_valg echoz
# modifed from   Chris Deon  and then Nicholas Hamilton using Scott McPeak.

#SOURCES = source/main_test_01.cpp source/libs/system_org.cpp source/libs/Base_TSym_entity.cpp source/libs/Cmd_agent_v3Operaor.cpp source/libs/drivers.cpp source/libs/msg_dispatcher.cpp source/libs/parser.cpp source/libs/R_linez.cpp source/libs/railhubz.cpp source/libs/trainz.cpp
CXX     = clang++
#OBJECTS = $(SOURCES:.cpp=.o)
#OBJECTS = $BJECTS
BINARY  = main_test_01

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := source
INCDIR      := 3rd_party
BUILDDIR    := obj
BINARYDIR   := binaries
#RESDIR      := res
SRCEXT      := cpp
DEPEXT      := d
OBJEXT      := o



LDFLAGS =  -lSDL2_image -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -lGLU -lGL -lm -lglut
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -pg -g

INC         := -I$(INCDIR) -I/usr/local/include
INCDEP      := -I$(INCDIR)

SOURCES     := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")



OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Rhub_debug00_01: $(MAIN) $(SOURCES)
#	g++            $(MAIN) $(SOURCES) -o obj/$@
#	%.o: %.cpp
#	g++ -c $< -o $@
#tidy:
#	@clang-tidy * -header-filter=.* **/*.cpp **/*.h

ehcoz: 
	echo ' "sourceinfO" $(SOURCES)' 
all: $(BINARY)
	


#Make the Directories
directories:
	@mkdir -p $(BINARYDIR)
	@mkdir -p $(BUILDDIR)

#Clean only Objecst
clean:
	@$(RM) -rf $(BUILDDIR)

#Full Clean, Objects and Binaries
cleaner: clean
	@$(RM) -rf $(BINARYDIR)

#clean :
#	rm -f $(BINARY) *.o *.d


initdrectory:
	rmdir obj
	mkdir obj


#-include $(OBJECTS:.o=.d)
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))






#$(BINARY): $(OBJECTS)
#	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)


$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<
	@$(CXX) $(CXXFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp


#linker
$(BINARY): $(Objects)
	$(CXX) -o $(BINARYDIR)/$(BINARY) $^ $(LDFLAGS)