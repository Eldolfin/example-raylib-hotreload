BUILD_DIR = ./built
MAIN_EXECUTABLE = $(BUILD_DIR)/main
GUEST_DLL = $(BUILD_DIR)/plugin.dll
CLFAGS = -Wall -Wextra
LIBS = -lraylib

default: built $(GUEST_DLL)

$(MAIN_EXECUTABLE): src/hot_reload_host.cpp
	g++ $(CLFAGS) src/hot_reload_host.cpp $(LIBS) -o $(MAIN_EXECUTABLE)

$(GUEST_DLL): src/hot_reload_guest.c $(MAIN_EXECUTABLE)
	gcc $(CLFAGS) -shared src/hot_reload_guest.c -o $(GUEST_DLL)

run: $(MAIN_EXECUTABLE)
	$(MAIN_EXECUTABLE)

built:
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
