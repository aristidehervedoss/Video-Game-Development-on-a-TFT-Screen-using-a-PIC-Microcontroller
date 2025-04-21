# 🚀 Rocket Run

Rocket Run is a fast-paced 2D arcade-style game developed for the **dsPIC33EP512MU810** microcontroller, designed to run on a **320x240 TFT display**. Built entirely in C, this project was part of a university mini-project focused on embedded systems and microcontroller programming.

---

## 📖 About the Project

The player controls a character tasked with **dodging bombs** and **collecting falling items** like pizzas, pineapples, and coins. Each item collected increases the score, and the goal is to **reach 20 points before time runs out**. A single bomb ends the game, so reflexes and timing are key.

This project showcases:
- Low-level embedded C programming
- Real-time input handling via joystick
- Graphics rendering on a TFT display
- Timer-based game logic and animations

---

## 🎮 Features

- ⏱️ **Timer-based game loop** with interrupt handling
- 🕹️ **Joystick-controlled character movement**
- 🎯 **Randomized falling objects** with unique behaviors
- 💥 **Victory and defeat conditions** with custom end screens
- 🌌 **Animated scrolling background** to enhance gameplay
- 🧠 **Linear congruential generator (LCG)** for pseudo-random events

---

## 🧰 Tech Stack

| Component          | Details                                  |
|-------------------|-------------------------------------------|
| Microcontroller    | dsPIC33EP512MU810                        |
| Display            | TFT 320x240 LCD (Parallel 8-bit mode)    |
| Language           | C                                        |
| IDE                | MPLAB X IDE                              |
| Compiler           | XC16                                     |
| Image Processing   | Python + Jupyter Notebook (for sprite conversion) |

---

## 🛠️ Installation & Setup

### Prerequisites

- MPLAB X IDE (latest version)
- Microchip XC16 Compiler
- Python (for image processing scripts)
- TFT screen connected to the microcontroller
- Joystick input connected to GPIO pins

### Building the Project

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/rocket-run.git

2. Open the project in MPLAB X IDE.

3. Compile and upload the code to your dsPIC33EP512MU810 using a supported programmer/debugger.

4. Ensure the TFT screen and joystick are wired correctly (as per your board design).



### Screenshots


1. Game in Progress



![image](https://github.com/user-attachments/assets/42c06d1e-85ee-4ac5-be3c-4f9bb2ed981a)

2. Victory Screen



![image](https://github.com/user-attachments/assets/d6cab6ee-37bd-4039-ad05-8e5893a87fa9)

3. Defeat Screen




![image](https://github.com/user-attachments/assets/243dd63f-69eb-4d0a-956e-c4a16cfe932c)

4. Pause Screen



![image](https://github.com/user-attachments/assets/2f734b65-2aa3-4424-b0d2-6d28e826e869)

