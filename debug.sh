gcc card_generator.c -o card_generator $(pkg-config --cflags --libs cairo) -fsanitize=address -g
./card_generator