# RACKlette Recruiting Task

Welcome to Team RACKlette's recruiting challenge!

We are a student HPC team at ETH Zurich working on high-performance
computing, parallel programming, and system optimization. This small
task gives you a first taste of the concepts we work with -- and helps
us see that you are curious and motivated enough to follow through.

It should take **10-20 minutes**. No prior HPC knowledge needed.

---

## Prerequisites

You need **Git**, a **C compiler**, and **make**. Check if they are
already installed by opening a terminal and running:

```
git --version
gcc --version
make --version
```

> **How to open a terminal:**
> - **macOS:** press `Cmd + Space`, type *Terminal*, hit Enter
> - **Linux:** press `Ctrl + Alt + T`, or search for *Terminal* in your apps
> - **Windows:** install [WSL](https://learn.microsoft.com/en-us/windows/wsl/install)
>   (Windows Subsystem for Linux), then open the *Ubuntu* app it provides.
>   All commands below are then run inside that Ubuntu terminal.

If any of the version commands fail, install the missing tools:

| OS | Command |
|----|---------|
| Ubuntu / Debian (incl. WSL) | `sudo apt install git build-essential` |
| macOS | `xcode-select --install` (installs git, gcc, and make in one go) |
| Fedora / RHEL | `sudo dnf install git gcc make` |

---

## Step-by-step instructions

### Step 1 — Clone the repository

In your terminal, navigate to a folder where you want to keep the task
(e.g. your home directory or Desktop), then clone the repo:

```
cd ~
git clone <repo-url>
cd <repo-name>
```

You are now inside the project folder. All subsequent commands should
be run from this same folder.

> **Tip:** you can confirm you are in the right place by running `ls`.
> You should see `task.c` and `Makefile` listed.

---

### Step 2 — Read `task.c`

Open `task.c` in any text editor — for example:

```
# macOS / Linux
open task.c          # opens in your default editor on macOS
nano task.c          # simple terminal editor on Linux/macOS/WSL
```

Or just open it with VS Code, Notepad++, or whatever editor you prefer.

Read the comment block at the top of the file. It explains what the
program does and gives you a direct hint for solving it.

---

### Step 3 — Edit `task.c`

Find the line that says:

```c
#define TILE_SIZE 1    /* <-- change this */
```

Replace `1` with the value you think is correct (the hint in the file
tells you how to figure it out). Save the file.

---

### Step 4 — Compile

Back in your terminal (make sure you are still in the project folder), run:

```
make
```

This compiles `task.c` into an executable called `task`. If you see
`Build successful!` you are ready for the next step. If you see an
error, double-check that you saved the file and that `gcc` is installed.

---

### Step 5 — Run the program

```
./task
```

The `./` tells your terminal to run the `task` file that is in the
current folder (as opposed to searching for a system command called `task`).

The program will print your checksum and compare it to the magic value.

---

### Step 6 — Iterate until it matches

If the checksums do not match, go back to **Step 3**, try a different
value for `TILE_SIZE`, save, and repeat from **Step 4**. There are only
a handful of valid options — you will get there quickly.

When the checksum matches, the program prints the interview sign-up link.
Follow it to book your interview slot. Good luck!

---

## Troubleshooting

**`make: command not found`** — install the prerequisites listed above.

**`./task: Permission denied`** — run `chmod +x ./task` and try again.

**`make` succeeds but the program crashes** — make sure `TILE_SIZE`
evenly divides 64 (the matrix size). Valid values: 1, 2, 4, 8, 16, 32, 64.

**Nothing changes after editing** — make sure you saved the file before
running `make`. `make` will only recompile if the file has changed.

---

*-- Team RACKlette*
