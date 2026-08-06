# 🚀 Zysh

![Version](https://img.shields.io/badge/version-1.3.0--alpha-orange)
![License](https://img.shields.io/badge/license-MPL%202.0-green)
![C++](https://img.shields.io/badge/C++-20-blue)

> A modern Unix shell written in C++  
> *Status: Alpha (1.3.0-alpha)*

---

## 📖 Overview

Zysh is a work-in-progress Unix shell built from scratch in C++20.  
The main goal is to create a modular, maintainable, and extensible shell that stays compatible with classic Unix concepts while embracing modern development practices.

> ⚠️ This project is in early development — use with caution!

---
## 🆕 New Features (v1.3.0-alpha)

Here are the latest additions to Zysh:

 - 🌀 **Pipe Support (`|`)** – Zysh now supports piping between commands. Chain multiple commands together where the output of one becomes the input of the next.
- ⚡ **Efficient Data Flow** – Built on Unix-style pipe semantics with proper process synchronization.

**Example Usage:**

```bash
Zysh> ls -la | grep ".md"
-rw-r--r-- 1 user user 1243 Aug 7 10:00 README.md
-rw-r--r-- 1 user user 2345 Aug 7 09:00 CONTRIBUTING.md

Zysh> echo "Hello World" | wc -c
12

Zysh> ps aux | grep zysh | wc -l
3

Zysh> ls | sort | head -5
CMakeLists.txt
LICENSE
README.md
build/
src/
```
---

## 🎯 Goals

- Build a modern Unix shell from scratch.
- Keep the architecture modular and extensible.
- Maintain compatibility with traditional Unix command execution.
- Experiment with new shell features while preserving performance.
- Explore alternative designs for common limitations in traditional Unix shells while maintaining compatibility.
---

## 🖥️ Supported Platforms

- Linux (x86_64)


## ✅ Current Features

- ⚙️ Lexer & Token system  
- 📦 Parser 
- 🧱 CMake-based build system  
- ▶️ **Executor**
- 🧩 Modular architecture for easy extension
- 🏠 **Built-in commands**
- 🌀 **Pipe and chaining commands**

---

## 🔮 Planned Features

- [x] Command execution engine  
- [x] Built-in commands 
- [x] Pipes (|)  
- [ ] I/O redirection (>, <, >>)  
- [ ] Environment variable support  
- [ ] Command history  
- [ ] Syntax highlight
- [ ] Auto-completion (TAB)  
- [ ] Scripting (.zys scripts)

---

## 🛠️ Build Instructions

```bash
# Configure the project
cmake -B build

# Build it
cmake --build build

# Run (after build)
./build/Zysh_1_3_0_alpha
```
---

## 🚀 Usage Example

After building, run Zysh and try some commands:

```bash
./build/Zysh_1_3_0_alpha 
Zysh> ls -la
Zysh> echo "Hello from Zysh!"
Zysh> pwd
Zysh> whoami
```

---

## 📜 License

This project is licensed under the Mozilla Public License 2.0.
See the [LICENSE](LICENSE) file for details.

---

## 🤝 Contributing

Contributions are welcome!
Feel free to open an issue or submit a pull request.

---

## 📬 Contact

Maintainer: RTXGATE(Taha salimkhani)

project: https://github.com/RTXGATE/Zysh

Email: rtxgate@gmail.com