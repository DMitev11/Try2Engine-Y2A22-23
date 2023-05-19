cd engine/libraries/SDL
cmake -DCMAKE_CXX_FLAGS=-m64 -DCMAKE_SHARED_LINKER_FLAGS=-m64 -S . -B ./build
cmake --build ./build --config Release
cmake --install ./build --prefix ./install --config Release
cd ../SDL_Image
cmake -DCMAKE_CXX_FLAGS=-m64 -DCMAKE_SHARED_LINKER_FLAGS=-m64 -DSDL3_DIR=../SDL/install/cmake/ -S . -B ./build
cmake --build ./build --config Debug 
cmake --install ./build --prefix ./install --config Release