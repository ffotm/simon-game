# Simon Game

The **Simon Game** is a simple memory-based web/Robotics game where players must repeat an increasingly long sequence of colors and sounds. It tests focus, memory, and reflexes — all within an engaging and minimal interface.

## Features

- Interactive color buttons with sound feedback

- Random sequence generation for each new round

- Increasing difficulty as the sequence grows

- Game-over alert and reset functionality

- Responsive and lightweight design using HTML, CSS, and JavaScript also with a Robotics version 

## Project Structure

```
SimonGame/
│
├── index.html        # Main game interface
├── style.css         # Game styling and layout
├── script.js         # Core game logic (sequence generation and event handling)
├── rs.ino            # hardware code 
└── sounds/           # Audio files for each color (optional)
```

## How It Works

1. Press any key or the start button to begin the game.

2. Watch the sequence of highlighted colors.

3. Repeat the sequence by clicking the colors in the same order.

4. Each successful round adds one more color to the sequence.

5. A wrong input ends the game — press start to try again.

## Technologies Used

- HTML5 — structure

- CSS3 — design and animation

- JavaScript (ES6) — logic and interactivity

- C++ — hardware logic code

## Future Improvements

- Add difficulty modes (easy, medium, hard)

- Save high scores using localStorage

- Add sound toggle and theme switcher

## Installation & Usage

1. Clone this repository:

2. git clone https://github.com/ffotm/simon-game.git

3. Open index.html in your browser.

4. Start the game and test your memory.

