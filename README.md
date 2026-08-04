# 🚀 Zysh

![Version](https://img.shields.io/badge/version-1.2.0--alpha-orange)
![License](https://img.shields.io/badge/license-MPL%202.0-green)
![C++](https://img.shields.io/badge/C++-20-blue)

> A modern Unix shell written in C++  
> *Status: Alpha (v1.2.0-alpha)*

---

## 📖 Overview

Zysh is a work-in-progress Unix shell built from scratch in C++20.  
The main goal is to create a modular, maintainable, and extensible shell that stays compatible with classic Unix concepts while embracing modern development practices.

> ⚠️ This project is in early development — use with caution!

---
## 🆕 New Features (v1.2.0-alpha)

Here are the latest additions to Zysh:

- 🏠 **Built-in Commands** – Zysh now supports internal commands:
  - `exit` – Exit the shell
  - `cd` – Change directory
  - `export` – Set environment variables (viewable with `printenv`)
  - `unset` – Remove environment variables
- 💬 **Simple Prompt** – Clean and minimal command prompt for better user experience

**Example Usage**

```bash
Zysh> export MYVAR="hello"
Zysh> printenv MYVAR
hello
Zysh> unset MYVAR
Zysh> printenv MYVAR
(no output)
Zysh> cd /tmp
Zysh> pwd
/tmp
Zysh> exit
Exiting Zysh shell![returned 0]
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
- 📦 Basic Parser 
- 🧱 CMake-based build system  
- ▶️ **Executor**
- 🧩 Modular architecture for easy extension
- 🏠 **Built-in commands**

---

## 🔮 Planned Features

- [x] Command execution engine  
- [x] Built-in commands 
- [ ] Pipes (|)  
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
./build/Zysh_1_2_0_alpha
```
---

## 🚀 Usage Example

After building, run Zysh and try some commands:

```bash
./build/Zysh_1_2_0_alpha 
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