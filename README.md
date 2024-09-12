# Card Generator in C

This is a C-based card generator that reads names from a text file and generates a card (image) for each name using the Cairo library for rendering.

## Features

- Generate personalized cards with names from a text file.
- Customize the card background and font.
- Outputs cards as PNG files in the `output` directory.

## Getting Started

### 1. Install Dependencies

The project uses the Cairo graphics library. You need to install Cairo and FreeType.

#### On Linux (Debian/Ubuntu):

```bash
sudo apt-get update
sudo apt-get install libcairo2-dev libfreetype6-dev
```

On macOS (using Homebrew):

```bash
brew install cairo freetype
```

### 2. Clone the Repository

```bash
git clone https://github.com/BaseMax/CardCGenerator.git
cd CardCGenerator
```

### 3. Compile the Program

To compile the program, use the following gcc command:

```bash
gcc card_generator.c -o card_generator $(pkg-config --cflags --libs cairo)
```

### 4. Directory Structure

Ensure the following files are present in the project directory:

- `card_generator.c (the main C program)
- `card-background.png (the background image for the card)
- `names.txt (a list of names to be included on the cards, one name per line)
- `arial.ttf (or any other TrueType font file)

#### Example Structure

```
/CardCGenerator
|-- card_generator.c
|-- card-background.png
|-- names.txt
|-- arial.ttf
|-- output/  (this directory will be created automatically to store generated cards)
```

### 5. Run the Program

Run the program to generate the cards:

```bash
./card_generator
```

The generated cards will be saved in the output directory.

## Customization

- **Background Image:** You can replace card-background.png with your own background image.
- **Font:** Replace arial.ttf with another font if needed.
- **Names:** Edit names.txt to include the names you want to generate cards for.

## Linking

To check the linking flags for Cairo:

```bash
$ pkg-config --cflags --libs cairo
-I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -lcairo

## License

This project is licensed under the GPL-3.0 License.

### Author

Max Base - 2024
