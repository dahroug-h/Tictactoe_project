# Tictactoe_project
Tictactoe_project
# 🎮 TicTacBoom - Qt GUI Tic Tac Toe Game

![CI](https://github.com/dahroug-h/Tictactoe_project/actions/workflows/qt.yml/badge.svg)

A modern, GUI-based Tic Tac Toe game built with **Qt (C++)**, featuring:
- Classic 2-player mode
- Player profiles & sign-in
- Game statistics and history
- Unit tests using Qt Test Framework

---

## 🚀 Features

- 🎨 Beautiful user interface with `Qt Widgets`
- 👥 Login & signup system
- 🧠 Choose difficulty levels
- 🕘 Game history tracking (view previous matches & outcomes)
- 📊 Track your wins/losses
- ✅ Automated unit testing using GitHub Actions

---

## 🧪 Running the Unit Tests
TicTacToe_Game/
│
├── Qt_2/
│   ├── TicTacBoom.pro         # Main GUI app
│   ├── (source files for GUI)
│   └── test/
│       └── test/
│           └── Qttest/
│               ├── Qttest.pro
│               └── MyQttest  # Unit tests

If you're cloning the project and want to run tests locally:


```bash
# Clone the repository
git clone https://github.com/dahroug-h/Tictactoe_project.git
cd YOUR_REPO_NAME

# Build the game
cd Qt_2
qmake TicTacToe.pro
make
