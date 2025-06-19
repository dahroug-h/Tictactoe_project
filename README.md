# Tictactoe_project
Tictactoe_project
# 🎮 TicTacBoom - Qt GUI Tic Tac Toe Game

![CI](https://github.com/dahroug-h/Tictactoe_project/actions/workflows/qt.yml/badge.svg)

A modern, GUI-based Tic Tac Toe game built with **Qt (C++)**, featuring:
- Classic 2-player mode
- Player profiles & sign-in
- Game statistics and history
- Unit tests using Qt Test Framework

-------------------------
## Team members:

  - Hassan Dahrog(Leader)
  - Hassan Ehab
  - Ahmed Saber
  - Hesham Selim
  - Mahmoud Matar
-------------------------
## 🚀 Features

- 🎨 Beautiful user interface with `Qt Widgets`
- 👥 Login & signup system
- 🧠 Choose difficulty levels
- 🕘 Game history tracking (view previous matches & outcomes)
- 📊 Track your wins/losses
- ✅ Automated unit testing using GitHub Actions

---

## 📁 Project Structure
```text
TicTacToe_Game/
│
├── Qt_2/
│   ├── TicTacToe.pro          # Main GUI app
│   ├── *.cpp / *.h / *.ui     # Game source files (GUI, logic, etc.)
│   └── test/
│       └── test/
│           └── Qttest/
│               ├── Qttest.pro
│               └── MyQttest  # Unit test executable
```
If you're cloning the project and want to run tests locally:


```bash
# Clone the repository
git clone https://github.com/dahroug-h/Tictactoe_project.git
cd YOUR_REPO_NAME

# Build the game
cd Qt_2
qmake TicTacToe.pro
make
