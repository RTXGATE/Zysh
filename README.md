# 🚀 Zysh

![Version](https://img.shields.io/badge/version-1.5.0--alpha-orange)
![License](https://img.shields.io/badge/license-MPL%202.0-green)
![C++](https://img.shields.io/badge/C++-20-blue)

> A modern Unix shell written in C++  
> *Status: Alpha (1.5.0-alpha)*

---

## 📖 Overview

Zysh is a work-in-progress Unix shell built from scratch in C++20.  
The main goal is to create a modular, maintainable, and extensible shell that stays compatible with classic Unix concepts while embracing modern development practices.

> ⚠️ This project is in early development — use with caution!

---

## 🆕 New Features (v1.5.0-alpha)

Here are the latest additions to Zysh:

- 🔤 **Quote Support** – Zysh now handles single and double quotes:
  
  - Single quotes preserve the literal value of characters inside them.
  - Double quotes allow spaces and support escape sequences.

- ⚡ **Escape Character Support** – Backslash ("\") can be used to escape characters:
  - `"\\"` – Literal backslash
  - `"\""` – Literal double quote
  - `"\ "` – Literal space
  - Other escaped characters are preserved according to the current quoting context.

- 🔄 **Input Continuation** – Zysh supports multi-line input for incomplete commands, using a continuation prompt:
  - `"dquote>"` – Unterminated double quote
  - `"quote>"` – Unterminated single quote
  - `"escape>"` – Trailing escape character

**Example Usage:**

```bash
# Single quotes
Zysh> echo 'Hello $USER'
Hello $USER

# Double quotes
Zysh> echo "Hello world"
Hello world

# Escaped spaces
Zysh> echo hello\ world
hello world

# Input continuation
Zysh> echo "This is a very long
dquote> command that spans
dquote> multiple lines"
This is a very long
command that spans
multiple lines
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
- 🔤 **Quote support**
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
./build/Zysh_1_5_0_alpha
```
---

## 🚀 Usage Example

After building, run Zysh and try some commands:

```bash
./build/Zysh_1_5_0_alpha 
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