cmake_minimum_required(VERSION 3.20)

project(Zysh LANGUAGES CXX ASM_NASM)

set(CMAKE_CXX_STANDARD 20)

add_executable(
	Zysh_1_1_0_alpha
	src/main.cpp
	src/Shell.cpp
	src/built-in/builtin.cpp
	src/lexer/Lexer.cpp
	src/parser/Parser.cpp
	src/executor/Executor.cpp
	src/ASM_src/prt_str.asm
	src/ASM_src/input_str.asm
)
target_include_directories(Zysh_1_1_0_alpha PRIVATE
	src
)
