# 🚀 Zysh

![Version](https://img.shields.io/badge/version-1.4.0--alpha-orange)
![License](https://img.shields.io/badge/license-MPL%202.0-green)
![C++](https://img.shields.io/badge/C++-20-blue)

> A modern Unix shell written in C++  
> *Status: Alpha (1.4.0-alpha)*

---

## 📖 Overview

Zysh is a work-in-progress Unix shell built from scratch in C++20.  
The main goal is to create a modular, maintainable, and extensible shell that stays compatible with classic Unix concepts while embracing modern development practices.

> ⚠️ This project is in early development — use with caution!

---
## 🆕 New Features (v1.4.0-alpha)

Here are the latest additions to Zysh:

 - 📂 **I/O Redirection** – Zysh now supports full input/output redirection:
  - `<`  – Redirect input from a file
  - `>`  – Redirect output to a file (overwrite)
  - `>>` – Redirect output to a file (append)
  - `2>` – Redirect standard error (overwrite)
  - `2>>` – Redirect standard error (append)
  - `1>&2` – Redirect standard output to standard error
- 🧹 **Cleaner Codebase** – Removed assembly files for better portability and maintainability across different architectures.

**Example Usage:**

```bash
# Redirect output to file
Zysh> echo Hello > output.txt
Zysh> cat output.txt
Hello

# Append output to file
Zysh> echo Another line >> output.txt
Zysh> cat output.txt
Hello
Another line

# Redirect input from file
Zysh> cat < input.txt
Content of input.txt

# Redirect errors
Zysh> ls /nonexistent 2> error.log
Zysh> cat error.log
ls: cannot access '/nonexistent': No such file or directory

# Redirect stdout to stderr
Zysh> echo Error message 1>&2
Error message
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

- ⚙️ **Lexer & Token system**  
- 📦 **Parser** 
- 🧱 **CMake-based build system**  
- ▶️ **Executor**
- 🧩 **Modular architecture for easy extension**
- 🏠 **Built-in commands**
- 🌀 **Pipe and chaining commands**
- 📂 **I/O Redirection**
---

## 🔮 Planned Features

- [x] Command execution engine  
- [x] Built-in commands 
- [x] Pipes (|)  
- [x] I/O redirection (>, <, >>)  
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
./build/Zysh_1_4_0_alpha 
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