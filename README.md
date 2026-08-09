# 🚀 Zysh

![Version](https://img.shields.io/badge/version-1.6.0--alpha-orange)
![License](https://img.shields.io/badge/license-MPL%202.0-green)
![C++](https://img.shields.io/badge/C++-20-blue)

> A modern Unix shell written in C++  
> *Status: Alpha (1_6_0-alpha)*

---

## 📖 Overview

Zysh is a work-in-progress Unix shell built from scratch in C++20.  
The main goal is to create a modular, maintainable, and extensible shell that stays compatible with classic Unix concepts while embracing modern development practices.

> ⚠️ This project is in early development — use with caution!

---

## 🆕 New Features (v1_6_0-alpha)

Here are the latest additions to Zysh:

- 🔤 **Advanced Word Parsing** – Zysh now handles quoted and unquoted word segments with proper context preservation during lexing:
  - Single-quoted strings (`'...'`) – Preserve literal value of every character
  - Double-quoted strings (`"..."`) – Allow escape sequences and variable expansion
  - Quote context tracking – Each word segment retains its quote information during parsing
- ⚡ **Escape Sequences** – Full support for common escape sequences inside and outside quotes:
  - `\a` – Alert / Bell ( on work )
  - `\b` – Backspace
  - `\f` – Form feed
  - `\n` – Newline
  - `\r` – Carriage return
  - `\t` – Horizontal tab
  - `\v` – Vertical tab
  - `\\` – Backslash
  - `\'` – Single quote
  - `\"` – Double quote

**Example Usage:**

```bash
# Newline and tab escapes
Zysh> echo "hello\nworld"
hello
world

Zysh> echo "hello\tworld"
hello   world

# Multiple escapes combined
Zysh> echo "Line1\nLine2\tTabbed"
Line1
Line2    Tabbed

# Quote characters inside strings
Zysh> echo "She said \"Hello!\""
She said "Hello!"

Zysh> echo 'It\'s a beautiful day'
It's a beautiful day
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
./build/Zysh_1_6_0_alpha
```
---

## 🚀 Usage Example

After building, run Zysh and try some commands:

```bash
./build/Zysh_1_6_0_alpha 
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