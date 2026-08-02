cmake_minimum_required(VERSION 3.20)

project(Zysh LANGUAGES CXX ASM_NASM)

set(CMAKE_CXX_STANDARD 20)

add_executable(
	Zysh
	src/main.cpp
	src/Shell.cpp
	src/lexer/Lexer.cpp
	src/parser/Parser.cpp
	src/executor/Executor.cpp
	src/ASM_src/prt_str.asm
	src/ASM_src/input_str.asm
)
target_include_directories(Zysh PRIVATE
	src
)
