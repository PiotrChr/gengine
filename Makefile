BUILD_FOLDER:=./build
CMAKE_MAC:=/usr/local/bin/cmake
CMAKE_DEB:=/usr/bin/cmake
TARGET_MAC:=-DTARGET_MAC=True
TARGET_WIN:=-DTARGET_WIN=True
TARGET_DEB:=-DTARGET_DEB=True
CMAKE_OPTIONS_MAC:=-DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++ ${TARGET_MAC} -B ./build/mac_x64/
CMAKE_OPTIONS_DEB:=-DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++ ${TARGET_DEB} -B ./build/deb_x64/ 
CMAKE_OPTIONS_WIN:=-DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++ ${TARGET_WIN} -B ./build/win_x64/
CMAKE_OPTIONS:=--no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -S ./ -G "Unix Makefiles"
CMAKE_BUILD_OPTIONS:=--config Debug --target all -j 14 --


default: make-all

make-all: make-mac_x64 make-deb_x64

make-mac_x64: config-mac_x64 build-mac_x64

make-deb_x64: config-deb_x64 build-deb_x64

config-all: config-mac_x64 config-deb_x64
	
config-mac_x64:
	${CMAKE_MAC} ${CMAKE_OPTIONS} ${CMAKE_OPTIONS_MAC}

config-deb_x64:
	${CMAKE_DEB} ${CMAKE_OPTIONS} ${CMAKE_OPTIONS_DEB}

build-all: build-mac_x64 build-deb_x64

build-mac_x64:
	${CMAKE_MAC} --build ${BUILD_FOLDER}/mac_x64 ${CMAKE_BUILD_OPTIONS}

build-deb_x64:
	${CMAKE_DEB} --build ${BUILD_FOLDER}/deb_x64 ${CMAKE_BUILD_OPTIONS}

# clean-all: clean-mac_x64 clean-deb_x64

# clean-mac_x64:
# 	${CMAKE_MAC} --clean ${BUILD_FOLDER}/mac_x64

# clean-deb_x64:
# 	${CMAKE_DEB} --clean ${BUILD_FOLDER}/deb_x64

install-all: install-mac_x64 install-deb_x64

install-mac_x64:
	${CMAKE_MAC} --install 

install-deb_x64:
	${CMAKE_DEB} --install 

qs:
	git add -A && git commit -m "sync" && git push origin HEAD