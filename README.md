# fractol

## Description
A fractal visualization project that renders various types of fractals using computer graphics. This program allows users to explore different mathematical fractals, including the Mandelbrot and Julia sets, with interactive features for zooming and color manipulation. Developed as part of the 42 curriculum.

## Features

### Available Fractals
- Mandelbrot Set
- Julia Set (with variable parameters)
- Burning Ship

### Interactive Controls
- Mouse wheel: Zoom in/out based on mouse position
- Arrow keys: Move around the fractal
- Number keys: Color scheme selection
- ESC: Exit program
- C: change color scheme

## Getting Started

### Installation
Clone and compile the project:
```bash
git clone https://github.com/Evan-Edwards/fractol.git
cd fractol
make
```

### Usage
```bash
./fractol mandelbrot
./fractol julia <num 1> <num 2>
./fractol burning
```

## Technical Details

### Input Handling
- Command-line argument validation
- Fractal type selection
- Parameter handling for Julia set
- Window management and event handling

### Graphics
- Uses MinilibX graphics library
- Complex number calculations
- Color mapping and gradients
- Multi-threading for improved performance (if implemented)

## Error Handling
- Invalid command-line arguments
- Memory allocation failures
- Window creation errors
- Invalid fractal parameters

## Performance
The program is optimized for smooth rendering and interaction:
- Efficient calculation algorithms
- Optimized color calculations
- Smooth zooming and navigation


## Additional Features
- Multiple color palettes
- Zoom tracking
- Coordinate display
- Parameter adjustment for Julia set
- Screenshot capability (if implemented)

---
This project is part of the 42 School curriculum.