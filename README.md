# Card C Generator

```
gcc card_generator.c -o card_generator $(pkg-config --cflags --libs cairo)
```

## Linking

```
$ pkg-config --cflags --libs cairo
-I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -lcairo
```

Copyright 2024, Max Base
