gcc certificate_generator.c -o certificate_generator $(pkg-config --cflags --libs cairo)
./certificate_generator