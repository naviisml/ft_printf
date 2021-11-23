# ft_printf

The ft_printf() function formats and prints its arguments, after the first, under control of the format. The format is a character string which contains three types of objects: plain characters, which are simply copied to standard output, character escape sequences which are converted and copied to the standard output, and format specifications, each of which causes printing of the next successive argument.

The arguments after the first are treated as strings if the corresponding format is either c, b or s; otherwise it is evaluated as a C constant.

## Features

- ft_printf & ft_fprintf
- Conversion for `%u`, `$d` `%i`, `%c`, `%s`, `%p`, `%x`, `%X`, `%%`
- Conversion for `-`, `+`, `0`, `.`, `#`, ` `

## Prototypes

**ft_printf**

```
int	ft_printf(const char *format, ...);
```

**ft_fprintf**

```
int	ft_fprintf(int fd, const char *format, ...);
```