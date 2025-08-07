# 🌀 FRACTOL

> Explore the infinite beauty of mathematical fractals in real time.

**fract’ol** is a simple yet visually striking computer graphics project written in **C** using the **MiniLibX** graphics library. The goal is to render and interact with mathematical fractals like the **Mandelbrot set** and **Julia sets** in a smooth, zoomable windowed interface.

---

## 📌 Project Goals

- Learn to use **MiniLibX**, a minimal graphics library
- Work with **complex numbers** in a visual and interactive way
- Implement **fractals** (Mandelbrot and Julia)
- Handle user inputs (keyboard and mouse)
- Practice event handling and real-time rendering
- Optimize for performance and smooth interaction

---

## 📦 Features

- 🧠 Renders **Mandelbrot** and **Julia** fractals
- 🖱️ Mouse **wheel zoom** (in and out infinitely)
- 🧮 Dynamic **Julia set generation** using command-line parameters
- 🎨 Multi-color display with customizable color ranges
- 💻 Responsive window: ESC key and close button exit cleanly
- 📸 Uses **MiniLibX** to create and manage the display window

---

## 🚀 Usage

### Build

```bash
make
```

## Run
```bash
./fractol <fractal_name> [optional_parameters]
```

## Examples
```bash
./fractol mandelbrot
./fractol julia 0.355 0.355
./fractol ship
```

---

## 🎛️ Controls

| Input            | Action                |
|-----------------:|:---------------------:|
| Mouse Scroll     | Zoom in/out           |
| Arrow Keys       | Pan the view          |
| ESC Key          | Exit the Program      |
| Window close (X) | Exit the Program      |
| M                | Switch to Maldelbrot  |
| B                | Switch to BurningShip |
| J                | Switch to Julia       |


---

# 🔧 Supported Fractals

- `Mandelbrot` -> Classic fractal
- `julia` -> Parametrized Julia set (e.g., julia -0.7 0.27015)
- `BurningShip` -> Similar to Mandelbrot but uses absolute values

---

## 📁 Project Structure

```text
.
├── color.c
├── formula.c
├── fractol.c
├── fractol.h
├── hook.c
├── Makefile
├── minilibx-linux
│   ├── configure
│   ├── LICENSE
│   ├── Makefile
│   ├── Makefile.gen
│   ├── Makefile.mk
│   ├── man
│   │   ├── man1
│   │   │   ├── mlx.1
│   │   │   ├── mlx_loop.1
│   │   │   ├── mlx_new_image.1
│   │   │   ├── mlx_new_window.1
│   │   │   └── mlx_pixel_put.1
│   │   └── man3
│   │       ├── mlx.3
│   │       ├── mlx_loop.3
│   │       ├── mlx_new_image.3
│   │       ├── mlx_new_window.3
│   │       └── mlx_pixel_put.3
│   ├── mlx_clear_window.c
│   ├── mlx_destroy_display.c
│   ├── mlx_destroy_image.c
│   ├── mlx_destroy_window.c
│   ├── mlx_expose_hook.c
│   ├── mlx_ext_randr.c
│   ├── mlx_flush_event.c
│   ├── mlx_get_color_value.c
│   ├── mlx_get_data_addr.c
│   ├── mlx.h
│   ├── mlx_hook.c
│   ├── mlx_init.c
│   ├── mlx_int_anti_resize_win.c
│   ├── mlx_int_do_nothing.c
│   ├── mlx_int_get_visual.c
│   ├── mlx_int.h
│   ├── mlx_int_param_event.c
│   ├── mlx_int_set_win_event_mask.c
│   ├── mlx_int_str_to_wordtab.c
│   ├── mlx_int_wait_first_expose.c
│   ├── mlx_key_hook.c
│   ├── mlx_lib_xpm.c
│   ├── mlx_loop.c
│   ├── mlx_loop_hook.c
│   ├── mlx_mouse.c
│   ├── mlx_mouse_hook.c
│   ├── mlx_new_image.c
│   ├── mlx_new_window.c
│   ├── mlx_pixel_put.c
│   ├── mlx_put_image_to_window.c
│   ├── mlx_rgb.c
│   ├── mlx_screen_size.c
│   ├── mlx_set_font.c
│   ├── mlx_string_put.c
│   ├── mlx_xpm.c
│   ├── mlx_xpm.c.ok
│   ├── README.md
│   ├── rgb2c.pl
│   └── test
│       ├── main.c
│       ├── Makefile.gen
│       ├── Makefile.mk
│       ├── new_win.c
│       ├── open24.xpm
│       ├── open30.xpm
│       ├── open.xpm
│       └── run_tests.sh
├── render.c
├── switch.c
└── utils.c

```

---

## ⚠️ Rules & Restrictions

- Written in C, following the 42 Norm
- No global variables
- No memory leaks
- Must use MiniLibX
- Must handle zooming, input, and window interaction smoothly

---

## 🧠 Math Concepts Used

- Complex numbers: represented as **a + bi**
- Escape-time algorithm for rendering
- Color mapping based on iteration count
- Zoom using coordinate transformation

---

## 📄 License

This project is developed as part of the **42 School** curriculum. Feel free to reuse, modify, and learn from it!

---

## 🙌 Credits

Built by students at [42 Firenze](https://42firenze.it), with love and sockets ❤️
