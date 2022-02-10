#Compiler and Linker
CC          := clang++

#The Target Binary Program
TARGET      := main_test_01

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := source
INCDIR      := 3rd_party
BUILDDIR    := obj
TARGETDIR   := binaries
RESDIR      := res
SRCEXT      := cpp
DEPEXT      := d
OBJEXT      := o

#Flags, Libraries and Includes
CXXFLAGS      := -std=c++17 -Wall -Wextra -Wpedantic -pg -g
LIB         := -lSDL2_image -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -lGLU -lGL -lm -lglut
INC         := -I$(INCDIR) -I/usr/local/include
INCDEP      := -I$(INCDIR)

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
SOURCES     := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Defauilt Make
all: $(TARGET)

check_valg:
	@valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./$(TARGETDIR)/$(TARGET)

tidy:
	clang-tidy $(SOURCES) -checks=-*,clang-analyzer-*,-clang-analyzer-cplusplus*

#Remake
remake: cleaner all

#Copy Resources from Resources Directory to Target Directory
resources: directories
	@cp $(RESDIR)/* $(TARGETDIR)/

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

#Clean only Objecst
clean:
	@$(RM) -rf $(BUILDDIR)

#Full Clean, Objects and Binaries
cleaner: clean
	@$(RM) -rf $(TARGETDIR)

#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Link
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

#Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CXXFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp

#Non-File Targets
.PHONY: all remake clean cleaner resources