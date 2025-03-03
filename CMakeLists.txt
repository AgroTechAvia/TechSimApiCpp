cmake_minimum_required(VERSION 3.10)
project(TechSimAPI)

# Добавьте библиотеку techsimapi
add_subdirectory(techsimapi)

# Добавьте все примеры
add_subdirectory(examples)

#git submodule init 
#git submodule update 
#mkdir build
#cd build
#cmake ..
#cmake --build .