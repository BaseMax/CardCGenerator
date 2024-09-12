gcc card_generator.c -o card_generator $(pkg-config --cflags --libs cairo)
./card_generator