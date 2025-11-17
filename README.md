# 🐧 Project: Linux Kernel Loadable Module (LKM) Rootkit

## Introduction and Objective

This repository hosts a highly technical **Proof-of-Concept (PoC)** for an Advanced Linux Loadable Kernel Module (LKM) Rootkit, developed in **C**. Its primary goal is to simulate sophisticated **persistence and evasion techniques** by operating within the **Kernel Space**.

This module intercepts core Operating System functions to manipulate the information presented to user-space tools (like `ls` or `ps`), demonstrating how adversaries can achieve stealth against traditional monitoring and forensic utilities.

---

## ⚙️ Core Technical Features

This project showcases mastery of low-level systems programming and evasion:

| Feature | Kernel Mechanism Utilized | Value Demonstrated |
| :--- | :--- | :--- |
| **System Call Hooking** | Direct manipulation of the **`sys_call_table`**. | Mastery of **Kernel Memory Manipulation** and **Function Interception** logic. |
| **Write Protection Bypass** | Kernel-level manipulation of the **CR0 Control Register** flags. | Ability to temporarily disable the CPU's Write Protection required for modifying the call table. |
| **Process/File Hiding** | Interception of `sys_getdents64`. | Filters out directory entries (processes, files, or folders) matching a **secret signature** before they are returned to the user. |
| **Module Self-Hiding** | Logic to remove the LKM's entry from the kernel's internal list and `/proc/modules`. | Demonstrates stealth against basic kernel integrity checks. |
| **Covert C2 Channel** | Implementation using **Netfilter Hooks (`nf_hook_ops`)**. | Establishes a command-and-control channel by listening for **ICMP "magic packets"** without creating a visible socket. |

---

## 🔬 Skills & Value Proposition

This project is a powerful demonstration of skills highly sought after in advanced security roles:

* **Low-Level Programming:** Deep command of the **C language** for system-level programming.
* **Operating System Architecture:** Proven understanding of the Linux kernel structure, memory management, and system call execution flow.
* **Offensive Security Engineering:** Practical experience in developing **sophisticated evasion techniques** that bypass user-space security controls and EDR solutions.

---

## ⚠️ Ethical Disclaimer

This is a **Security Research and Proof-of-Concept (PoC) tool** intended solely for educational and defensive analysis purposes.

**It must be compiled and tested only within isolated virtual environments** for which the user has explicit legal authorization. The module includes robust cleanup logic in the `module_exit` function to fully restore all system calls and integrity mechanisms upon removal.

---

## 📜 License

This project is licensed under the **MIT License**. See the `LICENSE` file for details.

