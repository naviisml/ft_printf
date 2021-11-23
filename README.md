# C Boilerplate

## Features

- Uses Makefile for compilation
- Rich configuration located in the `Makefile`
- Including `srcs/` and `includes/` folder for the source files.
- Special `objects/` folder for `.o` files
- Seperated `build/` folder the final build files

## Commands

To build the program in the final stage, the `all` rule as followed in a terminal;
```
make all
```

To build the final script, and run it after compilation, you may use the `dev` command used as followed in a terminal;
```
make dev
```

To clean up the `objects/` files and folder, you can use the `clean` command as followed in a terminal;
```
make clean
```

To remove both the `objects/` files, the `build` files and the compiled program file, you can simply use the `fclean` command as followed in a terminal;
```
make fclean
```